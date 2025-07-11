#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

typedef struct stack {
    node *head;
} stack;

node* createNode(int value) {
    node *newnode = (node *)malloc(sizeof(node));
    if (newnode == NULL) {
        printf("Khong cap phat duoc node\n");
        return NULL;
    }
    newnode->data = value;
    newnode->next = NULL;
    return newnode;
}

stack* createStack() {
    stack *newstack = (stack *)malloc(sizeof(stack));
    if (newstack == NULL) {
        printf("Khong cap phat duoc stack\n");
        return NULL;
    }
    newstack->head = NULL;
    return newstack;
}

void push(stack *newstack, int value) {
    node *newnode = createNode(value);
    if (newnode == NULL) return;

    newnode->next = newstack->head;
    newstack->head = newnode;
}

void printList(stack *newstack) {
    node *current = newstack->head;
    printf("Stack hien tai: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void themPhanTuVaoStack(stack *newstack) {
    int n, value;
    printf("Nhap so luong phan tu muon them: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("So luong khong hop le\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        do {
            printf("Nhap phan tu thu %d: ", i + 1);
            scanf("%d", &value);
            if (value <= 0) {
                printf("Gia tri khong hop le, vui long nhap lai.\n");
            }
        } while (value <= 0);
        push(newstack, value);
    }
}

int main(void) {
    stack *newstack = createStack();
    if (newstack == NULL) {
        printf("Tao ngan xep khong thanh cong\n");
        return 1;
    }

    themPhanTuVaoStack(newstack);
    printList(newstack);

    return 0;
}
