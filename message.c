#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>

#include "message.h"



inline int isfull(mq_t * queue) {
    return (queue->send+1)%SIZE == queue->recv;
}

inline int isempty(mq_t * queue) {
    return queue->send == queue->recv;
}

mq_t * create(void) {
    mq_t * queue = (mq_t*)malloc(sizeof(mq_t));
    queue->send = 0;
    queue->recv = 0;
}

void send(mq_t * queue, void * message) {
    while (isfull(queue));
    int next = (queue->send+1) % SIZE;
    queue->messages[next] = message;
    queue->send = next;
}

void * recv(mq_t * queue) 
{
    while (isempty(queue));
    void * message = queue->messages[queue->send];
    queue->recv = (queue->recv+1) % SIZE;
    return message;
}

void destroy(mq_t * queue) {
    while (!isempty(queue));
    free(queue);
}