#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct devregiris{
   char giris[5];
   char cikis[5];
}dvr;

struct deger{
   char harf[10];
   int deger[10];
}dgr;

struct kapilar{
    char kapitipi[100];
    char girissayisi[10];
    char cikis[100];
    char giris[100];
    int gecikme[10];
};

struct komut{
    char sutun[100];
    char sutun2[100];
};

struct komut kmt[20];
struct kapilar kapi[20];

int yapilacakislem[10];
char yapilacakislemcikis[10][100];

void komut_oku(char gelen[]){
    FILE *fptr;
    int sayac=0;
    fptr = fopen(gelen,"r");
    if(fptr == NULL){
        printf("Dosya bulunamadi\n");
        exit(0);
    }



int sayac2=0;
int i=0;
int deger;
        sayac=0;
        while(!feof(fptr)){
        fscanf(fptr,"%s",kmt[sayac].sutun);
        if(kmt[sayac].sutun[0] == 'Y'  || kmt[sayac].sutun[0] == 'y'){
                fscanf(fptr,"%s",kmt[sayac].sutun2);
            txtdevre_oku(kmt[sayac].sutun2);
        }
        else if(kmt[sayac].sutun[0] == 'I' || kmt[sayac].sutun[0] == -115){
            fscanf(fptr,"%s",kmt[sayac].sutun2);
            txtdeger_oku(kmt[sayac].sutun2);
        }
        else if(kmt[sayac].sutun[0] == 'H' || kmt[sayac].sutun[0] == 'h'){
            fscanf(fptr,"%s",kmt[sayac].sutun2);
            highmethod(kmt[sayac].sutun2[0]);
        }
        else if(kmt[sayac].sutun[0] == 'G' || kmt[sayac].sutun[0] == 'g'){
                sayac2=0;
        fscanf(fptr,"%s",kmt[sayac].sutun2);
            if(kmt[sayac].sutun2[0] == NULL)
                printf("Islem yapilamadi.\n");
            else if(kmt[sayac].sutun2[0] == '*'){
                while(dgr.harf[sayac2] != NULL){
                printf("%c : %d\n",dgr.harf[sayac2],dgr.deger[sayac2]);
                sayac2++;
            }
            }
            while(dgr.harf[sayac2] != NULL){
                if(dgr.harf[sayac2] == kmt[sayac].sutun2[0]){
                    printf("%c : %d\n",dgr.harf[sayac2],dgr.deger[sayac2]);
                }
                sayac2++;
            }
        }
        else if(kmt[sayac].sutun[0] == 'S' || kmt[sayac].sutun[0] == 's'){
            int deger2=0;
                sayac2=0;
        for(i=0;i<100;i++){
            sayac2=0;
                if(yapilacakislemcikis[i][0] == NULL)
                break;
                while(dgr.harf[sayac2] != '\0'){
                if(dgr.harf[sayac2] == yapilacakislemcikis[i][0])
                deger=dgr.deger[sayac2];
                sayac2++;
                }
        if(deger==1)
            deger2=0;
        else
            deger2=1;
            printf("%d.ns:%c %d--->%d\n",yapilacakislem[i],yapilacakislemcikis[i][0],deger2,deger);
        }
        }
        else if(kmt[sayac].sutun[0] == 'C' || kmt[sayac].sutun[0] == 'c'){
            exit(0);
        }
        sayac++;
        }




}

void txtdeger_oku(char gelen[]){
FILE *fptr;
fptr = fopen(gelen,"r");
 if(fptr == NULL){
        printf("Dosya bulunamadi\n");
        exit(0);
    }


char cumle[150];
int sayac=0;
int sayac2=0;
int i;
int k;

for(i = 1;fgets(cumle,sizeof(cumle),fptr) != NULL;i++){
for(k=0;k<40;k++){
        if(cumle[k]=='\t'){
            dgr.deger[sayac] = cumle[k+1]-48;
            sayac++;
        }else if(k==0){
            dgr.harf[sayac2] = cumle[k];
            sayac2++;
        }
    }
}
}

