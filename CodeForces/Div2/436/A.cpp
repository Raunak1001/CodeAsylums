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

		ll n;
		cin >> n;
		vi v(n);
		map<ll,ll> m;
		for(ll i=0;i<n;i++){
			cin >> v[i];
			m[v[i]]++;
		}
		if(m.size()!=2){
			cout << "NO"<< endl;
			return 0;
		}
		vi a;
		map<ll,ll> :: iterator it;
		for(it=m.begin();it!=m.end();++it){
			if((it->second)!=n/2){
				cout << "NO"<< endl;
				return 0;
			}
			else{
				a.pb(it->first);
			}
		}


		cout <<"YES"<< endl;
		cout << a[0]<< " "<< a[1]<< endl;

	return 0;
}			