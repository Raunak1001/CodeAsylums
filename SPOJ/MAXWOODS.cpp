#include<bits/stdc++.h>
using namespace std;
#define vi vector<long long int>
#define vc vector<char>
#define vvi vector<vector<long long int>  >
#define vvc vector<vector<char>  >
#define ll long long int 
#define pr pair<long long int,long long int>
#define mp make_pair

ll myFun(ll i,ll j,ll temp,vvi &ans,vvc &v){

if(i<0 || i>=v.size() || j<0 || j>=v[0].size() || v[i][j]=='#'){
	return 0;
}

if(ans[i][j]!=-1){
	return ans[i][j];
}


ll counta,countb=0;

	counta=myFun(i+1,j,(temp==0?1:0),ans,v);
	
if(temp){
	
	countb=myFun(i,j+1,1,ans,v);
	
}
else {
	countb=myFun(i,j-1,0,ans,v);	

}

if(v[i][j]=='T')
ans[i][j]= max(counta,countb)+1;
else
ans[i][j]= max(counta,countb);
return ans[i][j];
}


int main(){

ll t;
cin >> t;
for(ll q=0;q<t;q++){

ll n,m;
cin >>n>>m;
vvc v(n,vc(m));

for(ll i=0;i<n;i++){
	for(ll j=0;j<m;j++){

cin >> v[i][j];

	}
}
vvi ans(n,vi(m,-1));
myFun(0,0,1,ans,v);

if(ans[0][0]!=-1)
cout << ans[0][0]<<endl;
else
	cout <<0<<endl;

}
return 0;

}
	