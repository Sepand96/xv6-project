#include "types.h"
#include "stat.h"
#include "user.h"




void rrtest(void)
{
    int n, pid;
    int cid[10],wTime[10],rTime[10];
    printf(1, "RR sanity test test\n");

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
            int i;
            for(i = 0 ; i < 1 ; i++)
            {
                printf(1,"Child %d prints for the %d time\n",getpid(),i);
            }
            break;
        }
        if(pid > 0)
            cid[n] = pid;
    }
    
    if(pid > 0)
    {
        for(n=0;n<10;n++)
            getPerformanceData(&wTime[n],&rTime[n]);
        
        for(n=0;n<10;n++)
            printf(1, "Child %d status:\nWaiting Time: %d\tRunning Time : %d\tTurnaround Time: %d\n",cid[n],wTime[n],rTime[n],wTime[n]+rTime[n]);
    }
}

int main(void)
{
    rrtest();
    exit();
}
