#include<iostream>
#include "hopscotch.cpp"
#include <pthread.h>

using namespace std;

Hopscotch *obj;

void *run(void* x){
//  sleep(1000);
  
  pthread_t tid;
  tid = pthread_self();
  int key;
  key = (int)x;
  int val;
  val = key * 100; 

  cout << "Adding key : " << key << endl;
  cout << "Thread "<< tid <<" calling add " << endl;
  obj->add(&key,&val); 
  cout << "Thread "<< tid <<" FINISHED add " << endl;  
  //obj->trial();
  pthread_exit(NULL);
    
}

int main()
{
  int NUM_THREADS = 500;
  pthread_t threads[NUM_THREADS];
  int rc;  

 // int key[2] = {0, 1024, 1024*2, };
  int val[2] = {100, 200};
  obj = new Hopscotch;
  for(int t=0; t<NUM_THREADS; t++){
    //cout << "Creating thread : " << t << endl;
    rc = pthread_create(&threads[t], NULL, run, (void *)(1024*t));
    if (rc){
      //printf("ERROR; return code from pthread_create() is %d\n", rc);
    }
  }
  

  //obj->trial(); 
  pthread_exit(NULL);


  return 0;
 
}
