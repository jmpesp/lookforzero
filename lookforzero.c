#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BYTES_PER_READ (16 * 1024 * 1024)

int main(int argc, char **argv) {
  uint8_t *buffer = (uint8_t *)malloc(BYTES_PER_READ);
  FILE *fp;
  uint32_t i;

  if (argc < 2) {
    fprintf(stderr, "Usage: %s <device>\n", argv[0]);
    fprintf(stderr, "Returns 1 if a non-zero value is found, 0 otherwise\n");
    return 1;
  }

  fp = fopen(argv[1], "r");
  if (fp == NULL) {
    fprintf(stderr, "Cannot open %s\n", argv[1]);
    return 1;
  }

  while (fread(buffer, BYTES_PER_READ, 1, fp) == 1) {
    for (i = 0; i < BYTES_PER_READ; i++) {
      if (buffer[i] != 0) {
        fprintf(stderr, "Found non-zero byte, offset %d\n", i);
        free(buffer);
        fclose(fp);
        return 1;
      }
    }
  }

  free(buffer);
  fclose(fp);
  return 0;
}
