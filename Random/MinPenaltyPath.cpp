#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vc vector<char>
#define vvi vector<vector<int>  >
#define vvp vector<vector<pair<int,int> > >
#define vvc vector<vector<char>  >
#define ll int 
#define pr pair<int,int>
#define mp make_pair        


int main() {

    ll n,m;
    cin >>n>>m;
    vvp v(n+1);
    for(ll i=0;i<m;i++){
        ll a,b,c;
        cin >>a>>b>>c;
       v[a].push_back(mp(b,c));
       v[b].push_back(mp(a,c));
        
       
    }

    ll  a,b;
    cin >>a>>b;
    vi dis(n+1,1000000);
    dis[a]=0;
    priority_queue<pair<ll,ll>,vector<pair<ll,ll> >,greater<pair<ll,ll> > > pq;
    pq.push(mp(0,a));
    while(!pq.empty()){
        pr p=pq.top();
        pq.pop();
    for(ll i=0;i<v[p.second].size();i++)
    {   pr newP=v[p.second][i];
        
        if(dis[newP.first]>(dis[p.second]|newP.second)){
            dis[newP.first]=(dis[p.second]|newP.second);
            //cout <<p.second << " "<<i<<" "<<dis[v[p.second][i]]<< endl;
            pq.push(mp(dis[newP.first],newP.first));
        }
            
        
        
    }
        
        
    }
    
    if(dis[b]!=1000000){
            cout << dis[b]<<endl;
        }else{
            cout <<-1<< endl;
        }
    
    return 0;
}
    