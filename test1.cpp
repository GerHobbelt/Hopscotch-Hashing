#include<iostream>
#include "hopscotch.cpp"
using namespace std;


int main()
{
  Hopscotch *obj=new Hopscotch;
  int key1=0;
  int val1=100;
  int key2=1;
  int val2=200;
  int key3=1025;
  int val3=300;
  
  obj->add(&key1,&val1);
  cout<<"Add 1 complete"<<endl;
  obj->add(&key2,&val2);
  cout<<"Add 2 completes"<<endl;
  obj->add(&key3,&val3);
  cout<<"Add 3 completes"<<endl;

  if(obj->contains(&key1))
    cout<<"Key 1 present"<<endl;

  if(obj->contains(&key2))
    cout<<"Key 2 present"<<endl;

  if(obj->contains(&key3))
    cout<<"Key 3 present"<<endl;

  return 0;
  
}
