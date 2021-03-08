#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct kelimesayma
{

    char *kelime;
    int kelime_sayisi;
    struct kelimesayma* next;
    struct kelimesayma* prev;

};
struct kelimesayma *ilk = NULL,*son = NULL, *son_eklenen,*gecici,*siralanmis,*siralanmis_son,*tmp_x;
FILE *dosya;
int kelimesayisi=1;
int sonkelimesayi=0;
int siralanmisboyut=0;
int siralanmissonboyut=0;
char kelimedizi[1000];
int j=0;
void ekle(char veri)
{

    struct kelimesayma *yeni = (struct kelimesayma*) malloc(sizeof(struct kelimesayma)*20);
    yeni->kelime = veri;
    yeni->kelime_sayisi=0;
    yeni->next = NULL;

    if(ilk == NULL)      //Ýlk düðümde eleman olup olmadýðýný kontrol et.
    {
        ilk = yeni;
        son = ilk;
    }
    else                 //Ýlk düðümde eleman varsa bu iþlemleri yap.
    {
        son->next = yeni;
        son = son->next;
    }

    son_eklenen=yeni;

}
void listele()
{

    gecici = ilk;

    if (gecici == NULL)
    {

        printf("Listenizde eleman bulunmamaktadir...");


    }
    else
    {
        while (gecici != NULL)
        {

            printf("%s\n", gecici->kelime);
            gecici = gecici->next;

        }
    }

}
void kelimesayisibul()
{
    gecici = ilk;

    if (gecici == NULL)
    {
        sonkelimesayi=0;
    }
    else
    {
        while (gecici != NULL)
        {
            sonkelimesayi++;
            gecici = gecici->next;

        }
    }

}
void arama(char *aranan)
{
    struct kelimesayma *gecici1 = (struct kelimesayma*) malloc(sizeof(struct kelimesayma)*20);
    int kontrol = 0;
    gecici = ilk;
    int deger=0;

    if (gecici == NULL)

        kontrol = -1;
    else
    {

        while (gecici != NULL)
        {

            if ( strcmp(gecici->kelime,aranan)==0  && deger==0)
            {

                kontrol = 1;
                gecici->kelime_sayisi=gecici->kelime_sayisi+1;
                deger=1;

            }

            gecici = gecici->next;
        }


    }

}
void sirala()
{
    son = ilk;
    int i;
    for(i=sonkelimesayi-1; i>=0; i--)
    {
        struct kelimesayma *temp = (struct kelimesayma*) malloc(sizeof(struct kelimesayma)*20);
        temp->kelime=son->kelime;
        temp->kelime_sayisi=son->kelime_sayisi;
        temp->next=NULL;
        if(temp->kelime_sayisi>0)
        {
            if(siralanmisboyut==0)
            {
                siralanmis=temp;
            }
            else
            {
                gecici=siralanmis;
                while(gecici->next!=NULL)
                {
                    gecici=gecici->next;
                }
                gecici->next= temp;
            }
            siralanmisboyut++;
        }
        son=son->next;
    }
    gecici=siralanmis;
    while(gecici!=NULL)
    {
        if(siralanmissonboyut==0)
        {
            basaekleee(gecici->kelime_sayisi,gecici->kelime);
        }
        else
        {
            tmp_x=siralanmis_son;
                  int kacsonra=1;
            if(tmp_x->kelime_sayisi <= gecici->kelime_sayisi)
            {
                basaekleee(gecici->kelime_sayisi,gecici->kelime);
            }
            else
            {
                int varmi=0;
                while(tmp_x!=NULL)
                {
                    if(tmp_x->kelime_sayisi <= gecici->kelime_sayisi)
                    {
                        varmi=1;
                    }
                    tmp_x=tmp_x->next;

                }

                if(varmi==1)
                {
                    tmp_x=siralanmis_son;
                    while(tmp_x->next->kelime_sayisi >= gecici->kelime_sayisi)
                    {
                        tmp_x=tmp_x->next;
                        kacsonra++;
                        if(tmp_x->next==NULL){
                            break;
                        }
                    }

                    arayaekle(gecici->kelime_sayisi,kacsonra, gecici->kelime);
                }else{
                    sonaekle(gecici->kelime_sayisi,gecici->kelime);

                }

            }


        }


        gecici=gecici->next;

    }
    gecici=siralanmis_son;
    while(gecici!=NULL){
        printf("\n %d %s",gecici->kelime_sayisi,gecici->kelime);
        gecici=gecici->next;
    }


}
void basaekleee(int value, char *kelimee)//https://sanalkurs.net/c-c-ile-programlama-tek-yonlu-bagli-liste-islemleri-linked-list-10053.html
{
    struct kelimesayma *var = (struct kelimesayma*) malloc(sizeof(struct kelimesayma)*20);

    var->kelime_sayisi=value;
    var->kelime=kelimee;
    if(siralanmis_son==NULL)
    {

        siralanmis_son=var;
        siralanmis_son->next=NULL;
    }
    else
    {
        var->next=siralanmis_son;
        siralanmis_son=var;
    }
    siralanmissonboyut++;


}

