#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//========================================================

struct node {
	int data;
    struct node *next;
};
typedef struct node node;

//node *createNode(void);
void tambahAwal(node **pList);
void tambahData(node **pList);
void tambahAkhir (node **pList);
void hapusAwal (node **pList);
void hapusTengah (node **Plist);
void hapusAkhir (node **pList);
void tranverse(node *pList);
void cariData(node **pList);
void hitungData (node **pList);
void penjumlahanData (node **pList);
void insertNode(node **pList, node *pPre, node *pNew);

//========================================================

int main()
{
  node *pList;
  char pilih;

  pList = NULL;
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
     		tambahAwal(&pList);
     else if (pilih == '2')
			tambahData(&pList);
     else if (pilih == '3')
            tambahAkhir (&pList);
     else if (pilih == '4')
            hapusAwal (&pList);
     else if (pilih == '5')
            hapusTengah (&pList);
     else if (pilih == '6')
            hapusAkhir (&pList);
     else if (pilih == '7')
     		tranverse(pList);
     else if (pilih == '8')
             cariData (&pList);
     else if (pilih == '9')
             hitungData (&pList);
     else if (pilih == '0')
             penjumlahanData (&pList);
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

void tambahAwal(node **pList){
  int bil;
  node *pNew, *pCur;

  system("cls");
  fflush(stdin);
  printf("masukkan bilangan : ");
  fflush(stdin);
  scanf("%d", &bil);

  pNew = (node *)malloc(sizeof(node));
  if (pNew != NULL){
  	  pNew->data = bil;

  	  if(*pList == NULL){
        *pList = pNew;
        pNew->next = *pList;
  	  } else {
          node *pWalker = *pList;
          while (pWalker->next != *pList){
            pWalker = pWalker->next;
          }
          pNew->next = *pList;
          pWalker->next = pNew;
          *pList = pNew;
   	  }
  }
  else{
      printf("Alokasi memori gagal");
      getch();
  }
}

//========================================================

void tambahData(node **pList){
  int pos, bil;
  node *pNew, *pCur;

  system("cls");
  tranverse(*pList);
  printf("\nposisi penyisipan setelah data bernilai : ");
  fflush(stdin);
  scanf("%d", &pos);
  printf("\nbilangan : ");
  fflush(stdin);
  scanf("%d", &bil);

  pCur = *pList;
  do {
    if (pCur->data == pos) break;
    pCur = pCur->next;
  } while (pCur != *pList);

  if (pCur->data != pos){
    printf("Node tidak ditemukan.\n");
    getch();
    return;
  }

  pNew = (node *)malloc(sizeof(node));
  if (pNew == NULL){
    printf("Alokasi memori gagal.\n");
    getch();
  }else{
     pNew->data = bil;
     pNew->next = pCur->next;
     pCur -> next = pNew;
  }
}

//========================================================
void tambahAkhir (node **pList){
  int pos, bil;
  node *pNew, *pCur;

  system("cls");
  fflush(stdin);
  printf("masukkan bilangan : ");
  fflush(stdin);
  scanf("%d", &bil);

  pNew = (struct node*)malloc(sizeof(struct node));
  if (pNew == NULL){
    printf("\nalokasi memori gagal");
    getch();
  }
  pNew->data = bil;
  pNew->next = NULL;

  if (*pList == NULL) {
    *pList = pNew;
    pNew->next = *pList;
  } else {
    pCur = *pList;
    while (pCur->next != *pList){
        pCur = pCur->next;
    }
    pCur->next = pNew;
    pNew->next = *pList;
  }
}

//========================================================

void hapusAwal(node **pList){
    system("cls");
    if (*pList == NULL){
    printf(" List kosong, tidak ada data yang dihapus.\n");
    getch();
    return;
  }

  node *pCur = *pList;

  if ((*pList)->next == *pList){
    free(pCur);
    *pList = NULL;
  }else {
      node *pWalker = *pList;

      while(pWalker->next != *pList){
            pWalker = pWalker->next;
            }
            pWalker->next = (*pList)->next;
            *pList = (*pList)->next;
            free(pCur);
  }
  printf("Data berhasil dihapus.\n");
  getch();
}
//========================================================

void hapusTengah(node **pList){
    system("cls");
    if (*pList == NULL){
    printf(" List kosong, tidak ada data yang dihapus.\n");
    getch();
  }

  int data;
  printf("Masukkan data yang ingin dihapus:\n");
  scanf("%d", &data);

  node *pCur = *pList;
  node *pPre = NULL;

   do {
        if (pCur->data == data) break;
        pPre = pCur;
        pCur = pCur->next;
    } while (pCur != *pList);

    if (pCur->data != data) {
        printf("Data tidak ditemukan.\n");
        getch();
        return;
    }

    if (pPre == NULL) {
        hapusAwal(pList);
    } else {
        pPre->next = pCur->next;
        free(pCur);
        printf("Data berhasil dihapus");
        getch();
    }
}
//========================================================

void hapusAkhir (node **pList){
    system("cls");
    if (*pList == NULL) {
        printf("List kosong, tidak ada data yang dihapus.\n");
        getch();
        return;
  }

  if ((*pList)->next == *pList){
    free(*pList);
    *pList = NULL;
  } else {
      node *pCur = *pList;
      node *pPre = NULL;
      while (pCur->next != *pList){
        pPre = pCur;
        pCur = pCur->next;
      }
      pPre->next = *pList;
      free(pCur);
  }
  printf("Data berhasil dihapus.\n");
  getch();
}

//========================================================


void tranverse(node *pList){
   //traverse a circular linked list

    system("cls");
	if (pList == NULL ){
        printf ("List kosong.\n");
        return;
	}

	node *pWalker = pList;
	do {
        printf("%d ", pWalker->data);
        pWalker = pWalker->next;
    } while (pWalker != pList);

    printf("\n");
    getch();
}

//========================================================

void cariData(node **pList){
    system("cls");
    int nilai;
       printf("Masukkan data yang dicari:");
       scanf("%d", &nilai);

       node *pCur = *pList;
       do {
        if (pCur->data == nilai) {
            printf("Data %d ditemukan dalam list.\n", pCur->data);
            getch();
            return;
        }
        pCur = pCur->next;
    } while (pCur != *pList);

    printf("Data tidak ditemukan dalam list.\n");
    getch();
}

//========================================================

void hitungData (node **pList) {
    system("cls");
    int jumlah = 0;
    node *pWalker = *pList;

    do {
        jumlah++;
        pWalker = pWalker->next;
    } while (pWalker != *pList);

    printf("Jumlah data dalam list: %d\n", jumlah);
    getch();
}
//========================================================

void penjumlahanData (node **pList){
   system("cls");
   int sum = 0;
   node *pWalker = *pList;

   do{
      sum += pWalker->data;
      pWalker = pWalker->next;
   }while (pWalker != *pList);

   printf("Hasil penjumlahan data dalam list: %d\n", sum);
   getch();
}

//========================================================

void insertNode(node **pList, node *pPre, node *pNew){
    if (pPre == NULL){
       if( *pList == NULL){
        //add before first logical node or to an empty list
        *pList = pNew;
        pNew->next = pNew;
       }
    }else {
       //add in the middle or at the end
       pNew -> next = pPre -> next;
       pPre -> next = pNew;
   }
}

//========================================================
