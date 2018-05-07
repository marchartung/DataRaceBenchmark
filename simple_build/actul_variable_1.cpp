#include <pthread.h>
#include <cassert>

const unsigned times = 10;
unsigned k=0;


void * thread(void *)
{
    while(k==1)
        k=0;
    return NULL;
}

bool main_thread()
{
    int i=0;
    while(k==0)
    {
        k=1;
        ++i;
    }
    return i<times;
}


int main()
{
    pthread_t pid;
    
    assert(pthread_create(&pid,NULL,thread,NULL) == 0);
    
    bool res = main_thread();
    
    pthread_join(pid,NULL);
    
    assert(res);
    return 0;
}