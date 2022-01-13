#include <stdio.h>

#include <stdlib.h>

/*
This is the first test code of the famous Tic_Tac_Toe game. It's human vs human version player1 by default
starts the game and player1 is assigned 'X' coin and player2 is assigned 'O' coin. The game can result in either of the
players winning or in a draw.
*/

//The following function changes the colour of the text to red
void red() {
  printf("\033[1;31m");
}

//The following function resets the colour of the text back to black
void reset() {
  printf("\033[0m");
}

//The following function prints the rules of the game and the grid with position description
void rules(int m, int n) {
  printf("Player1: X and Player2: O\nPlayer1 will start first and each player will take turns in filling the grid\nThe game will end when either of the Players wins or when the game results in a tie\nPlayers will have to enter the location in the grid where they would like to insert their coin\nThe grid positioning is as follows:\n\n");
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      printf(" [%d,%d] ", i + 1, j + 1);
      if (j != n - 1) {
        printf("|");
      }
    }
    if (i != m - 1) {
      printf("\n------------------------\n");
    }
  }
  printf("\n\n");
}

//The following code is for printing the grid every time a coin is inserted.
void print_grid(int A[3][3], int m, int n) {
  printf("\n");
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (A[i][j] == 1) {
        printf(" X ");
      } else if (A[i][j] == 2) {
        printf(" O ");
      } else {
        printf("   ");
      }
      if (j != n - 1) {
        printf("|");
      }
    }
    if (i != m - 1) {
      printf("\n----------\n");
    }
  }
}

//following function is to print the gird when either of the player wins. It changes the colour of the winning combination.
void print_win_case(int A[3][3], int m1, int n1, int m2, int n2, int m3, int n3) {
  printf("\n");
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if ((i == m1 && j == n1) || (i == m2 && j == n2) ||
        (i == m3 && j == n3)) {
        red();
        if (A[i][j] == 1) {
          printf(" X ");
        } else if (A[i][j] == 2) {
          printf(" O ");
        }
        reset();
      } else {
        if (A[i][j] == 1) {
          printf(" X ");
        } else if (A[i][j] == 2) {
          printf(" O ");
        } else {
          printf("   ");
        }

      }
      if (j != 2) {
        printf("|");
      }

    }
    if (i != 2) {
      printf("\n----------\n");
    }
  }
}

//This function check if there's any winning combination in the grid.
int check_result(int A[3][3]) {
  for (int i = 0; i < 3; i++) {
    if (A[i][0] == A[i][1] && A[i][1] == A[i][2] && A[i][0] != 0) {
      print_win_case(A, i, 0, i, 1, i, 2);
      return A[i][0];
    }
    if (A[0][i] == A[1][i] && A[1][i] == A[2][i] && A[i][0] != 0) {
      print_win_case(A, 0, i, 1, i, 2, i);
      return A[0][i];
    }
  }

  if (A[0][0] == A[1][1] && A[1][1] == A[2][2] && A[0][0] != 0) {
    print_win_case(A, 0, 0, 1, 1, 2, 2);
    return A[0][0];
  }
  if (A[2][0] == A[1][1] && A[1][1] == A[0][2] && A[2][0] != 0) {
    print_win_case(A, 2, 0, 1, 1, 0, 2);
    return A[2][0];
  }
  return 0;
}

int main() {
  int Grid[3][3];
  int m = 3, n = 3;
  int turns = 0;
  int rounds = 1;
  int win = 0;
  int p1_m, p1_n, p2_m, p2_n;
  rules(m, n);
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      Grid[i][j] = 0;
    }
  }

  while (1) {
    printf("\nRound:%d\n", rounds);
    printf("Player1's turn:");
    scanf("%d,%d", & p1_m, & p1_n);
    while (Grid[p1_m - 1][p1_n - 1] != 0) {
      printf("ERROR: Already occupied insert again\n");
      scanf("%d,%d", & p1_m, & p1_n);
    }
    while (p1_m > 3 || p1_n > 3) {
      printf("ERROR: Invalid position insert again\n");
      scanf("%d,%d", & p1_m, & p1_n);
    }
    printf("Player1 inserted X in position:[%d,%d]", p1_m, p1_n);
    Grid[p1_m - 1][p1_n - 1] = 1;
    print_grid(Grid, m, n);
    turns = turns + 1;
    win = check_result(Grid);
    if (win == 1) {
      printf("\nCONGRATULATIONS!!\nPlayer1 wins");
      break;
    }
    if (turns == 9) {
      printf("\nGame Resulted in a Tie");
      break;
    }

    printf("\n\nPlayer2's turn:");
    scanf("%d,%d", & p2_m, & p2_n);
    printf("Player2 inserted X in position:[%d,%d]", p2_m, p2_n);
    while (Grid[p2_m - 1][p2_n - 1] != 0) {
      printf("ERROR: Already occupied insert again\n");
      scanf("%d,%d", & p2_m, & p2_n);
    }
    while (p2_m > 3 || p2_n > 3) {
      printf("ERROR: Invalid position insert again\n");
      scanf("%d,%d", & p2_m, & p2_n);
    }
    Grid[p2_m - 1][p2_n - 1] = 2;
    turns = turns + 1;
    rounds = rounds + 1;
    print_grid(Grid, m, n);
    win = check_result(Grid);
    if (win == 2) {
      printf("CONGRATULATIONS!!\nPlayer2 wins");
      break;
    }
  }
  if (win == 0) {
    print_grid(Grid, m, n);
  }
  return 0;
}
