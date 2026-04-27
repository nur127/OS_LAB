#include<stdio.h>>
#include<unistd.h>

int main(){
    if(fork() == 0 ){
        // cout<<"Child ID :"<<getpid()<<endl;
        printf("Child Id : %d",getpid());
        printf("Parent ID : %d",getppid());

        for(int i = 6; i < 11 ; i++)
        {
            printf(i + " " );
        }
    }
    else if(fork() == 1){
        printf("Parent section : ");
        for(int i = 1; i < 6 ; i++)
        {
            printf(i + " " );
        }
    }
}
