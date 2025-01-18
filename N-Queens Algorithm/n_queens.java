import java.util.Scanner;

public class n_queens {

    public static boolean is_valid_position(int row, int col, String board[][], int n) {

        for (int i = 0; i < row; i++) {
            if (board[i][col].equals("Q")) {
                return false;
            }
        }

        for (int i = 1; i <= row; i++) {
            if (col - i >= 0 && board[row - i][col - i].equals("Q")) {
                return false;
            }
        }

        for (int i = 1; i <= row; i++) {
            if (col + i < n && board[row - i][col + i].equals("Q")) {
                return false;
            }
        }

        return true;
    }

    public static boolean place_queen(int n, String board[][], int row) {
        if (row == n) {
            return true; 
        }

        for (int col = 0; col < n; col++) {
            if (is_valid_position(row, col, board, n)) {
                board[row][col] = "Q";
                if (place_queen(n, board, row + 1)) {
                    return true;
                } else {
                    board[row][col] = "-";
                }
            }
        }

        return false;
    }

    public static void printBoard(String[][] board) {
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[i].length; j++) {
                System.out.print(board[i][j] + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        Scanner myObj = new Scanner(System.in);
        System.out.println("Enter a number (n):");
        int n = myObj.nextInt();
        myObj.close();

        if (n < 1) {
            System.out.println("No solution found.");
            return;
        }

        String[][] board = new String[n][n];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                board[i][j] = "-";
            }
        }

        if (place_queen(n, board, 0)) {
            printBoard(board);
        } else {
            System.out.println("No solution found.");
        }
    }

}
