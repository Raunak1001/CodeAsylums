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


ll getMax(ll a,ll b){
ll ans=max(b-a,a+b);
return max(ans,a*b);

}


ll getMin(ll a,ll b){
	//cout << a<< " "<<b<< endl;
ll ans=min(b-a,a+b);
return min(ans,a*b);

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
			vi v(n);
			for(ll i=0;i<n;i++){
				cin >> v[i];
			}
			vvi fin(n,vi(2,0));
			fin[0][0]=v[0];
			fin[0][1]=v[0];
			for(ll i=1;i<n;i++){

				fin[i][0]=max(getMax(v[i],fin[i-1][0]),getMax(v[i],fin[i-1][1]));

				fin[i][1]=min(getMin(v[i],fin[i-1][0]),getMin(v[i],fin[i-1][1]));
					
			}

			/*for(ll i=0;i<n;i++){
				cout << fin[i][0]<<" "<< fin[i][1]<< endl;
			}*/

			cout << fin[n-1][1]<< endl;

		}


	return 0;
}			