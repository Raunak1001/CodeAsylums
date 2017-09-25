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
#define vvvb vector< vvb >

ll mod=1000000007;
int main(){
		std::ios::sync_with_stdio(false); 

		ll t;
		cin >>t;
		map<ll,ll> v;
			v[2]=1;
			v[3]=1;
			for(ll i=4;i<=1000000;i++){
				v[i]+= v[i-2]%mod + v[i-3]%mod;
				v[i]%=mod;
			}


		while(t--){

			ll n;
			cin >>n;


			cout <<v[n]<< endl;
		}

	return 0;
}