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
		while(t--){
			ll n;
			cin >> n;
			vi v(n);
			for(ll i=0;i<n;i++){
				cin >> v[i];
				if(i!=0){
					v[i]+=v[0];
				}
			}
			if(n==1){
				cout << 0<< endl;
				continue;
			}
			vvi dp(n,vi(2,0));
			dp[1][0]=v[0];
			dp[1][1]=abs(v[1]-v[0]);

			for(ll i=2;i<n;i++){
				dp[i][0]=max(v[i-1]+dp[i-1][1],dp[i-1][0]);
				dp[i][1]=max(v[i]+dp[i-1][0],dp[i-1][1]);
			}
			cout<< max(dp[n-1][1],dp[n-1][0])<< endl;

		}


	return 0;
}			