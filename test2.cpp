#include<iostream>
#include "hopscotch.cpp"
using namespace std;


int main()
{
  Hopscotch *obj=new Hopscotch;
  int key1[33];
  int val1[33];
  for(int i=0;i<33;++i){
   key1[i] = i;
   val1[i] = 100+i;
   obj->add(&key1[i],&val1[i]);
  }  
  int key2 = 1025;
  int val2 = 300;
  obj->add(&key2,&val2);
  obj->trial();  
  return 0;
 
}
