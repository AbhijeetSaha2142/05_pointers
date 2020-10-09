#include <stdio.h>

int main(){
    //1
    long l = 1;
    int i = 1;
    char c = 1;

    //2
    //addresses in hexadecimal and decimal
    printf("addresses:\n");
    printf("&l hex: %p, &l dec: %lu\n", &l, &l);
    printf("&i hex: %p, &i dec: %lu\n", &i, &i);
    printf("&c hex: %p, &c dec: %lu\n", &c, &c);
    // the address of c is 1 byte away from i
    // the address of i is 4 bytes away from l
    // this suggests their respective sizes
    // if another variable was made before l it's address would probably be 4 bytes away from l
    
    //3
    long* lp = &l;
    int* ip = &i;
    char* cp = &c;

    //4
    printf("\npointer values:\n");
    printf("&l hex: %p, &l dec: %lu\n", lp, lp);
    printf("&i hex: %p, &i dec: %lu\n", ip, ip);
    printf("&c hex: %p, &c dec: %lu\n", cp, cp);

    //5
    // change through dereferenced pointers
    *lp = 1234;
    *ip = 1234;
    *cp = 123;

    // print out new values
    printf("\nnew values:\nl: %ld\n",l);
    printf("i: %d\n",i);
    printf("c: %d\n", (int) c);

    //6
    unsigned int ui = 42;
    int* uiip = &ui;
    char* uicp = &ui;

    //7
    //print out pointers and dereferenced value
    printf("\nunsigned int pointers and the values they point to\n");
    printf("int pointer: %p, points to: %d\n", uiip, *uiip);
    printf("char pointer: %p, points to: %d\n", uicp, *uicp);

    //8
    //printing as hexadecimal then as decimal
    printf("\nprinting unsigned int:\n");
    printf("ui as hex: %x\n",ui);
    printf("ui as dec: %u\n\n",ui);
    
    //9
    //printing each byte of the unsigned int
    printf("each byte of the unsigned int:\n");
    int n;
    for(n = 0; n < sizeof(unsigned int); n++) {
        printf("byte %d, hex: %hhx, dec: %hhu\n",n,*(uicp+n),*(uicp+n));
    }

    //10
    //incrementing each byte of the unsigned int
    printf("\nincrementing each byte of the unsigned int:\n");
    n = 0;
    for(n = 0; n < sizeof(unsigned int); n++) {
        *(uicp+n) += 1;
        printf("byte %d modified, hex ui: %x, dec ui: %u\n",n, ui, ui);
    }

    //printing each byte of the new unsigned int
    printf("\neach byte of the  new unsigned int:\n");
    n = 0;
    for(n = 0; n < sizeof(unsigned int); n++) {
        printf("byte %d, hex: %hhx, dec: %hhu\n",n,*(uicp+n),*(uicp+n));
    }

    //11
    //incrementing each byte of the unsigned int
    printf("\nincrementing each byte of the unsigned int by 16:\n");
    n = 0;
    for(n = 0; n < sizeof(unsigned int); n++) {
        *(uicp+n) += 16;
        printf("byte %d modified, hex ui: %x, dec ui: %u\n",n, ui, ui);
    }

    //printing each byte of the new unsigned int
    printf("\neach byte of the  new unsigned int:\n");
    n = 0;
    for(n = 0; n < sizeof(unsigned int); n++) {
        printf("byte %d, hex: %hhx, dec: %hhu\n",n,*(uicp+n),*(uicp+n));
    }
    
    // for an unsigned int it seems like each byte is part of a base 256 number
    // the memory addres is the zeroth power place
    // memory address + n is the nth power place
    return 0;

}