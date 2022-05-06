// program to read points in from a file and prints coords of a specific point
// we don't know how many points are in the file

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct point {
  int     tag;
  float   x;
  float   y;
  struct point *next;
} Point;


int main(int argc, char **argv) {

  if (argc != 2) {
    printf("Correct usage appName pointsFile\n");
    return(-1);
  }
  
  // pointer to hold the link to all points
  Point *thePoints = 0;
  // read in points
  int tag;
  float x,y;
  
  FILE *inputFile = fopen(argv[1],"r");
  while (fscanf(inputFile, "%d, %f, %f\n", &tag, &x, &y) != EOF) {
    Point *nextPoint = (Point *)malloc(sizeof(Point));
    nextPoint->tag = tag;
    nextPoint->x = x;
    nextPoint->y = y;
    nextPoint->next = thePoints;

    thePoints = nextPoint;
  }

  bool done = false;
  while (done == false) {

    int tagToFind;
    printf("Enter tag to find: ");
    scanf("%d",&tagToFind);
    
    // now serach for wanted tag;
    Point *currentPoint = thePoints;
    while (currentPoint != 0 && currentPoint->tag != tagToFind) {
      currentPoint = currentPoint->next;
    }  
    
    if (currentPoint != 0) {
      printf("FOUND Point with tag %d at locaction: %f %f\n", tag, currentPoint->x, currentPoint->y);
    } else {
      printf("Could not find point with tag %d\nExiting\n", tagToFind);
      done = true;
    }
  }

  fclose(inputFile);
  
  return 0;
}

