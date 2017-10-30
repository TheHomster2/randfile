#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

/*
Anthony Hom Charles Weng
Systems - 4
HW 7 - /Dev(ise a )/random( plan)
*/

int main (){
  int fd = open("/dev/random", O_RDONLY);
  int rand1[10];
  // read into the array the random characters
  read(fd, rand1, sizeof(rand1));
  // done with the file
  close(fd);

  printf("array 1:\n");
  int i = 0;
  // loop through array and print (runs from i = 0-9)
  while(10 - i){
    printf("%d: %d\n", i, rand1[i]);
    i ++;
  }

  // write to the file the array
  fd = open("out.txt", O_CREAT | O_WRONLY, 0600);
  // ??write the bit chain rand into the file out.txt??
  write(fd, rand1, sizeof(rand1));
  // done with the file
  close(fd);

  fd = open("out.txt", O_RDONLY);
  int rand2[10];
  // read into rand2 the bits from out.txt
  read(fd, rand2, sizeof(rand2));
  // done with the file
  close(fd);

  printf("\n\n\narray 2:\n");
  i = 0;
  // loop through array and print (runs from i = 0-9)
  while(10 - i){
    printf("%d: %d\n", i, rand1[i]);
    i ++;
  }
}
