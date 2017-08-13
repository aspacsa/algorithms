#include <stdio.h>

int compare(int num1, int num2) {
    if (num1 > num2)
        return 1;
    else
        return 0;
}

void insert(int *array, int position, int value) {
    int current_position = position - 1; 
    while( current_position >= 0 && compare(array[current_position], value) > 0 ) {
        array[current_position + 1] = array[current_position];
        current_position--;
    }
    array[current_position + 1] = value;
}

void sort(int *array, int size) {
    for (int index = 1; index < size; index++)
        insert(array, index, array[index]);
}


int main(void) {
    int unsorted_array[] = {9,15,8,1,4};
    int size = sizeof(unsorted_array) / sizeof(unsorted_array[0]);
    sort(unsorted_array, size);
    
    printf("New sorted array:\n");
    for (int i = 0; i < size; i++)
        printf("array[%i] = %i\n", i, unsorted_array[i]);

    return 0;
}