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
			cin >> n;
			vi v(n);
			for(ll i=0;i<n;i++){
				cin >> v[i];
			}
			sort(v.begin(),v.end());
			vi sum(n);
			sum[0]=v[0];
			for(ll i=1;i<n;i++){
				sum[i]=sum[i-1]+v[i];
			}
			vi newSum(n);
			newSum[n-1]=v[n-1];
			for(ll i=n-2;i>=0;i--){
				newSum[i]=v[i]+newSum[i+1];
			}
			vi a(n);
			vi b(n);
			a[0]=0;
			b[n-1]=0;
			for(ll i=1;i<n;i++){
				a[i]=(abs(sum[i-1]-(i*v[i])))+a[i-1];
			}
			for(ll i=n-2;i>=0;i--){
				b[i]=(abs(newSum[i+1]-(n-i-1)*v[i]))+b[i+1];
			}

		/*	for(ll i=1;i<n;i++){
				a[i]=a[i]-v[0];
			}
			for(ll i=0;i<n-1;i++){
				b[i]=b[i]-v[n-1];
			}*/
			ll count=b[0];
			for(ll i=0;i<n-1;i++){
				count=min(count,a[i]+b[i+1]);
			}
			cout << count<< endl;
		}

	return 0;
}			