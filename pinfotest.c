#include "types.h"
#include "stat.h"
#include "user.h"
#include "pinfo.h"
int main(){
    struct proc_stat proc_stat;
    getpinfo(&proc_stat);
    printf(1, "PID is %d, Runtime is %d, num_run is %d, current_queue is %d, ticks[0] is %d, ticks[1] is %d, ticks[2] is %d, ticks[3] is %d, ticks[4] is %d\n", proc_stat.pid, proc_stat.runtime, proc_stat.num_run, proc_stat.current_queue, proc_stat.ticks[0], proc_stat.ticks[1], proc_stat.ticks[2], proc_stat.ticks[3], proc_stat.ticks[4]);
    for(int i=0;i<500;i++){
        printf(1, "%d", i);
    }
    printf(1, "\n");
    getpinfo(&proc_stat);
    printf(1, "PID is %d, Runtime is %d, num_run is %d, current_queue is %d, ticks[0] is %d, ticks[1] is %d, ticks[2] is %d, ticks[3] is %d, ticks[4] is %d\n", proc_stat.pid, proc_stat.runtime, proc_stat.num_run, proc_stat.current_queue, proc_stat.ticks[0], proc_stat.ticks[1], proc_stat.ticks[2], proc_stat.ticks[3], proc_stat.ticks[4]);
    for(int i=0;i<500;i++){
        printf(1, "%d", i);
    }
    printf(1, "\n");
    exit();
}