//
//  vectors_and_matrices_APR.cpp
//  HelloWorld
//
//  Created by Соломія Серант on 05.12.2025.
//
#include <iostream>
#include <stdio.h>

#define COLUMNS 256
#define ROWS    128

static unsigned char image[ROWS] [COLUMNS];

int main(int argc, char ** argv)
{
    int s = atoi(argv[1]);
    for (int i=0; i<ROWS; ++i)
        for (int j=0; j < COLUMNS; ++j)
            image[i][j] = (i*s) ^j;
    fwrite(image[0], COLUMNS, ROWS, stdout);
    return 0;
}
