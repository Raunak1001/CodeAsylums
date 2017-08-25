#include<bits/stdc++.h>
using namespace std;
#define vi vector<long long int>
#define vvi vector<vector<long long int>  >
#define ll long long int 
#define pr pair<long long int,long long int>
#define mp make_pair

int main(){


ll t;
cin >> t;
for(ll q=0;q<t;q++){
	ll ans=0;
ll w,n;
cin >> w>>n;
vi a(n),b(n);
for(ll i=0;i<n;i++){
	cin >> a[i]>>b[i];
}
vvi v(n+1,vi(w+1,0));
for(ll i=1;i<n+1;i++){
	for(ll j=1;j<w+1;j++){
if(a[i-1]<=j){
	v[i][j]=max(b[i-1]+v[i-1][j-a[i-1]],v[i-1][j]);
	ans=max(ans,v[i][j]);
}else{
	v[i][j]=v[i-1][j];
}

	}


}
/*for(ll i=1;i<n+1;i++){
	for(ll j=1;j<w+1;j++){
cout << v[i][j]<<" ";
	}
	cout << endl;
}*/



cout <<"Hey stupid robber, you can get " <<ans<<"."<<endl;

}

}
