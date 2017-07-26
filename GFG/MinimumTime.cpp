#include<bits/stdc++.h>
using namespace std;
#define vi vector<long long int>
#define vvi vector<vector<pair<long long int,long long int> > >
#define ll long long int 
#define pr pair<long long int,long long int>
#define mp make_pair

int main()
 {
     ll t;
     cin >>t;
     for(ll q=0;q<t;q++){
         ll n; cin >>n;
         ll a,b,c;
         cin >>a>>b>>c;
         vvi v(2*n+1);
     v[0].push_back(make_pair(1,min(a,(c+b))));
     v[1].push_back(mp(1+1,min(a,c)));
     v[1].push_back(mp(1-1,b));
     
         for(ll i=2;i<=2*n;i++){
            if(i+1<=2*n)
             v[i].push_back(make_pair(i+1,a));
             v[i].push_back(make_pair(i-1,b));
             if(i<=n)
             v[i].push_back(make_pair(2*i,c));
         }
         vi dis(2*n+1,INT_MAX);
         priority_queue<pr,vector<pr>,greater<pr> > pq;
         pq.push(mp(0,0));
dis[0]=0;
         while(!pq.empty()){
             ll u=pq.top().second;
             pq.pop();
//cout << u<<endl;
             for(ll i=0;i<v[u].size();i++){
                 ll temp=v[u][i].first;
                 if(dis[temp]>dis[u]+v[u][i].second){
                     dis[temp]=dis[u]+v[u][i].second;
                     pq.push(make_pair(dis[temp],temp));
                 }
             }
             
         }
         
         
       cout << dis[n] <<endl;
     }
     
     
     return 0;
}