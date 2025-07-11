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
    if (newnode == NULL) return NULL;
    newnode->data = value;
    newnode->next = NULL;
    return newnode;
}

stack* createStack() {
    stack *newstack = (stack *)malloc(sizeof(stack));
    if (newstack == NULL) return NULL;
    newstack->head = NULL;
    return newstack;
}

void push(stack *newstack, int value) {
    node *newnode = createNode(value);
    if (newnode == NULL) {
        printf("Khong tao duoc node moi\n");
        return;
    }
    newnode->next = newstack->head;
    newstack->head = newnode;
}

void themPhanTuVao(stack *newstack) {
    int n, value;
    do {
        printf("Nhap so phan tu trong danh sach: ");
        scanf("%d", &n);
        if (n <= 0) {
            printf("So luong khong hop le. Nhap lai.\n");
        }
    } while (n <= 0);

    for (int i = 0; i < n; i++) {
        do {
            printf("Nhap phan tu thu %d: ", i + 1);
            scanf("%d", &value);
            if (value <= 0) {
                printf("Phan tu khong hop le. Nhap lai.\n");
            }
        } while (value <= 0);
        push(newstack, value);
    }
}

void printStack(stack *newstack) {
    if (newstack->head == NULL) {
        printf("Stack rong\n");
        return;
    }
    node *temp = newstack->head;
    printf("Cac phan tu trong stack: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int pop(stack *newstack) {
    if (newstack->head == NULL) {
        printf("Stack rong, khong the pop\n");
        return -1;
    }
    node *temp = newstack->head;
    int value = temp->data;
    newstack->head = temp->next;
    free(temp);
    return value;
}

int main(void) {
    stack *newstack = createStack();
    if (newstack == NULL) {
        printf("Tao stack that bai\n");
        return 1;
    }

    themPhanTuVao(newstack);
    printStack(newstack);

    int lay = pop(newstack);
    if (lay != -1) {
        printf("Phan tu vua lay ra: %d\n", lay);
        printStack(newstack);
    }

    return 0;
}
