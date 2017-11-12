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

vvi dp(5*10000,vi(500,-1));
vb mainVisited(5000000,0);

ll myFun(vvi &v,ll temp,vb &visited,ll k,ll current,ll parent){
	cout <<temp<<" "<<current<<endl;
	vi mid;
	ll ans=0;
	if(k==current){
		return 1;
	}

	if(dp[temp][current]!=-1){
		return ans;
	}

	for(ll i=0;i<v[temp].size();i++){
		if(v[temp][i]!=temp && v[temp][i]!=parent){
			visited[v[temp][i]]=1;
			ans+=myFun(v,v[temp][i],visited,k,current+1,temp);
			visited[v[temp][i]]=0;
		}
	}



return dp[temp][current]=ans;


}



int main(){
		std::ios::sync_with_stdio(false); 
		cin.tie(NULL);
		cout.tie(NULL);

		ll n,k;
		cin >> n>> k;
		vvi v(n+1);
		for(ll i=0;i<n-1;i++){
			ll a,b;
			cin >>a>>b;
			v[a].pb(b);
			v[b].pb(a);
		}
		vb visited(n+1,0);
		visited[1]=1;
		ll ans=0;
		for(ll i=1;i<=n;i++){
			visited[i]=1;
			ans+=myFun(v,i,visited,k,0,-1);
			visited.clear();
			visited.resize(n+1,0);
		}
		cout << ans/2<< endl;


	return 0;
}			