#include<bits/stdc++.h>
#include <sstream>
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
ll mod=1000000009;
ll myFun(vi &dp,ll a,ll i,ll n){

	if(a==((1<<n)-1)){
		return 1;
	}
	if(dp[a]!=-1){
		return dp[a];
	}
	ll count=0;
	for(ll k=i;k<101;k++){
		for(ll j=0;j<v[k].size();j++){
			if((a & (1<<(v[k][j]-1)))==0){
					count+=myFun(dp,(a^(1<<(v[k][j]-1))),k+1,n)%mod;
					count%=mod;
				}
			}
	}

	return dp[a]=count;

}


int main(){
		std::ios::sync_with_stdio(false); 
		cin.tie(NULL);
		cout.tie(NULL);
		ll t;
		cin >>t;
		while(t--){

			ll n;
			cin >> n;
			cin.ignore();
			vvi v(101);
			for(ll i=1;i<=n;i++){
				string s;
				getline(cin,s);
				ll j=0;
				while(j<s.size()){
					string a="";
					while(j<s.size() && s[j]!=' '){
						a+=s[i];
					}
					ll c=stoi(a);
					v[c].pb(i);
				}
			}
			ll a=1;
			vi dp(1000000,-1);
			ll count=0;
			for(ll i=1;i<=100;i++){
				for(ll j=0;j<v[i].size();j++){
					count+=myFun(dp,(a^(1<<(v[i][j]-1))),i+1,n)%mod;
					count%=mod;
				}
			}
			cout << count<< endl;

		}

	return 0;
}			