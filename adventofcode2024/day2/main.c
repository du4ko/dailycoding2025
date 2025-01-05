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

int check_inc_dec(int * row, int size)
{
    if(row[0] == row[1])
    {
        return 0;
    }
    if(row[0] < row[1])
    {
        for(int i = 0; i < size - 1; i++)
        {
            // printf("%d + %d ", row[i], row[i+1]);
            // printf("\n");
            if(row[i] < row[i+1])
            {
                continue;
            }
            else
            {
                return 0;
            }

        }
    }

    if(row[0] > row[1])
    {
        for(int i = 0; i < size - 1; i++)
        {
            if(row[i] > row[i+1])
            {
                continue;
            }
            else
            {
                return 0;
            }
        }
    }
    return 1;
}

int solution_one(int ** data, int * column_in_row)
{
    int return_array = 0;
    int col_result = 1;
    for (int i = 0; i < MAX_ROWS; i++) {
        col_result = 1;
        int check_row = check_inc_dec(data[i],column_in_row[i]);
            

        if(check_row == 0)
        {
            continue;
        }
        if(data[i][0] < data[i][1])
        {
            for(int k = 0; k < column_in_row[i] - 1;k++ )
            {
                int result = data[i][k + 1] - data[i][k];
                if(result > 3)
                {
                    //printf("row - %d col - %d \n", i + 1, k + 1);
                    col_result = 0;
                    break;
                }
            }
        }
        if(data[i][0] > data[i][1])
        {
            for(int k = 0; k < column_in_row[i] - 1;k++ )
            {
                int result = data[i][k] - data[i][k + 1];
                if(result > 3)
                {
                    //printf("row - %d col - %d \n", i + 1, k + 1);
                    col_result = 0;
                    break;
                }
            }
        }

        if(col_result == 1)
        {
            return_array += 1;
            for(int u = 0; u < column_in_row[i]; u++)
            {
                printf("%d ", data[i][u]);
            }
            printf("\n");

        }
 
    }
    return return_array;
}

int main() {
    int rows = 0;
    int column_in_row[MAX_ROWS] = {0};
    int** data = readinput("first_input.txt", &rows, column_in_row);

    if (data == NULL) {
        return 1; // Error occurred
    }

    int solution_task_one = solution_one(data, column_in_row);
    printf("%d\n", solution_task_one);
    // Free allocated memory
    for (int i = 0; i < MAX_ROWS; i++) {
        free(data[i]);
    }
    free(data);

    return 0;
}
