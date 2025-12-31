#include <stdio.h>
#define MAX 5  // Maximum size of the queue

int queue[MAX];
int front = -1, rear = -1;

// Function to insert an element into the circular queue
void insert() {
    int item;
    if ((front == 0 && rear == MAX - 1) || (rear + 1) % MAX == front) {
        printf("\nQueue Overflow! Cannot insert more elements.\n");
        return;
    }

    printf("Enter element to insert: ");
    scanf("%d", &item);

    if (front == -1) { // First element insertion
        front = 0;
        rear = 0;
    } else {
        rear = (rear + 1) % MAX; // Circular increment
    }

    queue[rear] = item;
    printf("%d inserted into the circular queue.\n", item);
}

// Function to delete an element from the circular queue
void delete() {
    if (front == -1) {
        printf("\nQueue Underflow! No elements to delete.\n");
        return;
    }

    printf("Deleted element: %d\n", queue[front]);

    if (front == rear) {
        // Queue becomes empty after deletion
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % MAX; // Circular increment
    }
}

// Function to display elements of the circular queue
void display() {
    if (front == -1) {
        printf("\nQueue is Empty.\n");
        return;
    }

    printf("\nCircular Queue elements are: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX; // Circular increment
    }
    printf("\n");
}

// Main function
int main() {
    int choice;
    printf("CIRCULAR QUEUE IMPLEMENTATION USING ARRAY\n");

    do {
        printf("\n----- MENU -----\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert(); break;
            case 2: delete(); break;
            case 3: display(); break;
            case 4: printf("Exiting program...\n"); break;
            default: printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
