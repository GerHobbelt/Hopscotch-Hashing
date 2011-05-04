#include<iostream>
#include "hopscotch.cpp"
using namespace std;

int main()
{
  Hopscotch *test_hop = new Hopscotch;
  cout<<"Bucket size"<<sizeof(*(test_hop))<<endl;
  int i[1048576];
  int k[1048576];
  for(int j=0;j<1048576;j++)
  {
    i[j]=j;
    k[j]=j;
    test_hop->add(&i[j],&k[j]);
  }
	cout<<"done"<<endl;
  int l[10];
  l[0] = 1048577;
    if(!test_hop->contains(&l[0]))
      cout<<"Error!!"<<endl;
    return 0;

}
