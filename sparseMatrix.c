#include <stdio.h>
#define MAX 100

void display(int sparse[MAX][3]) {
    printf("\nRow\tColumn\tValue\n");
    for (int i = 1; i <= sparse[0][2]; i++) {
        printf("%d\t%d\t%d\n", sparse[i][0], sparse[i][1], sparse[i][2]);
    }
}

void add(int sparse1[MAX][3], int sparse2[MAX][3], int result[MAX][3]) {
    if (sparse1[0][0] != sparse2[0][0] || sparse1[0][1] != sparse2[0][1]) {
        printf("Matrices can't be added.\n");
        return;
    }

    int i = 1, j = 1, k = 1;
    result[0][0] = sparse1[0][0];
    result[0][1] = sparse1[0][1];

    while (i <= sparse1[0][2] && j <= sparse2[0][2]) {
        if (sparse1[i][0] < sparse2[j][0] || 
           (sparse1[i][0] == sparse2[j][0] && sparse1[i][1] < sparse2[j][1])) {
            result[k][0] = sparse1[i][0];
            result[k][1] = sparse1[i][1];
            result[k][2] = sparse1[i][2];
            i++; k++;
        } else if (sparse1[i][0] > sparse2[j][0] || 
                  (sparse1[i][0] == sparse2[j][0] && sparse1[i][1] > sparse2[j][1])) {
            result[k][0] = sparse2[j][0];
            result[k][1] = sparse2[j][1];
            result[k][2] = sparse2[j][2];
            j++; k++;
        } else {
            result[k][0] = sparse1[i][0];
            result[k][1] = sparse1[i][1];
            result[k][2] = sparse1[i][2] + sparse2[j][2];
            i++; j++; k++;
        }
    }

    while (i <= sparse1[0][2]) {
        result[k][0] = sparse1[i][0];
        result[k][1] = sparse1[i][1];
        result[k][2] = sparse1[i][2];
        i++; k++;
    }

    while (j <= sparse2[0][2]) {
        result[k][0] = sparse2[j][0];
        result[k][1] = sparse2[j][1];
        result[k][2] = sparse2[j][2];
        j++; k++;
    }

    result[0][2] = k - 1;

    display(result);
}

void transpose(int sparse[MAX][3], int result[MAX][3]) {
    result[0][0] = sparse[0][1];
    result[0][1] = sparse[0][0];
    result[0][2] = sparse[0][2];

    int k = 1;
    for (int i = 0; i < sparse[0][1]; i++) {
        for (int j = 1; j <= sparse[0][2]; j++) {
            if (sparse[j][1] == i) {
                result[k][0] = sparse[j][1];
                result[k][1] = sparse[j][0];
                result[k][2] = sparse[j][2];
                k++;
            }
        }
    }

    display(result);
}

void main() {
    int sparse1[MAX][3], sparse2[MAX][3], result[MAX][3];
    int choice = 0;

    printf("Enter the rows cols and number of elements in first matrix:\n");
    scanf("%d %d %d", &sparse1[0][0], &sparse1[0][1], &sparse1[0][2]);

    printf("Enter the rows cols and number of elements in second matrix:\n");
    scanf("%d %d %d", &sparse2[0][0], &sparse2[0][1], &sparse2[0][2]);

    printf("\nMATRIX A\n");
    for (int i = 1; i <= sparse1[0][2]; i++) {
        printf("Enter the tuples : ");
        scanf("%d %d %d", &sparse1[i][0], &sparse1[i][1], &sparse1[i][2]);
    }

    printf("\nMATRIX B\n");
    for (int i = 1; i <= sparse2[0][2]; i++) {
        printf("Enter the tuples: ");
        scanf("%d %d %d", &sparse2[i][0], &sparse2[i][1], &sparse2[i][2]);
    }

    while (choice != 4) {
        printf("\nEnter your choice\n1. Display\n2. Addition\n3. Transpose\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nMATRIX A:\n");
                display(sparse1);
                printf("\nMATRIX B:\n");
                display(sparse2);
                break;
            case 2:
                add(sparse1, sparse2, result);
                break;
            case 3:
                transpose(sparse1, result);
                break;
            case 4:
                printf("Exited\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    }
}
