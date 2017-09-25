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



int main(){
		std::ios::sync_with_stdio(false); 
		cin.tie(NULL);
		cout.tie(NULL);


		ll t;
		cin>>t;
		while(t--){

			ll n;
			cin >>n;
			ll mn=1000000000;
			ll ans=0;
			for(ll i=0;i<n;i++){
				ll a;
				cin >>a;
				if(a<mn){
					mn=a;
					ans=i;
				}
			}
			cout << ans+1<< endl;

		}

	return 0;
}		