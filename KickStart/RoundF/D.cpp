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


vi v(10001,0);
int main(){
		std::ios::sync_with_stdio(false); 
		cin.tie(NULL);
		cout.tie(NULL);

		ll t;
		cin >> t;
		//cout <<t << endl;
		
		v[1]=1;
		v[2]=2;
		v[3]=3;

	for(ll i=4;i<=10000;i++){
			ll temp=sqrt(i);
			ll ans=INT_MAX;
			//cout << temp<< endl;
			for(ll j=temp;j>=1;j--){
			    ll b=i-(j*j);
				ans=min(ans,v[b]+1);
				if(ans==1){
					break;
				}
			}
			v[i]=ans;
		}
		for(ll q=1;q<=t;q++){
			ll n;
			cin >> n;

			cout <<"Case #"<<q<<": "<< v[n]<< endl;


		}


	return 0;
}			