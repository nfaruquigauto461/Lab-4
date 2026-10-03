#include <stdio.h>
#include <stdlib.h>

extern int sum_array(const int *arr, long n);

int main(int argc, char *argv[]){
    // opens the file

    FILE *file = fopen(argv[1], "r");
    if(!file){
        perror("error opening file");
        return 1;
    }

    // reads the number of elements
    long n = 0;
    if(fscanf(file, "%ld", &n) != 1){
        printf("error reading count");
        fclose(file);
        return 1;
    }

    // allocates memory for the array
    int *array = malloc(n * sizeof(int));
    if(!array){
        perror("memory allocation failed");
        fclose(file);
        return 1;
    }

    // reads N integers from the file into array  
    for (long i = 0; i < n; i++){
        if(fscanf(file, "%d", &array[i]) != 1){
            printf("error reading element at index");
            free(array);
            fclose(file);
            return 1;
        }
    }

    fclose(file);

    //calls assembly function
    int total_sum = sum_array(array, n);

    //prints total sum
    printf("Sum: %d\n", total_sum);

    // clears allocated memory
    free(array);
    return 0;
}


