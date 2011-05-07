#include <iostream>
using namespace std;

int* remove(int *key){
	unsigned int hash = (*key&1023);
	Bucket* start_bucket = segments_arys[hash];
	start_bucket->lock();
	
	unsigned int hop_info = start_bucket->_hop_info;
	unsigned int mask = 1;
	for(int i=0;i<HOP_RANGE;++i,mask<<=1){
		if(mask & hop_info){
			Bucket* check_bucket = start_bucket+i;
			if(*key==*(check_bucket->_key)){
				int* rc = check_bucket->_data;
				check_bucket->_key=NULL;
				check_bucket->_data=NULL;
				start_bucket->hop_info &=~(1<<i);
				start_bucket->unlock();
				return rc;
			}
		}
	}
	start_bucket->unlock();
	return NULL;
} 
