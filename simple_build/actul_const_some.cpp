#include <pthread.h>
#include <cassert>

const unsigned times = 10;
unsigned arr[times];


void * thread(void *)
{
    for(unsigned i=0;i<times;++i)
        arr[i] = 0;
    return NULL;
}

bool main_thread()
{
    int i=0;
    bool error = true;
    for(;i<times;++i)
        arr[i] = 1;
    
    for(i=0;i<times;++i)
        if(arr[i]==1)
        {
            error = false;
            break;
        }
    return !error;
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