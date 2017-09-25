#include<bits/stdc++.h>
using namespace std;
#define vi vector<long long int>
#define vp vector<pair<long long int,long long int > >
#define vc vector<char>
#define vvi vector<vector<long long int>  >
#define vvp vector<vector<pair<long long int,long long int> > >
#define vvc vector<vector<char>  >
#define ll long long int 
#define pr pair<long long int,long long int>
#define mp make_pair		
#define pb push_back
#define vb vector<bool>
#define vvb vector< vb >
#define vvvb vector< vvb >
pr myFun(vvi &v, vvi &b,ll i, vvp &dp,ll time,ll tm){
	//cout <<time<<endl;
	ll n=dp.size();
	if(time>tm){
		return mp(10000000,-1);
	}
	if(i==n-1){
		//cout << time<< endl;
		//cout << time<< endl;
		return mp(0,time);
	}

	if(dp[i][time].first!=-1){
		//cout <<"Sfs"<< endl;
		return dp[i][time];
	}
	//dp[i][time][risk]=1;
	ll count=10000000;
	ll mint=-1;
	for(ll j=1;j<n;j++){
		if(j==i){
			continue;	
		}
		pr a=myFun(v,b,j,dp,time+v[i][j],tm);
		a.first+=b[i][j];
		if(count>a.first){
		count=a.first;
		mint=a.second;
	}
	}
return dp[i][time]=mp(count,mint);



}

int main(){
		std::ios::sync_with_stdio(false);

		ll t;
		cin >>t;
		while(t--){
			//mint=-1;
			ll n,time;
			cin >> n>> time;
			ll a;
			vvi v(n+1,vi(n+1));
			vvi b(n+1,vi(n+1));
			ll risk;
			ll mx=0;
			for(ll i=1;i<=n;i++){
				for(ll j=1;j<=n;j++){
					cin >>a;
					//cout <<a<< endl;
					v[i][j]=a;
				}
			}
			for(ll i=1;i<=n;i++){
				for(ll j=1;j<=n;j++){
					cin >>a;
					mx=max(mx,a);
					//cout <<a<< endl;
					b[i][j]=a;
				}
				risk+=mx;
				mx=0;
			}


			vvp dp(n+1,vp(time+1,mp(-1,-1)));
			
			pr p=myFun(v,b,1,dp,0,time);
			if(p.first!=10000000){
				cout << p.first<<" ";
				cout << p.second<<endl;
			}else{
				cout << -1<< endl;
			}
			//cout << mint<< endl;
			
		}

	



	return 0;
}