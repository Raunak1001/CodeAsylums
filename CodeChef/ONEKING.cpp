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

bool myFun(pr a,pr b){
	if(a.first==b.first){
		return a.second>b.second;
	}
	return a.first<b.first;
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
			vp v(n);
			for(ll i=0;i<n;i++){
				ll a,b;
				cin >>a>>b;
				v[i].first=a;
				v[i].second=b;
			}
			sort(v.begin(),v.end(),myFun);

			ll count=1;
			ll maxEnd=v[0].second;
			ll start=v[0].first;
			for(ll i=1;i<n;i++){
				if(v[i].first>maxEnd){
					start=v[i].first;
					maxEnd=v[i].second;
					count++;
				}else{
					maxEnd=min(v[i].second,maxEnd);
				}
			}

			cout << count << endl;

		}



	return 0;
}			