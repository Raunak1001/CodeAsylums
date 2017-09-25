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

			ll l;
			cin >>l;
			map<ll,ll> m;
			for(ll i=0;i<l;i++){
				ll a;
				cin >>a;
				ll k=2;
				while(a>1){
						if(a%k==0){
							while(a%k==0){
								m[k]++;
								a/=k;
							}
						}
					
					k++;

				}


			}

			ll ans=1;
			map<ll,ll> :: iterator it;
			for(it=m.begin();it!=m.end();++it){
				ans*=(it->second + 1);
			}


			cout << ans<< endl;


		}




	return 0;
}		