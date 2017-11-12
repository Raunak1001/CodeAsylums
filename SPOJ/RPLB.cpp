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



int main(){
		std::ios::sync_with_stdio(false); 
		cin.tie(NULL);
		cout.tie(NULL);

		ll t;
		cin >> t;
		ll p=1;
		while(t--){
			ll n,m;
			cin >>n>>m;
			vi v(n);
			for(ll i=0;i<n;i++){
				cin >> v[i];
			}

			vvi dp(n,vi(2,0));
			if(v[0]<=m){
				dp[0][0]=v[0];
			}
			ll ans=0;
			for(ll i=1;i<n;i++){
				dp[i][1]=max(dp[i-1][0],dp[i-1][1]);
				dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
				if(dp[i-1][1]+v[i]<=m){
					dp[i][0]=max(dp[i][0],dp[i-1][1]+v[i]);
				}
					ll k=i-2;
					while(k>=0){
						ll a=dp[k][0]+v[i];
						ll b=dp[k][1]+v[i];
						if(a<=m){
							dp[i][0]=max(dp[i][0],a);
						}
						if(b<=m){
							dp[i][0]=max(dp[i][0],b);
						}
						k--;
					}
				

			}
			cout <<"Scenario #"<<p<<": "<< max(dp[n-1][0],dp[n-1][1])<< endl;
			p++;
		}

	return 0;
}
