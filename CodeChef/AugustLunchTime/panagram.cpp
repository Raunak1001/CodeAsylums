#include<bits/stdc++.h>
using namespace std;
#define vi vector<long long int>
#define vp vector<pair<long long int,long long int > >
#define vc vector<char>
#define vvi vector< vi >
#define vvvi vector< vvi >
#define vvp vector<vector<pair<long long int,long long int> > >
#define vvc vector<vector<char>  >
#define ll long long int 
#define pr pair<long long int,long long int>
#define mp make_pair		
#define pb push_back
#define vb vector<bool>
#define vvb vector< vb >
#define vvvb vector< vvb >


int main(){
		std::ios::sync_with_stdio(false); 


		ll t;
		cin >>t;
		while(t--){

			vi a(26,0);
			for(ll i=0;i<26;i++){
				cin >> a[i];
			}
			ll n;
			string s;
			cin >>s;
			n=s.size();
			vb v(26,0);


			for(ll i=0;i<n;i++){
				ll temp=s[i]-'a';
				v[temp]=1;
			}
			ll ans=0;
			for(ll i=0;i<26;i++){
				if(!v[i]){
					ans+=a[i];
				}
			}

				cout << ans<<endl;

		}


	return 0;
}