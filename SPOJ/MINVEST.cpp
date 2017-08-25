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
	ll m=1000001;
	int main(){

		ll t;
		cin >>t;
		while(t--){
				vvi v(11,vi(m,0));

			ll n,y;
			cin >>n>>y;
			ll d;
			cin >>d;
			vi a(d);
			vi b(d);
			//cout <<"AS"<< endl;
			for(ll i=0;i<d;i++){
				cin >> a[i];
				a[i]/=1000;
				cin >> b[i];
			}

			for(ll i=1;i<=d;i++){
				for(ll j=1;j<m;j++){
					if(j>=a[i-1]){
						//cout <<v[i][j-a[i-1]]+b[i-1]<<endl;
						//v[i][j]=v[i][j-a[i-1]]+b[i-1];
						v[i][j]=max(v[i-1][j],v[i][j-a[i-1]]+b[i-1]);
					}else{
						v[i][j]=v[i-1][j];
					}
				}
			}

			/*for(ll i=1;i<=d;i++){
				for(ll j=1;j<=1000;j++){
					cout << v[i][j]<<" ";
					}
				cout << endl;
			}*/
			ll newN=n;
			n/=1000;
			ll prof=0;
			ll total=0;
			//cout<<y<<endl;
			while(y--){
				prof=v[d][n];
				newN+=prof;
				n=newN/1000;
			}
			cout << newN<< endl;



		}
		
		return 0;
	}