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

		cin>>t;
		while(t--){

			ll l,r;
			cin >>l>>r;
			ll a=l/6;
			if(l%6!=0){
				a++;
			}
			a=a*6;
			//cout <<a<< endl;
			ll b=(r/6)*6;

			//cout <<b<< endl;
			ll n=(b-a)/6;
			n++;
			ll s=n*(2*a+(n-1)*6);
			s/=2;
			cout <<s<< endl;

		}



	return 0;
}			