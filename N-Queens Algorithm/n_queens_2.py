n = int(input("Enter a number: "))


def is_valid_position(row, col, board, n):
    for i in range(row):
        if board[i][col] == "Q":
            return False

    for i in range(1, row + 1):
        if col - i >= 0 and board[row - i][col - i] == "Q":
            return False
        if col + i < n and board[row - i][col + i] == "Q":
            return False

    return True


def place_queen(n, board, row):
    if row == n:
        return True

    for col in range(n):
        if is_valid_position(row, col, board, n):
            board[row][col] = "Q"
            if place_queen(n, board, row + 1):
                return True
            else:
                board[row][col] = "-"

    return False


board = [["-"] * n for _ in range(n)]
if place_queen(n, board, 0):
    for row in board:
        print(" ".join(row))
else:
    print("No solution found.")
