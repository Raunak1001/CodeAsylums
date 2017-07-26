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
ll ans=0;
bool DFS(vvp &v,ll u,ll x,ll k,vi &visited){

if(u==x){
	return 1;
}
visited[u]=true;

for(ll i=0;i<v[u].size();i++){

	if(!visited[v[u][i].first]){
	if(DFS(v,v[u][i].first,x,k,visited)){

		if(v[u][i].second <= k){
								//cout << u<<" "<<v[u][i].first<< endl;

		ans=(ans^(v[u][i].second));
		//cout <<ans << endl;
	}
		visited[u]=false;
		return true;

	}
}
}
		visited[u]=false;
return false;
}


int main(){
	
ll t;
scanf("%lld",&t);
while(t--){
ll n;
scanf("%lld",&n);

vvp v(n+1);
ll a,b,c;
for(ll i=0;i<n-1;i++){
scanf("%lld",&a);
scanf("%lld",&b);
scanf("%lld",&c);

v[a].pb(mp(b,c));
v[b].pb(mp(a,c));
}
ll m;
cin >>m;
vi visited(n+1,0);
for(ll i=0;i<m;i++){
	ll u,x,k;
	scanf("%lld",&u);
	scanf("%lld",&x);
	scanf("%lld",&k);

	DFS(v,u,x,k,visited);
	printf("%lld\n",ans );
	ans=0;
	
}





}




	return 0;
}