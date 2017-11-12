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



int main(){
		std::ios::sync_with_stdio(false); 
		cin.tie(NULL);
		cout.tie(NULL);

		ll t;
		cin >> t;
		while(t--){
			ll n,m;
			cin >>n>>m;
			vi v(n);

			for(ll i=0;i<n;i++){
				cin >> v[i];
			}
			ll ans=1	;
			vi a(n,1);
			for(ll i=m+1;i<n;i++){
				a[i];
			}
			for(ll i=0;i<n;i++){
				for(ll j=i+1;j<n;j++){
					if(v[j]<v[i] || i==m){
						a[j]=max(a[j],a[i]+1);
						ans=max(ans,a[j]);
					}
				}
			}
			cout << ans<< endl;

		}

	return 0;
}			