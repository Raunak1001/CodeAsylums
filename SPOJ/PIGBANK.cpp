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

int main(){
	
	ll t;
	cin >>t;
	while(t--){
		ll e,f;
		cin >>e>>f;
		ll n;
		cin >>n;
		vi a(n),b(n);
		for(ll i=0;i<n;i++){
			cin >>a[i];
			cin >> b[i];
		}
ll m=f-e;
vvi v(n+1,vi(m+1,1000000));
for(ll i=0;i<=n;i++){
	v[i][0]=0;
}
for(ll i=1;i<=n;i++){
	for(ll j=1;j<=m;j++){
		if(j>=b[i-1]){
			v[i][j]=min(v[i-1][j],a[i-1]+v[i][j-b[i-1]]);
		}else{
			v[i][j]=v[i-1][j];
		}
	}
}

	if(v[n][m]==1000000){
		cout <<"This is impossible."<< endl;
	}else{
		cout <<"The minimum amount of money in the piggy-bank is "<<v[n][m]<<"."<< endl;
	}

	}


	return 0;
}