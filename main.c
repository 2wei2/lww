#include<stdio.h>
#include<time.h>
#include"hashtable.c"
#include "hashtable.h"


int  main(void) {
    clock_t start, finish; 
    double    duration; 

    start = clock(); 
    file_read_ht();
    file_write_ht();    
    finish = clock(); 
    
    duration = (double)(finish - start) / CLOCKS_PER_SEC; 
    printf( "%f seconds\n", duration ); 
	search_ht();
    cleartable();     
    
    return 0;
}