void txtdevre_oku(char gelen[]){
FILE *fptr;
fptr = fopen(gelen,"r");
if(fptr == NULL){
        printf("Dosya bulunamadi\n");
        exit(0);
    }

char dizi[100];
char cumle[150];
char cumle2[100];
char giris2[10];
char giris3[10];
int sayac=0;
int sayac2=0;
int sayac3=0;
int sayacc=0;
int i;
int imlec;

while(!feof(fptr)){
       if(sayacc==0){
           fscanf(fptr,"%s",cumle2);
        }
        fgets(cumle,100,fptr);
    sayacc++;}

fclose(fptr);
fptr = fopen(gelen,"r");
if(strcmp(cumle2,".giris") == 0){
while(!feof(fptr)){
       fgets(cumle,100,fptr);
       if(sayac == 0){
        for(i=0;i<40;i++){
            if(cumle[i]=='\t'){
                dvr.giris[sayac3]=cumle[i+1];
                sayac3++;
                if(cumle[i+1]=='#'){
                    break;
                }
            }
        }
       }
       if(sayac == 1){
            sayac3=0;
        for(i=0;i<40;i++){
            if(cumle[i]=='\t'){
                dvr.cikis[sayac3]=cumle[i+1];
                sayac3++;
       if(cumle[i+1]=='#'){
                    break;
                }
            }
        }
       }
       sayac++;


       if(sayac>1){

           fscanf(fptr,"%s",dizi);
           imlec = ftell(fptr);
           fscanf(fptr,"%s\t%s",kapi[sayac2].kapitipi,kapi[sayac2].girissayisi);


           if(kapi[sayac2].girissayisi[0]=='1'){
                fseek(fptr,imlec,SEEK_SET);
                fscanf(fptr,"\t%s\t%s\t%s\t%s\t%s\t%s",dizi,kapi[sayac2].kapitipi,kapi[sayac2].girissayisi,kapi[sayac2].cikis
           ,kapi[sayac2].giris,kapi[sayac2].gecikme);
           }
           else if(kapi[sayac2].girissayisi[0]=='2'){
               fseek(fptr,imlec,SEEK_SET);
            fscanf(fptr,"%s\t%s\t%s\t%s\t%s\t%s\t%s",dizi,kapi[sayac2].kapitipi,kapi[sayac2].girissayisi,kapi[sayac2].cikis
           ,kapi[sayac2].giris,giris2,kapi[sayac2].gecikme);
           strcat(kapi[sayac2].giris,giris2);
           }
           else if(kapi[sayac2].girissayisi[0]=='3'){
               fseek(fptr,imlec,SEEK_SET);
            fscanf(fptr,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s",dizi,kapi[sayac2].kapitipi,kapi[sayac2].girissayisi,kapi[sayac2].cikis
           ,kapi[sayac2].giris,giris2,giris3,kapi[sayac2].gecikme);
           strcat(kapi[sayac2].giris,giris2);
           strcat(kapi[sayac2].giris,giris3);
           }
    sayac2++;
       }
}

int sayacc=0;
int numara=0;
while(kapi[sayacc].gecikme[0] != NULL){
    numara = atoi(kapi[sayacc].gecikme);
    kapi[sayacc].gecikme[0] = numara;
    sayacc++;
}
}

else if(strcmp(cumle2,".include") == 0){
while(!feof(fptr)){
       fgets(cumle,100,fptr);
       if(sayac == 1){
        for(i=0;i<40;i++){
            if(cumle[i]=='\t'){
                dvr.giris[sayac3]=cumle[i+1];
                sayac3++;
                if(cumle[i+1]=='#'){
                    break;
                }
            }
        }
       }
       if(sayac == 2){
            sayac3=0;
        for(i=0;i<40;i++){
            if(cumle[i]=='\t'){
                dvr.cikis[sayac3]=cumle[i+1];
                sayac3++;
       if(cumle[i+1]=='#'){
                    break;
                }
            }
        }
       }
       sayac++;

       if(sayac>2){
           fscanf(fptr,"%s",dizi);
           imlec = ftell(fptr);
           fscanf(fptr,"%s\t%s",kapi[sayac2].kapitipi,kapi[sayac2].girissayisi);


           if(kapi[sayac2].girissayisi[0]=='1'){
                fseek(fptr,imlec,SEEK_SET);
                fscanf(fptr,"\t%s\t%s\t%s\t%s\t%s\t%s",dizi,kapi[sayac2].kapitipi,kapi[sayac2].girissayisi,kapi[sayac2].cikis
           ,kapi[sayac2].giris,kapi[sayac2].gecikme);
           }
           else if(kapi[sayac2].girissayisi[0]=='2'){
               fseek(fptr,imlec,SEEK_SET);
            fscanf(fptr,"%s\t%s\t%s\t%s\t%s\t%s\t%s",dizi,kapi[sayac2].kapitipi,kapi[sayac2].girissayisi,kapi[sayac2].cikis
           ,kapi[sayac2].giris,giris2,kapi[sayac2].gecikme);
           strcat(kapi[sayac2].giris,giris2);
           }
           else if(kapi[sayac2].girissayisi[0]=='3'){
               fseek(fptr,imlec,SEEK_SET);
            fscanf(fptr,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s",dizi,kapi[sayac2].kapitipi,kapi[sayac2].girissayisi,kapi[sayac2].cikis
           ,kapi[sayac2].giris,giris2,giris3,kapi[sayac2].gecikme);
           strcat(kapi[sayac2].giris,giris2);
           strcat(kapi[sayac2].giris,giris3);
           }
    sayac2++;
       }
}

fclose(fptr);
FILE *fptr;
fptr = fopen("baska_dosya.txt","r");
 if(fptr == NULL){
        printf("Dosya bulunamadi");
        exit(0);
    }
    sayac=0;
    int sayac5=0;
    int kontrol=0;
    sayac2--;
while(!feof(fptr)){
       fgets(cumle,100,fptr);
       if(sayac == 0){
        for(i=0;i<40;i++){
            if(cumle[i]=='\t'){
                    if(cumle[i+1]=='#'){
                    break;
                }
                while(dvr.giris[sayac5] != '\0'){
                    if(dvr.giris[sayac5] == cumle[i+1])
                    kontrol = 1;
                    sayac5++;
                }sayac5=0;
                if(kontrol != 1)
                dvr.giris[sayac3]=cumle[i+1];
                sayac3++;kontrol = 0;
            }
        }
       }
       if(sayac == 1){
         /*   sayac3=0;
        for(i=0;i<40;i++){
            if(cumle[i]=='\t'){
                    if(cumle[i+1]=='#'){
                    break;
                }
                    while(dvr.cikis[sayac5] != '\0'){
                    if(dvr.cikis[sayac5] == cumle[i+1])
                    kontrol = 1;
                    sayac5++;
                }sayac5=0;
            if(kontrol != 1)
                dvr.cikis[sayac3]=cumle[i+1];
                sayac3++;

            }
        }*/
       }
       sayac++;

       if(sayac>1){
           fscanf(fptr,"%s",dizi);
           imlec = ftell(fptr);
           fscanf(fptr,"%s\t%s",kapi[sayac2].kapitipi,kapi[sayac2].girissayisi);


           if(kapi[sayac2].girissayisi[0]=='1'){
                fseek(fptr,imlec,SEEK_SET);
                fscanf(fptr,"\t%s\t%s\t%s\t%s\t%s\t%s",dizi,kapi[sayac2].kapitipi,kapi[sayac2].girissayisi,kapi[sayac2].cikis
           ,kapi[sayac2].giris,kapi[sayac2].gecikme);
           }
           else if(kapi[sayac2].girissayisi[0]=='2'){
               fseek(fptr,imlec,SEEK_SET);
            fscanf(fptr,"%s\t%s\t%s\t%s\t%s\t%s\t%s",dizi,kapi[sayac2].kapitipi,kapi[sayac2].girissayisi,kapi[sayac2].cikis
           ,kapi[sayac2].giris,giris2,kapi[sayac2].gecikme);
           strcat(kapi[sayac2].giris,giris2);
           }
           else if(kapi[sayac2].girissayisi[0]=='3'){
               fseek(fptr,imlec,SEEK_SET);
            fscanf(fptr,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s",dizi,kapi[sayac2].kapitipi,kapi[sayac2].girissayisi,kapi[sayac2].cikis
           ,kapi[sayac2].giris,giris2,giris3,kapi[sayac2].gecikme);
           strcat(kapi[sayac2].giris,giris2);
           strcat(kapi[sayac2].giris,giris3);
           }
    sayac2++;
       }
}


int sayacc=0;
int numara=0;


while(kapi[sayacc].gecikme[0] != NULL){
    numara = atoi(kapi[sayacc].gecikme);
    kapi[sayacc].gecikme[0] = numara;
    sayacc++;
}
}




}

