using System;

namespace n_queens
{

public class n_queens {

    static bool is_valid_position(int row, int col, char[][] board, int n) {

        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }

        for (int i = 1; i <= row; i++) {
            if (col - i >= 0 && board[row - i][col - i] == 'Q') {
                return false;
            }
        }

        for (int i = 1; i <= row; i++) {
            if (col + i < n && board[row - i][col + i] == 'Q') {
                return false;
            }
        }

        return true;
    }

    static bool place_queen(int n, char[][] board, int row) {
        if (row == n) {
            return true; 
        }

        for (int col = 0; col < n; col++) {
            if (is_valid_position(row, col, board, n)) {
                board[row][col] = 'Q';
                if (place_queen(n, board, row + 1)) {
                    return true;
                } else {
                    board[row][col] = '-';
                }
            }
        }

        return false;
    }

    static void printBoard(char[][] board) {
        for (int i = 0; i < board.Length; i++) {
            for (int j = 0; j < board[i].Length; j++) {
                Console.Write(board[i][j] + " ");
            }
            Console.WriteLine();
        }
    }

    static void Main(string[] args) {
        Console.WriteLine("Enter a number (n):");
        int n = int.Parse(Console.ReadLine());

        if (n < 1) {
            Console.WriteLine("No solution found.");
            return;
        }

        char[][] board = new char[n][];
        for (int i = 0; i < n; i++) {
            board[i] = new char[n];
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                board[i][j] = '-';
            }
        }

        if (place_queen(n, board, 0)) {
            printBoard(board);
        } else {
            Console.WriteLine("No solution found.");
        }
    }

}

}