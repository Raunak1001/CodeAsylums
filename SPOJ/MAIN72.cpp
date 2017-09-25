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
ll ans=0;

void myFun(vi &a, vvb &v,ll i,ll sum){


ll n=a.size();
if(v[i][sum]){
	return ;
}
v[i][sum]=1;
if(i>=n){
	//cout << sum<< endl;
	ans+=sum;
	return ;
}


myFun(a,v,i+1,sum+a[i]);
myFun(a,v,i+1,sum);

return ;
}


int main(){
		std::ios::sync_with_stdio(false); 

		ll t;
		cin >>t;
		while(t--){

		ll n;
		cin >>n;
		vi a(n);
		ll sum=0;
		for(ll i=0;i<n;i++){
			cin >> a[i];
			sum+=a[i];
		}
		vvb v(n+1,vb(sum+1,0));
		ans=0;
		myFun(a,v,0,0);
		cout << ans<< endl;

		}


	return 0;
}