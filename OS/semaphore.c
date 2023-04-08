#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <semahpore.h>

int loop, count = 0;
sem_t s;
void *thread(void *unused){
  int i;
    for(i=0; i<loo0; i++){
      sem_wait(&s);
      count++;
      count--;
      sem_post(&s);
    }
}
int main(int argc, shar *argv[]){
  int n;
  pthread_t tid[10];
  loop = atoi(argv[1]);
  sem_init(&s, 0, 1);
  for(n=0; n<10; n++)
    pthread_create(&tid[n], NULL, &thread, NULL);
  for(n=0; n<10; n++)
    pthread_join(tid[n], NULL);
  printf("count = %d\n", count);
}
