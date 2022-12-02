/*

ÖDEV_4
AD - SOYAD : Sema Nur EKMEKCI;
NUMARA : 21100011050;

*/

#include <stdio.h>
#include <stdlib.h>

struct agac{
    int data;
    struct agac * right;
    struct agac * left;
	};
	
int sayac = 0;
struct agac *root = NULL;
struct agac *temp;
struct agac *temp2;
struct agac *kokDugum(int data){
    struct agac * root = (struct agac *) malloc (sizeof(struct agac));
    root->data = data;
    root->left = NULL;
    root->right = NULL;

    return root;
};

struct agac *elemanEkle(struct agac *root, int data){
    if(root == NULL){
        root = kokDugum(data);

    }
    else{
        if(data < root->data){
            root->left = elemanEkle(root->left,data);}
        else{
            root->right = elemanEkle(root->right,data);}
    }
    return root;
};

int inorderSirala(struct agac *root){
	
    if(root!=NULL){
        inorderSirala(root->left);
        printf("%d ",root->data,sayac++);
        
        inorderSirala(root->right);
    }
    return sayac;
}

int yukseklikBul(struct agac *root){
    if(root==0){
        return 0;
    }
    int s1 = yukseklikBul(root->left);
    int s2 = yukseklikBul(root->right);
    if(s1 > s2){
        return s1+1;
    }else{
        return s2+1;
    }
	}


struct agac * arama(struct agac *root, int silinecek){
if(root!=NULL){
    if(root->data == silinecek)
        return root->data;
        
    else if(silinecek > root->data )
        arama(root->right,silinecek);
    
    else
	    arama(root->left,silinecek);
	}else
		return NULL;
   }



struct agac* silme(struct agac *root, int data) {
	if(root == NULL) 
	{
		return root; 
	}
	else if(data < root->data){
	
	 root->left = silme(root->left,data);
	}
	else if(data > root->data)
	{
	 root->right = silme(root->right,data);	
	}
	else {
	
		if(root->left == NULL && root->right == NULL) { 
			free(root);
			root = NULL;
		}
	
		else if(root->left == NULL) {
			struct agac *temp = root;
			root = root->right;
			free(temp);
		}
		else if(root->right == NULL) {
			struct agac *temp = root;
			root = root->left;
			free(temp);
		}
		else { 
			root = root->right;
			while(root->left != NULL) 
			{ 
			root = root->left;
			}
			temp = root;
			root->data = temp->data;
			root->right = silme(root->right,temp->data);
		}
	}
	return root;
}
	int solTaraf(struct agac *root){
		if(root==NULL){
			return 0;
		}
		else{
			return solTaraf(root->left)+1;		
		}	
	}
	
	
	int sagTaraf(struct agac *root){
		if(root==NULL){
			return 0;
		}
		else {
			return sagTaraf(root->right)+1;					
		}		
		
	}

	
	
void fullBinaryControl(struct agac *root){
	int s2 = sagTaraf(root);
	int s1 = solTaraf(root); 
	int elemanSayisi = inorderSirala(root);
	if(s1 != s2){
		printf("Full Binary Degil");
		}else{
			if(elemanSayisi%2==1){
				printf("\nFull Binary\n");
			}
			else if(elemanSayisi%2 == 0){
				printf("\nComplete Binary\n");
			}
			else{
				printf("\nFull Binary Degil\n");
			}
			}
		}



int main()
{
     int yukseklik;
    int islem;

	int sayi;
	while(1==1){
	system("COLOR F");
	printf("\n1)Ekleme\n2)Silme\n3)Inorder Siralama\n4)Yukseklik Bulma\n5)Full Binary Control\n6)Complete Binary Control\n7)Arama");
	printf("\nIslem Giriniz-->");
	scanf("%d", &islem);

		switch(islem){

		case 1:
		    printf("Sayi Giriniz : ");
            scanf("%d",&sayi);
            root = elemanEkle(root,sayi);
			break;
        case 2:
              if(root==NULL){
                printf("\n~~~~~~~~AGAC YAPISI BOS~~~~~~~~\n");
                system("COLOR C");
				system("COLOR C");
				system("COLOR C");
            }else{
            printf("Silinecek Elemani Giriniz : ");
            scanf("%d",&sayi);
            root = silme(root,sayi);}
            break;
		case 3:
			if(root == NULL){
				printf("\n~~~~~~~~AGAC YAPISI BOS~~~~~~~~\n");
				system("COLOR C");
				system("COLOR C");
				system("COLOR C");
			}else{
				printf("\n");
				inorderSirala(root);
			}
			break;

        case 4:
            yukseklik = yukseklikBul(root);
            printf("\nYukseklik -> %d\n",yukseklik-1);
            break;
        case 5:
            if(root==NULL){

                printf("\n~~~~~~~~AGAC YAPISI BOS~~~~~~~~\n");
                system("COLOR C");
				system("COLOR C");
				system("COLOR C");
            }else{
            	fullBinaryControl(root);
			}
			break;
		case 6:
			if(root==NULL){

                printf("\n~~~~~~~~AGAC YAPISI BOS~~~~~~~~\n");
                system("COLOR C");
				system("COLOR C");
				system("COLOR C");
            }else{
            	fullBinaryControl(root);
			}
			break;
        case 7:
        	printf("Aranacak Sayiyi Giriniz : ");
        	scanf("%d",&sayi);
        	int aranan = arama(root,sayi);
        	if(aranan!=NULL){
        		printf("\n%d degeri mevcut\n",aranan);	
			}else{
				printf("\n%d degeri mevcut degil\n",sayi);
			}
			break;
}
}}
