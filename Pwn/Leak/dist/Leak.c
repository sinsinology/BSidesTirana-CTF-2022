#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 0x100

int main()
{
  char* flagBuf;
  char buf[20];
  int fd;

  flagBuf = malloc(SIZE);
  fd = open("flag", 0);
  read(fd, flagBuf, SIZE);

  setbuf(stdout, NULL);
  setbuf(stdin, NULL);
  setbuf(stderr, NULL);

  printf("Enter some string that can exploit a stupid printf\n");

  gets(buf);
  printf(buf);
}
