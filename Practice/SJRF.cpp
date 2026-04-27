#include<bits/stdc++.h>
using namespace std ;

int main(){
    int n ;
    cin >>n ;
    vector<int>at(n),bt(n),ct(n),tt(n),wt(n),rt(n);

    for(int i = 0 ; i < n ; i++){
        cin>>at[i]>>bt[i];
        rt[i] = bt[i];
    }

    int current = 0 ,completed = 0;
    while(completed < n ){
        int idx = -1 ,min = INT_MAX ;
        for(int i = 0 ; i < n ; i++){
            if(at[i] <= current && rt[i]>0){
                if(rt[i] < min){
                    min = rt[i];
                    idx = i;
                }
            }
        }

        if(idx == -1){
            current++;
            continue;
        }

        rt[idx]--;
        current++;
        if(rt[idx] == 0){
            ct[idx] = current;
            completed++;
        }
    }

    for(int i = 0; i < n; i++) {
        tt[i] = ct[i] - at[i];
        wt[i]  = tt[i] - bt[i];
    }

    // Output
    cout << "\nP\tAT\tBT\tCT\tTAT\tWT\n";
    cout << "---------------------------------\n";

    float totalWT = 0, totalTAT = 0;

    for(int i = 0; i < n; i++) {
        cout << "P" << i+1 << "\t"
             << at[i] << "\t"
             << bt[i] << "\t"
             << ct[i] << "\t"
             << tt[i] << "\t"
             << wt[i] << "\n";

        totalWT += wt[i];
        totalTAT += tt[i];
    }

    cout << "\nAverage Waiting Time = " << totalWT / n;
    cout << "\nAverage Turnaround Time = " << totalTAT / n << endl;
}