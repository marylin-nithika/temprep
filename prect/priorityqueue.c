#include <stdio.h>

int data[20];
int priority[20];
int size = 0;

// Insert element with priority
void insert(int value, int p) {
    data[size] = value;
    priority[size] = p;
    size++;
}

// Delete highest priority element
void delete() {
    if (size == 0) {
        printf("Priority Queue is empty\n");
        return;
    }

    int highest = 0;
    for (int i = 1; i < size; i++) {
        if (priority[i] < priority[highest]) {
            highest = i;
        }
    }

    printf("Deleted element: %d\n", data[highest]);

    // Shift elements
    for (int i = highest; i < size - 1; i++) {
        data[i] = data[i + 1];
        priority[i] = priority[i + 1];
    }

    size--;
}

// Display queue
void display() {
    if (size == 0) {
        printf("Priority Queue is empty\n");
        return;
    }

    printf("Element : Priority\n");
    for (int i = 0; i < size; i++) {
        printf("%d : %d\n", data[i], priority[i]);
    }
}

int main() {
    insert(10, 2);
    insert(20, 1);
    insert(30, 3);

    display();
    delete();
    display();

    return 0;
}
