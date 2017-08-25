#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define vi vector<long long int >
#define vvi vector<vector<long long int > >

int main(){
ll n,m,k;
cin >>n>>m>>k;
vi a(n+1,0),v(n+1,0);
for(ll i=1;i<=n;i++){
	cin >> v[i];
	a[v[i]]=i;
}
vi op(m);
for(ll i=0;i<m;i++){
	cin >> op[i];
}
ll y;
ll swipe=0;
ll ans=0;
for(ll i=0;i<m;i++){

	swipe=0;
y=a[op[i]];

swipe=y/k;

if(y%k==0){
	swipe--;
}

ans+=swipe+1;
if(y!=1){

		swap(a[v[y]],a[v[y-1]]);
	swap(v[y],v[y-1]);
}


}

cout << ans<<endl;


}
