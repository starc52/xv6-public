#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc,char *argv[]){
    int pid = fork();
    if(pid ==0){
        for(int i=0;i<100;i++){
            printf(1, "%d\n", i);
        }
        sleep(100);
        exec(argv[1], argv);
        printf(1, "exec %s failed\n", argv[1]);
        // int a;
        // int b;
        // waitx(&a, &b);
        // printf(1, "wait time is%d and run time is %d\n", a, b);
    }
    else{
        int a=0;
        int b=0;
        waitx(&a, &b);
        printf(1, "wait time is%d and run time is %d\n", a, b);
    }
    exit();
}