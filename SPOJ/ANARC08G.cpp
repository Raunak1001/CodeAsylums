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
		ll k=1;
		while(1){

			ll n;
			cin >> n;
			if(n==0){
				break;
			}
			ll sum=0;
			vvi v(n+1,vi(n+1,0));
			for(ll i=1;i<=n;i++){
				for(ll j=1;j<=n;j++){
					cin >> v[i][j];
					sum+=v[i][j];
				}
			}
			cout <<k<<". "<<sum<<" ";
			ll count=0;
			sum=0;
			for(ll i=1;i<=n;i++){	
				sum=0;
				for(ll j=1;j<=n;j++){
					sum+=(v[i][j]-v[j][i]);
				}
				if(sum>0){
					count+=sum;
				}
			}
			cout << count<< endl;	
			k++	;

		}

	return 0;
}			