#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 100
#define N 8

// Function prototypes
bool isSafe(int row, int col);
bool solveNQueens(int col);
void printBoard();
void subsetSum(int arr[], int n, int sum, int subset[], int subsetSize, int totalSum, int nodeCount);
void findSubsets(int arr[], int n, int sum);

int board[N][N];

int main() {
    int choice;

    do {
        printf("\nChoose an option:\n");
        printf("1. Solve N-Queens Problem\n");
        printf("2. Solve Subset Sum Problem\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                // Initialize the board
                for (int i = 0; i < N; i++)
                    for (int j = 0; j < N; j++)
                        board[i][j] = 0;

                if (solveNQueens(0) == false) {
                    printf("Solution does not exist\n");
                } else {
                    printf("N-Queens Solution:\n");
                    printBoard();
                }
                break;
            }
            case 2: {
                int arr[] = {10, 7, 5, 18, 12, 20, 15};
                int n = sizeof(arr) / sizeof(arr[0]);
                int sum = 35;

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
bool isSafe(int row, int col) {
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
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

bool solveNQueens(int col) {
    if (col >= N)
        return true;

    for (int i = 0; i < N; i++) {
        if (isSafe(i, col)) {
            board[i][col] = 1;

            if (solveNQueens(col + 1))
                return true;

            board[i][col] = 0; // BACKTRACK
        }
    }

    return false;
}

void printBoard() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
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
    int subset[MAX];
    subsetSum(arr, n, sum, subset, 0, 0, 0);
}