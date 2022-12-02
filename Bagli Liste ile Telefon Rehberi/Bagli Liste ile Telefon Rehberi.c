#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

// Odev_1
// Ad Soyad: Sema Nur EKMEKCÝ
// Ogrenci No: 21100011050
// Telefon Rehberi Odevi 

struct node{
    char ad[20];
    char soyAd[20];
    long int telefon;
    struct node * next;
};

struct node * start = NULL;
struct node * temp = NULL;
int i;

void kisiEkle()
{
	long int telefonKontrol;
	int durum = 1;
    struct node *yeniKisi;
    yeniKisi = (struct node *) malloc (sizeof(struct node));
    printf("\nEkleme Islemi Yapiyorsunuz\n");
    printf("Ad: ");
    scanf("%s", &yeniKisi->ad);
    printf("Soyad: ");
    scanf("%s", &yeniKisi->soyAd);
    printf("Telefon: (5XXXXXXXXX) ");
    scanf("%li", &telefonKontrol);
    
	temp = start;
	
    if(start == NULL){
    	yeniKisi->telefon = telefonKontrol;
        start = yeniKisi;
    	start->next = start;
    	printf("\n--> Eleman Eklendi\n");
        }else{
			temp = start;
            int elemanSayisi = elemanSayisiBul();			
			do{
            	if(temp->telefon == telefonKontrol){
            		printf("\nVar Olan Telefon Numarasi Tusladiniz. Ekleme Islemi Yapilamadi\n");
            		durum = 0;
            		break;
				}
					temp = temp->next;	
				}while(temp->next!=start);
		    if(durum == 1){
		    yeniKisi->telefon = telefonKontrol;
            temp = start;
            while(temp->next!=start){
            	temp = temp->next;
			}
            temp->next = yeniKisi;
            yeniKisi->next = start;
            start = yeniKisi;
            printf("\n--> Eleman Eklendi\n");
			}
        }
    
}


void listele(){
    temp = start;
    if(temp==NULL){
    	printf("\n--> Liste Bos Listelenecek Eleman Yok\n");
	}else{
	while (temp->next!=start)
    {
        printf("\n-> %s  %s  %li\n",temp->ad, temp->soyAd,temp->telefon);
        temp = temp->next;
    }
    printf("\n-> %s  %s  %li\n",temp->ad, temp->soyAd,temp->telefon);
}}
    

void silme(){
	long int silinecek;
	struct node * temp2;
	struct node * last;
	temp = start;
	last=start;

	if(temp==NULL){
		printf("\n--> Liste Bos Silinecek Eleman Yok\n");
	}else{
		printf("Silinecek Telefon No'yu Giriniz : ");
    	scanf("%li",&silinecek);
		if(temp->next ==start){ //tek eleman varsa
			free(start);
			start=NULL;
		}
		else if(temp->telefon == silinecek){ //ilk eleman ise
			temp2 = temp->next;
			while(last->next != start){
				last=last->next;
			}
			last->next=temp2;
			free(start);
			start=temp2;
			printf("\n--> Eleman Silindi\n");
		 }
		else{
		
		while(temp->next->telefon != silinecek){ 
			temp=temp->next;
		}
		temp2 = temp->next->next;
		free(temp->next);
		temp->next = temp2;
		printf("\n--> Eleman Silindi\n");
	}}
	
}


void sirala(){
// int i = 0 , j=0;
int kucuk,sonuc;
struct node *temp2,*p;
p = (struct node *) malloc (sizeof(struct node));
temp = start;
if(start == NULL){
		printf("\n--> Liste Bos Siralanacak Eleman Yok\n");}
		else{
		
do{
	temp2 = temp->next;
	do{
		if(strlen(temp->soyAd)<strlen(temp2->soyAd)){
		kucuk = strlen(temp->soyAd);
		}
		else{
		kucuk = strlen(temp2->soyAd);
			}
		sonuc = strncmp(temp->soyAd,temp2->soyAd,kucuk);
		if(sonuc>0){
			
			strcpy(p->ad,temp->ad);
			strcpy(temp->ad, temp2->ad);
			strcpy(temp2->ad, p->ad);
			
			strcpy(p->soyAd,temp->soyAd);
			strcpy(temp->soyAd, temp2->soyAd);
			strcpy(temp2->soyAd, p->soyAd);
			
			p->telefon = temp->telefon;
			temp->telefon = temp2->telefon;
			temp2->telefon = p->telefon;

		}
		temp2 = temp2->next;
	}while(temp2!=start);
	temp = temp->next;
}while(temp->next != start);
printf("Soyisime Gore Alfabetik Sirali Liste\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
listele();
}}
	

int elemanSayisiBul(){
	int elemanSayisi = 0;
			temp = start;
			while(temp->next!=start){
			elemanSayisi++;
			temp = temp->next;
		}
		return elemanSayisi;
}


void arama(){
	int durum = 0;
	int islem;
	int i;
	int aranan;
		
	temp = start;
	if(start == NULL){
		printf("\n--> Liste Bos Aranacak Eleman Yok\n");

}else{

	printf("--> Neye Gore Arama Yapmak Istersiniz?\n1->Ad\n2->Telefon\nSeciminiz: ");
	scanf("%d",&islem);
	int elemanSayisi = elemanSayisiBul();
	if(islem==1){
		int durum = 0;
		char arananAd[20];
		printf("--> Aranan Adi Giriniz: ");
		scanf("%s",&arananAd);
	
		temp = start;
		for(i = 0;i<=elemanSayisi;i++){
			aranan = strcmp(temp->ad,arananAd);
			if(aranan==0){
				durum = 1;
				printf("--> %s  %s  %li\n",temp->ad,temp->soyAd,temp->telefon);
			}
			temp = temp->next;
		}
		if(durum = 0){
			printf("--> %s adinda bir kayit yok.",arananAd);	
		}
	}else if(islem == 2){
		long int arananTelefon;
		printf("--> Aranan Telefonu Giriniz: ");
		scanf("%lf",&arananTelefon);
			temp = start;
		for(i=0;i<=elemanSayisi;i++){
			
			if(temp->telefon == arananTelefon){
				durum = 1;
				printf("%s  %s  %li\n",temp->ad,temp->soyAd,temp->telefon);
			}
			temp = temp->next;
		}
		if(durum == 0){
			printf("--> %li telefon numarali bir kayit yok.",arananTelefon);
		}
		
	}
		
}
	}


int main(){
    setlocale(LC_ALL, "Turkish");
    while(1){
	int secim;
	 
    printf("\n1-> Ekleme\n");
    printf("2-> Silme\n");
    printf("3-> Arama\n");
    printf("4-> Listeleme\n");
    printf("5-> Soyada Gore Siralama\n");
    printf("0-> Cikis\n"); 
    printf("Seciminiz: ");
    scanf("%d",&secim);

    switch (secim)
    {
    case 1 :
        kisiEkle();
        break;
    case 2:
    	silme();
    	break;
    case 3:
    	arama();
    	break;
    case 4:
        listele();
        break;
    case 5:
    	sirala();
    	break;
    case 0:
        return 1;
    default:
        printf("Hatali Tuslama Yaptiniz!!!");
    }
    }
    return 0;
}
