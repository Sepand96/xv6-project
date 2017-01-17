/*#include "types.h"
#include "user.h"
#include "spinlock.h"
#include "param.h"

#define NUM_OF_CHILD 30

int main(void) {
    int childPid[NUM_OF_CHILD], pid;
    int i , j,cid = 0;
    struct spinlock lock;
    def::initlock(&lock,"cidlock");
    for ( i = 0; i < NUM_OF_CHILD; i++) {
        childPid[i] = 0;
    }
     for (  i = 0; i < NUM_OF_CHILD; i++) {
        pid = fork();
        if (pid < 0) {
		 printf(1, "fork failed\n");
		 exit();
	} 
	else if (pid == 0) {
            def::acquire(&lock);
            childPid[cid] = getpid();
            cid++;
            def::release(&lock);
            int childid=0;
            int k;
            for(k = 0;k<NUM_OF_CHILD;k++)
            {
                if(childPid[k] == getpid())
                {
                    childid = k;
                    break;
                }
            }
            if(childid%3 == 0)
                nice();
            else if(childid%3 == 1)
            {
                nice();
                nice();
            }
            for ( j = 0; j < 1000; j++) {

                printf(1, "cid : %d\n", childid);
            }
            exit();
	}
    }
    int sumOfWtime = 0;
    int sumOfRtime = 0;
    int sumOfRtimeQ1 = 0;
    int sumOfRtimeQ2 = 0;
    int sumOfRtimeQ0 = 0;
    int sumOfWtimeQ1 = 0;
    int sumOfWtimeQ2 = 0;
    int sumOfWtimeQ0 = 0;
    int numOfQ1 = 0;
    int numOfQ2 = 0;
    int numOfQ0 = 0;
    int childid=0;
    int info[NUM_OF_CHILD][3] ;
    for (  i = 0; i < NUM_OF_CHILD; i++) {
        int wtime;
        int rtime;
	int pid2=getPerformanceData(&wtime,&rtime);
        int k = 0;
	for( k = 0;k<NUM_OF_CHILD;k++)
        {
            if(childPid[k] == pid2)
            {
                childid = k;
                break;
            }
        }
	switch(childid % 3) 
        {
            case 0 :
                sumOfRtimeQ0 += rtime;
                sumOfWtimeQ0 += wtime;
                numOfQ0++;
                break;
            case 1 :
                sumOfRtimeQ1 += rtime;
                sumOfWtimeQ1 += wtime;
                numOfQ1++;
                break;
            case 2 :
                sumOfRtimeQ2 += rtime;
                sumOfWtimeQ2 += wtime;
                numOfQ2++;
                break;
        }
        sumOfRtime += rtime;
        sumOfWtime += wtime;

	info[childid][0] = wtime;
        info[childid][1] = rtime;
        info[childid][2] = wtime + rtime;
     }
	    for(   i = 0 ; i < NUM_OF_CHILD ; i++ ){

       		 printf(1, "child %d : \n", i);
       		 printf(1, "wtime : %d , rtime : %d , turnaround time : %d\n\n", info[i][0], info[i][1], info[i][2]);
    }



	 printf(1, "Average waiting time for all children : %d \n", sumOfWtime / NUM_OF_CHILD);
   	 printf(1, "Average turnaround time for all children : %d \n",
           (sumOfWtime + sumOfRtime) / NUM_OF_CHILD);
        printf(1, "Average waiting time for queue 3 children : %d \n",  sumOfWtimeQ0 /  numOfQ0);
    	printf(1, "Average turnaround time for queue 3 children : %d \n",
           (sumOfWtimeQ0 + sumOfRtimeQ0) / numOfQ0);
    	printf(1, "Average waiting time for queue 1 children : %d \n", sumOfWtimeQ1 /  numOfQ1);
    	printf(1, "Average turnaround time for queue 1 children : %d \n",
           (sumOfWtimeQ1 + sumOfRtimeQ1) / numOfQ1);
    	printf(1, "Average waiting time for queue 2 children : %d \n",  sumOfWtimeQ2 /  numOfQ2);
    	printf(1, "Average turnaround time for queue 2 children : %d \n",
           (sumOfWtimeQ2 + sumOfRtimeQ2) / numOfQ2);
	exit();
}*/
