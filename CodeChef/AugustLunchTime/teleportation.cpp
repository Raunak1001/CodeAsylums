#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
#define vi vector<long long int>
#define vp vector<pair<long long int,long long int > >
#define vc vector<char>
#define vvi vector< vi >
#define vvvi vector< vvi >
#define vvp vector<vector<pair<long long int,long long int> > >
#define vvc vector<vector<char>  >
#define ll long long int 
#define pr pair<long long int,long long int>
#define mp make_pair		
#define pb push_back
#define vb vector<bool>
#define vvb vector< vb >
#define vvvb vector< vvb >



bool isValid(ll x,ll y,ll a,ll b,ll r,ll c){

	if(a<0 || a>=r || b<0 || b>=c){
		return 0;
	}
return 1;
}

void buildGraph(vvi &graph,ll x,ll y,vi &visited,vi &p,vi &q,ll r,ll c){


	ll n=visited.size();
		for(ll i=0;i<n;i++)
			{
				if(visited[i]){
					continue;
				}
				if(isValid(x,y,x+p[i],y+q[i],r,c)){

					graph[(x*c+y)].pb(c*(p[i]+x)+(q[i]+y));
					visited[i]=1;
					buildGraph(graph,(p[i]+x),(q[i]+y),visited,p,q,r,c);
					visited[i]=0;
				}
				if(isValid(x,y,x-p[i],y-q[i],r,c)){
					graph[(x*c+y)].pb(c*(x-p[i])+(y-q[i]));
					visited[i]=1;
					buildGraph(graph,(x-p[i]),(y-q[i]),visited,p,q,r,c);
					visited[i]=0;
				}
				if(isValid(x,y,x-p[i],q[i]+y,r,c)){
					graph[(x*c+y)].pb(c*(x-p[i])+(q[i]+y));
					visited[i]=1;
					buildGraph(graph,(x-p[i]),(q[i]+y),visited,p,q,r,c);
					visited[i]=0;
				}
				if(isValid(x,y,p[i]+x,y-q[i],r,c)){
					graph[(x*c+y)].pb(c*(p[i]+x)+(y-q[i]));
					visited[i]=1;
					buildGraph(graph,(p[i]+x),(y-q[i]),visited,p,q,r,c);
					visited[i]=0;
				}

			}



}


ll myFun(vvi &graph,ll temp,ll steps,vvi &dp,vi &cost,ll n){
//cout <<temp<< endl;
if(steps>n){
	return 0;
}

if(dp[temp][steps]!=-1){
	return dp[temp][steps];
}

ll count=cost[temp];
for(ll i=0;i<graph[temp].size();i++){
	count=max(count,myFun(graph,graph[temp][i],steps+1,dp,cost,n)+cost[temp]);
}


return dp[temp][steps]=count;



}



int main(){
		//std::ios::sync_with_stdio(false); 

		ll t;
		cin >>t;
		while(t--){

			ll r,c,n;
			scanf("%lld",&r);
			scanf("%lld",&c);
			scanf("%lld",&n);
			ll x,y;
			scanf("%lld",&x);
			scanf("%lld",&y);
			vi p(n);
			vi q(n);
			vi cost(r*c,0);
			for(ll i=0;i<n;i++){
				scanf("%lld",&p[i]);
			}
			for(ll i=0;i<n;i++){
				scanf("%lld",&q[i]);
			}

			for(ll i=0;i<r;i++){
				for(ll j=0;j<c;j++){
					scanf("%lld",&cost[c*i+j]);
				}
			}
			/*for(ll i=0;i<r*c;i++){
				cout << cost[i]<<" ";
			}
			*/
			vvi graph(r*c);
			vi visited(n,0);

			for(ll i=0;i<n;i++)
			{
				
				if(isValid(x,y,x+p[i],y+q[i],r,c)){

					graph[(x*c+y)].pb(c*(p[i]+x)+(q[i]+y));
					visited[i]=1;
					buildGraph(graph,(p[i]+x),(q[i]+y),visited,p,q,r,c);
					visited[i]=0;
				}
				if(isValid(x,y,x-p[i],y-q[i],r,c)){
					graph[(x*c+y)].pb(c*(x-p[i])+(y-q[i]));
					visited[i]=1;
					buildGraph(graph,(x-p[i]),(y-q[i]),visited,p,q,r,c);
					visited[i]=0;
				}
				if(isValid(x,y,x-p[i],q[i]+y,r,c)){
					graph[(x*c+y)].pb(c*(x-p[i])+(q[i]+y));
					visited[i]=1;
					buildGraph(graph,(x-p[i]),(q[i]+y),visited,p,q,r,c);
					visited[i]=0;
				}
				if(isValid(x,y,p[i]+x,y-q[i],r,c)){
					graph[(x*c+y)].pb(c*(p[i]+x)+(y-q[i]));
					visited[i]=1;
					buildGraph(graph,(p[i]+x),(y-q[i]),visited,p,q,r,c);
					visited[i]=0;
				}

			}


			/*for(ll i=0;i<r*c;i++){
				cout << i<<" : ";
				for(ll j=0;j<graph[i].size();j++){
					cout << graph[i][j]<<" ";
				}
				cout << endl;

			}
*/
			vvi dp(r*c,vi(n+1,-1));

			cout << myFun(graph,x*c+y,0,dp,cost,n)<< endl;


		}


	return 0;
}