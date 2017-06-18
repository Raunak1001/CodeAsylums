#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define vi vector<long long int >
#define vvi vector<vector<long long int > >




int main(){

ll t;
cin >>t;
for(ll q=0;q<t;q++){
ll n;
cin >> n;
ll sum=0;
vi v(n,0);
for(ll i=0;i<n;i++){
	cin >> v[i];
	sum+=v[i];
}
sort(v.begin(),v.end());
	ll i=0;
ll cur=0;
ll newSum=0;
ll mmax=sum*n;
for(ll i=0;i<n;i++){
	cur+=v[i];
	newSum=cur+(sum-cur)*(n-i-1);
mmax=max(mmax,newSum);
}




cout << mmax<<endl;

}
}