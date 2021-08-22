#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cqueue.h"

cqueue_t *cqueue_create(size_t capacity) {
    cqueue_t *cqueue = malloc(sizeof(cqueue_t));
    
    if (!memset(cqueue, 0, sizeof(cqueue_t)))
        return NULL;

    cqueue->queue = calloc(capacity, sizeof(void *));
    
    if (!cqueue->queue)
        return NULL;

    cqueue->capacity = capacity;

    return cqueue;
}

void cqueue_destroy(cqueue_t *cqueue) {
    free(cqueue->queue);
    free(cqueue);
}

int cqueue_peek(cqueue_t *cqueue, void **data) {
    if (!cqueue)
        return CQUEUE_NULLPTR;

    if (CQUEUE_IS_EMPTY(cqueue))
        return CQUEUE_EMPTY;

    if (!data)
        return CQUEUE_NULLPTR;
       
    *data = cqueue->queue[cqueue->rd];

    return CQUEUE_OK;
}

int cqueue_read(cqueue_t *cqueue, void **data) {
    int ret;
    
    ret = cqueue_peek(cqueue, data);
    if (ret != CQUEUE_OK)
        return ret;

    cqueue->rd = ((cqueue->rd + 1) % cqueue->capacity);
    cqueue->size--;

    return CQUEUE_OK;
}

int cqueue_write(cqueue_t *cqueue, void *data) {
    if (!cqueue)
        return CQUEUE_NULLPTR;

    if (cqueue->size == cqueue->capacity)
        return CQUEUE_FULL;

    cqueue->queue[cqueue->wr] = data;
    cqueue->wr = ((cqueue->wr + 1) % cqueue->capacity);
    cqueue->size++;

    return CQUEUE_OK;
}
