#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char *argv[]) {
    // Initialize random number generator
    srand(time(NULL));

    // Define the range for random number generation
    int minrand = 1;
    int maxrand = 100;

    // Check for correct number of arguments
    if (argc != 3) {
        // Handle the case where the number of arguments is incorrect
        printf("Incorrect usage. You provided %d arguments. The correct number of arguments is 2\n", argc - 1);
        return 1; 
    }

    // Convert the arguments to integers (number of rows and columns)
    char *endptr;
    long num1 = strtol(argv[1], &endptr, 10);
    if (*endptr != '\0' || num1 <= 0) {
        printf("Incorrect usage. The first parameter must be a positive integer (number of rows)\n");
        return 1;
    }

    long num2 = strtol(argv[2], &endptr, 10);
    if (*endptr != '\0' || num2 <= 0) {
        printf("Incorrect usage. The second parameter must be a positive integer (number of columns)\n");
        return 1;
    }

    int rows = (int) num1;
    int cols = (int) num2;

    // Allocate memory for the matrix
    int **matrix = malloc(rows * sizeof(int *));
    if (matrix == NULL) {
        perror("Error allocating memory for rows");
        return 1;
    }

    for (int i = 0; i < rows; i++) {
        matrix[i] = malloc(cols * sizeof(int));
        if (matrix[i] == NULL) {
            perror("Error allocating memory for columns");
            return 1; 
        }
    }

    // Generate random values for the matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = minrand + rand() % (maxrand - minrand + 1);
        }
    }

    // Open the file to write the matrix
    FILE *file = fopen("matrix.txt", "w");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Write the matrix to the file
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fprintf(file, "%d", matrix[i][j]);
            if (j < cols - 1) {
                fprintf(file, " "); // Print space between numbers in a row
            }
        }
        fprintf(file, "\n"); // Newline after each row
    }

    // Close the file
    fclose(file);

    // Free the allocated memory
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
