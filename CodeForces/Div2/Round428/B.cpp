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

		ll n,k;
		cin>>n>>k;
		ll count=n*8;
		ll a;
		for(ll i=0;i<k;i++){
			cin >>a;
			if(a%2==0){
				count-=a;
			}else{
				count-=(a+1);
			}
			if(count<0){
				cout <<"NO"<< endl;
				return 0;
			}
			//cout << count << endl;

		}

		cout <<"YES"<< endl;



	return 0;
}