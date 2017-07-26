#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define vi vector<long long int >
#define vvi vector<vector<long long int > >


int main(){

ll n,m;
cin >>n>>m;
ll x,y;
cin >>x;
vi b(n,0);
vi g(m,0);
ll a;
for(ll i=0;i<x;i++){
cin >>a;
b[a]=1;
}
cin >>y;	
for(ll i=0;i<y;i++){
cin >>a;
g[a]=1;
}
if(x==0 && y==0){
	cout <<"No"<<endl;
	return 0;
}
ll mmax=max(n,m);
if(mmax!=n){
b.swap(g);
swap(n,m);
}
y=(n-m);

ll q=0;
while(q<2){
ll i=0,j=0;
for(ll j=0;j<m;j++){
	b[j]=b[j] | g[j];
g[j]=b[j];
}
i=m;
j=0;
while(i!=j)
{
if(j>=m){
	j=0;
}
if(i>=n){
i=0;
}
b[i]=b[i] | g[j];
g[j]=b[i];
j++;
i++;
}
q++;
}
for(ll i=0;i<n;i++){
	if(!b[i]){
		cout <<"No"<<endl;
		return 0;
	}
}
for(ll i=0;i<m;i++){
	if(!g[i]){
		cout <<"No"<<endl;
		return 0;
	}
}

cout <<"Yes"<<endl;
return 0;


}
