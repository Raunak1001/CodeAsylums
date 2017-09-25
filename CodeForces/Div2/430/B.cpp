#include<bits/stdc++.h>
using namespace std;
#define vi vector<long long int>
#define vp vector<pair<long long int,long long int > >
#define vc vector<char>
#define vvi vector< vi >
#define vvvi vector< vvi >
#define vvp vector<vector<pair<long long int,long long int> > >
#define vvc vector<vector<char>  >
#define ll double
#define pr pair<long long int,long long int>
#define mp make_pair		
#define pb push_back
#define vb vector<bool>
#define vvb vector< vb >
#define vvvb vector< vvb >


int main(){
		std::ios::sync_with_stdio(false); 

		ll r,d;
		cin >>r>>d;
		ll n;
		cin >>n;
		ll count=0;
		ll a,b,c;
		for(ll i=0;i<n;i++){
			cin >>a>>b>>c;
			ll dist=sqrt(a*a+b*b);
			if(dist+c<=r && dist-c>=r-d){
				count++;
			}
		}
		cout << (long long int)count << endl;

	return 0;
}