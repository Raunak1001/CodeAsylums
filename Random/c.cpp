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

		ll n,m,k;
		cin >>n>>m>>k;
		vvi v(n,vi (m));
		for(ll i=0;i<n;i++){
			for(ll j=0;j<m;j++){
				cin >> v[i][j];
			}
		}

		ll ans=0;
		ll a=0;
		if(n==1){
			for(ll j=0;j<m;j++){
				ans+=v[0][j];
			}
		
		cout << ans<<" "<<a<<endl;
		return 0;
	}

		for(ll j=0;j<m;j++){
			ll count=0;
			ll mx=0;
			for(ll i=n-2;i>=0;i--){
				if(v[i][j]==1)
				v[i][j]+=v[i+1][j];
				mx=max(mx,v[i][j]);
			}
			ll temp=min(k,mx);
			for(ll i=0;i<n;i++){
				if(v[i][j]>=temp){
					ans+=temp;
					a+=count;
					break;
				}else if(v[i][j]==1){
					count++;
				}
			}
			//cout << ans<< endl;
		}

		/*for(ll i=0;i<n;i++){
			for(ll j=0;j<m;j++){
				cout << v[i][j]<<" ";
			}
			cout << endl;
		}*/

		cout << ans<<" "<< a<< endl;

	return 0;
}			