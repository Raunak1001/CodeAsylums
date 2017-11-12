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

vvi dp(5*10000,vi(501,0));

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
		map<pr,ll> m[n+1];
		for(ll i=1;i<=n;i++){
			dp[i][1]=v[i].size();
			for(ll j=0;j<v[i].size();j++){
				m[i][mp(v[i][j],1)]=1;
			}
		}

		ll ans=0;
		for(ll l=2;l<=k;l++){
			for(ll i=1;i<=n;i++){
				for(ll j=0;j<v[i].size();j++){
					ll temp=dp[v[i][j]][l-1]-m[v[i][j]][mp(i,l-1)];
					m[i][mp(v[i][j],l)]=temp;
					dp[i][l]+=temp;
				}
			}
		}

		/*for(ll i=1;i<=n;i++){
			for(ll l=1;l<=k;l++){
				cout << dp[i][l]<<" ";
			}
			cout << endl;
		}
*/
		for(ll i=1;i<=n;i++){
			ans+=dp[i][k];
		}
		cout << ans/2<< endl;





	return 0;
}			