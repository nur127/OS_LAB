#include<bits/stdc++.h>
using namespace std ;
int main(){
    int n ,r ;
    cin>>n>>r ;
    vector<vector<int>>max(n,vector<int>(r));
    vector<vector<int>>allocation(n,vector<int>(r));
    vector<vector<int>>need(n,vector<int>(r));
    vector<int>available(r);
    vector<bool>finish(n,false);
    vector<int>safe_seq;

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < r ; j++){
            cin>>max[i][j]>>allocation[i][j];
        }
    }

    for(int i = 0 ; i < r ; i ++){
        cin >>available[i];
    }

    int count = 0 ;

    while(count < n){
        bool found = false ;
        for(int i = 0 ; i < n ; i++){
            if(finish[i] == false){
                int j ;
                for(j = 0 ; j < r ; j++){
                    if(need[i][j] > available[j]){
                        break;
                    }
                }
                if(j== r){
                    for(int k = 0 ; k < r ; k++){
                        available[k] += allocation[i][k];
                    }

                    safe_seq.push_back(i);
                    finish[i] = true ;
                    found = true;
                    count++;

                }

            }
        }

        if(found == false){
            cout<<"Deadlock Detected"<<endl ;
            return 0 ;
        }
    }

    cout<<" No Dead Lock "<<endl ;
    for(int i = 0 ; i  < n ; i++){
        cout<<"P"<<safe_seq[i]<<"->";
    }


}

