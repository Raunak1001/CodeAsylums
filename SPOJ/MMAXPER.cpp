#include<bits/stdc++.h>
using namespace std;
#define vi vector<long long int>
#define vc vector<char>
#define vvi vector<vector<long long int>  >
#define vvc vector<vector<char>  >
#define ll long long int 
#define pr pair<long long int,long long int>
#define mp make_pair

ll myFun(vi &l,vi &r,vvi &ans,ll temp,ll height,ll i){
if(i>=l.size()){
	return 0;
}
if(ans[i][temp]!=-1){
	return ans[i][temp];
}

/*if(i==l.size()-1){
 ans[i][temp]=max(r[i]+myFun(l,r,ans,0,l[i],i+1)+abs(l[i]-height)+l[i],l[i]+myFun(l,r,ans,1,r[i],i+1)+abs(r[i]-height)+r[i]);

}*/
else
	 ans[i][temp]=max(r[i]+myFun(l,r,ans,0,l[i],i+1)+abs(l[i]-height),l[i]+myFun(l,r,ans,1,r[i],i+1)+abs(r[i]-height));


return ans[i][temp];

}


int main(){

ll n;
cin >> n;
ll a,b;
vi l(n),r(n);
vvi ans(n,vi(2,-1));
for(ll i=0;i<n;i++){
cin >> a>> b;
l[i]=min(a,b);
r[i]=max(a,b);
}


cout << max(r[0]+myFun(l,r,ans,0,l[0],1),l[0]+myFun(l,r,ans,1,r[0],1))<< endl;

/*for(ll i=0;i<n;i++){
	for(ll j=0;j<2;j++){
		cout << ans[i][j]<<" ";
	}
cout << endl;
}*/





}