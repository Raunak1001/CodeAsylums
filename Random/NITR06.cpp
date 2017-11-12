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

void Djikstra(vvi &dis,ll s,vvp &v){

	priority_queue<pr,vp,greater<pr> > pq;
	pq.push(mp(0,s));
	dis[s][0]=0;
	dis[s][1]=0;
	dis[s][2]=0;
	while(!pq.empty()){
		pr p=pq.top();
		//cout <<p.second<<endl;
		pq.pop();
		for(ll i=0;i<v[p.second].size();i++){

			if(dis[v[p.second][i].first][0]>dis[p.second][0]+v[p.second][i].second){
				dis[v[p.second][i].first][0]=dis[p.second][0]+v[p.second][i].second;

				pq.push(mp(dis[v[p.second][i].first][0],v[p.second][i].first));
			}
			if(dis[v[p.second][i].first][1]>min(dis[p.second][1]+v[p.second][i].second,dis[p.second][0]+(v[p.second][i].second)/2)){
				dis[v[p.second][i].first][1]=min(dis[p.second][1]+v[p.second][i].second,dis[p.second][0]+(v[p.second][i].second)/2);
				pq.push(mp(dis[v[p.second][i].first][1],v[p.second][i].first));
			}

			if(dis[v[p.second][i].first][2]>min(dis[p.second][2]+v[p.second][i].second,dis[p.second][0])){
				dis[v[p.second][i].first][2]=min(dis[p.second][2]+v[p.second][i].second,dis[p.second][0]);
				pq.push(mp(dis[v[p.second][i].first][2],v[p.second][i].first));
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
			ll s,d;
			cin >>s>>d;
			vvi dis(n+1,vi(3,INT_MAX));
			Djikstra(dis,s,v);

			/*for(ll i=1;i<=n;i++){
				cout << dis[i][0] <<" ";
				cout <<dis[i][1]<<" ";
				cout <<dis[i][2]<<endl;
					
			}
			cout << endl;*/
			ll a=dis[d][1];
			ll b=dis[d][0];
			for(ll i=1;i<=n;i++){
				dis[i][0]=INT_MAX;
				dis[i][1]=INT_MAX;
				dis[i][2]=INT_MAX;
			}
			Djikstra(dis,d,v);
			ll ans=min(a+dis[s][1],b+dis[s][2]);
			cout <<ans<< endl;
		}

	return 0;
}			