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

ll myFun(vp &v, vvi &dp,ll w,ll h){
	//	cout <<w<<" "<<h<< endl;
	ll n=v.size();
	if(w<0 || h<0){
		return 1000000;
	}
	if(w==0 || h==0){
		//cout <<"sd"<< endl;
		return 0;
	}
	ll count=0;
	//cout << w<< " "<<h<< endl;
	if(dp[w][h]!=-1){
		return dp[w][h];
	}
	count=w*h;

	for(ll i=0;i<n;i++){
		if(w>=v[i].first && h>=v[i].second){
			//cout <<"SF"<< endl;
		ll a=min(myFun(v,dp,w-v[i].first,h)+myFun(v,dp,v[i].first,h-v[i].second),myFun(v,dp,w,h-v[i].second)+myFun(v,dp,w-v[i].first,v[i].second));
		count=min(a,count);
	}
}
	count=min(count,w*h);
	return dp[w][h]=count;
}


int main(){
		std::ios::sync_with_stdio(false); 

		ll t;
		cin >>t;
		while(t--){

			ll w,h;
			cin >>w>>h;
			ll n;
			cin >> n;
			vp v;
			ll a,b;
			for(ll i=0;i<n;i++){
				cin >>a>>b;
				v.pb(mp(a,b));
			}
			n=v.size();
			//cout << n<< endl;
			/*for(ll i=0;i<n;i++){
				cout << v[i].first<<" "<< v[i].second<< endl;
				}*/
			vvi dp(w+1,vi(h+1,-1));
			cout << myFun(v,dp,w,h)<<endl;
			//cout << dp[21][4]<< endl;
		}

	return 0;
}