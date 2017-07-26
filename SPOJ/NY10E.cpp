#include<bits/stdc++.h>
using namespace std;
#define vi vector<long long int>
#define vvi vector<vector<long long int>  >
#define ll long long int 
#define pr pair<long long int,long long int>
#define mp make_pair
	

ll myFun(ll digits,ll mx, vvi &v){
if(digits<0){
	return 0;
}
if(digits==0){
	return 1;
}
if(v[digits][mx]!=-1){
return v[digits][mx];
}
ll sum=0;
for(ll i=0;i<=mx;i++){
	sum+=myFun(digits-1,i,v);
}
return v[digits][mx]=sum;


}


int main(){

 ll t;
 cin >>t;
 vvi v(65,vi(10,-1));
 ll sum=0;
myFun(64,9,v);

for(ll q=0;q<t;q++){
ll p,n;
cin >> p>>n;
	cout <<p<<" "<<v[n][9]<< endl;
 }


}