#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define vi vector<long long int >
#define vvi vector<vector<long long int > >

int main(){

string a,b;
cin >>a>>b;
ll m=b.length();
vi  v(52,0);
for(ll i=0;i<m;i++){
if(b[i]<=90){
	v[b[i]-65]+=1;
}else{
	v[b[i]-71]+=1;
}

}
ll yay=0,whoop=0;
ll n =a.length();
for(ll i=0;i<n;i++){
	if(a[i]<=90){
if(v[a[i]-65]>0){
	v[a[i]-65]-=1;
	a[i]='0';
	yay++;
	}
}else{
if(v[a[i]-71]>0){
	v[a[i]-71]-=1;
	a[i]='0';
	yay++;
	}

}
}

for(ll i=0;i<n;i++){
	if(a[i]=='0'){
		continue;
	}
	if(a[i]<=90){
if(v[a[i]+32-71]>0){
	v[a[i]+32-71]-=1;
	a[i]='0';
	whoop++;
	}
}else{
if(v[a[i]-32-65]>0){
	v[a[i]-32-65]-=1;
	a[i]='0';
	whoop++;
	}

}
}

cout << yay<<" "<<whoop<<endl;





}
