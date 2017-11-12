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

	ll myFun(unordered_map<ll,ll> &m,ll n){

		if(m.find(n)!=m.end()){
			return m[n];
		}

		ll a=sqrt(n);
		ll count=0;
		for(ll i=2;i<=a;i++){
			if(n%i==0){
				//ll temp=max(max(myFun(m,n-i)+1,myFun(m,i)+1),(ll)0);
				count=myFun(m,n-i)+1;
				break;
			}
		}

		return m[n]=count;

	}


	int main(){
			std::ios::sync_with_stdio(false); 
			cin.tie(NULL);
			cout.tie(NULL);

			ll t;
			cin >>t;
			unordered_map<ll,ll> m;
			m[2]=0;
			ll k=1;
			while(t--){

				ll n;
				cin >>n;
				cout <<"Case #"<<k<<": " <<myFun(m,n)<< endl;
				k++;
			}

		return 0;
	}			