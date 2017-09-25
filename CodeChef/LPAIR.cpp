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
	return a.first<b.first;
}


int main(){
		std::ios::sync_with_stdio(false); 
		cin.tie(NULL);
		cout.tie(NULL);

		ll n;
		cin >>n;
		vp v(n);
		for(ll i=0;i<n;i++){
			cin >> v[i].first;
			cin >> v[i].second;
		}

		sort(v.begin(),v.end(),myFun);
		set<ll> s;
		ll count=0;
		s.insert(v[0].second);
		for(ll i=1;i<n;i++){
			ll temp=distance(upper_bound(s.begin(),s.end(),v[i].second),s.end());
			s.insert(v[i].second);	
			//cout << temp<< endl;
			count+=temp;
		}

		cout << count << endl;


	return 0;
}			