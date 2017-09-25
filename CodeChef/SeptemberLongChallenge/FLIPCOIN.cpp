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

		ll n,q;
		cin>>n>>q;
		vi v(n+2,0);
		while(q--){
			ll a,b,c;
			cin >>a>>b>>c;
			if(a==0){

				v[b]++;
				v[c+1]--;
			}else{
				ll count=0;
				rep(i,1,n+1)
				{	
					v[i]+=v[i-1];
					if(i>=b && i<=b && v[i]%2!=0){
						count++;
					}
				}
				cout << count<< endl;
				}


		}


	return 0;
}		