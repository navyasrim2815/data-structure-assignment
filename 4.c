#include <stdio.h>
#include <string.h>

#define MAX 5

char queue[MAX][50];
int front = -1, rear = -1;

void enqueue(char doc[]) {
    if (rear == MAX - 1) {
        printf("Queue is Full\n");
        return;
    }
    if (front == -1) front = 0;
    strcpy(queue[++rear], doc);
    printf("Document added to queue\n");
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("No documents to print\n");
        return;
    }
    printf("Printing: %s\n", queue[front++]);
}

void display() {
    if (front == -1 || front > rear) {
        printf("No pending documents\n");
        return;
    }
    printf("Pending documents:\n");
    for (int i = front; i <= rear; i++) {
        printf("%s\n", queue[i]);
    }
}

int main() {
    int choice;
    char doc[50];

    do {
        printf("\n1. Add Document\n2. Print Document\n3. Display Queue\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter document name: ");
                scanf("%s", doc);
                enqueue(doc);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
        }
    } while (choice != 4);

    return 0;
}