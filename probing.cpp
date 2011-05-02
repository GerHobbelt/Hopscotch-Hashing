#include <iostream>
#include "probe.hpp"
using namespace std;

Hopscotch::Hopscotch(){
	segments_arys = new Bucket[MAX_SEGMENTS];
}


void Hopscotch::trial(){

  Bucket* temp;
  for(int i=0;i<40;i++){
    temp=segments_arys+i;
    if(temp->_key != NULL )
    cout<<"Key:"<<*temp->_key<<" Data:"<<*temp->_data<<"Array index:"<<i<<endl;
    else
      cout<<"NULL at:"<<i<<endl;
  
  }
   
  cout<<"--------------------"<<endl;
}



int* Hopscotch::remove(int *key){
    int* rc    = NULL:

    unsigned int hash = ((*key)&(MAX_SEGMENTS-1));
    Bucket* start_bucket = segments_arys+hash;
    start_bucket->lock();   
    if (*key == *(start_bucket->_key)){
        rc = start_bucket->_data;
        start_bucket->_key=NULL;
        start_bucket->_data=NULL;
        start_bucket->isNULL = 1;
        start_bucket->unlock();
         return rc;
    }
       
     if((key==NULL)&&((start_bucket->isNULL)==0)){
        start_bucket->unlock();
        return NULL;

    }

    unsigned int start = hash+1;
    for(unsigned int i = start;(i&(MAX_SEGMENTS-1)) != hash;i++){
      unsigned int temp = (i&(MAX_SEGMENTS-1));
      Bucket* check_bucket = segments_arys+temp;
     
        if (*key == *(check_bucket->_key)){
            rc = check_bucket->_data;
            check_bucket->_key=NULL;
            check_bucket->_data=NULL;
            check_bucket->isNULL = 1;
            start_bucket->unlock();
             return rc;
        }
            
        if((key==NULL)&&((check_bucket->isNULL)==0)){
        start_bucket->unlock();
        return NULL;   
        }   
     }
    
    start_bucket->unlock();
    return NULL;

}


bool Hopscotch::contains(int* key){
   
    unsigned int hash = ((*key)&(MAX_SEGMENTS-1));
    Bucket* start_bucket = segments_arys+hash;
    if (*key == *(start_bucket->_key)){
         return true;     
     }
     if((key==NULL)&&((start_bucket->isNULL)==0))
      return false;

    unsigned int start = hash+1;
    for(unsigned int i = start;(i&(MAX_SEGMENTS-1)) != hash;i++){
      unsigned int temp = (i&(MAX_SEGMENTS-1));
      Bucket* check_bucket = segments_arys+temp;
      if (*key == *(check_bucket->_key)){
         return true;     
       }
      if((key==NULL)&&((check_bucket->isNULL)==0))
          return false;   
    }
    return false;
}



bool Hopscotch::add(int *key,int *data){
  
  unsigned int hash=((*key)&(MAX_SEGMENTS-1));
  Bucket* start_bucket=segments_arys+hash;
  Bucket* probe_bucket;

  start_bucket->lock();

  if(contains(key)){
    start_bucket->unlock();
    return false;
  }


  if(start_bucket->_key==NULL){
    start_bucket->_key=key;
    start_bucket->_data=data;
    start_bucket->unlock();
    return true;
  }

  for(int i=hash+1;(i&MAX_SEGMENTS-1)!=hash;i++){

    probe_bucket=segments_arys+(i&(MAX_SEGMENTS-1));

    if(probe_bucket->_key==NULL){
      probe_bucket->lock();
      if(probe_bucket->_key==NULL){
        probe_bucket->_key=key;
        probe_bucket->_data=data;
        probe_bucket->unlock();
        start_bucket->unlock();
        return true;
      }
      else{
        probe_bucket->unlock();
      }
    }
  }
  
  start_bucket->unlock();  
  return false;
}