void sonaekle(int value, char *kelimee)//https://sanalkurs.net/c-c-ile-programlama-tek-yonlu-bagli-liste-islemleri-linked-list-10053.html
{
    struct kelimesayma *temp;
    temp=siralanmis_son;
    struct kelimesayma *var = (struct kelimesayma*) malloc(sizeof(struct kelimesayma)*20);

    var->kelime_sayisi=value;
    var->kelime=kelimee;

    if(siralanmis_son==NULL)
    {
        siralanmis_son=var;
        siralanmis_son->next=NULL;
    }
    else
    {


        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=var;
    }
    siralanmissonboyut++;

}

void arayaekle(int value, int loc, char *kelimee)//https://sanalkurs.net/c-c-ile-programlama-tek-yonlu-bagli-liste-islemleri-linked-list-10053.html
{
    struct kelimesayma *var2,*temp;
    struct kelimesayma *var = (struct kelimesayma*) malloc(sizeof(struct kelimesayma)*20);

    var->kelime_sayisi=value;
    var->kelime=kelimee;
    temp=siralanmis_son;

    if(siralanmis_son==NULL)
    {
        siralanmis_son=var;
        siralanmis_son->next=NULL;
    }
    else
    {
        while(temp->kelime_sayisi!=loc && temp->next!=NULL)
        {
            temp=temp->next;
        }
        var2=temp->next;
        temp->next=var;
        var->next=var2;
    }
    siralanmissonboyut++;


}





int main()
{
    char aranan[30];
    char * kelime;
    dosya = fopen("deneme.txt","r");//metin bulundugu dosya okuma modunda acýlýyor.
    if(dosya==NULL)
    {
        printf(" Dosya AcÝlamadi!");
    }
    else
    {
        printf("\t\t\t\tDOSYA ACILDI\n");
    }
    char kelime_satiri[100];
    int ch;
    for(ch = fgetc(dosya); ch!=EOF; ch = getc(dosya))
    {
        if(ch == '\n')
        {
            kelimesayisi++;
        }
    }

    int cursor=0;
    fseek(dosya,0,SEEK_SET); // cursoru basa almazsak dosyayý okuyamayiz cunku kelime sayýsýný bulurken cursorun yeri degisti.

    for(int i=0; i<kelimesayisi; i++)   // elde edilen satirlari bosluga gore parcaliyoruz.
    {

        fseek(dosya,cursor,SEEK_SET);

        fgets(kelime_satiri,100,dosya);
        cursor=ftell(dosya);
        strtok(kelime_satiri,"\n");

        char* ptr = strtok(kelime_satiri," ");
        int ayrac=0;// her bir satirda cursorun hangi boslukta kaldigini tutmamiz icin.

        while(ptr != NULL)
        {


            if(ayrac>=0)
            {

                ekle(ptr);

                const size_t len_my_str = strlen(ptr) + 1;
                kelime = malloc(len_my_str);
                strncpy(kelime, ptr, len_my_str);
                son_eklenen->kelime=kelime;

            }


            ptr = strtok(NULL, " ");
            ayrac++;
            arama(kelime);

        }

    }


    listele();
    kelimesayisibul();

    printf("Kelime adedi : %d",sonkelimesayi);
    sirala();
}
