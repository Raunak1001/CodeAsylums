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

ll myFun(vi &layer,vi &end,vvi &dp,ll l,ll j,ll cost,ll m,ll ly){
	cost%=m;

	if(ly==l){
		cost+=end[j];
		if(cost%m==0)
		{
			return 1;
		}
		return 0;
	}

	if(dp[ly][cost]!=-1){
		return dp[ly][cost];
	}
	ll count=0;
	for(ll i=0;i<layer.size();i++){
		count +=myFun(layer,end,dp,l,i,cost+layer[i],m,ly+1);
	}
	return dp[ly][cost]=count;





}

int main(){
		std::ios::sync_with_stdio(false); 
		cin.tie(NULL);
		cout.tie(NULL);

		ll n,l,m;
		cin >>n>>l>>m;
		vi start(n);
		vi layer(n);
		vi end(n);
		for(ll i=0;i<n;i++){
			cin >> start[i];
		}

		for(ll i=0;i<n;i++){
			cin >> layer[i];
		}
		for(ll i=0;i<n;i++){
			cin >> end[i];
		}

		vvi dp(l+1,vi(m+1,-1));
		ll count=0;
		for(ll i=0;i<n;i++){
			count+=myFun(layer,end,dp,l,i,start[i],m,1);
		}

		cout << count << endl;

	return 0;
}		