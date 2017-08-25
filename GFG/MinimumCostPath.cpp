#include<bits/stdc++.h>
using namespace std;
#define vi vector<long long int>
#define vvi vector<vector<long long int> >
#define vvp vector<vector<pair<long long int,long long int> > >
#define ll long long int 

bool valid(ll i,ll j, ll n){
    if(i<0 || i>=n || j<0 || j>=n){
        return false;
    }
    return true;
}



int main()
 {

ll t;
cin >> t;
for(ll q=0;q<t;q++){
    ll n;
    cin >> n;
  vvp v(n*n);
  vvi a(n,vi(n));

for(ll i=0;i<n;i++){
    for(ll j=0;j<n;j++){
        cin >> a[i][j];
    }
}


for(ll i=0;i<n;i++){
    for(ll j=0;j<n;j++){
ll temp=i*n+j;

if(valid(i+1,j,n)){
    v[temp].push_back(make_pair((i+1)*n+j,a[i+1][j]));
}

if(valid(i-1,j,n)){
    v[temp].push_back(make_pair((i-1)*n+j,a[i-1][j]));
}

if(valid(i,j+1,n)){
    v[temp].push_back(make_pair((i)*n+j+1,a[i][j+1]));
}

if(valid(i,j-1,n)){
    v[temp].push_back(make_pair((i)*n+j-1,a[i][j-1]));
}



    }
}

vi dis(n*n,100000);
dis[0]=0;
priority_queue<pair<ll,ll> vector<pair<ll,ll> >,greater<pair<ll> > > pq;
pq.push(make_pair(0,0));
while(!pq.empty()){
pair<ll,ll> p=pq.top();
pq.pop();
for(ll i=0;i<v[p.first].size();i++){
if(dis[v[p.first][i].first]>dis[p.first]+v[p.first][i].second){
    dis[v[p.first][i].first]=dis[p.first]+v[p.first][i].second;
    pq.push(make_pair(v[p.first][i].first,dis[v[p.first][i].first]));
}


}


}


cout << dis[n*n]<< endl;

}


    return 0;
}