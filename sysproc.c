#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"

int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return proc->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = proc->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(proc->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

int
sys_getPerformanceData(void)
{
    char *_wtime = 0, *_rtime = 0;
    argptr(0, &_wtime, sizeof(int));
    argptr(1, &_rtime, sizeof(int));
    int * etime=0,*rtime=0,*ctime=0;
    //int pid = proc->pid;
    gettime(ctime,rtime,etime);
    *_wtime = (*etime - *ctime)- *rtime;
    *_rtime = *rtime;
    return 0;
}

int
sys_nice(void)
{
    if(proc->priority > 1)
        proc->priority--;
    return 0;
}

int
sys_getQ(void)
{
    char *arr = 0,*size=0;
    argptr(0, &arr, sizeof(int));
    argptr(1, &size, sizeof(int));
    int i[NPROC],sz;
    getque(i,&sz);
    int j;
    for(j=0;j<sz;j++)
        arr[j] = i[j];
    *size = sz;
    return 0;
}