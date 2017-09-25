#include<bits/stdc++.h>
using namespace std;
#define vi vector<long long int>
#define vp vector<pair<long long int,long long int > >
#define vc vector<char>
#define vvi vector<vector<long long int>  >
#define vvp vector<vector<pair<long long int,long long int> > >
#define vvc vector<vector<char>  >
#define ll long long int 
#define pr pair<long long int,long long int>
#define mp make_pair		
#define pb push_back
#define vb vector<bool>
#define vvb vector< vb >



int main(){
		std::ios::sync_with_stdio(false); 

	ll n;
	cin >>n;
	vvi v(n+1,vi(n,0));
	vi m(n+1,0);

	for(ll i=0;i<n-1;i++){
		ll p,q;
		cin >>p>>q;
		v[p].pb(q);
		v[q].pb(p);
		m[p]++;
		m[q]++;
			
	}

	ll count=0;
	set<pr > s;
	for(ll i=1;i<=n;i++){
		pq.insert(mp(m[i],i));
	}
	ll temp=0;
	set<ll> ::iterator it;
	while(s.size()!=0){
		it=s.begin();
		if(temp==n-1){
			break;
		}
		for(ll i=0;i<v[(*it)].size();i++){
			ll f=(*temp);
			temp++;
			set<ll> :: iterator newIt=s.find(v[(*it)][i]);
			//newIt++;
			s.erase(newIt);
			s.insert(mp(f,v[(*it)][i]));

		}
		count++;


	}


	cout << count << endl;


	return 0;
}