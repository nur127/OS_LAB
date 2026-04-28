// Question 2-Process
// Write a program where:
// •	parent prints numbers 1–5 
// •	child prints numbers 6–10 
// Observe execution order.



#include<stdio.h>
#include<unistd.h>

int main(){
    if(fork() == 0){
        printf("Child Id : %d\n", getpid());
        printf("Parent ID : %d\n", getppid());

        for(int i = 6; i < 11; i++){
            printf("%d ", i);
        }
    }
    else{
        printf("Parent section:\n");
        for(int i = 1; i < 6; i++){
            printf("%d ", i);
        }
    }
    return 0;
}
