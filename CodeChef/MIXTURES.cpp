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

		ll n;
		while(scanf("%lld",&n)!=EOF){
			vi v(n);

			for(ll i=0;i<n;i++){
				scanf("%lld",&v[i]);
			}

			vvi val(n+1,vi(n+1,INT_MAX));
			vvi dp(n+1,vi(n+1,INT_MAX));


			for(ll l=0;l<n;l++){
				for(ll i=0;i<n;i++){
					if(i+l>=n){
						break;
					}

					if(l==0){
						dp[i][i]=0;
						val[i][i]=v[i];
					}else{
						for(ll k=i;k<i+l;k++){
							if(dp[i][i+l]>dp[i][k]+dp[k+1][i+l]+val[i][k]*val[k+1][i+l]){
								dp[i][i+l]=dp[i][k]+dp[k+1][i+l]+val[i][k]*val[k+1][i+l];
								val[i][i+l]=(val[i][k]%100 + val[k+1][i+l]%100)%100;
							}
						}
					}

				}
			}

			/*for(ll i=0;i<n;i++){
				for(ll j=0;j<n;j++){
					cout <<dp[i][j]<<" ";
				}
				cout << endl;
			}

			for(ll i=0;i<n;i++){
				for(ll j=0;j<n;j++){
					cout <<val[i][j]<<" ";
				}
				cout << endl;
			}*/


			cout << dp[0][n-1]<< endl;




		}

	return 0;
}		