#include<bits/stdc++.h>
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
ll mod=1000000007;
ll myFun(vi &a,ll i,ll m,vvi &dp){

	ll n=a.size();
	if(m<0){
		return 0;
	}
	if(i>=n){
		if(m==0)
		return 1;
		return 0;
	}
	if(dp[i][m]!=-1){
		return dp[i][m];
	}
	ll count=0;
	for(ll j=0;j<=a[i];j++){
		count+=myFun(a,i+1,m-j,dp)%mod;
		count%=mod;
	}
	return  dp[i][m]=count%mod;

}



int main(){

	ll t;
	cin >> t;
	while(t--){

		ll n,m;
		cin >>n>>m;
		vi a(n);
		ll b;
		for(ll i=0;i<n;i++){
			cin >>b>>a[i];
			a[i]-=b;
			m-=b;
		}
		if(m<0){
			cout << 0<< endl;
			continue;
		}
		vvi dp(n+1,vi(m+1,-1));
		cout << myFun(a,0,m,dp)<< endl;


		/*for(ll i=0;i<n;i++){
			for(ll j=0;j<=m;j++){
				cout << dp[i][j]<<" ";
			}
			cout << endl;
		}*/


	}




	return 0;
}	