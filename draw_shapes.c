#include <stdio.h>
#include "draw.h"

/* Prints a size x size square whose left col is at startCol */
void print_square(int leftCol, int size)
{
  int i, j;
  int endCol = leftCol + size;
  for (int row = 0; row < size; row++){
    int col;
    for (col = 0; col < leftCol; col++) putchar(' ');
    for (       ; col < endCol;  col++) putchar('*');
    putchar('\n');
  }
}

// Prints a triangle of specified height whose left edge is at col leftCol.
void print_triangle(int leftCol, int size)
{
  for (int row = 0; row <= size; row++) {
    int minCol = leftCol + size - row, maxCol = leftCol + size + row;
    int col;
    for (col = 0; col < minCol; col++) putchar(' ');
    for (       ; col <= maxCol; col++) putchar('*');
    putchar('\n');
  }
}

// Prints an arrow using bitmap
void print_arrow_bitmap()
{
  for(int row = 0; row < 7; row++) {
    unsigned short int rowBits = font_arrow[row];
    for (int col = 0; col < 12; col++) {
      unsigned short int colMask = 1 << (11 - col);
      putchar( (rowBits & colMask) ? '*' : ' ');
    }
    putchar('\n');
  }
}

// Prints an arrow  using print_triangle and print_rectangle functions
void print_arrow_with_square_triangle(int squareLeftCol,int squareSize, int triangleLeftCol, int triangleSize)
{
  print_triangle(triangleLeftCol, triangleSize);
  print_square(squareLeftCol,squareSize);
  putchar('\n');
}

