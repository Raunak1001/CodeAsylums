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


		double l,r,x,y,k;
		cin >>l>>r>>x>>y>>k;

		if(k*x>r || k*y<l){
			cout <<"NO"<< endl;
			return 0;
		}


		cout <<"YES"<< endl;
	return 0;
}