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
		cin >>t;
		while(t--){
			ll n;
			cin >>n;
			ll ans=0;
			ll temp=0;
			ll pv=-1;
			ll a;

			for(ll i=1;i<n+1;i++){
				ans =(ans^i);
				//cout << ans<<endl;
				cin >>a;
				if(a<pv && temp!=2){
					temp=1;
				}
				if(a<1 || a>n){
					temp=2;
				}
				pv=a;
				//cout <<a<<endl;
				ans=(ans^a);

			}
			//cout << ans<< endl;
			if(ans!=0 || temp!=1){
				cout <<"Ugly"<<endl;
			}else{
				cout <<"Beautiful"<< endl;
			}
		}



	return 0;
}		