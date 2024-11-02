#include <stdio.h>
#include <stdlib.h>

#define MAX 6

//========================================================

struct stack {
    int top;
    int *data;
};
typedef struct stack stack;

void createStack(stack *s);
void push(stack *s, int value);
void pop(stack *s);
void stackTop(stack *s);
void isEmpty(stack *s);
void isFull(stack *s);
void stackCount(stack *s);
void destroyStack(stack *s);

//========================================================

int main() {
    stack s;
    char pilih;
    int value;

    createStack(&s);

    do {
        system("cls");
        printf("\nPilih Operasi:\n");
        printf("1. Push ke Stack\n");
        printf("2. Pop dari Stack\n");
        printf("3. Tampilkan Stack Top\n");
        printf("4. Cek apakah Stack kosong\n");
        printf("5. Cek apakah Stack penuh\n");
        printf("6. Hitung jumlah dalam Stack\n");
        printf("7. Hancurkan Stack\n");
        printf("Masukkan pilihan (tekan q untuk keluar): ");
        fflush(stdin);
        scanf(" %c", &pilih);

        if (pilih == 'q') {
            break;
        } else if (pilih == '1') {
            printf("Masukkan nilai yang ingin di-push: ");
            scanf("%d", &value);
            push(&s, value);
        } else if (pilih == '2') {
            pop(&s);
        } else if (pilih == '3') {
            stackTop(&s);
        } else if (pilih == '4') {
            isEmpty(&s);
        } else if (pilih == '5') {
            isFull(&s);
        } else if (pilih == '6') {
            stackCount(&s);
        } else if (pilih == '7') {
            destroyStack(&s);
        }

        printf("\nTekan enter ...");
        getchar();
        getchar();

    } while (1);

    destroyStack(&s);
    return 0;
}
//========================================================

void createStack(stack *s) {
    s->top = -1;
    s->data = (int *)malloc(sizeof(int) * MAX);
}

//========================================================

void push(stack *s, int value) {
    if (s->top == MAX - 1) {
        printf("Stack penuh. Tidak bisa push.\n");
    } else {
        s->data[++(s->top)] = value;
        printf("Nilai %d di-push ke stack.\n", value);
    }
}

//========================================================

void pop(stack *s) {
    if (s->top == -1) {
        printf("Stack kosong. Tidak ada elemen yang bisa di-pop.\n");
    } else {
        printf("Nilai %d telah di-pop dari stack.\n", s->data[s->top--]);
    }
}

//========================================================

void stackTop(stack *s) {
    if (s->top == -1) {
        printf("Stack kosong. Tidak ada elemen di top.\n");
    } else {
        printf("Top stack adalah: %d\n", s->data[s->top]);
    }
}

//========================================================

void isEmpty(stack *s) {
    if (s->top == -1) {
        printf("Stack kosong.\n");
    } else {
        printf("Stack tidak kosong.\n");
    }
}

//========================================================

void isFull(stack *s) {
    if (s->top == MAX - 1) {
        printf("Stack penuh.\n");
    } else {
        printf("Stack tidak penuh.\n");
    }
}

//========================================================

void stackCount(stack *s) {
    printf("Jumlah elemen dalam stack: %d\n", s->top + 1);
}

//========================================================

void destroyStack(stack *s) {
    free(s->data);
    s->top = -1;
    printf("Stack telah dihancurkan.\n");
}
