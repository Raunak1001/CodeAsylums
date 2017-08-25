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
		//string s;
		if(n==0){
			cout <<0<< endl;
			return 0;
		}
		char a;
		ll mx=0;
		ll current=0;
		a=getchar();
		for(ll i=0;i<n;i++){
			a=getchar();
			//cout <<a<< endl;
			if(a==' '){
				mx=max(current,mx);
				current=0;
			}else if(a<95){
				current++;
				//cout <<"asfasdfsa"<< endl;
			}

		}

		mx=max(mx,current);
		printf("%lld\n", mx);

		/*for(ll i=0;i<n;i++){
			cout <<s[i];
		}*/

		

	
	return 0;
}