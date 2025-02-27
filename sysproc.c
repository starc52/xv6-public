#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"
#include "pinfo.h"

struct proc_stat;
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
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
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
    if(myproc()->killed){
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
int sys_test1(void){
  return test1(25);
}
int sys_waitx(void){
  int *wtime, *rtime, *ttime;
  if(argptr(0, (char**)&wtime, sizeof(int)) < 0){
    return -1;
  }
  if(argptr(1, (char**)&rtime, sizeof(int)) < 0){
    return -1;
  }
  if(argptr(2, (char**)&ttime, sizeof(int)) < 0){
    return -1;
  }
  return waitx(wtime, rtime);
}
int sys_set_priority(void){
  int prior;
  if(argint(0, &prior)<0){
    return -1;
  }
  return set_priority(prior);
}
int sys_getpinfo(void){
  struct proc_stat* proc_stat;
  if(argptr(0, (char**)&proc_stat, sizeof(struct proc_stat))<0){
    return -1;
  }
  return getpinfo(proc_stat);
}