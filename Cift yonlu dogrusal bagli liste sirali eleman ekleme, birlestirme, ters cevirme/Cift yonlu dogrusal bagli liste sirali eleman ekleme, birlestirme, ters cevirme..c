#include <stdio.h>
#include <stdlib.h>

/*
AD-Soyad : Sema Nur Ekmekci
Numara : 21100011050
Ödev_2 - Çift yönlü doğrusal bağlı liste sıralı eleman ekleme, birleştirme, ters çevirme.
*/




struct node1{

	int data;
	struct node1 *next;
	struct node1 *prev;

};

struct node2{

	int data;
	struct node2 *next;
	struct node2 *prev;

};


struct node1 *start1 = NULL;
struct node1 *temp1;
struct node2 *start2 = NULL;
struct node1 *temp2;


void bagliListe1(){

		struct node1 *dugum1 = (struct node1 *) malloc (sizeof(struct node1));
		dugum1->data = rand() % 1000;
		if(start1==NULL){

		dugum1->next = NULL;
		dugum1->prev = NULL;
		start1 = dugum1;

		}else{
			temp1 = start1;
			while(temp1->next!=NULL){
				temp1 = temp1->next;
			}

			dugum1->next = NULL;
			dugum1->prev = temp1;
			temp1->next = dugum1;

		}
}

bagliListe2(){
	struct node2 *dugum2 = (struct node2 *) malloc (sizeof(struct node2));
		dugum2->data = rand() % 100;
		if(start2==NULL){

		dugum2->next = NULL;
		dugum2->prev = NULL;
		start2 = dugum2;

		}else{
			temp2 = start2;
			while(temp2->next!=NULL){
				temp2 = temp2->next;
			}

			dugum2->next = NULL;
			dugum2->prev = temp2;
			temp2->next = dugum2;

}

}

void adresleriYazdir(int dugumSayisi,int durum){
	printf("\n\t1.Bagli Liste\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	int sayac=1;

	temp1 = start1;

	while(temp1->next!=NULL){

		printf("%d.Dugum Degeri-> %d -> %d.Dugum Adresi-> %p\n",sayac,temp1->data,sayac,temp1);
		temp1 = temp1->next;
		if(durum == 1)
			sayac+=2;
		else
			sayac+=1;
	};
		printf("%d.Dugum Degeri-> %d -> %d.Dugum Adresi-> %p\n",sayac,temp1->data,sayac,temp1);
	if(durum == 1){
	if(dugumSayisi!=1){
	printf("\n\t2.Bagli Liste\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

		temp2 = start2;
		sayac=2;
	while(temp2->next!=NULL){
		printf("%d.Dugum Degeri-> %d -> %d.Dugum Adresi-> %p\n",sayac,temp2->data,sayac,temp2);
		temp2 = temp2->next;
		sayac+=2;
	};
	printf("%d.Dugum Degeri-> %d -> %d.Dugum Adresi-> %p\n",sayac,temp2->data,sayac,temp2);
	sayac++;}}
}

void tersCevir(int dugumSayisi){
	int cevrildi = 1;
    temp1 = start1;
    struct node1 *a = NULL;
    struct node1 *b = NULL;
    struct node1 *c = temp1->next;
    while(dugumSayisi>0){
        a = c;
        temp1->next = b;
        a->prev = a->next;
        c = a->next;
        a->next = temp1;
        b = temp1;
        temp1 = a;
        dugumSayisi-=1;

    }
    start1 = b->prev;



}



void listeBirlestir(int dugumSayisi,int *durum){
	int i;
	struct node1 *iter1;
	struct node2 *iter2;
	temp1 = start1;
	temp2 = start2;
	*durum = 0;
	int sayac = 0;
	for(i = 1 ; i<=dugumSayisi/2 ; i++){
		sayac++;
		iter1 = temp1->next;
		iter2 = temp2->next;
		temp2->prev = temp1;
		temp2->next = temp1->next;
		temp1->next = temp2;
		if(sayac != dugumSayisi/2){
		iter1->prev=temp2;
		temp1 = iter1;
		temp2 = iter2;
		}



	}
	return durum;
}



int main(int argc, char *argv[]) {
	int durum = 1; //1.bagli listeyi yazdyrmak için.
	int dugumSayisi;

	printf("\nKac Dugum Istersiniz?: ");
	scanf("%d",&dugumSayisi);
	if(dugumSayisi<=0){
		printf("\n-> Gecersiz Deger Girdiniz\n\n");

	}else{
		if(dugumSayisi == 1){
			bagliListe1();
		}else{
	int dugumSayisiTemp = dugumSayisi-1;
	while(dugumSayisiTemp>0){

		bagliListe1();

		bagliListe2();
		dugumSayisiTemp-=2;

	}
	if(dugumSayisi % 2 == 1){
		bagliListe1();
	}
}
	adresleriYazdir(dugumSayisi,durum);
	listeBirlestir(dugumSayisi,&durum);
	adresleriYazdir(dugumSayisi,durum);
	tersCevir(dugumSayisi-1);
	adresleriYazdir(dugumSayisi,durum);
}

	return 0;
}
