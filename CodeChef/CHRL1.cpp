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

ll myFun(vp &v,ll i,ll k){

if(k==0){
	return 0;
}
ll n=v.size();
if(i>=n){
	return 0;
}

ll count=myFun(v,i+1,k);
if(k-v[i].first>=0){
	count=max(myFun(v,i+1,k-v[i].first)+v[i].second,count);
}
return count;

}

int main(){
		std::ios::sync_with_stdio(false); 
		cin.tie(NULL);
		cout.tie(NULL);

		ll t;
		cin>>t;
		while(t--){
			 ll n,k;
			 cin >> n>>k;

			 vp v(n);
			 for(ll i=0;i<n;i++){
			 	cin >> v[i].first;
			 	cin >> v[i].second;
			 }	

			 ll  count=0;
			 count=myFun(v,1,k);
			 if(v[0].first<=k){
			 	count=max(myFun(v,1,k-v[0].first)+v[0].second,count);
			 }
			 cout << count << endl;



		}


	return 0;
}			