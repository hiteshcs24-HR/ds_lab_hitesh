#include <stdio.h>
#define MAX 5   // Maximum size of the queue

int queue[MAX];
int front = -1, rear = -1;

// Function to insert an element into the queue
void insert() {
    int item;
    if (rear == MAX - 1) {
        printf("\nQueue Overflow! Cannot insert more elements.\n");
    } else {
        printf("Enter element to insert: ");
        scanf("%d", &item);
        if (front == -1)  // First element insertion
            front = 0;
        rear++;
        queue[rear] = item;
        printf("%d inserted into the queue.\n", item);
    }
}

// Function to delete an element from the queue
void delete() {
    if (front == -1 || front > rear) {
        printf("\nQueue Underflow! No elements to delete.\n");
    } else {
        printf("Deleted element: %d\n", queue[front]);
        front++;
        if (front > rear) {
            // Reset queue after last deletion
            front = rear = -1;
        }
    }
}

// Function to display the elements in the queue
void display() {
    if (front == -1) {
        printf("\nQueue is Empty.\n");
    } else {
        printf("\nQueue elements are: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    int choice;
    printf("QUEUE IMPLEMENTATION USING ARRAY\n");
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
