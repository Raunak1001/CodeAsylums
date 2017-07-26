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

int main(){
	
	ll n;
	cin >>n;
	ll k;
	cin >>k;
	if(k==0){
		cout <<"NO"<< endl;
		return 0;
	}
	ll a=n/k;
	if(a%2==0){
				cout <<"NO"<< endl;
	}else{
		cout <<"YES"<< endl;
	}

	return 0;
}