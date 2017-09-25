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

void  myFun(map<ll,ll> &m,vi &ans,vi &nm){

	ll n=ans.size();
	ll temp=ans[n-1];
	ll p=nm.size();
	for(ll i=p-1;i>=0;i--){
		m[nm[i]+temp]++;
		nm.pb(nm[i]+temp);
	}

	nm.pb(temp);


}

int main(){
		std::ios::sync_with_stdio(false); 
		cin.tie(NULL);
		cout.tie(NULL);

		ll t;
		cin >>t;
		while(t--){

			ll n;
			cin >>n;
			ll a=pow(2,n);
			vi v(a,0);
			for(ll i=0;i<a;i++){
				cin >> v[i];
			}
			sort(v.begin(),v.end());
			vi ans;
			if(n==1){
				cout << v[1]<< endl;
				continue;
			}	
			map<ll,ll> m;
			vi nm;
			ans.pb(v[1]);
			ans.pb(v[2]);
			nm.pb(v[1]);
			//m[v[1]]=1;
			myFun(m,ans,nm);
			ll i=3;
			ll count=2;
			while(count<n){
				while(m[v[i]]>=1){
					m[v[i]]--;
					i++;
				}
				ans.pb(v[i]);
				count++;
				i++;
				myFun(m,ans,nm);
			}
			show(ans);
			cout << endl;

		}

	return 0;
}			