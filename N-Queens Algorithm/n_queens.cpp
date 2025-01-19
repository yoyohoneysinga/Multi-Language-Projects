#include <iostream>
using namespace std;

bool is_valid_position(int row, int col, int n, char **board)
{
    for (int i = 0; i < row; i++)
    {
        if (board[i][col] == 'Q')
        {
            return false;
        }
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
    }
    for (int i = row, j = col; i >= 0 && j < n; i--, j++)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
    }
    return true;
}

bool place_queen(int n, char **board, int row)
{
    if (row == n)
    {
        return true;
    }

    for (int col = 0; col < n; col++)
    {
        if (is_valid_position(row, col, n, board))
        {
            board[row][col] = 'Q';
            if (place_queen(n, board, row + 1))
            {
                return true;
            }
            else
            {
                board[row][col] = '-';
            }
        }
    }

    return false;
}

void printBoard(char **board, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cout << "Enter a number (n):" << endl;
    cin >> n;

    if (n < 1)
    {
        cout << "No solution found." << endl;
        return 0;
    }

    char **board = new char *[n];
    for (int i = 0; i < n; i++)
    {
        board[i] = new char[n];
        for (int j = 0; j < n; j++)
        {
            board[i][j] = '-';
        }
    }

    if (place_queen(n, board, 0))
    {
        printBoard(board, n);
    }
    else
    {
        cout << "No solution found." << endl;
    }

    for (int i = 0; i < n; i++)
    {
        delete[] board[i];
    }
    delete[] board;

    return 0;
}
