#include "types.h"
#include "stat.h"
#include "user.h"




void frrtest(void)
{
    int n, pid;
    int wTime[10],rTime[10];
    printf(1, "FRR sanity test test\n");

    for(n=0; n<10; n++)
    {
        pid = fork();
        if(pid < 0)
        {
            printf(1,"fork failed!\n");
            return;
        }
        if(pid == 0)
        {
            int i= 0;
            for(i=0 ; i < 100000 ; i++);
            
            break;
        }
    }
    
    if(pid > 0)
    {
        for(n=0;n<10;n++)
            getPerformanceData(&wTime[n],&rTime[n]);
    }
}

int main(void)
{
    frrtest();
    exit();
}
