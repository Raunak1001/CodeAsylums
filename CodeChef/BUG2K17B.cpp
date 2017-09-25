#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define pr pair<ll,ll>
#define vi vector<ll>
#define vvi vector< vi >
#define vvvi vector< vvi >
#define vp vector<pr >
#define vvp vector<vp >
#define vc vector<char>
#define vvc vector<vc  >
#define mp make_pair		
#define pb push_back
#define vb vector<bool>
#define vvb vector< vb >
#define vvvb vector< vvb >
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,b,a) for(ll i=b;i>=a;i--)
#define show(a) rep(i,0,a.size()){cout <<a[i]<<" ";}
#define ct(a) cout <<a<<endl



int main(){
		std::ios::sync_with_stdio(false); 
		cin.tie(NULL);
		cout.tie(NULL);

		ll t;
		cin >>t;
		while(t--){
			ll n,m;
			cin >>n>>m;
			vvp v(n+1);
			while(m--){
				ll a,b,c;
				cin >>a>>b>>c;
				v[a].pb(mp(b,c));
				v[b].pb(mp(a,c));
			}


			priority_queue<pr,vp,greater<pr> > pq;
			pq.push(mp(0,1));
			vi dis(n+1,INT_MAX);
			dis[1]=0;
			while(!pq.empty()){
				pr p=pq.top();
				pq.pop();
				for(ll i=0;i<v[p.second].size();i++){
					if(dis[v[p.second][i].first]>dis[p.second]+v[p.second][i].second){
						dis[v[p.second][i].first]=dis[p.second]+v[p.second][i].second;
						pq.push(mp(dis[v[p.second][i].first],v[p.second][i].first));
					}
				}
			}



			if(dis[n]==INT_MAX){
				cout <<"NONE"<<endl;
				continue;
			}else{
				cout << dis[n]<< endl;
			}

		}


	return 0;
}		