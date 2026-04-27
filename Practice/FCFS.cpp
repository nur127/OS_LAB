#include<bits/stdc++.h>
using namespace std ;

int main(){
    int n,totalWT=0 , totalTT =0 ;
    double avgTT,avgWT;
    cout<<"Enter Number Of Process : \n";
    cin>>n ;

    vector<int>at(n),bt(n),ct(n),tt(n),wt(n);

    for(int i = 0 ; i < n ; i++){
        cin>>at[i]>>bt[i];
    }

    int current = 0 ;
        for(int i = 0 ; i < n ; i++){
            if(at[i] > current ){
                current = at[i];
            }
            ct[i] = current + bt[i];
            current = ct[i];
        }
    // Calculation of TAT 
    for(int i = 0 ; i < n ; i++){
        tt[i] = ct[i] - at[i];
    }

    // Calculation of WT 
    for(int i = 0 ; i < n ; i++){
        wt[i] = tt[i] - bt[i];
    }

    for(int i = 0 ; i<n ; i++){
        totalTT += tt[i];
        totalWT += wt[i];
    }
    avgTT = double(totalTT)/n;
    avgWT = double(totalWT) /n;

    cout<<" AT  |"<<" BT  |"<<" CT  |"<<" TAT  |" << " WT  |"<<endl;

    for(int i = 0 ; i < n ; i++){
        cout <<" "<<at[i]<<"  |"<<" "<<bt[i]<<"    |"<<" "<<ct[i]<<"   |"<<" "<<tt[i]<<"    |"<<" "<<wt[i]<<"   |"<<endl;
    }

    cout<<"\n Total TAT : "<<totalTT<<endl;
    cout<<"\n Total WT : "<<totalWT<<endl;
    cout<<"\n Average TAT : "<<avgTT<<endl;
    cout<<"\n Average WT : "<<avgWT<<endl;
}