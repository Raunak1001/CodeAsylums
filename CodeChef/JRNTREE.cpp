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
#define mod 1000000007
ll number;
ll myFun(vvi &v,vi &a,ll city){
number++;
ll n=a.size();
/*if(number>=n){
	return 0;
}*/
if(number==n-1 || v[city].size()==0){
	//out << city<< endl;
	return 1;
}
ll count=1;
ll visited=0;
for(ll i=0;i<v[city].size();i++){
	if(a[number]==0 || a[number]==v[city][i]){
		ll temp=myFun(v,a,v[city][i]);
		if(temp!=0){
			count*=temp%mod;
			count%=mod;
			visited++;
		}

	}
}

return ((visited%mod)*(count%mod))%mod;




}

int main(){
		std::ios::sync_with_stdio(false); 
		cin.tie(NULL);
		cout.tie(NULL);
		ll n;
		cin >>n;
		vi a(n+1);
		for(ll i=1;i<=n;i++){
			cin >>a[i];
		}

		vvi v(n+1);
		for(ll i=0;i<n-1;i++){
			ll b,c;
			cin >>b>>c;
			v[b].pb(c);
		}
		number=1;
		ll count=0;
		if(a[1]==0){
			for(ll i=1;i<=n;i++){
				count+=myFun(v,a,i)%mod;
				count%=mod;
			}
		}else{
			count=myFun(v,a,a[1])%mod;
		}

		cout << count << endl;



	return 0;
}		