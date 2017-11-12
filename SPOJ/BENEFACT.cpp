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
ll temp=0;
ll myFun(vvp &v,ll i,ll par){

	ll count1=0;
	ll count2=0;
	for(ll j=0;j<v[i].size();j++){
		if(v[i][j].first!=par){
			ll a=myFun(v,v[i][j].first,i)+v[i][j].second;
			if(a>=count1){
				count2=count1;
				count1=a;
			}else if(a>count2){
				count2=a;
			}
		}
		temp=max(temp,count1+count2);
	}
return count1;

}



int main(){
		std::ios::sync_with_stdio(false); 
		cin.tie(NULL);
		cout.tie(NULL);

		ll t;
		cin >> t;
		while(t--){
			temp=0;
			ll n;
			cin >> n;
			vvp v(n+1);
			for(ll i=0;i<n-1;i++){
				ll a,b,c;
				cin >>a>>b>>c;
				v[a].pb(mp(b,c));
				v[b].pb(mp(a,c));
			}
			myFun(v,1,-1);
			cout << temp<< endl;

		}

	return 0;
}			