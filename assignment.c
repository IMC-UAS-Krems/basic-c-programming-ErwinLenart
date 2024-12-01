#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // initialize random number generator
    srand(time(NULL));
    int minrand = 1;
    int maxrand = 100;

    // WRITE YOUR CODE HERE
    //task 1
    if (argc !=3){
        printf("Incorrect usage, You provided %d arguments.The correct number of arguments is 2\n", argc - 1);
    }; 
    //task 2
    char *endptr;
    long num1 = strtol(argv[1], &endptr, 10);
    if (*endptr != '\0' || num1 <= 0) {
        printf("Incorrect usage. The parameters you provided are not positive integers\n");
    }

    long num2 = strtol(argv[2], &endptr, 10);
    if (*endptr != '\0' || num2 <= 0) {
        printf("Incorrect usage. The parameters you provided are not positive integers\n");
    }
    //task 3
    int rows = (int) num1;
    int cols = (int) num2;

    int **matrix = malloc(rows * sizeof(int *));

    for (int i = 0; i < rows; i++) {
        matrix[i] = malloc(cols * sizeof(int));
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = minrand + rand() % (maxrand - minrand + 1);
        }
    }

    //task 4

    FILE *file = fopen("matrix.txt", "w");

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fprintf(file, "%d", matrix[i][j]); 

            if (j < cols - 1) {
                fprintf(file, " "); 
            }
        }
        fprintf(file, "\n");  
    }

    fclose(file);

    return 0;

}
