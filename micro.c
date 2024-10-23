#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
int arr[5];
// Function for linear search
void linearSearch() {
    int  i, m;
    printf("\n================= Linear Search =================\n");
    printf("Enter 5 array elements:\n");
    for (i = 0; i < 5; i++) {
        printf("Element %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    printf("\nEnter search key: ");
    scanf("%d", &m);
    
    for (i = 0; i < 5; i++) {
        if (arr[i] == m) {
            printf("\nElement found successfully at position a[%d]=%d\n", i, m);
            return;
        }
    }
    printf("\nElement not found.\n");
}

// Function for binary search
void binarySearch() {
    int  key, i;
    int high = 4, low = 0, mid;
    printf("\n================= Binary Search =================\n");
    printf("Enter 5 organized array elements:\n");
    for (i = 0; i < 5; i++) {
        printf("Element %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    printf("\nEnter search key: ");
    scanf("%d", &key);

    while (low <= high) {
        mid = (high + low) / 2;
        if (key == arr[mid]) {
            printf("\nKey found at position a[%d]\n", mid);
            return;
        } else if (key > arr[mid]) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    printf("\nKey not found.\n");
}

// Function for pointer-based array search
void pointerSearch() {
    int n=5, i, search, *ptr, found = 0;
    printf("\n============= Pointer-based Array Search =============\n");
    printf("Enter %d elements of the array:\n", n);
    for (i = 0; i < n; i++) {
        printf("Element %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    printf("\nEnter the element to search: ");
    scanf("%d", &search);

    ptr = arr;
    for (i = 0; i < n; i++) {
        if (*(ptr + i) == search) {
            printf("\nElement %d found at position %d.\n", search, i + 1);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("\nElement %d not found in the array.\n", search);
    }
}

// Function for linked list search
void linkedListSearch() {
    struct Node* head = NULL;
    int n, data, key;
    
    printf("\n=============== Linked List Search ===============\n");
    printf("Enter the total number of elements to insert: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter data for node %d: ", i+1);
        scanf("%d", &data);
        newNode->data = data;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            struct Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    printf("\nEnter data to search: ");
    scanf("%d", &key);

    struct Node* temp = head;
    int index = 0;
    while (temp != NULL) {
        if (temp->data == key) {
            printf("\nElement found at index %d in the linked list.\n", index);
            return;
        }
        temp = temp->next;
        index++;
    }
    printf("\nElement not found in the linked list.\n");
}

int main() {
    int choice;

    while (1) {
        // Display the menu with enhanced formatting
        printf("\n==================== Search Menu ====================\n");
        printf("|1. Linear Search|\n");
        printf("|2. Binary Search|\n");
        printf("|3. Pointer-based Array Search|\n");
        printf("|4. Linked List Search|\n");
        printf("|5. Exit|\n");
        printf("======================================================\n");
        printf("|Enter your choice: ");
        scanf("%d", &choice);
        
        // Switch case to handle user choice
        switch (choice) {
            case 1:
                linearSearch();
                break;
            case 2:
                binarySearch();
                break;
            case 3:
                pointerSearch();
                break;
            case 4:
                linkedListSearch();
                break;
            case 5:
                printf("\nExiting the program. Goodbye!\n");
                exit(0); // Exit the program
            default:
                printf("\nInvalid choice! Please select a valid option.\n");
                break;
        }
        printf("======================================================\n");
    }

    return 0;
}