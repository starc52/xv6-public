#include "types.h"
#include "stat.h"
#include "user.h"
#include "pinfo.h"

int main()
{
    for (int i = 0; i < 15; i++)
    {
        int pid = fork();
        if (pid == 0)
        {
            int h=0;
            for(int k=0;k<20000000;k++){
                int n=23;
                h++;
                int f[n + 2]; 
                int j;
                f[0] = 0;
                f[1] = 1;
                for (j = 2; j <= n; j++)
                {
                    f[j] = f[j - 1] + f[j - 2];
                }
                f[j]-=h;
            }
            exit();
        }
    }
    int a[15];
    int b[15];
    for(int i=0;i<15;i++){
        waitx(&a[i], &b[i]);
    }
    for(int i=0;i<15;i++){
        printf(1, "%d is run Time\n",  b[i]);
    }
    exit();
}