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
		std::ios::sync_with_stdio(false); 

		ll n;
		ll a;
		ll sum=0;
		cin >>n;
		ll temp=0;
		for(ll i=0;i<n;i++){
			cin >>a;
			sum+=a;
			if(a%2!=0){
				temp=1;
			}

		}

		if(sum%2!=0){
			cout <<"First"<< endl;
			return 0;
		}

		if(temp){
			cout <<"First"<< endl;
			return 0;
		}

		cout <<"Second"<< endl;


	return 0;
}