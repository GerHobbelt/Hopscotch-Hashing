#include<iostream>
#include "hopscotch.cpp"
#include <pthread.h>
#include <time.h>
#include <stdlib.h>
#include <sys/time.h>
using namespace std;

Hopscotch *obj;
int size = 524288;
void* run(void* x){
int *data = reinterpret_cast<int*>(x);
int thid = *data;
delete data;
int *k = (int*) malloc(sizeof(int));
srand(time(NULL));
for(int p=0;p<200;p++){
int tem = size+ (200*(thid+1))+p;
obj->add(new int(tem),new int(tem));
*k = rand()&1048575;
obj->contains(k);
}
for(int p=0;p<400;p++){
*k = rand()&1048575;
obj->contains(k);
}
for(int p=0;p<200;p++){
*k = rand()&1048575;
obj->remove(k);
*k = rand()&1048575;
obj->contains(k);
}
delete k;
}

int main(){
timeval start,end;
obj = new Hopscotch;
for(int j=0;j<size;j++){
 obj->add(new int(j),new int(j));
}
pthread_t threads[64];
gettimeofday(&start,NULL);
for (int r=0;r<64;r++){
pthread_create(&threads[r], NULL, run, new int(r));
}
for(int r=0;r<64;r++){
pthread_join(threads[r],NULL);
}
gettimeofday(&end,NULL);
long seconds = end.tv_sec - start.tv_sec;
long nsec = end.tv_usec - start.tv_usec;
cout<<"Time "<<(((seconds*1000000)+(nsec)))<<endl;
}