void highmethod(char alinan){
    int sayac = 0;
    int kontrol = 0;
    int hangiharf;
    int sayac2 = 0;
    char tmp;
    int yayilimsayac=0;
    //int yapilacakislem[10];
    char yapilacakislemharf[10][100];
    char yapilacakislemkapi[10][100];
    char yapilacakislemgirissayisi[10];
    //char yapilacakislemcikis[10][100];
    int toplam=0;
    int sayac3=0;
    int sayac4=0;
while(dgr.harf[sayac]!=NULL){
    if(dgr.harf[sayac]==alinan){
        kontrol = 1;
        hangiharf = sayac;
    }
    sayac++;
}

if(kontrol == 0){
    printf("Girdiginiz harf devrede yoktur.\n");
    kontrol = 0;
}

else if(dgr.deger[hangiharf] == 1 && kontrol == 1){
    printf("Girdiginiz uc zaten 1'dir\n");
    kontrol = 0;
}
else{
    dgr.deger[hangiharf] = 1;
    yapilacakislem[sayac3]=0;
    yapilacakislemharf[sayac3][0]=alinan;
    yapilacakislemcikis[0][0]=alinan;
    sayac3++;

    while(kapi[sayac2].kapitipi[0] != NULL){
        if(strchr(kapi[sayac2].giris,alinan)){
                tmp = kapi[sayac2].cikis[0];

        while(tmp != dvr.cikis[0]){
            if(strchr(kapi[sayac4].giris,tmp)){
                toplam+=kapi[sayac2].gecikme[0];
                yapilacakislem[sayac3]=toplam;
                yapilacakislemgirissayisi[sayac3]=kapi[sayac2].girissayisi[0];
                strcpy(yapilacakislemharf[sayac3],kapi[sayac2].giris);
                strcpy(yapilacakislemkapi[sayac3],kapi[sayac2].kapitipi);
                strcpy(yapilacakislemcikis[sayac3],kapi[sayac2].cikis);
                sayac3++;
                toplam+=kapi[sayac4].gecikme[0];
                yapilacakislem[sayac3]=toplam;
                yapilacakislemgirissayisi[sayac3]=kapi[sayac4].girissayisi[0];
                strcpy(yapilacakislemharf[sayac3],kapi[sayac4].giris);
                strcpy(yapilacakislemkapi[sayac3],kapi[sayac4].kapitipi);
                strcpy(yapilacakislemcikis[sayac3],kapi[sayac4].cikis);
                sayac3++;
                tmp = kapi[sayac4].cikis[0];
            }
         sayac4++;
        }sayac4=0;toplam=0;
        }
        sayac2++;
    }

}

int i,j,z;
int degisken=0;
char degiskenharf[1][100];
char degiskenkapi[1][100];
char degiskencikis[1][100];
char degiskengiris;

for(i=0; i<sayac3-1;i++){
        for(j=i+1; j<sayac3; j++){
            if(yapilacakislem[i] > yapilacakislem[j]){
                degisken = yapilacakislem[i];
                degiskengiris = yapilacakislemgirissayisi[i];
                strcpy(degiskenharf[0],yapilacakislemharf[i]);
                strcpy(degiskenkapi[0],yapilacakislemkapi[i]);
                strcpy(degiskencikis[0],yapilacakislemcikis[i]);
                strcpy(yapilacakislemharf[i],yapilacakislemharf[j]);
                strcpy(yapilacakislemcikis[i],yapilacakislemcikis[j]);
                strcpy(yapilacakislemkapi[i],yapilacakislemkapi[j]);
                yapilacakislem[i] = yapilacakislem[j];
                yapilacakislemgirissayisi[i] = yapilacakislemgirissayisi[j];
                strcpy(yapilacakislemharf[j],degiskenharf[0]);
                strcpy(yapilacakislemkapi[j],degiskenkapi[0]);
                strcpy(yapilacakislemcikis[j],degiskencikis[0]);
                yapilacakislem[j] = degisken;
                yapilacakislemgirissayisi[j] = degiskengiris;
            }
        }
    }




for(z=1;z<sayac3;z++){
    if(strcmp(yapilacakislemkapi[z],"NAND") == 0 && yapilacakislemgirissayisi[z] == '2'){
          nandkapisi(yapilacakislemharf[z][0],yapilacakislemharf[z][1],yapilacakislemcikis[z][0]);
    }
    else if(strcmp(yapilacakislemkapi[z],"XOR") == 0 && yapilacakislemgirissayisi[z] == '2'){
          exorkapisi(yapilacakislemharf[z][0],yapilacakislemharf[z][1],yapilacakislemcikis[z][0]);
    }
    else if(strcmp(yapilacakislemkapi[z],"NOR") == 0 && yapilacakislemgirissayisi[z] == '2'){
          norkapisi(yapilacakislemharf[z][0],yapilacakislemharf[z][1],yapilacakislemcikis[z][0]);
    }
    else if(strcmp(yapilacakislemkapi[z],"XNOR") == 0 && yapilacakislemgirissayisi[z] == '2'){
          exnorkapisi(yapilacakislemharf[z][0],yapilacakislemharf[z][1],yapilacakislemcikis[z][0]);
    }
    else if(strcmp(yapilacakislemkapi[z],"NOT") == 0 && yapilacakislemgirissayisi[z] == '1'){
          notkapisi(yapilacakislemharf[z][0],yapilacakislemcikis[z][0]);
    }
    else if(strcmp(yapilacakislemkapi[z],"AND") == 0 && yapilacakislemgirissayisi[z] == '2'){
          andkapisi(yapilacakislemharf[z][0],yapilacakislemharf[z][1],yapilacakislemcikis[z][0]);
    }
    else if(strcmp(yapilacakislemkapi[z],"AND") == 0 && yapilacakislemgirissayisi[z] == '3'){
          andkapisi3(yapilacakislemharf[z][0],yapilacakislemharf[z][1],yapilacakislemharf[z][2],yapilacakislemcikis[z][0]);
    }
    else if(strcmp(yapilacakislemkapi[z],"NOR") == 0 && yapilacakislemgirissayisi[z] == '3'){
          norkapisi3(yapilacakislemharf[z][0],yapilacakislemharf[z][1],yapilacakislemharf[z][2],yapilacakislemcikis[z][0]);
    }
}


}

