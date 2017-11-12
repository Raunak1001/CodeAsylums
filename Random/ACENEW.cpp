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

			ll n;
			cin >> n;
			vi a(n);
			for(ll i=0;i<n;i++){
				cin >> a[i];
			}
			ll k;
			cin >> k;
			sort(a.begin(),a.end());
			ll ans=0;
			for(ll i=0;i<n;i++){
				ll j=i+1;
				ll l=n-1;
				while(j<l){
					if(a[i]+a[j]+a[l]<=k){
						j++;
					}else{
						ans+=(l-j);
						l--;						
					}
				}
			}
			cout << ans<< endl;

		}



	return 0;
}			