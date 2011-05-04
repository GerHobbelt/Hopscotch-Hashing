#include<iostream>
#include "probing.cpp"
using namespace std;

int main()
{
  probing *test_probe = new probing;

  int i[1024];
  int k[1024];
  for(int j=0;j<1024;j++)
  {
    i[j]=j;
    k[j]=j;
  }
  for(int j=0;j<1024;j++)
  {
    test_probe->add(&i[j],&k[j]);
  }
  cout<<"here"<<endl;
  test_probe->remove(&i[10]);
  for(int j=0;j<100;j++)
  {

    if(!test_probe->contains(&i[j]))
      cout<<"Error!!"<<endl;
  } 
  test_probe->trial();
  int l[10];
  l[0] = 2000;
  int m[10];
  m[0]= 2000;
  test_probe->add(&l[0],&m[0]);
  test_probe->trial();
  cout<<"Success"<<endl;
  l[1] = 2001;
  m[1] = 2001;
  test_probe->add(&l[1],&m[1]);
  return 0;

}
