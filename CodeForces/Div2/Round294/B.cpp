#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define vi vector<long long int >
#define vvi vector<vector<long long int > >


int main(){

ll n; 
cin >>n;
vi v(n);
vi a(n-1,0);
vi b(n-2,0);


for(ll i=0;i<n;i++){
cin >> v[i];
}

for(ll i=0;i<n-1;i++){
cin >> a[i];
}

sort(v.begin(), v.end());
int temp=0;
sort(a.begin(), a.end());

for(ll i=0;i<n-1;i++){
	if(v[i]!=a[i]){
cout << v[i]<< endl;
temp=1;
break;
	}
}
if(!temp){
	cout << v[n-1]<< endl;
}

for(ll i=0;i<n-2;i++){
cin >> b[i];
}

sort(b.begin(),b.end());
temp=0;

for(ll i=0;i<n-2;i++){
	if(a[i]!=b[i]){
cout << a[i]<< endl;
temp=1;
break;
	}
}
if(!temp){
	cout << a[n-2]<< endl;
}

return 0;




}