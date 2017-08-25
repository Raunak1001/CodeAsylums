#include<bits/stdc++.h>
using namespace std;
#define vi vector<char>
#define vvi vector<vector<char> >
#define ll long long int 

int main()
 {

ll t;
cin >> t;
for(ll q=0;q<t;q++){
    
    ll countX=0;
    ll countY=0;
    ll temp='a';
    ll winX=0;
    ll winY=0;
    vvi v(3,vi(3)); 
    for(ll i=0;i<3;i++){
        for( ll j=0;j<3;j++){
            cin >> v[i][j];
            if(v[i][j]=='X'){
                countX++;
            }else{
                countY++;
            }
            if(j==0){
                temp=v[i][j];
            }
            if(j==1 && v[i][j]!=temp){
                temp='a';
            }
            if(j==2){
                if(temp!='a' && v[i][j]==temp){
              if(temp=='X'){
                  winX++;
              }else winY++;      
                }
            }
            
        }
    }
    
    if(countX-countY!=1){
        cout << "Invalid"<< endl;
        continue;
    }
    for(ll j=0;j<3;j++){
        for(ll i=0;i<3;i++){
            if(i==0){
                temp=v[i][j];
            }
            if(i==1 && v[i][j]!=temp){
                temp='a';
            }
            if(i==2 && temp!='a' && v[i][j]==temp){
                if(temp=='X'){
                    winX++;
                }else{
                    winY++;
                }
            }
        }
    }
    if(v[0][0]==v[1][1] && v[1][1]==v[2][2]){
        if(v[0][0]=='X'){
            winX++;
        }else{
            winY++;
        }
    }
    
     if(v[0][2]==v[1][1] && v[1][1]==v[2][0]){
        if(v[0][2]=='X'){
            winX++;
        }else{
            winY++;
        }
    }
    
    
    
    
    if(countX>countY && winY>0){
        cout <<"Invalid"<<endl;
    continue;
        
    }
    
    if(countY>countX && winX>0){
        cout <<"Invalid"<<endl;
    continue;
        
    }
    
    cout <<"Valid"<< endl;
    
}


	return 0;
}