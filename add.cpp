bool add(int *key,int *data){
  unsigned int hash=((*key)&1023);
  Bucket* start_bucket=segments_arys+hash;
  start_bucket->lock();
  if(contains(key)){
    start_bucket->unlock();
    return false;
  }

  Bucket* free_bucket=start_bucket;
  int free_distance=0;
  for(;free_distance<ADD_RANGE;++free_distance){
    if(NULL==free_bucket->_key && NULL == __sync_val_compare_and_swap(&(free_bucket->_key),NULL,-1))
      break;
    ++free_bucket;
  }

  if(free_distance < ADD_RANGE){
    do{
      if(free_distance < HOP_RANGE){
        start_bucket->_hopInfo |= (1<<free_distance);
        free_bucket->_data=data;
        free_bucket->_key=key;
        start_bucket->unlock();
        return true;
      }
      find_closer_bucket(&free_bucket,&free_distance);
    }while(NULL != free_bucket);
  }
  start_bucket->unlock();
  return false;
}


