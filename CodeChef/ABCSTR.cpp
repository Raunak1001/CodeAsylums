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

		string s;
		cin >>s;
		ll n=s.size();
		vi a(n+1,0);
		vi b(n+1,0);
		vi c(n+1,0);
		for(ll i=1;i<=n;i++){
			if(s[i-1]=='A'){
				a[i]++;
			}
			if(s[i-1]=='B'){
				b[i]++;
			}
			if(s[i-1]=='C'){
				c[i]++;
			}
			a[i]+=a[i-1];
			b[i]+=b[i-1];
			c[i]+=c[i-1];
				
		}


		map<pr,ll> m;
		m[mp(0,0)]=1;
		ll count=0;
		for(ll i=1;i<=n;i++){
			pr p=mp(a[i]-b[i],a[i]-c[i]);
			if(m[p]>=1){
				count+=m[p];
			}
			m[p]++;
		}

		cout << count << endl;


	return 0;
}			