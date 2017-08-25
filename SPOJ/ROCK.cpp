#include<bits/stdc++.h>
using namespace std;
#define vi vector<long long int>
#define vp vector<pair<long long int,long long int > >
#define vc vector<char>
#define vvi vector<vector<long long int>  >
#define vvvi vector< vvi >
#define vvp vector<vector<pair<long long int,long long int> > >
#define vvc vector<vector<char>  >
#define ll long long int 
#define pr pair<long long int,long long int>
#define mp make_pair		
#define pb push_back

ll myFun(string &s,vvvi &dp,ll i,ll a,ll b){

	ll n=s.size();
	if(i>=n){
	if(b>a){
		return a+b;
	}
		return 0;
	}

	if(dp[i][a][b]!=-1){
		return dp[i][a][b];
	}

	ll count=0;
	if(b>a){
		count=a+b;
	}
	ll temp=0;
if(s[i]=='0'){
temp=max(myFun(s,dp,i+1,a+1,b),myFun(s,dp,i+1,1,0)+count);
}else{
	temp=max(myFun(s,dp,i+1,a,b+1),myFun(s,dp,i+1,0,1)+count);

}
count =max(count,temp);
return dp[i][a][b]=count;

}



int main(){
//std::ios::sync_with_stdio(false); 

ll t;
cin >>t; 	
while(t--){

ll n;
cin >>n;
string s;
cin >>s;
vvvi dp(n,vvi(n+1,vi(n+1,-1)));
cout << myFun(s,dp,0,0,0)<< endl;

}




	return 0;
}