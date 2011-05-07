#include<iostream>
#include "hopscotch.cpp"
#include <pthread.h>

using namespace std;

Hopscotch *obj;


int key[5];
int val[5];

int iKey[32];
int iVal[32];

void *run(void* x){
  int index = (int)x;
  
  obj->add(&key[index],&val[index]); 
  
  obj->trial();
  pthread_exit(NULL);
}



int main()
{
  cout << "ONE EMPTY IN NEIGHBORHOOD, 5 threads" << endl;
  obj = new Hopscotch;

  cout << "FILLING UP THE NEIGHBORHOOR, Main Thread" << endl;
  for(int i=0; i<31; i++){
    iKey[i] = i * 1024;
    iVal[i] = i * 100;    
    obj->add(&iKey[i],&iVal[i]); 
  }
  obj->trial();
  cout << "FINISHED FILLING UP THE NEIGHBORHOOR, Main Thread" << endl;

  int NUM_THREADS = 5;
  pthread_t threads[NUM_THREADS];
  int rc;

  for(int i=0; i<5; i++){
    key[i] = 1024 * (32 + i);
  }

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
