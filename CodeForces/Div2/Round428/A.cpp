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
		cin >>n>>k;
		vi v(n,0);
		int a;
		
		int b=0;
for(int i=0;i<n;i++){

	cin >>a;
	b=b+a;
	if(b>8){
		k-=8;
		b-=8;
	}else
	{
		k-=b;
		b=0;
	}

	if(k<=0){
		cout <<i+1<< endl;
		return 0;
	}

}
cout <<-1<< endl;
		



	return 0;
}