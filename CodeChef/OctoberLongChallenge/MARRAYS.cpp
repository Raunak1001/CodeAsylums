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

ll myFun(vvp &v,vvi &dp,ll temp,ll j){

	ll n=v.size()-1;
if(temp==n){
	ll ans=INT_MIN;
	for(ll i=0;i<v[temp].size();i++){
		//cout <<temp<< " "<<abs(0-v[temp-1][j])<< endl;
		ans=max(ans,abs(v[n][i].first-v[temp-1][j].second));
	}	
	//cout << ans<< endl;
	return ans*(temp-1);

}

if(dp[temp][j]!=-1){
	return dp[temp][j];
}
ll ans=INT_MIN;
for(ll i=0;i<v[temp].size();i++){
	
		ans=max(ans,myFun(v,dp,temp+1,i)+abs(v[temp-1][j].second-v[temp][i].first)*(temp-1));
	
}
//cout << temp << " " <<ans<< endl;
return dp[temp][j]=ans;

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
			ll mx=0;
			for(ll i=1;i<n+1;i++){
				ll m;
				cin >>m;
				vi mid;
				ll tempmin=INT_MAX;
				ll tempmax=INT_MIN;
				for(ll j=0;j<m;j++){
					ll a;
					cin >> a;
					tempmax=max(tempmax,a);
					mid.pb(a);
					tempmin=min(tempmin,a);
				}
				//cout << tempmin<<" "<<tempmin<< endl;
				vb visited(m,0);
				for(ll j=0;j<m;j++){
					/*1*/
					if(mid[j]==tempmax || mid[j]==tempmin){
						pr p;
						if(j==m-1){
							v[i].pb(mp(mid[0],mid[j]));
							visited[0]=1;
						}else{
							v[i].pb(mp(mid[j+1],mid[j]));
							visited[j+1]=1;
						}
						if(j==0){
							v[i].pb(mp(mid[j],mid[m-1]));
						}else{
							v[i].pb(mp(mid[j],mid[j-1]));
						}

					}
				}
				mx=max(mx,(ll)v[i].size());

			}

			/*for(ll i=1;i<=n;i++){
				for(ll j=0;j<v[i].size();j++){
					cout << v[i][j].first<<" "<<v[i][j].second<<endl;
				}
					cout << endl;
			}*/

			vvi dp(n+1,vi(mx+1,-1));
			
			ll ans=0;
			for(ll i=0;i<v[1].size();i++){
				ans=max(ans,myFun(v,dp,2,i));
			}
			cout << ans<< endl;
		}


	return 0;
}			