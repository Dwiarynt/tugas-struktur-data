#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//========================================================

struct node {
	int data;
    struct node *left;
    struct node *right;

};
typedef struct node node;

//node *createNode(void);
void tambahAwal(node **head);
void tambahData(node **head);
void tambahAkhir (node **head);
void hapusAwal (node **head);
void hapusTengah (node **head);
void hapusAkhir (node **head);
void tranverse(node *head);
void cariData(node **head);
void hitungData (node **head);
void penjumlahanData (node **head);
void insertNode(node **head, node *pPre, node *pNew);

//========================================================

int main()
{
  node *head;
  char pilih;

  head = NULL;
  do{
     system("cls");
     printf("masukkan pilihan\n");
     printf("1. tambah data di awal\n");
     printf("2. tambah data di tengah list\n");
     printf("3. tambah data di akhir list\n");
     printf("4. hapus data di awal list\n");
     printf("5. hapus data di tengah list\n");
     printf("6. hapus data di akhir list\n");
     printf("7. cetak isi list\n");
     printf("8. cari data dalam list\n");
     printf("9. jumlah data dalam list\n");
     printf("0. tampilkan hasil penjumlahan data dalam list\n ");
     printf("MASUKKAN PILIHAN (tekan q untuk keluar) : ");
     fflush(stdin);
     scanf("%c", &pilih);
     if (pilih == '1')
     		tambahAwal(&head);
     else if (pilih == '2')
			tambahData(&head);
     else if (pilih == '3')
            tambahAkhir (&head);
     else if (pilih == '4')
            hapusAwal (&head);
     else if (pilih == '5')
            hapusTengah (&head);
     else if (pilih == '6')
            hapusAkhir (&head);
     else if (pilih == '7')
     		tranverse(head);
     else if (pilih == '8')
             cariData (&head);
     else if (pilih == '9')
             hitungData (&head);
     else if (pilih == '0')
             penjumlahanData (&head);
  } while (pilih != 'q');

  return 0;
}

//========================================================

/*node *createNode(void){
  node *ptr;

  ptr = (node *)malloc(sizeof(node));
  return(ptr);
}*/

//========================================================

void tambahAwal(node **head){
  int bil;
  node *pNew;

  system("cls");
  fflush(stdin);
  printf("masukkan bilangan : ");
  fflush(stdin);
  scanf("%d", &bil);
  pNew = (node *)malloc(sizeof(node));

  if (pNew != NULL){
  	  pNew->data = bil;
      pNew->right = *head;
      pNew->left = NULL;
      //add before first logical node or to an empty list
      if (*head != NULL){
        (*head)->left = pNew;
      }
      *head = pNew;
  }
  else{
      printf("Alokasi memori gagal");
      getch();
  }
}

//========================================================

void tambahData(node **head){
  int pos, bil;
  node *pNew, *pCur;

  system("cls");
  tranverse(*head);
  printf("\nposisi penyisipan setelah data bernilai : ");
  fflush(stdin);
  scanf("%d", &pos);
  printf("\nbilangan : ");
  fflush(stdin);
  scanf("%d", &bil);

  pCur = *head;
  while (pCur != NULL && pCur -> data != pos) {
    pCur = pCur -> right;
  }

  pNew = (node *)malloc(sizeof(node));

  if (pCur == NULL){
     printf("\nnode tidak ditemukan");
     getch();
  }
  else if (pNew == NULL){
     printf("\nalokasi memeori gagal");
     getch();
  }
  else{
     pNew->data = bil;
     pNew->left = pCur;
     pNew -> right = pCur -> right;

     if (pCur->right != NULL){
        pCur->right->left = pNew;
     }
     pCur->right = pNew;
  }
}

//========================================================
void tambahAkhir (node **head){
  int pos, bil;
  node *pNew, *pCur;

  system("cls");
  fflush(stdin);
  printf("masukkan bilangan : ");
  fflush(stdin);
  scanf("%d", &bil);

  pNew = (node *)malloc(sizeof(node));

  if (pNew == NULL){
    printf("\nalokasi memori gagal");
    getch();
  }
  pNew->data = bil;
  pNew->right = NULL;

  if (*head == NULL) {
      pNew->left = NULL;
      *head = pNew;
  } else {
    pCur = *head;
    while (pCur->right != NULL){
        pCur = pCur->right;
    }
    pNew->left = pCur;
    pNew->right = NULL;
    pCur->right = pNew;
  }
}

