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

void DFS2(vvi &v,ll i,vi &visited){
    
    visited[i]=true;
    for(ll j=0;j<v[i].size();j++){
        if(!visited[v[i][j]]){
            cout << v[i][j]<<" ";
            DFS2(v,v[i][j],visited);
        }
    }
    return ;
    
}


void DFS(vvi &v,ll i,vi &visited, stack<ll> &s){
    
    
    visited[i]=true;
    for(ll j=0;j<v[i].size();j++){
        if(!visited[v[i][j]]){
            DFS(v,v[i][j],visited,s);
        }
    }
    
    s.push(i);
    
    return ;
}

int main()
 {


ll t;
cin >>t;
while(t--){
ll n,m;
cin >>n>>m;
vvi v(n+1);
vvi newV(n+1);

for(ll i=0;i<n;i++){
    ll a,b;
    cin >>a>>b;
    v[a].pb(b);
    newV[b].pb(a);
}

stack<ll> s;
vi visited(n+1,0);

for(ll i=0;i<=n;i++){
    if(!visited[i]){
        DFS(v,i,visited,s);
    }
    
}
for(ll i=0;i<=n;i++){
    visited[i]=false;
}
while(!s.empty()){
    ll temp=s.top();
    s.pop();
    if(!visited[temp]){
    cout << temp<<" ";
    DFS2(v,temp,visited);
    cout <<", ";
    }
    
   
    
}
cout << endl; 
}

	return 0;
}