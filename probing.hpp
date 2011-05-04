#include<iostream>
#include<pthread.h>
using namespace std;

class probing {
  private:
 	static const int MAX_SEGMENTS = 1048576;
  
  int* BUSY;
	
  struct Bucket {
		
		int* volatile _key;
		int* volatile _data;
		unsigned int volatile _lock; 
		unsigned int volatile isNULL;
		pthread_mutex_t lock_mutex;
		pthread_cond_t lock_cv;	

    Bucket(){
			_lock = 0;
			_key = NULL;
      _data=NULL;
			isNULL = 0;
			pthread_mutex_init(&lock_mutex,NULL);
			pthread_cond_init(&lock_cv, NULL);
  	}
		
    void lock(){
			pthread_mutex_lock(&lock_mutex);
      while(1){        
		    if (_lock==0){
					_lock =1;
				  pthread_mutex_unlock(&lock_mutex);
				  break;              
			  }
      	pthread_cond_wait(&lock_cv, &lock_mutex);   
 		  }
		}

		void unlock(){
			pthread_mutex_lock(&lock_mutex);
			_lock = 0;
		  pthread_cond_signal(&lock_cv);
	    pthread_mutex_unlock(&lock_mutex);
		}

	};
		
	Bucket* segments_arys;

  public:
	probing();
  ~probing();
	bool contains(int* key);
	bool add(int *key, int *data);
	int* remove(int* key);
	void trial();

};
