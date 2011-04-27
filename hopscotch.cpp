#include <iostream.h>
#include "hopscotch.hpp"
#include "add.cpp"
#include "contains.cpp"


Hopscotch::Hopscotch(){
	segments_arys = new Bucket[1024];
}

void Hopscotch::trial(){
	Bucket* oB = segments_arys+10;
	printf("Before Lock 10 %d\n",oB->_lock);
	oB->lock();
	printf("Lock 10 %d\n",oB->_lock);
	oB->unlock();
	printf("UnLock 10 %d\n",oB->_lock);
	oB = NULL;
}

int main(int argc, char *argv[]){
	Hopscotch* oHash;
	oHash = new Hopscotch;
	oHash->trial();
	printf("Succeed\n");
	oHash = NULL;
}


