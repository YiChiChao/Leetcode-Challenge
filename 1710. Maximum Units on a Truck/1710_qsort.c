#include<stdlib.h>
int cmp (const void* a, const void* b){
    int *A = *(int**)a;
    int *B = *(int**)b;
    return A[1] < B[1];
}

int maximumUnits(int** boxTypes, int boxTypesSize, int* boxTypesColSize, int truckSize){
    qsort(boxTypes, boxTypesSize, sizeof(boxTypes[0]), cmp);
    /*for(int i = 0; i < boxTypesSize; ++i){
        printf("%d\n", boxTypes[i][1]);
    }*/
    *boxTypesColSize = 2;
    int totalUnit = 0;
    int numberOfBoxes, numberOfUnitsPerBox;
    for(int i = 0; truckSize > 0 && i < boxTypesSize ; ++i){
        numberOfBoxes = boxTypes[i][0];
        numberOfUnitsPerBox = boxTypes[i][1];
        if(truckSize >= numberOfBoxes){
            totalUnit += numberOfBoxes * numberOfUnitsPerBox;
            truckSize -= numberOfBoxes;
        }
        else{
            totalUnit += truckSize * numberOfUnitsPerBox;
            truckSize = 0;
        }
        //printf("%d\n", totalUnit);
            
    }
    return totalUnit;
}
    
