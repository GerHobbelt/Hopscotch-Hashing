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
  int key2[33];
  int val2[33];
  for(int j=0;j<33;j++){
     int k = j+1;
     key2[j] = 1024 * k;
     val2[j] = 300;
     if (!(obj->add(&key2[j],&val2[j])))
     {
        cout<<"Breaking at :"<<k<<"for key "<<key2[j]<<endl;
        break;
     }
    
  }
  obj->trial();  
  return 0;
 
}
