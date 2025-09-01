#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define GENISLIK 100
#define UZUNLUK 33

int main(int argc, char**argv) {
    if (argc==1){
        printf("ENTER FILE NAME\n");
        return 1;
    }
    FILE *txtfile = fopen("asci.txt", "r");
    if (!txtfile) {
        printf("NO SUCH FILE\n");
        return 1;
    }

    char cizgi[GENISLIK + 2];
    char kare[UZUNLUK][GENISLIK + 2];
    while(1){

    
        for (int i=0; i<UZUNLUK; i++) {
            if(!fgets(cizgi,sizeof(cizgi),txtfile)) {
                fseek(txtfile, 0, SEEK_SET);
                fgets(cizgi,sizeof(cizgi),txtfile);
            }
            strcpy(kare[i],cizgi);
        }

        printf("\e[1;1H\e[2J");

        for(int x=0; x<UZUNLUK; x++){
            printf("%s",kare[x]);
        }
        usleep(64000);
    }
        fclose(txtfile);
        return 0;
}
