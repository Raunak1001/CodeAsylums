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
		//cout <<t<< endl;
		ll p=1;
		while(t--){
			//cout << t<< endl;
			ll a,b,c,g;
			cin >>a>>b>>c;
			cin >>b>>c>>c;
			cin >>c>>g>>g;

			ll mx=0;
			mx=max(mx,abs(a-b));
			mx=max(mx,abs(c-b));
			mx=max(mx,abs(a-c));
				cout << fixed;
				cout << setprecision(6);
				
				cout << "Case #"<<p<<": "<< (double)mx/6.0<< endl;



				p++;
		}



	return 0;
}