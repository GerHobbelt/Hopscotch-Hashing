#include <stdio.h>
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

unsigned int HOP_RANGE = 32;

bool contains(unsigned int* key){
	unsigned int hash = *key & 1023;
	Bucket* start_bucket = segments_ary[hash];
	unsigned int try_counter = 0;
	unsigned int timestamp;
	do{
		timestamp = start_bucket->_timestamp;
		unsigned int hop_info = start_bucket->_hop_info;
		int* bits = getBits(hop_info);
		Bucket check_bucket = start_bucket;
		for( int i = HOP_RANGE-1 ; i >= 0 ; i++){
			if(1 == bits[i]){
				if(*key == *(check_bucket->_key)){
					return true;
				}	
			}
			++check_bucket;
		}
		++try_counter;
	}while(timestamp != start_bucket->_timestamp && try_counter < MAX_TRIES)
	if(timestamp != start_bucket->_timestamp){
		Bucket* check_bucket = start_bucket;
		for(int i=0; i<HOP_RANGE ; i++){
			if(*key == (check_bucket->_key))
				return true;
			++check_bucket;
		}
	}
	return false;
}

int* getBits(unsigned int number){
	unsigned int value = number;
	const unsigned int MASK = (1 << (HOP_RANGE - 1));
	cout << "MASK" << MASK << endl;
	int* hops = new int[HOP_RANGE];

	for ( int i = 1; i <= HOP_RANGE; i++ ) 
	{
		hops[i-1] = ( value & MASK ? 1 : 0 );
		value <<= 1;
	}
	return hops;
}

