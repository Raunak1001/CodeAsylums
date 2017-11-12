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
#define vvvvb vector<vvvb>
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,b,a) for(ll i=b;i>=a;i--)
#define show(a) rep(i,0,a.size()){cout <<a[i]<<" ";}
#define ct(a) cout <<a<<endl
ll ans=INT_MAX;

bool isValid(ll i,ll j,vvi &v){

ll n=v.size();
ll m=v[0].size();
if(i<0 || i>=n || j<0 || j>=m){
	return 0;
}
return 1;

}

ll myFun(vvi &v,vb &visited,vi &dis,ll i,ll k,vvi &dp){
	ll n=v.size()-1;
	ll m=v[0].size()-1;
	if(1){
		k-=dis[i];
		visited[i]=1;
	}

	if(k<=0){
		return 0;
	}
	if(dp[i][k]!=-1){
		return dp[i][k];
	}
	ll temp=INT_MAX;
	/*if(isValid(i+1,j,v)){
		temp=myFun(v,visited,dis,i+1,j,k,dp)+1;
	}
	
	
	if(isValid(i,j+1,v)){
		temp=min(myFun(v,visited,dis,i,j+1,k,dp)+1,temp);
	}

	if(isValid(i+1,j+1,v)){
		temp=min(temp,myFun(v,visited,dis,i+1,j+1,k,dp)+1);
	}*/
	if(i+1<=n+m){
		temp=min(temp,myFun(v,visited,dis,i+1,k,dp)+1);
	}
	if(i+2<=n+m){
		temp=min(temp,myFun(v,visited,dis,i+2,k,dp)+1);
	}
visited[i]=0;
return dp[i][k]=temp;


}




int main(){
		std::ios::sync_with_stdio(false); 
		cin.tie(NULL);
		cout.tie(NULL);

		ll t;
		cin >>t;
		while(t--){
			ll n,m,k;
			cin >>n>>m>>k;

			vvi v(n,vi(m));
			for(ll i=0;i<n;i++){
				for(ll j=0;j<m;j++){
					cin >> v[i][j];
				}
			}

			vi dis(n+m,0);
			vb visited(n+m,0);
			for(ll i=0;i<n;i++){
				for(ll j=0;j<m;j++){
					if(visited[i+j]){
						continue;
					}
					visited[i+j]=1;
					ll a=i;
					ll b=j;
					while(a<n && b>=0){
						dis[i+j]+=v[a][b];
						a++;
						b--;
					}
					a=i;
					b=j;
					while(a>=0 && b<m){
						dis[i+j]+=v[a][b];
						a--;
						b++;
					}
					dis[i+j]-=v[i][j];
					//cout <<i<<" "<<j<<" "<<dis[i+j]<<endl;
				}
			}

			
			for(ll i=0;i<n;i++){
				for(ll j=0;j<m;j++){

					visited[i+j]=0;
								}
			}
			vvi dp(n+m,vi(k+1,-1));

			cout << myFun(v,visited,dis,0,k,dp)<<endl;

		}

	return 0;
}			