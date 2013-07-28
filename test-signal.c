#include <stdio.h>
#include <stdlib.h>
#include <signal.h>


int is_breaked = 1;

void my_terminate (int param)
{
  printf ("Terminating program...%d\n", param);
  is_breaked = 0;
}

int main ()
{
  signal (SIGTERM,my_terminate);
 
  while(is_breaked == 1)sleep(1);

  printf("main exited\n");

  return 0;
}
