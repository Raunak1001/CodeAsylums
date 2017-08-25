#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define vi vector<long long int >
#define vvi vector<vector<long long int > >

int main(){
ll t;
cin >>t;
for(ll q=0;q<t;q++){
	ll n,m;
	cin >>n;
	vi a(n);
	vi b(n);
	for(ll i=0;i<n;i++){
cin >> a[i];
	}
	for(ll i=0;i<n;i++){
		cin >> b[i];
	}

	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	ll currentCount=0;
	ll maxCount=0;
	ll j=0;
	ll time=0;
	//cout<< b[0]<<endl;
	for(ll i=0;i<n;i++){
		//cout << a[i]<<" "<<b[j]<<endl;
while(j<n && b[j]<a[i]){
	//cout<< a[i]<<endl;
	currentCount--;
	if(currentCount<0){
		currentCount=0;
	}
	j++;
}
if(j>=n){
	break;
}
if(a[i]<=b[j]){
	currentCount++;
}
if(currentCount>maxCount){
	maxCount=currentCount;
	time=a[i];
}

	}

	cout << maxCount<<" "<<time<<endl;
}

return 0;
}
