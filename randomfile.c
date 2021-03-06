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

int ran(){
  int randint;
  int fd = open("/dev/random", O_RDONLY);
  read(fd, &randint, sizeof(randint));
  if (errno) {
       printf("error: %s\n", strerror(errno));
   }
  close(fd);
  return randint;
}

int main (){
  int rand1[10];
  int i = 0;
  while (10 - i) {
    rand1[i] = ran();
    i ++;
  }
  printf("\nreading 1 done\n");


  printf("\narray 1:\n");
  // loop through array and print (runs from i = 0-9)
  i = 0;
  while(10 - i){
    printf("%d: %d\n", i, rand1[i]);
    i ++;
  }


  // write to the file the array
  int fd = open("out.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
  // ??write the bit chain rand into the file out.txt??
  write(fd, rand1, sizeof(rand1));
  // done with the file
  close(fd);
  printf("\nwritng done\n");


  fd = open("out.txt", O_RDONLY);
  int rand2[10];
  // read into rand2 the bits from out.txt
  read(fd, rand2, sizeof(rand2));
  // done with the file
  close(fd);
  printf("\nreading 2 done\n");


  printf("\narray 2:\n");
  i = 0;
  // loop through array and print (runs from i = 0-9)
  while(10 - i){
    printf("%d: %d\n", i, rand1[i]);
    i ++;
  }
}
