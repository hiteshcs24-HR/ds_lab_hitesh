#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// heads for two lists
struct Node *head1 = NULL;
struct Node *head2 = NULL;

// Create node
struct Node* createNode(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
void insertEnd(struct Node **head, int value) {
    struct Node *newNode = createNode(value);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Display list
void display(struct Node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("List: ");
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

/* ==============================
       SORT LINKED LIST
============================== */
void sortList(struct Node **head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *i, *j;
    int temp;

    for (i = *head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }

    printf("List sorted.\n");
}

/* ==============================
        REVERSE LINKED LIST
============================== */
void reverseList(struct Node **head) {
    struct Node *prev = NULL, *curr = *head, *next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    *head = prev;
    printf("List reversed.\n");
}

/* ==============================
      CONCATENATE TWO LISTS
============================== */
void concatenate() {
    if (head1 == NULL) {
        head1 = head2;
        printf("List concatenated (first list was empty).\n");
        return;
    }

    struct Node *temp = head1;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = head2;
    printf("Lists concatenated.\n");
}

/* ===============================
              MAIN MENU
=============================== */
int main() {
    int choice, value;

    while (1) {
        printf("\n---- MENU ----\n");
        printf("1. Insert into List 1\n");
        printf("2. Insert into List 2\n");
        printf("3. Display List 1\n");
        printf("4. Display List 2\n");
        printf("5. Sort List 1\n");
        printf("6. Reverse List 1\n");
        printf("7. Concatenate List 2 to List 1\n");
        printf("8. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertEnd(&head1, value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertEnd(&head2, value);
                break;

            case 3:
                display(head1);
                break;

            case 4:
                display(head2);
                break;

            case 5:
                sortList(&head1);
                break;

            case 6:
                reverseList(&head1);
                break;

            case 7:
                concatenate();
                break;

            case 8:
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
