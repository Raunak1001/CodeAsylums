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
		ll l,r;
		cin >>l>>r;
		ll count2=0;
		ll count3=0;
		if(r-l>=4){
			cout <<2<< endl;
			return 0;
		}
		for(int i=l;i<=r;i++){
			if(i%2==0){
				count2++;
			}
			if(i%3==0){
				count3++;
			}
		}
		if(count3>count2){
			cout<<3<< endl;
		}else{
			cout <<2<< endl;
		}

	return 0;
}