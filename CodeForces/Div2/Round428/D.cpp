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

ll GCD(ll a,ll b){

	if(a>b){
		swap(a,b);
	}

	if(a==0){
		return b;
	}
	return GCD(b%a,a);
}


int main(){
		std::ios::sync_with_stdio(false); 


		ll n;
		cin >>n;
		vi v(n,0);
		for(ll i=0;i<n;i++){
			cin >> v[i];
		}

		ll sum=0;
		ll result;
		for(ll i=0;i<n;i++){
			result=v[i];
			for(ll j=i;j<n;j++){
				result=GCD(result,v[j]);
				if(result>1){
					sum+=(j-i+1)*result;
				}
			}
		}

		cout << sum<< endl;




	return 0;
}