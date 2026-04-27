#include<bits/stdc++.h>
using namespace std ;

int main(){
    int n;
    cout <<"Enter Number Of Page : "<<endl;
    cin>>n;

    vector<int>page(n);
    cout <<"Enter Enter reference pages : "<<endl;
    for(int i = 0 ; i < n ; i++){
        cin>>page[i];
    }

    int f;
    cout <<"Enter Number Of Frame : "<<endl;
    cin>>f;

    vector<int>frame(f,-1);
    int pointer = 0 ,HT= 0 ,MS=0;

    for( int i = 0 ; i < n ; i++){
        bool found = false ;

        for(int j = 0 ; j<f ; j++){
            if(frame[j] == page[i]){
                found = true;
                break;
            }
        }

        if(found){
            HT++;
        }
        else{
            frame[pointer] = page[i];
            pointer = (pointer + 1) % f;
            MS++;
        }
    }

    cout<<"Number Of Pages HIT : " << HT<<endl ;
    cout<<"Number Of Pages MISS : " << MS<<endl ;
    cout<<"HIT Ratio : " << ((double)HT/n)*100<<"%"<<endl ;
    cout<<"MISS Ratio : " << ((double)MS/n)*100<<"%"<<endl ;

}