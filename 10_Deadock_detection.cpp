#include<bits/stdc++.h>
using namespace std;

int main(){
    int n , r ;
    cout << "Enter num of Process and Resources :"<<endl;
    cin >> n>>r ;
    vector<vector<int>>allocation(n,vector<int>(r));
    vector<vector<int>>current_need(n,vector<int>(r));
    vector<int>available(r);

    // Input Section For Allocation
    for(int i = 0 ; i < n ; i ++){
        for(int j = 0 ; j < r ; j++){
            cin>>allocation[i][j];
        }
    }
    // Input Section For Current Need or Request Section 
    for(int i = 0 ; i < n ; i ++){
        for(int j = 0 ; j < r ; j++){
            cin>>current_need[i][j];
        }
    }

    // Input Section For Available Resource 
    for(int i = 0 ; i < r ; i++){
        cin >> available[i];
    }

    vector<bool>finish(n,false);
    int count = 0;

    while(count < n){ //Safe Scan for Each process

        bool found = false ;
        for(int i = 0 ;  i < n ; i++){

            if(finish[i] == false){
                int j ;

                for(j = 0 ; j < r ; j++){
                    if((current_need[i][j] ) > (available[j])){
                        break ; 
                    }
                }
                if(j == r){
                    for(int k = 0 ; k <r ; k++){
                        available[k] +=allocation[i][k] ;
                     }
                        found = true;
                        finish[i] = true ;
                        count++;
                }
            }
        }

        if(found == false){
            cout<<"Deadlock Detected "<<endl;
            return 0 ;
        }

    }

    cout<<"Deadlock Not Detected "<<endl ;


}