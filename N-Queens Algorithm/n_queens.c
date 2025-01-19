#include <stdio.h>

int is_valid_position(int row, int col, int n, char board[n][n])
{
    for (int i = 0; i < row; i++)
    {
        if (board[i][col] == 'Q')
        {
            return 0;
        }
    }

    for (int i = 1; i <= row; i++)
    {
        if (col - i >= 0 && board[row - i][col - i] == 'Q')
        {
            return 0;
        }
    }

    for (int i = 1; i <= row; i++)
    {
        if (col + i < n && board[row - i][col + i] == 'Q')
        {
            return 0;
        }
    }

    return 1;
}

int place_queen(int n, char board[][n], int row)
{
    if (row == n)
    {
        return 1;
    }

    for (int col = 0; col < n; col++)
    {
        if (is_valid_position(row, col, n, board))
        {
            board[row][col] = 'Q';
            if (place_queen(n, board, row + 1))
            {
                return 1;
            }
            else
            {
                board[row][col] = '-';
            }
        }
    }

    return 0;
}

void printBoard(int n, char board[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int n;
    printf("Type a number and press enter: \n");
    scanf("%d", &n);

    char board[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            board[i][j] = '-';
        }
    }

    if (place_queen(n, board, 0))
    {
        printBoard(n, board);
    }
    else
    {
        printf("No solution found.\n");
    }

    return 0;
}
