#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define pr pair<ll,ll>
#define vi vector<ll>
#define vvi vector< vi >
#define vn vector<Node>
#define vvn vector< vn >
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

struct Node{

	ll b;
	ll t,p;
	Node(ll b,ll t,ll p):b(b),t(t),p(p){}
};

ll ans=0;
void myFun(vvn &v,ll i,vb &visited,ll profit ,ll count){

	if(count<=0){
		ans=max(ans,profit);
		return ;
	}

	for(ll j=0;j<v[i].size();j++){
		if(!visited[v[i][j].b] && v[i][j].t<=count){
			visited[v[i][j].b]=1;
			myFun(v,v[i][j].b,visited,profit+v[i][j].p,count-v[i][j].t);
			visited[v[i][j].b]=0;
		}
	}
	ans=max(ans,profit);
	return;


}

int main(){
		std::ios::sync_with_stdio(false); 
		cin.tie(NULL);
		cout.tie(NULL);

		ll n,m;
		cin >> n>> m;
		vvn v(n+1);

		for(ll i=0;i<n;i++){
			ll a,b,t,p;
			cin >> a>> b>> t>> p;
			v[a].pb(Node(b,t,p));
			v[b].pb(Node(a,t,p));
				
		}
		vb visited(n+1,0);	
		for(ll i=1;i<=n;i++){
			visited[i]=1;
			myFun(v,i,visited,0,m);
			visited[i]=0;
		}
		cout << ans<< endl;


	return 0;
}			