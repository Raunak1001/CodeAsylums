#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define vi vector<double >
#define vvi vector<vector<double > >

int main(){
double n,p,t;
cin >>n>>p>>t;
double ans=0;
if(n>t){
	n=t;
}
vvi v(n+1,vi(t+1,0));
v[0][0]=1;
for(ll i=1;i<=n;i++){
for(ll j=i;j<=t;j++)
{
	if(i==j){
		v[i][j]=v[i-1][j-1]*p;
ans+=v[i][j];
	}
	else{
v[i][j]=v[i-1][j-1]*p+v[i][j-1]*(1-p);
ans+=v[i][j];
	}
}
}
/*for(ll i=1;i<=n;i++){
for(ll j=i;j<=t;j++)
{
cout << v[i][j]<<" ";

}
cout << endl;
}
*/
/*if(t<=n){
cout << v[t][t]<<endl;
}
else{
	cout <<v[n][t]<<endl;
}*/
cout << std::setprecision(20)<<ans<<endl;
}
