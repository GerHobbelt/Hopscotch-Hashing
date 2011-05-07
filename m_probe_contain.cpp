#include<iostream>
#include "probing.cpp"
using namespace std;

int main()
{
  probing *test_probe = new probing;
  cout<<"Bucket size"<<sizeof(*(test_probe))<<endl;
  int i[1048576];
  int k[1048576];
  for(int j=0;j<1048576;j++)
  {
    i[j]=j;
    k[j]=j;
     test_probe->add(&i[j],&k[j]);
  }
  int l[10];
  l[0] = 1048577;
  for(int q=0;q<2097152;q++){
    if(test_probe->contains(&l[0]))
      cout<<"Error!!"<<endl;
  }
    return 0;

}
