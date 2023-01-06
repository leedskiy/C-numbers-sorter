#include "sorter.h"

void getCountL(char filename[], int * countLines){
    FILE *f1;
    f1 = fopen(filename,"r");

    char str[1024];

    while(fgets(str,sizeof(str),f1)){
        *countLines += 1;
    }

    fclose(f1);
}

void getLengthL(char filename[], int * countNums, int * countAllNums){
    FILE *f1;
    f1 = fopen(filename,"r");

    char str[1024];
    int length = 0;
    int i = 0;

    while(fgets(str,sizeof(str),f1)){
        int countSp = 0;

        length = strlen(str);

        for (int j = 0; j < length; ++j) {
            if(str[j] == ' '){
                ++countSp;
            }
        }

        ++countSp;
        *countAllNums += countSp;

        countNums[i] = countSp;
        ++i;
    }

    fclose(f1);
}

void giveNumsToStrs(char filename[], char * strs[], int countAllNums){
    FILE *f1;
    f1 = fopen(filename,"r");

    for (int i = 0; i < countAllNums; ++i) {
        strs[i] = malloc(1024 * sizeof (char));
    }

    char str[1024];
    int length = 0;

    int i = 0;

    while(fgets(str,sizeof(str),f1)){
        length = strlen(str);

        int j;
        int m = 0;

        for (j = 0; j < length; ++j) {
            if(str[j] == ' '){
                strs[i][m] = '\0';
                ++i;
                m = 0;
            }
            else{
                strs[i][m] = str[j];
                ++m;
            }
        }

        strs[i][m] = '\0';

        ++i;
    }

    fclose(f1);
}

void fillArray (int * arr[], char * strs[], int * countNums, int countLines){
    int k = 0;

    for (int i = 0; i < countLines; ++i) {
        for (int j = 0; j < countNums[i]; ++j) {
            sscanf(strs[k],"%d",&arr[i][j]);
            k++;
        }
    }
}

void swap(int * fst, int * snd){
    int temp = *fst;
    *fst = *snd;
    *snd = temp;
}

void bubbleSort(int * arr, int countNumsCurr){
    bool swapped;

    for (int i = 0; i < countNumsCurr-1; ++i)
    {
        swapped = false;
        for (int j = 0; j < countNumsCurr-i-1; ++j)
        {
            if (arr[j] > arr[j+1])
            {
                swap(&arr[j], &arr[j+1]);
                swapped = true;
            }
        }

        if (swapped == false) {
            break;
        }
    }
}

void sort(int * arr[], int * countNums, int countLines){
    for (int i = 0; i < countLines; ++i) {
        bubbleSort(arr[i],countNums[i]);
    }
}

void fillStrs(int * arr[], char * strs[], int * countNums, int countAllNums, int countLines){
    for (int i = 0; i < countAllNums; ++i) {
        strs[i] = malloc(1024 * sizeof (char));
    }

    int k = 0;

    for (int i = 0; i < countLines; ++i) {
        for (int j = 0; j < countNums[i]; ++j) {
            sprintf(strs[k], "%d", arr[i][j]);
            ++k;
        }
    }
}

void transferToFile(char * strs[], int * countNums, int countLines){
    FILE *f2;
    f2 = fopen("output.txt","w");

    int k = 0;

    for (int i = 0; i < countLines; ++i) {
        for (int j = 0; j < countNums[i]; ++j) {
            fputs(strs[k],f2);
            fputs(" ",f2);
            k++;
        }
        fputs("\n",f2);
    }

    fclose(f2);
}