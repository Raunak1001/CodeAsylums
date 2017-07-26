#include<bits/stdc++.h>
using namespace std;
#define vi vector<long long int>
#define vvi vector<vector<long long int>  >
#define ll long long int 
#define pr pair<long long int,long long int>
#define mp make_pair
	
int main(){

ll n;
cin >> n;
vvi v(2*n+1,vi(2*n+1));
for(ll i=2;i<=2*n;i++){
for(ll j=1;j<i;j++){
	ll a;
	cin >>a;
v[i][j]=a;
v[j][i]=a;
}
}

for(ll i=1;i<=2*n;i++){
	for(ll j=1;j<=2*n;j++){
		cout << v[i][j]<<" ";
	}
	cout << endl;
}
cout << endl;

map<ll,ll> m;
vi ans(2*n+1,0);
ll p=0;
while(p<n){
for(ll i=1;i<=2*n;i++){
	if(ans[i]!=0){
		continue;
	}
	ll mx=0;
	ll k=0;
	for(ll j=1;j<=2*n;j++){

if(v[i][j]>mx){
	mx=v[i][j];
	k=j;
	}
	}
	v[i][k]=-1;
	//cout << mx<< endl;	
	if(m[mx]==0){
		m[mx]=i;
	}else {
		//v[i][k]=-1;
		ans[m[mx]]=i;
		ans[i]=m[mx];
	}

}
for(ll i=1;i<=2*n;i++){
	for(ll j=1;j<=2*n;j++){
		cout << v[i][j]<<" ";
	}
	cout << endl;
}
cout << endl;

m.clear();
p++;
}
for(ll i=1;i<=2*n;i++){
	cout << ans[i]<< " ";
}

cout << endl;
}