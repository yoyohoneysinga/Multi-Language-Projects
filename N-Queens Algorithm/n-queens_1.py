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

queens_placed = 0
while queens_placed < n:
    for i in range(n):
        board = [["0"] * n for _ in range(n)]
        board[0][i] = "Q"
        queens_placed = 1
        print(f"Testing first queen at (0, {i}):")
        for row in range(1, n):
            for col in range(n):
                if board[row][col] == "0":
                    board[row][col] = "Q"
                    print(f"Placing queen at ({row}, {col}):")
                    for row_display in board:
                        print(" ".join(row_display)) 
                    if is_valid(n, board):
                        queens_placed += 1
                        break
                    else:
                        board[row][col] = "0"
                        print(f"Backtracking from ({row}, {col}):")
                        for row_display in board:
                            print(" ".join(row_display))  
        
        if queens_placed == n:
            print("Solution found:")
            for row_display in board:
                print(" ".join(row_display))  
            break

print(np.array(board))



