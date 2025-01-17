import numpy as np

n = int(input("Enter a number: "))

def horizontal_conflict(n: int, arr: list) -> bool:
    for i in range(n):
        count = 0
        for j in range(n):
            if arr[i][j] == "Q":
                count += 1
                if count > 1:
                    return True
    return False

def vertical_conflict(n: int, arr: list) -> bool:
    for i in range(n):
        count = 0
        for j in range(n):
            if arr[j][i] == "Q":
                count += 1
                if count > 1:
                    return True
    return False

def diagonal_conflict(n: int, arr: list) -> bool:
    main_diagonals = set()
    anti_diagonals = set()

    for i in range(n):
        for j in range(n):
            if arr[i][j] == "Q":
                if (i - j) in main_diagonals:
                    return True  
                main_diagonals.add(i - j)

                if (i + j) in anti_diagonals:
                    return True  
                anti_diagonals.add(i + j)
    
    return False 

def is_valid(n, board):
    return False if horizontal_conflict(n, board) or vertical_conflict(n, board) or diagonal_conflict(n, board) else True

def place_queen(n, board, row):
    if row == n:
        return True
    
    for col in range(n):
        board[row][col] = "Q"
        if is_valid(n, board):
            place_queen(n, board, row + 1)
            continue
        else:
            board[row][col] = "-"

    return False

board = [["-"] * n for _ in range(n)]
if place_queen(n, board, 0):
    for row in board:
        print(" ".join(row))
else:
    print("No solution found.")
