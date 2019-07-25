#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "whitebox-homework1.h"

int main()
{
    uint8_t tbx[16];
    unsigned char index[16];
    printf("======== TBOX ========\n");
    for(int i=0;i<16;i++){
        tbx[i] = tbox[0][i][0];
        printf("%02x ",tbx[i]);
    }
    printf("\n======================\n");
    printf("======== SBOX ========\n");
    int count=0;
    do{
    for(int i=0;i<16;i++){
        for(int j=0;j<16;j++){
            if(tbx[count]==sbox[i][j]){
                //printf("Index : %d %d\n", i,j);
                index[count] = i*16+j;
                count++;
            }
        }
    }
    /*
 *  $key : BOB!?***********
 *  $hint:
 *  sr(round_keys[r]);
 *	tbox[r][i][x] = sbox[x ^ roundKeys[r][i]];
    0 1 2 3 4 5 6 7 8 9 A B C D E F
    B e v a ? W t ! s V B 8 D O M q
    0 4 812 1 5 913 2 61014 3 7 1115
*/
    }while(count<15);

    count = 0;
    for(int i=0;i<16;i++){
        if(count == 3){
            printf("%c\n", index[i]);
            count = 0;
        }else {
            printf("%c ", index[i]);
            count++;
        }
    }
    printf("\n======================\n");
    sr(index);
    for(int i=0;i<16;i++){
        if(count == 3){
            printf("%c\n", index[i]);
            count = 0;
        }else {
            printf("%c ", index[i]);
            count++;
        }
    }
    printf("\n======================\n");

    sr(index);
    sr(index);
    for(int i=0;i<16;i++){
        printf("%c",index[i]);
    }
    printf("\n======================\n");
    return 0;
}
