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
    
    ll n,m;
    cin >>n>>m;
    
    vi a(n),b(m);
    for(ll i=0;i<n;i++){
        cin >>a[i];
    }

    for(ll j=0;j<m;j++){
        cin >>b[j];
    }
    ll k;
    cin >>k;
    set<ll> s;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            s.insert(a[i]+b[j]);
        }
    }

    set<ll> :: iterator it=s.begin();
    for(ll i=0;i<k-1;i++){
        it++;
    }
                //cout <<"Afs"<< endl;

    cout<<*it<< endl;
    
}
    
    
	return 0;
}