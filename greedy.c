#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_N 100
#define MAX_ARR 100

// N-Queens problem functions
bool isSafe(int board[MAX_N][MAX_N], int row, int col, int n);
bool solveNQueens(int board[MAX_N][MAX_N], int col, int n);
void printBoard(int board[MAX_N][MAX_N], int n);

// Subset Sum problem functions
void subsetSum(int arr[], int n, int sum, int subset[], int subsetSize, int totalSum, int nodeCount);
void findSubsets(int arr[], int n, int sum);

int main() {
    int choice, n;

    do {
        printf("\nChoose an option:\n");
        printf("1. Solve N-Queens Problem\n");
        printf("2. Solve Subset Sum Problem\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                printf("Enter the value of n for N-Queens problem: ");
                scanf("%d", &n);

                int board[MAX_N][MAX_N] = {{0}};

                if (solveNQueens(board, 0, n) == false) {
                    printf("Solution does not exist\n");
                } else {
                    printf("N-Queens Solution:\n");
                    printBoard(board, n);
                }
                break;
            }
            case 2: {
                int n, sum;
                printf("Enter the size of the array: ");
                scanf("%d", &n);

                int arr[MAX_ARR];
                printf("Enter the elements of the array:\n");
                for (int i = 0; i < n; i++) {
                    scanf("%d", &arr[i]);
                }

                printf("Enter the desired sum: ");
                scanf("%d", &sum);

                printf("Subset Sum Solution:\n");
                findSubsets(arr, n, sum);
                break;
            }
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please enter again.\n");
        }
    } while (choice != 3);

    return 0;
}

// N-Queens problem functions
bool isSafe(int board[MAX_N][MAX_N], int row, int col, int n) {
    int i, j;

    // Check the left side of this row
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    // Check upper diagonal on left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // Check lower diagonal on left side
    for (i = row, j = col; j >= 0 && i < n; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

bool solveNQueens(int board[MAX_N][MAX_N], int col, int n) {
    if (col >= n)
        return true;

    for (int i = 0; i < n; i++) {
        if (isSafe(board, i, col, n)) {
            board[i][col] = 1;

            if (solveNQueens(board, col + 1, n))
                return true;

            board[i][col] = 0; // BACKTRACK
        }
    }

    return false;
}

void printBoard(int board[MAX_N][MAX_N], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", board[i][j]);
        printf("\n");
    }
}

// Subset Sum problem functions
void subsetSum(int arr[], int n, int sum, int subset[], int subsetSize, int totalSum, int nodeCount) {
    if (totalSum == sum) {
        printf("Subset found: ");
        for (int i = 0; i < subsetSize; i++)
            printf("%d ", subset[i]);
        printf("\n");

        subsetSum(arr, n, sum, subset, subsetSize - 1, totalSum - arr[nodeCount], nodeCount + 1);
        return;
    } else {
        for (int i = nodeCount; i < n; i++) {
            subset[subsetSize] = arr[i];
            subsetSum(arr, n, sum, subset, subsetSize + 1, totalSum + arr[i], i + 1);
        }
    }
}

void findSubsets(int arr[], int n, int sum) {
    int subset[MAX_ARR];
    subsetSum(arr, n, sum, subset, 0, 0, 0);
}