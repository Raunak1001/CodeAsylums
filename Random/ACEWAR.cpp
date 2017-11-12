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

bool sortFun(pr a,pr b){
	return a.first<b.first;
}

int main(){
		std::ios::sync_with_stdio(false); 
		cin.tie(NULL);
		cout.tie(NULL);


		ll t;
		cin >> t;
		while(t--){
			ll n;
			cin >> n;
			vvp v(n+1);
			for(ll i=0;i<n-1;i++){
				ll a,b,c;
				cin >> a>> b>>c;
				v[a].pb(mp(b,c));
				v[b].pb(mp(a,c));
			}
			vi safe(n+1);
			for(ll i=1;i<=n;i++){
				cin >> safe[i];
			}
			vi cap(n+1);
			for(ll  i=1;i<=n;i++)
			{
				cin >> cap[i];
			}
			ll vertex,popu;
			cin >> vertex>>popu;
			vi dis(n+1,INT_MAX);
			priority_queue<pr,vp,greater<pr> > pq;
			dis[vertex]=0;
			pq.push(mp(0,vertex));
			ll level=safe[vertex];
			while(!pq.empty()){
				pr p=pq.top();
				pq.pop();
				for(ll i=0;i<v[p.second].size();i++){
					if(safe[v[p.second][i].first]>level && dis[v[p.second][i].first]>dis[p.second]+v[p.second][i].second){
						dis[v[p.second][i].first]=dis[p.second]+v[p.second][i].second;
						pq.push(mp(dis[v[p.second][i].first],v[p.second][i].first));
					}
				}
			}

			vp a;
			for(ll i=1;i<=n;i++){
				if(dis[i]!=INT_MAX)
				a.pb(mp(dis[i],i));
			}
			sort(a.begin(),a.end(),sortFun);
			
			ll flag=0;
			for(ll i=0;i<a.size();i++){
				if(safe[a[i].second]>level){
					popu-=cap[a[i].second];
				}
				if(popu<=0){
					cout <<"YES"<<" "<<a[i].first<<endl;
					flag=1;
					break;
				}
			}
			if(!flag){
				cout <<"NO"<<" "<<-1<< endl;
			}



		}


	return 0;
}			