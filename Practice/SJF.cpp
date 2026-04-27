#include<bits/stdc++.h>
using namespace std;

int main (){
    int n ,totalWT = 0 , totalAT;
    cin >>n ;
    vector<int>at(n),bt(n),ct(n),tt(n),wt(n);
    vector<bool>done(n,false);
    vector<int>index(n);

    for(int i = 0 ; i < n ; i++){
        cin>>at[i]>>bt[i];
    }

    int current = 0 , completed = 0 ;

    while(completed < n){
        int idx = -1 , min = INT_MAX ;
         for(int i = 0 ; i < n ; i++){
            if(at[i]<=current && done[i]==false){
                if(bt[i] < min){
                    min = bt[i];
                    idx = i;
                }

            }
        }

        if(idx == -1){
            current++;
            continue;
        }

        ct[idx] = bt[idx] + current;
        current = ct[idx];
        done[idx] = true;
        index[completed] = idx+1;
        completed++;
    }

        for(int i = 0 ; i < n ;i++){
        tt[i] = ct[i] - at[i];
        wt[i] = tt[i]-bt[i];
    }

    cout << "\nP\tAT\tBT\tCT\tTAT\tWT\n";
    for(int i = 0; i < n; i++) {
        cout << "P" << i+1 << "\t"
             << at[i] << "\t"
             << bt[i] << "\t"
             << ct[i] << "\t"
             << tt[i] << "\t"
             << wt[i] << "\n";
    }
     cout << "\nGantt Chart:\n| ";
    for(int i = 0; i < n; i++) {
        cout << "P" << index[i] << " | ";
    }

    cout << endl;

}