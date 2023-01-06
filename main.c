#include "sorter.h"

int main(int argsc, char *argv[]) {

    int countLines = 0;

    getCountL(argv[1], &countLines);

    int * countNums = malloc(countLines * sizeof(int));

    int countAllNums = 0;

    getLengthL(argv[1], countNums, &countAllNums);

    char * strs[countAllNums];

    giveNumsToStrs(argv[1], strs,countAllNums);

    int * arr[countLines];

    for (int i = 0; i < countLines; ++i) {
        arr[i] = malloc(countNums[i] * sizeof(int));
    }

    fillArray(arr,strs,countNums,countLines);

    for (int j = 0; j < countAllNums; ++j) {
        free(strs[j]);
    }

    sort(arr, countNums,countLines);

    fillStrs(arr,strs,countNums,countAllNums,countLines);

    for (int i = 0; i < countLines; ++i) {
        free(arr[i]);
    }

    transferToFile(strs,countNums,countLines);

    for (int j = 0; j < countAllNums; ++j) {
        free(strs[j]);
    }

    free(countNums);

    return 0;
}