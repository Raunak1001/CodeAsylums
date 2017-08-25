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
		cin>>n;
		ll count=0;
		for(int i=1;i<=n;i++){
			if(i<=(n+1)-i){
				count++;
			}else{
				break;
			}
		}



		cout << count-1<<endl;
	return 0;
}