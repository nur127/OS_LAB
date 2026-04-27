#include<bits/stdc++.h>
using namespace std ;
int main(){
    int n , r; 
    cout<<"Enter Number of Process and Resource"<<endl;
    cin>>n>>r;
    vector<vector<int>>max_need(n,vector<int>(r));
    vector<vector<int>>allocation(n,vector<int>(r));
    vector<vector<int>>current_need(n,vector<int>(r));
    vector<int>available(r);

    // Input for Max Need 
    for(int i = 0 ; i < n ; i++){
        cout<<"Give MAX NEED For P"<<i <<" :";
        for(int j = 0 ; j < r ; j++){
            cin>>max_need[i][j];
        }
    }

    // Input for Allocation  
    for(int i = 0 ; i < n ; i++){
        cout<<"Give Allocation Resource For  P"<<i <<" :";
        for(int j = 0 ; j < r ; j++){
            cin>>allocation[i][j];
        }
    }
    // Input for Available 
    cout<<"Available Resources : ";
    for(int i = 0 ; i < r ; i++){

        cin >> available[i];
    }

    // Calculation for Current need 

    for(int i = 0 ; i<n ;i++){
        for ( int j = 0 ; j < r ; j++){
            current_need[i][j] = max_need[i][j] - allocation[i][j];
        }
    }

    vector<bool>finish(n,false);
    vector<int>safeSeq;
    int count =  0 ;
    while(count < n ){ //for safe scan
         bool found = false ;
         for(int i = 0 ; i < n ; i++){
            if(finish[i] == false){
                int j ;
                for(j = 0 ; j < r ; j++){
                    if(current_need[i][j] > available[j]){
                        break;
                    }
                }
                    if(j == r){
                        for(int k = 0 ; k < r ; k++){
                            available[k] += allocation[i][k];
                        }
                        safeSeq.push_back(i);
                        finish[i] = true;
                        found = true ;
                        count++;
                }

            }
         }

         if(!found){
            cout<<"\n System is Not in Safe State "<<endl ;
            return 0 ;
         }
    }

    cout<<"System in Safe state "<<endl ;
    cout<<"Safe Sequences Are : "<<endl ;
    for(int i = 0 ;  i < n ; i++){
        cout<<"P"<<safeSeq[i]<<"->";
    }


}