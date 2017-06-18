#include<bits/stdc++.h>
using namespace std;
#define vi vector<long long int>
#define vvi vector<vector<long long int> >
#define ll int 
vvi v(16,vi(2,-1)),v1(16,vi(2,-1));

int main()
 {
ll t;
cin >>t;
for(ll q=0;q<t;q++){
    for(ll i=0;i<16;i++){
        for(ll j=0;j<2;j++){
            v[i][j]=-1;
            v1[i][j]=-1;
        }
    }
    int temp=0;
    ll n,e;
    cin >>n>>e;
int  a,b;
for(ll i=0;i<e;i++){
    cin >>a>>b;
    a--;
    b--;
    if(v[a][0]==-1){
        v[a][0]=b;
    }else{
        v[a][1]=b;
    }
    
}
ll n1,e1;
for(ll i=0;i<e;i++){
    cin >>a>>b;
    a--;
    b--;
    if(v1[a][0]==-1){

        v1[a][0]=b;
    }else{
                    

        v1[a][1]=b;
    }
    
}
   
    for(ll i=0;i<n;i++){
        if(v[i][1]==-1 && v1[i][1]==-1 && v[i][0]==v1[i][0]){
            continue;
        }
        
        if(v[i][0]!=v1[i][1] || v[i][1]!=v1[i][0]){
            cout <<0<<endl;
            temp=1;
            break;
        }
        }
        if(!temp){
            cout << 1<< endl;
        }
    
    
    
    
    
}


    return 0;
}