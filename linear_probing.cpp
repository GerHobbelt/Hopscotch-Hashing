#include<iostream>
#include "probing.cpp"
using namespace std;

int main()
{
  probing *test_probe = new probing;

  int i[100];
  int k[100];
  for(int j=0;j<100;j++)
  {
    i[j]=j;
    k[j]=j;
  }

  for(int j=0;j<100;j++)
  {
    test_probe->add(&i[j],&k[j]);
  }

  for(int j=0;j<100;j++)
  {

    if(!test_probe->contains(&i[j])){
      cout<<"Error!!"<<endl;
    return 0;
    }
  }

  cout<<"Success"<<endl;
  return 0;

}
