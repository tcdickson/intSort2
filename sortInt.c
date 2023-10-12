//(Sorting Integers) Write a program that sorts an array of integers into ascending or descending order. Use command-line arguments to pass either argument -a for ascending order or -d for descending order. [Note: This is the standard format for passing options to a program in UNIX.]
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// this function is used to compare two integers in ascending order
int compareIntegers(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}
// this function is used to compare two integers in descending order
int compareIntegersDesc(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}
// command line arguments. argc regers to the number of arguments passed. argv points to each argument passed to the program. 
int main(int argc, char *argv[]) {
    // if the number of arguments passed is less than 2 - or - by comparing the argument passed, with the two characters that need to be inputted (-a & -d) do not equal each other, we pring an error message and exit the program. 
    if (argc < 2 || (strcmp(argv[1], "-a") != 0 && strcmp(argv[1], "-d") != 0)) {
        printf("Usage: %s -a or %s -d followed by integers.\n", argv[0], argv[0]);
        return 1;
    }
    // this aray (aray1) will store the integers inputted. We subtract 2 in order to display the correct number of characters. when you type the program into the terminal, you have a space, and either -a or -d that occupy spaces. Therefore, we need to subtract 2. 
    int array1[argc - 2];
    // if argc is equal to 2, that means  no integers were provided to perform a sort on. Only the -a or -d were provided. If true, we prompt the user to enter at least 1 integer.
    if (argc == 2) {
        printf("Enter %d elements for the array: ", argc - 1);
      
    } else {
        //if the numbers inputted are valid, we store them in an array and convert from a string to an integer. 
        for (int i = 2; i < argc; i++) {
            array1[i - 2] = atoi(argv[i]);
        }
    }
    // using the strcmp to compare the inputted command argummant (argv[1]) to -a, or -d, we call the appropriate function.The qsort function is a function that sorts an array. The first parameter (array1) is the current array (or the base address). argc - 2 refers to the number of elements in the array that will be sorted. The sizeof regers to the size in bytes of each element in the array. Finally, the comparison function is called. The compareIntegers method compares the two elements. It takes int (*compar)(const void *, const void*. This coincides with the method defined above. The function returns a negative number if a is smaller than b, and a positive number if b s smaller than a. Zero if they are equal. This results in an ascending order of sort, with the negative values coming before the positive values. The second qsort method for -d works the same way but reversed for descending order. 
    if (strcmp(argv[1], "-a") == 0) {
        qsort(array1, argc - 2, sizeof(int), compareIntegers);
        printf("Array in ascending order:\n");
    } else if (strcmp(argv[1], "-d") == 0) {
        qsort(array1, argc - 2, sizeof(int), compareIntegersDesc);
        printf("Array in descending order:\n");
    }

    // Print the sorted array
    for (int i = 0; i < argc - 2; i++) {
        printf("%d ", array1[i]);
    }
    printf("\n");
    return 0;
}
