#include <pthread.h>
#include <cassert>

const unsigned times = 2;
unsigned k=0;


void * thread(void *)
{
    for(unsigned i=0;i<times;++i)
        k=0;
    return NULL;
}

bool main_thread()
{
    int i=0,j;
    for(j=0;j<times;++j)
    {
        if(k==0)
            ++i;
        k=1;
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