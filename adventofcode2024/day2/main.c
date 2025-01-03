#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000

int** readinput(const char* filename, int* rows, int* column_in_row) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }

    int** data = (int**)malloc(MAX_ROWS * sizeof(int*));
    if (data == NULL) {
        perror("Memory allocation failed for data rows");
        fclose(file);
        return NULL;
    }

    *rows = 0;
    char line[2048]; // Buffer large enough for any line

    while (*rows < MAX_ROWS && fgets(line, sizeof(line), file)) {
        int col = 0;
        char* token = strtok(line, " \t\n"); // Split line into tokens (numbers, space, or tab separated)

        data[*rows] = (int*)malloc(MAX_COLS * sizeof(int));
        if (data[*rows] == NULL) {
            perror("Memory allocation failed for data columns");
            fclose(file);
            return NULL;
        }

        while (token != NULL) {
            if (col >= MAX_COLS) {
                fprintf(stderr, "Row %d exceeds MAX_COLS limit\n", *rows + 1);
                fclose(file);
                return NULL;
            }
            data[*rows][col] = atoi(token); // Convert token to integer
            token = strtok(NULL, " \t\n");  // Move to next token
            col++;
        }

        column_in_row[*rows] = col; // Store the number of columns for the current row
        (*rows)++;
    }

    fclose(file);
    return data;
}

int * solution(int ** data)
{
	for (int i = 0; i < rows; i++) {
        for(int k = 0; k < column_in_row[i];k++ )
        {
        	printf("%d ", data[i][k]);
        }
        printf("\n");
    }
}

int main() {
    int rows = 0;
    int column_in_row[MAX_ROWS] = {0};
    int** data = readinput("first_input.txt", &rows, column_in_row);

    if (data == NULL) {
        return 1; // Error occurred
    }

    // Free allocated memory
    for (int i = 0; i < rows; i++) {
        free(data[i]);
    }
    free(data);

    return 0;
}
