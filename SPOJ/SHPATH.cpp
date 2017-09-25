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
ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);


ll t;
cin >>t;
while(t--){

	ll n;
	cin >>n;
	vvp v(n+1);
	map<string,ll> m;
	//cout << n<< endl;
	for(ll i=1;i<=n;i++){
		string s;
		cin >>s;
		m[s]=i;
		ll p;
		cin >>p;
		
		for(ll j=0;j<p;j++){
			ll a,b;
			cin >>a>>b;
			v[i].pb(mp(a,b));
			}
	}

	ll num;
	cin >>num;
	while(num--){

		string a,b;
		cin >>a>>b;
		ll start=m[a];
		ll end=m[b];
		priority_queue<pr,vp,greater<pr > > pq;
		vi dis(n+1,INT_MAX);
		dis[start]=0;
		pq.push(mp(0,start));
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

		cout << dis[end]<< endl;
	}





}




}