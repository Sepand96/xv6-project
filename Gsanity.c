        #include "types.h"
#include "user.h"
#include "stat.h"


int main(void) {
	int childpid = 0;
        int *a=0,*b=0;
	printf(1,"Father pid is %d\n",getpid());
	sleep(10);
        printf(1,"chid created\n");
	childpid = fork();	
	if(childpid<0){
		printf(1, "fork failled\n ");
		exit();
        }
	else 
        {
            int pid=getpid();
            int i=0;
            for (i=0;i<50;i++)
            {
                printf(1,"process %d is printing for the %d time\n",pid,i);                
            }
        }
        getPerformanceData(a,b);
	exit();
}


