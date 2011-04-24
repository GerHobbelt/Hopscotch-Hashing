#include "Hopscotch.hpp"


void Hopscotch::find_closer_free_bucket(Bucket** free_bucket,int* free_distance) {
	Bucket* move_bucket = *free_bucket -(HOP_RANGE-1);
	for(int free_dist = (HOP_RANGE -1);free_dist>0;--free_dist) {
		unsigned int start_hop_info = move_bucket->_hop_info;
		int move_free_distance = -1;
		unsigned int mask =1;
		for (int i=0;i<free_dist;++i,mask <<=1) {
			if(mask & start_hop_info){
				move_free_distance = i;
				break;
			}		
		}
		if (-1 != move_free_distance) {
			move_bucket->lock();
			if(start_hop_info == move_bucket->_hop_info) {
				Bucket* new_free_bucket = move_bucket + move_free_distance;
				move_bucket->_hop_info |= (1 << free_dist);
				free_bucket->_data = new_free_bucket->_data;
				free_bucket->_key = new_free_bucket->_key;
				++(move_bucket->_timestamp);
				new_free_bucket->_key = -1;
				new_free_bucket->_data = -1;
				move_bucket->_hop_info &= ~(1<<move_free_distance);
				*free_bucket = new_free_bucket;
				*free_distance -=free_dist;
				move_bucket->unlock();
				return;
			}
			move_bucket->unlock();
		}
		++move_bucket;
	}
	*free_bucket = NULL;
	*free_distance = 0;
}

