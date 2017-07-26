#include<bits/stdc++.h>
using namespace std;
#define vi vector<long long int>
#define vvi vector<vector<long long int>  >
#define ll long long int 
#define pr pair<long long int,long long int>
#define mp make_pair
ll mod=1000000009;

int main(){
ll t;

ll n,k;
cin >> n>>k;
vvi v(n+1,vi(k+1,0));
for(ll i=1;i<k+1;i++){
	v[1][i]=1;
}
vvi a(k+1);
for(ll i=1;i<k+1;i++){
for(ll j=1;j<k+1;j++){
	if(j%i==0 || i%j==0){
		a[i].push_back(j);
	}
}

}
for(ll i=2;i<n+1;i++){
for(ll j=1;j<k+1;j++){
	ll sum=0;
   for(ll m=0;m<a[j].size();m++)
{
	sum=sum%mod+(v[i-1][a[j][m]])%mod;
 }
v[i][j]=sum%mod;

 }


}
ll ans=0;
for(ll i=1;i<k+1;i++){
ans=ans%mod+(v[n][i])%mod;
}

cout << ans%mod<< endl;


return 0;

}