#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long int
 
ll myFun(ll n,ll r){
    ll ans=1;
    
    if(r>n-r){
        r=n-r;
    }
    for(ll i=0;i<r;i++){
        ans*=(n-i);
        ans/=(i+1);
    }
    
    return ans;
}
 
 
int main(){
    
    ll t;
    cin >>t;
    while(t--){
        ll n,k;
        cin >>n>>k;
        cout << myFun(n-1,k-1)<< endl;
        
        
    }
    
    
    
    
} 