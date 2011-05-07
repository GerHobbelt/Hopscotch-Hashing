#include<iostream>
#include "hopscotch.cpp"
#include <pthread.h>

using namespace std;

Hopscotch *obj;


int key[5] = {0, 1024, 3072, 4096, 5120};
int val[5] = {100, 200, 300, 400, 500};

void *run(void* x){
  int index = (int)x;
  for(int i=0; i<1; i++){
    obj->add(&key[index],&val[index]); 
  }
  obj->trial();
  pthread_exit(NULL);
}



int main()
{
  cout << "EMPTY NEIGHBORHOOD, 5 threads" << endl;

  obj = new Hopscotch;

  int NUM_THREADS = 5;
  pthread_t threads[NUM_THREADS];
  int rc;

  for(int t=0; t<NUM_THREADS; t++){    
    rc = pthread_create(&threads[t], NULL, run, (void *)(t));
    if (rc){
      printf("ERROR; return code from pthread_create() is %d\n", rc);
    }
  }  

  for(int t=0; t<NUM_THREADS; t++){
    pthread_join(threads[t], NULL);
  }  

  return 0; 
}
