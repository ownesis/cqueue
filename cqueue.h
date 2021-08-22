#ifndef _CIRCLEQUEUE_H_
#define _CIRCLEQUEUE_H_

#define CQUEUE_GET_SIZE(q) \
    q->size

#define CQUEUE_IS_EMPTY(q) \
    (!q->size) ? 1 : 0

#define CQUEUE_IS_FULL(q) \
    (q->size == q->capacity) ? 1 : 0

#define cqueue_push(q, v) \
    cqueue_write(q, (void *)v)

#define cqueue_pop(q, v) \
    cqueue_read(q, (void **)v)

#define cqueue_get(q, v) \
    cqueue_peek(q, (void **)v)

#include <stdint.h>

enum CQUEUE_code {
    CQUEUE_OK,
    CQUEUE_NULLPTR,
    CQUEUE_FULL,
    CQUEUE_EMPTY,
};

struct Circle_queue {
    void **queue;
    size_t capacity;
    size_t size;
    size_t rd;
    size_t wr;
};
typedef struct Circle_queue cqueue_t;

cqueue_t *cqueue_create(size_t capacity);
void cqueue_destroy(cqueue_t *cqueue);
int cqueue_write(cqueue_t *cqueue, void *data);
int cqueue_peek(cqueue_t *cqueue, void **data);
int cqueue_read(cqueue_t *cqueue, void **data);

#endif /* _CIRCLEQUEUE_H_ */
