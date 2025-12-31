#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

// Create new node
struct Node* createNode(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// a) Create DLL by inserting at end
void createDLL(int value) {
    struct Node *newNode = createNode(value);

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

// b) Insert to the LEFT of a node with given key
void insertLeft(int key, int val) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node *temp = head;
    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL) {
        printf("Key %d not found!\n", key);
        return;
    }

    struct Node *newNode = createNode(val);

    // If inserting before head
    if (temp == head) {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    } else {
        newNode->next = temp;
        newNode->prev = temp->prev;
        temp->prev->next = newNode;
        temp->prev = newNode;
    }
}

// c) Delete node by value
void deleteByValue(int key) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node *temp = head;

    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL) {
        printf("Value %d not found!\n", key);
        return;
    }

    // Only one node
    if (temp == head && temp->next == NULL) {
        head = NULL;
    }
    // Delete head
    else if (temp == head) {
        head = head->next;
        head->prev = NULL;
    }
    // Delete last node
    else if (temp->next == NULL) {
        temp->prev->next = NULL;
    }
    // Delete middle node
    else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }

    free(temp);
    printf("Node with value %d deleted.\n", key);
}

// d) Display DLL
void display() {
    struct Node *temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("DLL: ");
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) printf(" <-> ");
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int ch, val, key;

    while (1) {
        printf("\n1. Create Node (Insert at end)");
        printf("\n2. Insert to the LEFT of a node");
        printf("\n3. Delete by value");
        printf("\n4. Display");
        printf("\n5. Exit\n");
        printf("Enter choice: ");
        if (scanf("%d", &ch) != 1) {
            printf("Invalid input!\n");
            exit(0);
        }

        switch (ch) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                createDLL(val);
                break;

            case 2:
                printf("Enter new value: ");
                scanf("%d", &val);
                printf("Insert to the left of value: ");
                scanf("%d", &key);
                insertLeft(key, val);
                break;

            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &key);
                deleteByValue(key);
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}
