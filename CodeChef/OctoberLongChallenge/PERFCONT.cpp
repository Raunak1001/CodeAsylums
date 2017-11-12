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

			ll n,p;
			cin >>n>>p;
			ll hard=0,cw=0;
			ll flag=0;
			ll c=p/10;
			ll d=p/2;
			for(ll i=0;i<n;i++){
				ll a;
				cin >> a;

				if(c >=a){
					hard++;
				}
				if(d<=a){
					cw++;
				}
				
			}

			if(hard==2 && cw==1){
				cout <<"yes"<< endl;
			}else{
				cout << "no"<< endl;
			}
		}

	return 0;
}			