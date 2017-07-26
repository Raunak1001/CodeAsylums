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

int main(){
    
    ll t;
    cin >>t;
    while(t--){
        
        ll n;
        cin >>n;
        ll temp=0;
        ll a=0;
        map<ll,ll> m;
        for(ll i=0;i<n;i++){
            cin >>a;
            m[a]++;
            if(m[a]>(n/2)){
                cout<< a<<endl;
                temp=1;
                break;
            }
        }
        
        if(!temp)
        {
            cout <<"NO Majority Element"<< endl;
        }
    }
    
    
	return 0;
}