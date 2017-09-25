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

ll myFun(vi &v,ll i,vi &dp){

	ll n=v.size();
	if(i>=n){
		return 0;
	}
	if(dp[i]!=-1){
		return dp[i];
	}
	return dp[i]=max(myFun(v,i+1,dp),v[i]+myFun(v,i+2,dp));

}

int main(){
		std::ios::sync_with_stdio(false); 
		while(1){
		ll n,m;
		cin >>n>>m;
		if(n==0 && m==0){
			break;
		}

		vvi v(n,vi(m));
		for(ll i=0;i<n;i++){
			for(ll j=0;j<m;j++){
				cin >> v[i][j];
			}
		}
		vi row(n,0);
		for(ll i=0;i<n;i++)
		{
			vi dp(m,-1);
			row[i]=myFun(v[i],0,dp);
		}
		vi dp(n,-1);
		cout << myFun(row,0,dp)<< endl;

}
	return 0;
}