#include <stdio.h>

#define MAX_ROWS 1000

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    int leftArr[n1], rightArr[n2];

    // Copy data to temp arrays
    for (int i = 0; i < n1; i++) 
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++) 
        rightArr[j] = arr[mid + 1 + j];

    // Merge temp arrays back into arr
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Recursively sort halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge sorted halves
        merge(arr, left, mid, right);
    }
}

int calculate_distance(int arr_first[], int arr_sec[], int size) {
    int sum = 0;

    for (int i = 0; i < size; i++) {

        if (arr_first[i] > arr_sec[i]) {
            sum += arr_first[i] - arr_sec[i];
        } else if (arr_sec[i] > arr_first[i]) {
            sum += arr_sec[i] - arr_first[i];
        }
    }
    return sum;
}

int calculate_occur(int arr_first[], int arr_sec[])
{
    printf("%d ", arr_first[0]);
    int score = 0;
    for(int i = 0; i < MAX_ROWS; i++)
    {
        int count = 0;
        for(int k = 0; k < MAX_ROWS; k++)
        {
            if(arr_first[i] == arr_sec[k])
            {
                count++;
            }
        }
        score = (arr_first[i] * count) + score;
        //printf("%d \n", score);
    }
    return score;
}

int main() {


    FILE *file = fopen("input2.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    int firstColumn[MAX_ROWS];
    int secondColumn[MAX_ROWS];
    int row = 0;

    int test_arr_one[] = {3,4,2,1,3,3};
    int test_arr_two[] = {4,3,5,3,9,3};

    while (fscanf(file, "%d %d", &firstColumn[row], &secondColumn[row]) == 2) {
        row++;
    }


    // int first_c_size = sizeof(firstColumn) / sizeof(firstColumn[0]);
    // int sec_c_size = sizeof(secondColumn) / sizeof(secondColumn[0]);

    // mergeSort(firstColumn, 0,first_c_size - 1);
    // mergeSort(secondColumn,0, sec_c_size - 1);


    // int sum = calculate_distance(firstColumn, secondColumn, 1000);
    int sum = calculate_occur(firstColumn, secondColumn);
    //int test_sum = calculate_occur(test_arr_one, test_arr_two);
    printf("%d\n",sum);

}
