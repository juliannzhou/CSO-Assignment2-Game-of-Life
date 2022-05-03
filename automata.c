#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int* game_of_life(int board[5][5]) {
    int m = 5;
    int n = 5;
    int moves[8][2] = {{-1, 1},
                           {-1, 0},
                           {-1, -1},
                           {0,  -1},
                           {0,  1},
                           {1,  0},
                           {1,  -1},
                           {1,  1}};
    int dm = 8;
    int grid[m][n];
    memcpy(grid, board, sizeof(grid));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int total = 0;
            for (int k = 0; k < dm; k++) {
                int cr = i + moves[k][0];
                int cc = j + moves[k][1];
                if (cr >= 0 && cr < m && cc >= 0 && cc < n) {
                    total += grid[cr][cc];
                }
            }
            if (total < 2 || total > 3) {
                board[i][j] = 0;
            } else if (total == 3) {
                board[i][j] = 1;
            } else {
                board[i][j] = grid[i][j];
            }
        }
    }
    int *ptr;
    ptr = &board[0][0];
    return ptr;


}


int main(int argc, char *argv[]) {
    int n = atoi(argv[1]);
    char *mapping = malloc(strlen(argv[2]) + 1);
    strcpy(mapping,argv[2]);
    FILE *file = fopen(mapping, "r");

    char c;
    int matrix[5][5];

    for(int i =0; i < 5; i++)
    {
        for(int j=0; j<5; j++)
        {
            fscanf(file, " %c", &c);
            matrix[i][j] = c - '0';

        }

    }
    fclose(file);

    while (n > 0){
        int* ptr = game_of_life(matrix);

        for(int i =0; i < 5; i++)
        {
            for(int j=0; j<5; j++)
            {

                matrix[i][j] = *(ptr + (i * 5) + j);

            }

        }
        n--;
    }

    FILE*pfile=NULL;
    pfile = fopen(strcat(mapping, ".out"), "w");
    for(int k =0; k < 5; k++)
    {
        for(int l=0; l<5; l++)
        {
            printf("%d ", matrix[k][l]);
            fprintf(pfile, "%d ", matrix[k][l]);
        }
        printf("\n");
        fprintf(pfile, "\n");
    }
    fclose(pfile);


}