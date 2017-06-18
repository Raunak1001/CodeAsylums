#include<bits/stdc++.h>
using namespace std;
#define vi vector<long long int>
#define vvi vector<pair<long long int,long long int> > 
#define ll long long int 

bool myfun(pair<ll,ll> a, pair<ll,ll> b){
   // return (a.first)*(a.first)+(a.second)*(a.second)<(b.first)*(b.first)+(b.second)*(b.second);
return a.first<b.first;

}

int main()
 {

ll t;
cin >>t;
for(ll q=0;q<t;q++){
    ll n;
    cin >>n;
    ll x,y;
    vvi v(n);
    for(ll i=0;i<n;i++){
        cin >>x>>y;
        v[i]=make_pair(x,y);
        
    }
    sort(v.begin(),v.end(),myfun) ; 
    for(ll i=0;i<n;i++){
        cout <<v[i].first<<' '<<v[i].second<<", ";
    }
    
    cout << endl;
}
	return 0;
}