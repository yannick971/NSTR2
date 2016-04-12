#ifndef MESSAGE
#define MESSAGE

#define null ((void*)0)
#define SIZE 2

typedef struct 
{
    int send;
    int recv;
    void * messages[SIZE];
} mq_t;

inline int isfull(mq_t * queue);
inline int isempty(mq_t * queue);
mq_t * create(void);
void send(mq_t * queue, void * message);
void * recv(mq_t * queue);
void destroy(mq_t * queue);
 
#endif