void lowmethod(char alinan){
    int sayac = 0;
    int kontrol = 0;
    int hangiharf;
    int sayac2 = 0;
    char tmp;
    int yayilimsayac=0;
    //int yapilacakislem[10];
    char yapilacakislemharf[10][100];
    char yapilacakislemkapi[10][100];
    char yapilacakislemgirissayisi[10];
    //char yapilacakislemcikis[10][100];
    int toplam=0;
    int sayac3=0;
    int sayac4=0;
while(dgr.harf[sayac]!=NULL){
    if(dgr.harf[sayac]==alinan){
        kontrol = 1;
        hangiharf = sayac;
    }
    sayac++;
}

if(kontrol == 0){
    printf("Girdiginiz harf devrede yoktur.\n");
    kontrol = 0;
}

else if(dgr.deger[hangiharf] == 0 && kontrol == 1){
    printf("Girdiginiz uc zaten 0'dir\n");
    kontrol = 0;
}
else{
    dgr.deger[hangiharf]=0;
    yapilacakislem[sayac3]=0;
    yapilacakislemharf[sayac3][0]=alinan;
    yapilacakislemcikis[0][0]=alinan;
    sayac3++;

    while(kapi[sayac2].kapitipi[0] != NULL){
        if(strchr(kapi[sayac2].giris,alinan)){
                tmp = kapi[sayac2].cikis[0];

        while(tmp != dvr.cikis[0]){
            if(strchr(kapi[sayac4].giris,tmp)){
                toplam+=kapi[sayac2].gecikme[0];
                yapilacakislem[sayac3]=toplam;
                yapilacakislemgirissayisi[sayac3]=kapi[sayac2].girissayisi[0];
                strcpy(yapilacakislemharf[sayac3],kapi[sayac2].giris);
                strcpy(yapilacakislemkapi[sayac3],kapi[sayac2].kapitipi);
                strcpy(yapilacakislemcikis[sayac3],kapi[sayac2].cikis);
                sayac3++;
                toplam+=kapi[sayac4].gecikme[0];
                yapilacakislem[sayac3]=toplam;
                yapilacakislemgirissayisi[sayac3]=kapi[sayac4].girissayisi[0];
                strcpy(yapilacakislemharf[sayac3],kapi[sayac4].giris);
                strcpy(yapilacakislemkapi[sayac3],kapi[sayac4].kapitipi);
                strcpy(yapilacakislemcikis[sayac3],kapi[sayac4].cikis);
                sayac3++;
                tmp = kapi[sayac4].cikis[0];
            }
         sayac4++;
        }sayac4=0;toplam=0;
        }
        sayac2++;
    }

}

int i,j,z;
int degisken=0;
char degiskenharf[1][100];
char degiskenkapi[1][100];
char degiskencikis[1][100];
char degiskengiris;

for(i=0; i<sayac3-1;i++){
        for(j=i+1; j<sayac3; j++){
            if(yapilacakislem[i] > yapilacakislem[j]){
                degisken = yapilacakislem[i];
                degiskengiris = yapilacakislemgirissayisi[i];
                strcpy(degiskenharf[0],yapilacakislemharf[i]);
                strcpy(degiskenkapi[0],yapilacakislemkapi[i]);
                strcpy(degiskencikis[0],yapilacakislemcikis[i]);
                strcpy(yapilacakislemharf[i],yapilacakislemharf[j]);
                strcpy(yapilacakislemcikis[i],yapilacakislemcikis[j]);
                strcpy(yapilacakislemkapi[i],yapilacakislemkapi[j]);
                yapilacakislem[i] = yapilacakislem[j];
                yapilacakislemgirissayisi[i] = yapilacakislemgirissayisi[j];
                strcpy(yapilacakislemharf[j],degiskenharf[0]);
                strcpy(yapilacakislemkapi[j],degiskenkapi[0]);
                strcpy(yapilacakislemcikis[j],degiskencikis[0]);
                yapilacakislem[j] = degisken;
                yapilacakislemgirissayisi[j] = degiskengiris;
            }
        }
    }




for(z=1;z<sayac3;z++){
    if(strcmp(yapilacakislemkapi[z],"NAND") == 0 && yapilacakislemgirissayisi[z] == '2'){
          nandkapisi(yapilacakislemharf[z][0],yapilacakislemharf[z][1],yapilacakislemcikis[z][0]);
    }
    else if(strcmp(yapilacakislemkapi[z],"XOR") == 0 && yapilacakislemgirissayisi[z] == '2'){
          exorkapisi(yapilacakislemharf[z][0],yapilacakislemharf[z][1],yapilacakislemcikis[z][0]);
    }
    else if(strcmp(yapilacakislemkapi[z],"NOR") == 0 && yapilacakislemgirissayisi[z] == '2'){
          norkapisi(yapilacakislemharf[z][0],yapilacakislemharf[z][1],yapilacakislemcikis[z][0]);
    }
    else if(strcmp(yapilacakislemkapi[z],"XNOR") == 0 && yapilacakislemgirissayisi[z] == '2'){
          exnorkapisi(yapilacakislemharf[z][0],yapilacakislemharf[z][1],yapilacakislemcikis[z][0]);
    }
    else if(strcmp(yapilacakislemkapi[z],"NOT") == 0 && yapilacakislemgirissayisi[z] == '1'){
          notkapisi(yapilacakislemharf[z][0],yapilacakislemcikis[z][0]);
    }
    else if(strcmp(yapilacakislemkapi[z],"AND") == 0 && yapilacakislemgirissayisi[z] == '2'){
          andkapisi(yapilacakislemharf[z][0],yapilacakislemharf[z][1],yapilacakislemcikis[z][0]);
    }
    else if(strcmp(yapilacakislemkapi[z],"AND") == 0 && yapilacakislemgirissayisi[z] == '3'){
          andkapisi3(yapilacakislemharf[z][0],yapilacakislemharf[z][1],yapilacakislemharf[z][2],yapilacakislemcikis[z][0]);
    }
    else if(strcmp(yapilacakislemkapi[z],"NOR") == 0 && yapilacakislemgirissayisi[z] == '3'){
          norkapisi3(yapilacakislemharf[z][0],yapilacakislemharf[z][1],yapilacakislemharf[z][2],yapilacakislemcikis[z][0]);
    }
}




}

