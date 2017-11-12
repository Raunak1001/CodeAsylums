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

void Djikstra(vvp &v,vi &dis){
	dis[1]=0;
	priority_queue<pr,vp,greater<pr> > pq;
	pq.push(mp(0,1));
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
	return ;
}



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
			for(ll i=0;i<m;i++){
				ll a,b,c;
				cin >>a>>b>>c;
				v[a].pb(mp(b,c));
			}
			vi dis(n+1,INT_MAX);
			Djikstra(v,dis);
			ll ans=0;
			for(ll i=2;i<=n;i++){
				ans+=dis[i];
			}
			vvp g(n+1);
			for(ll i=1;i<=n;i++){
				for(ll j=0;j<v[i].size();j++){
					pr p=v[i][j];
					g[p.first].pb(mp(i,p.second));
				}
				dis[i]=INT_MAX;
			}

			Djikstra(g,dis);
			for(ll i=1;i<=n;i++){
				ans+=dis[i];
			}

			cout << ans<< endl;

		}


	return 0;
}			