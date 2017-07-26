#include<iostream>
#include<vector>
using namespace std;
#define ll long long 
#define vvi vector<vector<long long> >

bool check(vvi &v,ll i,ll j, ll n, ll m){

if(i<0 || i>=n ||j<0 || j>=m || v[i][j]!=-1){
	return false;
}
return true;
}


bool checkPixel(ll i,ll j,vvi &v,ll n,ll m){

if(check(v,i,j-1,n,m) && check(v,i-1,j,n,m) && check(v,i-1,j-1,n,m)){
	return true;
}else if(check(v,i,j+1,n,m) && check(v,i-1,j,n,m) &&check(v,i-1,j+1,n,m))
{
	return true;
}else if(check(v,i,j-1,n,m) && check(v,i+1,j,n,m) && check(v,i+1,j-1,n,m))
{
	return true;
}else if(check(v,i,j+1,n,m) && check(v,i+1,j,n,m) && check(v,i+1,j+1,n,m)){
	return true;
}

return false;
}


int main(){

ll n,m,k;
cin >>n>>m>>k;
ll a,b;
int temp=0;
vvi v(n,vector<ll>(m,0));
ll i=0;
for( i=0;i<k;i++){
cin >>a>>b;
v[a-1][b-1]=-1;
if(checkPixel(a-1,b-1,v,n,m)){
	
	temp=1;
	break;
}

}
if(temp){
cout<<i+1<<endl;
}else
cout <<0<< endl;

}