void norkapisi(char alinanharf,char alinanharf2,char verilenharf){
   int alinan,alinan2,verilen;
   int sayac=0;
   while(dgr.harf[sayac] != NULL){
    if(dgr.harf[sayac] == alinanharf)
        alinan = dgr.deger[sayac];
    else if(dgr.harf[sayac] == alinanharf2)
        alinan2 = dgr.deger[sayac];
        sayac++;
   }

   if(alinan == 0 && alinan2 == 0)
        verilen = 1;
   else
        verilen = 0;

        sayac=0;
        while(dgr.harf[sayac] != NULL){
        if(dgr.harf[sayac] == verilenharf)
        dgr.deger[sayac] = verilen;
        sayac++;
        }
}
void norkapisi3(char alinanharf,char alinanharf2,char alinanharf3,char verilenharf){
int alinan,alinan2,alinan3,verilen;
   int sayac=0;
   while(dgr.harf[sayac] != NULL){
    if(dgr.harf[sayac] == alinanharf)
        alinan = dgr.deger[sayac];
    else if(dgr.harf[sayac] == alinanharf2)
        alinan2 = dgr.deger[sayac];
    else if(dgr.harf[sayac] == alinanharf3)
        alinan3 = dgr.deger[sayac];
        sayac++;
   }

   if(alinan==0 && alinan2==0 && alinan3==0)
    verilen=1;
   else
    verilen=0;

    sayac=0;
        while(dgr.harf[sayac] != NULL){
        if(dgr.harf[sayac] == verilenharf)
        dgr.deger[sayac] = verilen;
        sayac++;
        }

}
void andkapisi(char alinanharf,char alinanharf2,char verilenharf){
int alinan,alinan2,verilen;
   int sayac=0;
   while(dgr.harf[sayac] != NULL){
    if(dgr.harf[sayac] == alinanharf)
        alinan = dgr.deger[sayac];
    else if(dgr.harf[sayac] == alinanharf2)
        alinan2 = dgr.deger[sayac];
        sayac++;
   }
   if(alinan==1 && alinan2==1)
    verilen=1;
   else
    verilen=0;

   sayac=0;
        while(dgr.harf[sayac] != NULL){
        if(dgr.harf[sayac] == verilenharf)
        dgr.deger[sayac] = verilen;
        sayac++;
        }

}
void andkapisi3(char alinanharf,char alinanharf2,char alinanharf3,char verilenharf){
   int alinan,alinan2,alinan3,verilen;
   int sayac=0;
   while(dgr.harf[sayac] != NULL){
    if(dgr.harf[sayac] == alinanharf)
        alinan = dgr.deger[sayac];
    else if(dgr.harf[sayac] == alinanharf2)
        alinan2 = dgr.deger[sayac];
    else if(dgr.harf[sayac] == alinanharf3)
        alinan3 = dgr.deger[sayac];
        sayac++;
   }
   if(alinan==1 && alinan2==1 && alinan3==1)
    verilen=1;
   else
    verilen=0;

    sayac=0;
        while(dgr.harf[sayac] != NULL){
        if(dgr.harf[sayac] == verilenharf)
        dgr.deger[sayac] = verilen;
        sayac++;
        }


}
void nandkapisi(char alinanharf,char alinanharf2,char verilenharf){
   int alinan,alinan2,verilen;
   int sayac=0;
   while(dgr.harf[sayac] != NULL){
    if(dgr.harf[sayac] == alinanharf)
        alinan = dgr.deger[sayac];
    else if(dgr.harf[sayac] == alinanharf2)
        alinan2 = dgr.deger[sayac];
        sayac++;
   }

    if(alinan == 1 && alinan2 == 1)
        verilen = 0;
    else
        verilen = 1;

        sayac=0;
        while(dgr.harf[sayac] != NULL){
        if(dgr.harf[sayac] == verilenharf)
        dgr.deger[sayac] = verilen;
        sayac++;
        }
}
void exorkapisi(char alinanharf,char alinanharf2,char verilenharf){
      int alinan,alinan2,verilen;
   int sayac=0;
   while(dgr.harf[sayac] != NULL){
    if(dgr.harf[sayac] == alinanharf)
        alinan = dgr.deger[sayac];
    else if(dgr.harf[sayac] == alinanharf2)
        alinan2 = dgr.deger[sayac];
        sayac++;
   }


     if(alinan == 0 && alinan2 == 0)
        verilen = 0;
     else if(alinan == 1 && alinan2 == 1)
        verilen = 0;
     else
        verilen = 1;

        sayac=0;
        while(dgr.harf[sayac] != NULL){
        if(dgr.harf[sayac] == verilenharf)
        dgr.deger[sayac] = verilen;
        sayac++;
        }
}
void exnorkapisi(char alinanharf,char alinanharf2,char verilenharf){
  int alinan,alinan2,verilen;
   int sayac=0;
   while(dgr.harf[sayac] != NULL){
    if(dgr.harf[sayac] == alinanharf)
        alinan = dgr.deger[sayac];
    else if(dgr.harf[sayac] == alinanharf2)
        alinan2 = dgr.deger[sayac];
        sayac++;
   }


     if(alinan == 0 && alinan2 == 0)
        verilen = 1;
     else if(alinan == 1 && alinan2 == 1)
        verilen = 1;
     else
        verilen = 0;

        sayac=0;
        while(dgr.harf[sayac] != NULL){
        if(dgr.harf[sayac] == verilenharf)
        dgr.deger[sayac] = verilen;
        sayac++;
        }
}
void notkapisi(char alinanharf,char verilenharf){
   int alinan,verilen;
   int sayac=0;
   while(dgr.harf[sayac] != NULL){
    if(dgr.harf[sayac] == alinanharf)
        alinan = dgr.deger[sayac];
        sayac++;
   }
   if(alinan == 1)
    verilen = 0;
   else
    verilen = 1;

   sayac=0;
        while(dgr.harf[sayac] != NULL){
        if(dgr.harf[sayac] == verilenharf)
        dgr.deger[sayac] = verilen;
        sayac++;
        }

}






