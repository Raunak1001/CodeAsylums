#include<bits/stdc++.h>
using namespace std;
#define vi vector<long long int>
#define vp vector<pair<long long int,long long int > >
#define vc vector<char>
#define vvi vector<vector<long long int>  >
#define vvp vector<vector<pair<long long int,long long int> > >
#define vvc vector<vector<char>  >
#define ll long long int 
#define pr pair<long long int,long long int>
#define mp make_pair		
#define pb push_back

ll myFun(ll n,ll k){
    
     if(n==0 && k==2){
        return 1;
    }
    
    if(n<0){
        return 0;
    }
   if(v[n][k]!=-1){
       return v[n][k];
   }
   ll count=0;
    for(ll i=0;i<=n;i++){
            count+=myFun(n-i,k+1);
        }
   
    v[n][k]=count;
    
    return count;
}



int main(){
    
    ll t;
    cin >>t;
    while(t--){
        ll n;
        cin >>n;
        vi v(n+1,vi(3,-1));
        ll count=0;
        for(ll i=0;i<=n;i++){
            count+=myFun(n-i,0);
        }
        cout << count<< endl;
        
        
        
    }
    
    
	return 0;
}