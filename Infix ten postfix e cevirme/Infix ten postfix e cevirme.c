#include <stdio.h>
#include <stdlib.h>

/*

    Ad Soyad : Sema Nur EKMEKCI
    Numara : 21100011050
    Odev_3

*/

struct Stack{
	char data;
	int oncelikDegeri;
	struct Stack *next;
};

struct Postfix{
	char data;
	int oncelikDdegeri;
	struct Postfix *next;

};

struct Stack *startS = NULL;
struct Postfix *startP = NULL;
struct Stack *tempS = NULL;
struct Postfix *tempP = NULL;
struct Stack *topS = NULL;
struct Postfix *topP = NULL;

char *islem;
char islemTemp[40];
int i,deger;
int sonuc = 0;
int sayacP = 0;
int carpmaVebolme = 2, toplamaVeCikarma = 1, kapaParantez = 4,acParantez = 0;
int durum = 0;
int sonucP;
void islemAl(){

	scanf("%s",&islemTemp);
	islem = islemTemp;
}

void pushStack(){
	if(durum == 0){
	printf("Sembol: %c\n",*(islem+i));
	printf("%c operator Stack'e eklendi.\n",*(islem+i));}
	struct Stack *yeniEleman = (struct Stack *) malloc (sizeof(struct Stack));
	if(durum == 0) yeniEleman->data = *(islem+i);
	else{
		yeniEleman->data = startP->data;

	}
	yeniEleman->oncelikDegeri = deger;
	yeniEleman->next = NULL;
	if(topS == NULL){
		topS = yeniEleman;
		startS = topS;
	}else{
		topS->next = yeniEleman;
		topS = yeniEleman;
	}



}



void pushPostfix(int sonuc){
	sayacP++;
	struct Postfix *yeniEleman = (struct Postfix *) malloc (sizeof(struct Postfix));
	if(sonuc==0){
		printf("Sembol: %c\n",*(islem+i));
		yeniEleman->data = *(islem+i);
		if(*(islem+i) == '*' || *(islem+i) == '/' || *(islem+i) == '+' || *(islem+i) == '-'){
			printf("%c operatoru Postfix'e eklendi.\n",*(islem+i));
	}else{

		printf("%c operandi Postfix'e eklendi.\n",*(islem+i));
	}
}else{
	printf("Sembol: %c\n",topS->data);
	yeniEleman->data = topS->data;
	printf("%c operatoru Stack'ten 'Postfix'e tasindi.\n",topS->data);
}
	yeniEleman->next = NULL;
	if(topP == NULL){
		topP = yeniEleman;
		startP = topP;
	}else{
		topP->next = yeniEleman;
		topP = yeniEleman;
	}


}
void popStack(){

	tempS = startS;
	if(tempS->next == NULL){

		  free(topS);
          topS = NULL;
          startS = NULL;
	}else{
	while(tempS->next->next!=NULL){
		tempS = tempS->next;
	}

	free(topS);
	tempS->next=NULL;
	topS = tempS;}

}


void ekranaYaz(){
	printf("\n");
	printf("--------------------------------\n");
	tempS = startS;
	printf("\t     STACK\n--------------------------------\n");
	if(tempS!=NULL){
	while(tempS->next!=NULL){
		printf(" %c",tempS->data);
		tempS = tempS->next;
	}
	printf(" %c",tempS->data);}
	else{
		printf("    Stack Bos");
	}
	printf("\n\n--------------------------------");
	tempP = startP;
	printf("\n\t     POSTFIX\n--------------------------------\n");
	if(tempP!=NULL){
	while(tempP->next!=NULL){
		printf(" %c",tempP->data);
		tempP = tempP->next;
	}
	printf(" %c",tempP->data);}
	else{
		printf("    Postfix Bos");
	}
	printf("\n\n");
}





int degerAl(){
	i=0;
	while(*(islem+i)!=NULL){
		if(*(islem+i) == ')'){
			deger = kapaParantez;
		}else if(*(islem+i) == '('){
			deger = acParantez;
		}
		else if(*(islem+i) == '*'||*(islem+i) == '/'){
			deger = carpmaVebolme;
		}else if (*(islem+i) == '+'||*(islem+i) == '-'){
			deger = toplamaVeCikarma;
		}else{
			deger = -1;
			sonuc = 0;
			pushPostfix(sonuc);
		}
	if(deger!=-1){
		donustur();
	}

	i++;
	ekranaYaz();
	}
	return deger;
}

void donustur(){

	if(startS == NULL){
		pushStack();
	}else{
		if(deger == acParantez){
			pushStack();
		}else if(deger == kapaParantez){
			while(topS->oncelikDegeri != acParantez){
				sonuc = 1;
				pushPostfix(sonuc);
				popStack();
			}
			popStack();
		}
		else if(topS->oncelikDegeri>=deger){

			while(topS!= NULL && topS->oncelikDegeri>=deger){
			sonuc = 1;
			pushPostfix(sonuc);
			popStack();
		}
		if(topS!=NULL && topS->oncelikDegeri == acParantez){
			sonuc = 0;
			pushPostfix(sonuc);
		}
		else{
			pushStack();

		}

		}else if(topS->oncelikDegeri == deger){
			sonuc = 0;
			pushPostfix(sonuc);
		}

		else{
			pushStack();

		}}
	}

void stackBosalt(){
	sonuc = 1;
	while(startS!=NULL){
		pushPostfix(sonuc);
		popStack();
	}
}

void sonucuStackeAt(char sonucP){
	printf("Sonuc: %d\n",sonucP);
	struct Stack *yeniEleman = (struct Stack *) malloc (sizeof(struct Stack));
	yeniEleman->data = '0'+ sonucP;
	yeniEleman->next = NULL;
	if(topS == NULL){
		topS = yeniEleman;
		startS = topS;
	}else{
		topS->next = yeniEleman;
		topS = yeniEleman;
	}
	printf("%d sonuc Stack'e eklendi.\n",sonucP);

}


void hesapla(){
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\tPostfix Degeri Hesaplaniyor.\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
	i = 0;
	int ilkCikan;
	int sonCikan;

	durum = 1;
	int a;
	while(sayacP>0){
		int sayac = 2;
		if(startP->data == '*' || startP->data == '/' || startP->data == '+' || startP->data == '-')
		{
			while(sayac>0){

				if(sayac == 2)
				{

					ilkCikan = (topS->data);

				    popStack();
				}else{

					sonCikan = (topS->data);
					popStack();
				}
				sayac--;
			}
			if(startP->data=='*') sonucP = sonCikan * ilkCikan;
			else if(startP->data=='/')	sonucP = sonCikan / ilkCikan;
			else if(startP->data=='+')	sonucP = sonCikan + ilkCikan;
			else sonucP = sonCikan - ilkCikan;

			sonucuStackeAt(sonucP);
		}else{
			pushStack();

			a = (int)(startP->data);
			printf("%c degeri Stack'e eklendi.\n",a);

		}
		sayacP--;
		i++;
		startP=startP->next;
		ekranaYaz();
	}

}


int main(int argc, char *argv[]) {
	islemAl();
	degerAl();

	stackBosalt();
	ekranaYaz();
	hesapla();
	ekranaYaz();
	printf("SONUC: %d",sonucP);
	return 0;
}
