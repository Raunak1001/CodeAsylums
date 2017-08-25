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


ll s,v1,v2,t1,t2;
cin >>s>>v1>>v2>>t1>>t2;
ll a=(s*v1)+2*t1;
ll b=(s*v2)+2*t2;
if(a>b){
	cout <<"Second"<< endl;
}else if(b>a){
	cout<<"First"<< endl;
}else{
	cout <<"Friendship"<< endl;
}
	
	return 0;
}