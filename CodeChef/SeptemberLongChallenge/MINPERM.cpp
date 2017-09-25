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
			vi v;
			ll a=2;
			ll count=0;
			while(count<n){
				if(n-count==1){
					v.pop_back();
					v.pb(a-1);
					v.pb(a-3);
				}else{
					v.pb(a);
					v.pb(a-1);
					a+=2;
				}
				count+=2;
			}

			show(v);
			cout << endl;

		}


	return 0;
}		