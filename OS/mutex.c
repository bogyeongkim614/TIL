#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

int loop, count = 0;
pthread_mutex_t m=PTHREAD_MUTEX_INITIALIZER;
void *thread(void *unused){
  int i,j;
  for(i=0; i<loop; i++){
    pthread_mutex_lock(&m);
    count++;
    count--;
    pthread_mutex_unlock(&m);
  }
}
int main(int argc, char *argv[]){
  int n;
  pthread_t tid[10];
  loop = atoi(argv[1]);
  for(n=0; n<10; n++)
    pthread_create(&tid[n], NULL, &thread, NULL);
  for(n=0; n<10; n++)
    pthread_join(tid[n], NULL);
  printf("count = %d\n", count);
}
