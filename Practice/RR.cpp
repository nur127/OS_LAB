#include<bits/stdc++.h>
using namespace std ;

int main(){
    int n ,tq;
    cin >>n>>tq ;
    vector<int>at(n),bt(n),ct(n),tt(n),wt(n),rt(n);
    vector<bool>done(n,false);
    for(int i = 0 ; i < n ; i++){
        cin >> at[i]>>bt[i];
        rt[i] = bt[i];
    }

    int current = 0 , completed = 0 ;

    while(completed < n){
        bool finish = false ;
        for(int i = 0 ; i < n ; i++){
            if(at[i] <= current && done[i] == false){
                finish = true;
                if(rt[i] > tq){
                    current+=tq;
                    rt[i]-=tq;
                }
                else{
                    current+=rt[i];
                    ct[i] = current ;
                    rt[i]  = 0;
                    done[i] = true;
                    completed++;
                }
            }
        } 

        if(finish == false){
            break;
        }
    }
}