//========================================================

void hapusAwal(node **head){
    system("cls");
    if (*head == NULL){
    printf(" List kosong, tidak ada data yang dihapus.\n");
    getch();
    return;
  }

  node *pCur = *head;
  *head = pCur->right;

  free(pCur);

  printf("Data berhasil dihapus.\n");
  getch();
}
//========================================================

void hapusTengah(node **head){
    system("cls");
    if (*head == NULL){
    printf(" List kosong, tidak ada data yang dihapus.\n");
    getch();
  }

  int data;
  printf("Masukkan data yang ingin dihapus:\n");
  scanf("%d", &data);

  node *pCur = *head;
  node *pPre = NULL;

  while (pCur != NULL && pCur->data != data){
    pPre = pCur;
    pCur = pCur->right;
  }

  if (pCur == NULL) {
    printf ("Data tidak ditemukan.\n", data);
    getch();
  }

  if (pPre == NULL){
    *head = pCur->right;
    if (*head != NULL){
        (*head)->left = NULL;
    }
  } else {
      pPre->right = pCur->right;
      if (pCur->right != NULL){
        pCur->right->left = pPre;
      }
  }

  free(pCur);
  printf("Data berhasil dihapus.\n");
  getch();
}

//========================================================

void hapusAkhir (node **head){
    system("cls");
    if (*head == NULL) {
        printf("List kosong, tidak ada data yang dihapus.\n");
        getch();
  }

  if ((*head)->right == NULL){
    free(*head);
    *head = NULL;
    getch();
  }

   node *pCur = *head;

  while (pCur->right != NULL){
    pCur = pCur->right;
  }

  node *pPre =pCur->left;
  pPre->right= NULL;

  free(pCur);

  printf("Data berhasil dihapus.\n");
  getch();
}

//========================================================

void tranverse(node *head){
   //traverse a linked list
	node *pWalker;

    system("cls");
	pWalker = head;
	if (pWalker == NULL ){
        printf ("List kosong.\n");
        return;
	}
	while (pWalker != NULL){
        printf("%d", pWalker -> data);
   	    pWalker = pWalker -> right;

   	    if(pWalker != NULL){
            printf(" -> ");
   	    }
	 }
   printf(" NULL\n ");
   getch();
}
//========================================================

void cariData(node **head){
    system("cls");
    int nilai;
       printf("Masukkan data yang dicari:");
       scanf("%d", &nilai);

       node *pCur = *head;
       while (pCur != NULL) {
           if (pCur->data == nilai) {
              printf("Data %d ditemukan dalam list.\n", pCur->data);
              getch();
              return;
           }
           pCur = pCur->right;
       }
       printf("Data tidak ditemukan dalam list.\n");
       getch();
}

//========================================================

void hitungData (node **head) {
    system("cls");
    int jumlah = 0;
    node *pWalker = *head;

    while (pWalker != NULL){
        jumlah++;
        pWalker = pWalker->right;
    }

    printf("Jumlah data dalam list: %d\n", jumlah);
    getch();
}

//========================================================

void penjumlahanData (node **head){
   system("cls");
   int sum = 0;
   node *pWalker = *head;

   while (pWalker != NULL) {
    sum += pWalker->data;
    pWalker = pWalker->right;
   }

   printf("Hasil penjumlahan data dalam list: %d\n", sum);
   getch();
}

//========================================================

void insertNode(node **head, node *pPre, node *pNew){
    if (pPre == NULL){
       //add before first logical node or to an empty list
	    pNew -> right = *head;
	    pNew->left = NULL;

	    if(*head != NULL){
            (*head)->left = pNew;
	    }
       *head = pNew;
    }
    else {
       //add in the middle or at the end
       pNew -> right = pPre -> right;
       pPre -> left = pPre;

       if(pPre->right != NULL){
        pPre->right->left = pNew;
       }
       pPre->right = pNew;
   }
}
//========================================================
