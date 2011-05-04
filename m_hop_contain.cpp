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

  for(int q=0;q<2097152;q++){
      if(test_hop->contains(&l[0]))
        cout<<"error"<<endl;
  }
    return 0;

}
