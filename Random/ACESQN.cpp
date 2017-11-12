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

void myFun(ll n,vi &v,map<ll,ll> &m){


	ll i=0;
	while(n>1 && i<v.size()){
		ll temp=v[i];
		/*if(temp>sqrt(n)){
			m[n]++;
			break;	
		}*/
		if(n%temp==0){
			m[temp]++;
			while(n%temp==0){
				n/=temp;
			}
		}
		i++;
	}
	if(n!=1){
	    m[n]++;
	}
	return ;

}

int main(){
		std::ios::sync_with_stdio(false); 
		cin.tie(NULL);
		cout.tie(NULL);

		ll t;
		cin >> t;
		vi sieve(1001,0);
		sieve[1]=1;
		for(ll i=3;i<1001;i+=2)
		{
			if(sieve[i]==0){
				for(ll j=3;i*j<1001;j+=2){
					sieve[i*j]=1;
				}
			}
		}

		vi v;
		v.pb(2);
		for(ll i=3;i<=1000;i+=2){
			if(sieve[i]==0){
				v.pb(i);
			}
		}

	while(t--){
		ll n;
		cin >> n;
		vi a(n);
		map<ll,ll> m;
		for(ll i=0;i<n;i++){
			cin >> a[i];
			myFun(a[i],v,m);
		}
		ll mx=0;
		map<ll,ll> :: iterator it;
		for(it=m.begin();it!=m.end();++it){
			mx=max(mx,it->second);
		}
		cout << mx<< endl;

	}



	return 0;
}			