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
#define MAX 10000000000000;



int main(){
		std::ios::sync_with_stdio(false); 
		cin.tie(NULL);
		cout.tie(NULL);
		

		ll t;
		cin >>t;
		while(t--){

			ll n,m;
			cin >>n>>m;
			vvi a(n,vi(m));
			vvi b(n,vi(m));
			vvi dp(n,vi(m,-1));
			for(ll i=0;i<n;i++){
				for(ll j=0;j<m;j++){
					cin >> a[i][j];
				}
			}

			for(ll i=0;i<n;i++){
				for(ll j=0;j<m;j++){
					cin >> b[i][j];
				}
			}
			ll prevMin=MAX;
			for(ll i=0;i<m;i++){
				dp[0][i]=a[0][i];
				prevMin=min(prevMin,dp[0][i]);
			}
			ll nmin=MAX;
			for(ll i=1;i<n;i++){
				for(ll j=0;j<m;j++){
					dp[i][j]=min(dp[i-1][j]+max(a[i][j]-b[i-1][j],(ll)0),prevMin+a[i][j]);
					nmin=min(nmin,dp[i][j]);
				}
				prevMin=nmin;
				nmin=MAX;
			}

			/*for(ll i=0;i<n;i++){
				for(ll j=0;j<m;j++){
					cout << dp[i][j]<<" ";
				}
				cout << endl;
			}*/

			cout << prevMin<< endl;

		}

	return 0;
}			