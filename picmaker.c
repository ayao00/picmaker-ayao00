#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>

int main(){

  int fd, i, j, r, b, g;
  char buffer[100];
  fd = open("pic.ppm", O_WRONLY | O_TRUNC | O_CREAT, 0644);
  write(fd, "P3\n500 500\n255\n", strlen("P3\n500 500\n255\n"));
  int k = 0;
  for(i = 0; i < 500; i++){
    for(j = 0; j < 500; j++){
      r = (i + k) % 256;
      b = (j + k) % 256;
      g = (i + j) % 256;
      if(i % 10 == 0 || j % 10 == 0){
        k += 10;
      }
      sprintf(buffer, "%d %d %d ", r, b, g);
      write(fd, buffer, strlen(buffer));
    }
    write(fd, "\n", 4);
  }

  close(fd);
  return 0;
}
