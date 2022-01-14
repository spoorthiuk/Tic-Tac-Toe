#This is the first test code of the famous Tic_Tac_Toe game. It's human vs human version player1 by default
#starts the game and player1 is assigned 'X' coin and player2 is assigned 'O' coin. The game can result in either of the
#players winning or in a draw.

#The following function changes the colour of the text to red
def red():
    s = "\033[1;31m"
    return s
#The following function changes the colour of the text to black
def reset():
    s = "\033[0m"
    return s

#The following function prints the rules of the game and the grid with position description
def rules(m, n):
    print("Player1: X and Player2: O\n"
          "Player1 will start first and each player will take turns in filling the grid\n"
          "The game will end when either of the Players wins or when the game results in a tie\n"
          "Players will have to enter the location in the grid where they would like to insert their coin\n"
          "The grid positioning is as follows:\n")
    for i in range(0, m):
        for j in range(0, n):
            print(i+1, j+1, end='')
            if (j != n-1):
                print("|", end='')
        if (i != m-1):
            print("\n------------\n", end='')
    print("\n\n", end='')

#The following code is for printing the grid every time a coin is inserted.
def print_grid(A, m, n):
    print("\n", end='')
    for i in range(0, m):
        for j in range(0, n):
            if (A[i][j] == 1):
                print(" X ", end='')
            elif (A[i][j] == 2):
                print(" O ", end='')
            else:
                print("   ", end='')
            if(j != n-1):
                print("|", end='')
        if(i != m-1):
            print("\n------------\n", end='')

#following function is to print the gird when either of the player wins. It changes the colour of the winning combination.
def print_win_case(A, m1, n1, m2, n2, m3, n3):
    print("\n")
    for i in range(0, 3):
        for j in range(0, 3):
            if(((i==m1) and (j==n1)) or ((i==m2) and (j==n2)) or ((i==m3) and (j==n3))):
                if (A[i][j] == 1):
                    print(red() + " X " + reset(), end='')
                elif (A[i][j] == 2):
                    print(red() + " O " + reset(), end='')
            else:
                if (A[i][j] == 1):
                    print(" X ", end='')
                elif (A[i][j] == 2):
                    print(" O ", end='')
                else:
                    print("   ", end='')
            if (j != 2):
                print("|", end='')
        if(i != 2):
            print("\n----------\n", end='')

#This function check if there's any winning combination in the grid.
def check_result(A):
    for i in range(0, 3):
        if (A[i][0] == A[i][1] and A[i][1] == A[i][2] and A[i][0] != 0):
            print_win_case(A, i, 0, i, 1, i, 2)
            return A[i][0]
        if (A[0][i] == A[1][i] and A[1][i] == A[2][i] and A[i][0] != 0):
            print_win_case(A, 0, i, 1, i, 2, i)
            return A[0][i]
    if (A[0][0] == A[1][1] and A[1][1] == A[2][2] and A[0][0] != 0):
        print_win_case(A, 0, 0, 1, 1, 2, 2)
        return A[0][0]
    if (A[2][0] == A[1][1] and A[1][1] == A[0][2] and A[2][0] != 0):
        print_win_case(A, 2, 0, 1, 1, 0, 2)
        return A[2][0]
    return 0

#main function call
m=3
n=3
turns=0
rounds=1
win=0
rules(m, n)
Grid = [[0, 0, 0],
        [0, 0, 0],
        [0, 0, 0]]

while True:
    print("\nRound:", rounds, "\n")
    p1_m, p1_n=[int(x) for x in input("Player1's turn:").split(",")]
    while (Grid[p1_m - 1][p1_n - 1] != 0):
        print("ERROR: Already occupied insert again\n")
        p1_m, p1_n = [int(x) for x in input("Player1's turn:").split(",")]
    while (p1_m > 3 or p1_n > 3):
        print("ERROR: Invalid position insert again\n")
        p1_m, p1_n = [int(x) for x in input("Player1's turn:").split(",")]
    print("Player1 inserted X in position:[", p1_m,",", p1_n,"]")
    Grid[p1_m - 1][p1_n - 1] = 1
    print_grid(Grid, m, n)
    turns = turns + 1
    win = check_result(Grid)
    if (win == 1):
        print("\nCONGRATULATIONS!!\nPlayer1 wins")
        break
    if (turns == 9):
        print("\nGame Resulted in a Tie")
        break
    print("\n", end='')
    p2_m, p2_n = [int(x) for x in input("Player2's turn:").split(",")]
    while (Grid[p2_m - 1][p2_n - 1] != 0):
        print("ERROR: Already occupied insert again\n")
        p2_m, p2_n = [int(x) for x in input("Player2's turn:").split(",")]
    while (p2_m > 3 or p2_n > 3):
        print("ERROR: Invalid position insert again\n")
        p2_m, p2_n = [int(x) for x in input("Player2's turn:").split(",")]
    print("Player2 inserted O in position:[", p2_m,",", p2_n,"]")
    Grid[p2_m - 1][p2_n - 1] = 2
    turns = turns + 1
    rounds = rounds + 1
    print_grid(Grid, m, n)
    win = check_result(Grid)
    if (win == 2):
        print("CONGRATULATIONS!!\nPlayer2 wins")
        break
if (win == 0):
    print_grid(Grid, m, n)

