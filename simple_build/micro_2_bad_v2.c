#include <assert.h>
#include <pthread.h>
#include <stdio.h>

int x=0;


void* t1(void* arg)
{
  x++;
  x++;
  x++;
  x++;
  x++;
  x++;
  x++;
  x++;
  x++;
  x++;
// 10
  assert(x>9);
}

void* t2(void* arg)
{
  x++;
  x++;
  x++;
  x++;
  x++;
  x++;
  x++;
  x++;
  x++;
  x++;
// 10

  assert(x>9);
}
int main(void)
{
  pthread_t id[2];

  pthread_create(&id[0], NULL, &t1, NULL);
  pthread_create(&id[1], NULL, &t2, NULL);

  pthread_join(id[0],NULL);
  pthread_join(id[1],NULL);

  return 0;
}
