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

ll myFun(vi &v,ll i,ll x,map<ll,ll> &m){
    ll n=v.size();
    if(i>n){
        return 0;
    }
    if(x==0){
        return 1;
    }
    if(x<0){
        return 0;
    }
    if(m[x]!=0){
        return m[x];
    }
    
        if(myFun(v,i+1,x-v[i],m) || myFun(v,i+1,x,m)){
            return m[x]=1;
        }
    return m[x]=-1;
    
    
    
}


int main(){
    ll t;
    cin >> t;
    while(t--){
        ll s,n,x;
        cin>>s>>n>>x;
        vi v(n+1,0);
        ll sum=s;
        ll a;
        v[0]=sum;
        for(ll i=1;i<=n;i++){
            cin >> a;
            v[i]=sum+a;
            sum=2*sum+a;
        }
        if((n==0 && x==s) || x==0){
            cout << "yes"<< endl;
        }
        
        for(ll i=0;i<=n;i++){
            cout << v[i]<< " ";
        }
        
        map<ll,ll> m;
        if(myFun(v,1,x-v[0],m) || myFun(v,1,x,m)){
            cout << "yes"<< endl;
        }else{
            cout << "no"<< endl;
        }
        
        
    }
    
    
	return 0;
}