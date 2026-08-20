#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

  int numberOfParticles = 10; // TODO what should this be?

  FILE *file = fopen(argv[1], "r");
  if (file == NULL) {
    fprintf(stderr, "Error: Could not open file %s\n", argv[1]);
    return 1;
  }

  fscanf(file, "numberOfParticles = %d", &numberOfParticles);

  fclose(file);

  printf("Number of particles: %d\n", numberOfParticles);

  return 0;
}
