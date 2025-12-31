#include <stdio.h>

#define MAX 100

int hashTable[MAX];
int m;

// Function to insert key using Linear Probing
void insert(int key) {
    int index = key % m;

    // Linear probing on collision
    while (hashTable[index] != -1) {
        index = (index + 1) % m;
    }

    hashTable[index] = key;
}

// Function to display hash table
void display() {
    int i;
    printf("\nHash Table:\n");
    printf("Address\tKey\n");
    for (i = 0; i < m; i++) {
        if (hashTable[i] != -1)
            printf("%d\t%d\n", i, hashTable[i]);
        else
            printf("%d\t---\n", i);
    }
}

int main() {
    int n, key, i;

    printf("Enter size of hash table (m): ");
    scanf("%d", &m);

    // Initialize hash table
    for (i = 0; i < m; i++)
        hashTable[i] = -1;

    printf("Enter number of employee records: ");
    scanf("%d", &n);

    printf("Enter %d employee keys (4-digit):\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &key);
        insert(key);
    }

    display();
    return 0;
}
10