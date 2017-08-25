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

struct Node{
	ll a;
	ll b;
	ll c;
};


ll myFun(vector<Node> &v,ll i,ll curra,ll currb,ll a,ll b,vvvi &dp){

ll n=v.size();
if(curra >=a && currb >=b){
	return 0;
}
if(curra>a)
{
	curra=a;
}
if(currb>b){
	currb=b;
}
if(i>=n){
	return 1000000;
}
if(dp[i][curra][currb]!=-1){
	return dp[i][curra][currb];
}
ll count =min(myFun(v,i+1,curra,currb,a,b,dp),myFun(v,i+1,curra+v[i].a,currb+v[i].b,a,b,dp)+v[i].c);

return dp[i][curra][currb]=count ;
//return count ;

}






int main(){
//std::ios::sync_with_stdio(false);

ll t;
cin >>t;
while(t--){
ll a,b;
cin >>a>>b;
ll n;
cin >>n;
vector<Node> v(n);
vvvi dp(n,vvi(a+1,vi(b+1,-1)));

for(ll i=0;i<n;i++){
cin >> v[i].a;
cin >> v[i].b;
cin >> v[i].c;
}
cout << myFun(v,0,0,0,a,b,dp)<< endl;





}

	return 0;
}