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
#define show(a) rep(i,a,b){cout <<a[i]<<" ";}
#define ct(a) cout <<a<<endl

ll myFun(map<ll,ll> &m,ll n){

	if(n<12){
		return m[n]=n;
	}
	if(m.find(n)!=m.end()){
		return m[n];
	}

	ll count=max(n,myFun(m,n/2)+myFun(m,n/3)+myFun(m,n/4));
	return m[n]=count;

}


int main(){
		std::ios::sync_with_stdio(false); 


		int t;
		map<ll,ll> m;
		
		while(scanf("%d",&t)!=EOF){
			myFun(m,t);
			ct(m[t]);
		}

	return 0;
}		