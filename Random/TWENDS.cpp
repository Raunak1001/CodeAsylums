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

ll myFun(ll start,ll end,ll temp,vvi &dp,vi &v){

	if(start>end){
		return 0;
	}

	if(dp[start][end]!=-1){
		return dp[start][end];
	}

	ll count=0;
	if(temp==0){
		count=max(myFun(start+1,end,1,dp,v)+v[start],myFun(start,end-1,1,dp,v)+v[end]);
	}else{
		v[start]>=v[end]? count=myFun(start+1,end,0,dp,v) : count=myFun(start,end-1,0,dp,v);
	}

	return dp[start][end]=count;

}


int main(){
		std::ios::sync_with_stdio(false); 
		cin.tie(NULL);
		cout.tie(NULL);
		ll k=1;
		while(1){

		ll n;
		cin >> n;

		if(n==0){
			break;
		}

		vi v(n);
		ll sum=0;
		for(ll i=0;i<n;i++){
			cin >> v[i];
			sum+=v[i];
		}
		vvi dp(n+1,vi(n+1,-1));
		ll a=myFun(0,n-1,0,dp,v);

		cout <<"In game "<<k<<", the greedy strategy might lose by as many as "<< 2*a-sum	<<" points."<< endl;
		k++;

	}

	return 0;
}			