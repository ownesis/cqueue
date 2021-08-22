#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cqueue.h"
#include <stdint.h>

#define ERR(c) \
    do { \
        if (ret == CQUEUE_OK) break; \
        fprintf(stderr, \
                "%s", \
                (c == 1) \
                    ? "Null ptr passed" \
                    : (c == 2) \
                        ? "Queue is full" \
                        : "Queue is empty" \
               ); \
        return EXIT_FAILURE; \
    } while (0)

int main(void) {
    int ret;
    char *ptr = NULL;
    char *ptr2 = NULL;
    int val = 0;
    int *ptr_val = NULL;
    
    val = 40;
    ptr2 = strdup("World");

    printf("[*] Generate circular queue of size '3'\n\n");
    cqueue_t *cqueue = cqueue_create(3);
   
    printf("[+] Add a const string\n");
    ret = cqueue_write(cqueue, (void *)"Hello");
    ERR(ret);

    printf("[+] Add a string\n");
    //ret = cqueue_write(cqueue, (void *)ptr2);
    ret = cqueue_push(cqueue, ptr2);
    ERR(ret);
 
    printf("[+] Add a integer\n\n");
    ret = cqueue_write(cqueue, (void *)&val);
    ERR(ret);
    
    printf("[i] size of queue: %ld\n", CQUEUE_GET_SIZE(cqueue));
    printf("[i] queue is full: %s\n\n", 
            (CQUEUE_IS_FULL(cqueue)) 
             ? "yes" 
             : "nop");

    printf("[+] Read the fisrt element added\n");
    ret = cqueue_read(cqueue, (void *)&ptr2);
    ERR(ret);

    printf("[i] ptr2 = %s\n", ptr2);
    printf("[i] size of queue: %ld\n\n", CQUEUE_GET_SIZE(cqueue));
  
    printf("[+] Read the second element added\n");
    ret = cqueue_read(cqueue, (void *)&ptr);
    ERR(ret);
    
    printf("[i] ptr = %s\n", ptr);
    printf("[i] size of queue: %ld\n\n", CQUEUE_GET_SIZE(cqueue));

    printf("[+] Read until remove the third element added\n");
    ret = cqueue_peek(cqueue, (void *)&ptr_val);
    ERR(ret);
    
    *ptr_val += 2; 
    printf("[i] val = %d\n", val);
    printf("[i] size of queue: %ld\n", CQUEUE_GET_SIZE(cqueue));

    free(ptr);
    
    cqueue_destroy(cqueue);

    return 0;
}
