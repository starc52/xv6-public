#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"
int main(){
    for(int i=0;i<10;i++){
        int pid = fork();
        if(pid==0){
            set_priority(60-i);
            sleep(10);
            printf(1, "%d\n", i);
            exit();
        }
    }
    while(1);
}