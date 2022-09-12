/******************************************************************************

Pascal triangle

This program outputs the first N rows of the Pascal triangle

*******************************************************************************/
#include <stdio.h>

#define 	NROWS				4		/*Must be equal or above 1*/
#define 	MAX_ARRAY_SIZE		820		/*For a maximum of 40 rows*/


unsigned int * PascalTrian (unsigned int nRows, unsigned int * arraySize);

int main(void)
{
    unsigned int nRows = NROWS;
    unsigned int * arraySize;
    unsigned int * result;
    result = PascalTrian(nRows, arraySize);
    return 0;
}

/**
 * Returns an array with the elements of the Pascal's triangle.
 * Array size must be returned on *NumRetorno.
 */
unsigned int * PascalTrian (unsigned int nRows, unsigned int * arraySize)
{
    unsigned int i,j, size = 0;
    unsigned int res[MAX_ARRAY_SIZE];
    unsigned int * result = res;
    
    /*Gets array size*/
    for(i=1; i<=nRows; i++)
    	size += i;
    arraySize = &size;
    
    printf("Total array size: %d\n", *arraySize);
    printf("Total rows: %d\n\n",nRows);
    
    *result = 1; printf("%d\n", *result); result++; /*First element (and row) of Pascal's triangle*/
    for(i=1; i<nRows; i++){  /*Loop over each row (starting with the second row)*/
        *result = 1; printf("%d ", *result); result++;  /*The first element of the row is always 1*/
        for(j=1; j<i; j++){
        	/*Gets the middle elements of the row by adding the elements of the previous row (if there are more than 2 rows)*/
            *result = *(result-i) + *(result-i-1); printf("%u ", *result); result++;
        }
        *result = 1; printf("%d ", *result); result++;  /*The last element of the row is always 1*/
        printf("\n");
    }
    return result;
}

