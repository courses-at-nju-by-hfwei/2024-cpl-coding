// Created by hfwei on 2024/10/26.

#include <stdbool.h>
#include <stdio.h>

#define N 8 // Change N as needed

// Function to print the board configuration
void printBoard(int board[][N]) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      printf("%s ", board[i][j] ? "Q" : ".");
    }
    printf("\n");
  }
  printf("\n");
}

// Function to check if placing a queen at board[row][col] is safe
bool isSafe(int board[][N], int row, int col) {
  // Check column for conflicts
  for (int i = 0; i < row; i++) {
    if (board[i][col])
      return false;
  }

  // Check upper left diagonal
  for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
    if (board[i][j])
      return false;
  }

  // Check upper right diagonal
  for (int i = row, j = col; i >= 0 && j < N; i--, j++) {
    if (board[i][j])
      return false;
  }

  return true;
}

// Recursive function to solve N-Queens
bool solveNQueens(int board[][N], int row) {
  if (row >= N) {
    printBoard(board);
    return true;
  }

  bool res = false;
  for (int col = 0; col < N; col++) {
    if (isSafe(board, row, col)) {
      board[row][col] = 1;
      res = solveNQueens(board, row + 1) || res;
      board[row][col] = 0;
    }
  }

  return res;
}

int main() {
  int board[N][N] = {0};

  if (!solveNQueens(board, 0)) {
    printf("Solution does not exist for %d-Queens.\n", N);
  }

  return 0;
}