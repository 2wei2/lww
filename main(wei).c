#include<stdio.h>
#include<time.h>
#include"hashtable(wei).c"
#include "hashtable(wei).h"


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
