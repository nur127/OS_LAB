#include<stdio.h>
#include<unistd.h>

int main(){
    int id = fork();
    if(id == 0){
        printf("Norozzaman \n");
        printf("Child ID : %d",getpid());
        printf("Parent ID : %d",getppid());
    }
    else{
        int id2 = fork();
        if(id2 == 0){
            printf("Nuralam \n");
            printf("Child2 ID : %d",getpid());
            printf("Parent ID : %d",getppid());
        }
        else{
            printf("Hasmot \n");
        
            printf("Parent ID : %d",getpid());
        }
    }
}