int main()
{
    FILE *fptr;
    fptr=fopen("log_komut.txt","w");
    struct tm *local,*gm;
    time_t t;
    gm=gmtime(&t);
    fprintf(fptr,"zaman\tkomut\tcikti\n");
    char komut[2];
    int sayac=0;
    int i=0;
    int sayacc=0;
    int deger;
    char cumle[100];
    char cumle2[100];

    while(1){
        printf(">");
        gets(komut);

        if(komut[0] == 'Y'  || komut[0] == 'y'){
                printf(">");
                gets(cumle);
            txtdevre_oku(cumle);
            fprintf(fptr,"%d/%d/%d-%d:%d:%d\tY %s\tdevre.txt yuklendi\n",gm->tm_year+1886,gm->tm_mon+5,
                    gm->tm_mday-11,gm->tm_hour+15,gm->tm_min,gm->tm_sec,cumle);
        }
        else if(komut[0] == 'I' || komut[0] == -115){
            printf(">");
            gets(cumle);
            txtdeger_oku(cumle);
            fprintf(fptr,"%d/%d/%d-%d:%d:%d\tI %s\tdegerler atandi\n",gm->tm_year+1886,gm->tm_mon+5
                    ,gm->tm_mday-11,gm->tm_hour+15,gm->tm_min,gm->tm_sec,cumle);
        }
        else if(komut[0] == 'H' || komut[0] == 'h'){
            highmethod(komut[1]);
            fprintf(fptr,"%d/%d/%d-%d:%d:%d\tH %c\t%c girisi birlendi\n",gm->tm_year+1886,gm->tm_mon+5,gm->tm_mday-11,
                    gm->tm_hour+15,gm->tm_min,gm->tm_sec,komut[1],komut[1]);
        }
        else if(komut[0] == 'G' || komut[0] == 'g'){
                fprintf(fptr,"%d/%d/%d-%d:%d:%d\tG",gm->tm_year+1886,gm->tm_mon+5,gm->tm_mday-11,gm->tm_hour+15,gm->tm_min,gm->tm_sec);
                sayac=0;
            if(komut[1] == NULL)
                printf("Islem yapilamadi.\n");
            else if(komut[1] == '*'){
                while(dgr.harf[sayac] != NULL){
                fprintf(fptr,"\t%c : %d",dgr.harf[sayac],dgr.deger[sayac]);
                printf("%c : %d\n",dgr.harf[sayac],dgr.deger[sayac]);
                sayac++;
            }fprintf(fptr,"\n");
            }
            while(dgr.harf[sayac] != NULL){
                if(dgr.harf[sayac] == komut[1]){
                    fprintf(fptr,"\t%c : %d\n",dgr.harf[sayac],dgr.deger[sayac]);
                    printf("%c : %d\n",dgr.harf[sayac],dgr.deger[sayac]);
                }
                sayac++;
            }
        }
        else if(komut[0] == 'S' || komut[0] == 's'){
            int deger2=0;
                sayac=0;
                fprintf(fptr,"%d/%d/%d-%d:%d:%d\tS",gm->tm_year+1886,gm->tm_mon+5,gm->tm_mday-11,gm->tm_hour+15,gm->tm_min,gm->tm_sec);
        for(i=0;i<100;i++){
            sayac=0;
                if(yapilacakislemcikis[i][0] == NULL)
                break;
                while(dgr.harf[sayac] != '\0'){
                if(dgr.harf[sayac] == yapilacakislemcikis[i][0])
                deger=dgr.deger[sayac];
                sayac++;
                }
        if(deger==1)
            deger2=0;
        else
            deger2=1;
        fprintf(fptr,"\t%d.ns:%c %d--->%d",yapilacakislem[i],yapilacakislemcikis[i][0],deger2,deger);
        printf("%d.ns:%c %d--->%d\n",yapilacakislem[i],yapilacakislemcikis[i][0],deger2,deger);
        }fprintf(fptr,"\n");
        }
        else if(komut[0] == 'K' || komut[0] == 'k'){
        printf(">");
        gets(cumle);
        komut_oku(cumle);
        }
        else if(komut[0] == 'C' || komut[0] == 'c'){
            exit(0);
        }
        else if(komut[0] == 'L' || komut[0] == 'l'){
            lowmethod(komut[1]);
            fprintf(fptr,"%d/%d/%d-%d:%d:%d\tH %c\t%c girisi sifirlandi\n",gm->tm_year+1886,gm->tm_mon+5,gm->tm_mday-11,
                    gm->tm_hour+15,gm->tm_min,gm->tm_sec,komut[1],komut[1]);
        }



        komut[0]="";
        komut[1]="";
        }






    return 0;
}
