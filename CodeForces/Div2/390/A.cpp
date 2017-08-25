#include<bits/stdc++.h>
using namespace std;
#define vi vector<long long int>
#define vc vector<char>
#define vvi vector<vector<long long int>  >
#define vvc vector<vector<char>  >
#define ll long long int 
#define pr pair<long long int,long long int>
#define mp make_pair

int main(){

ll n;
cin >>n;
vi v(n);
vi s(n);
for(ll i=0;i<n;i++){
	cin >> v[i];
	if(i!=0){
	s[i]=s[i-1]+v[i];
}else{
	s[i]=v[i];
}
}

if(s[n-1]!=0){
cout << "YES"<< endl;
	cout <<"1"<< endl;
	cout << 1<<" "<<n<< endl;
	//	cout<<i+2<<" "<< n<< endl;
	return 0;
}

for(ll i=n-2;i>=0;i--){
if(s[i]!=0){
	cout << "YES"<< endl;
	cout <<"2"<< endl;
	cout << 1<<" "<<i+1<< endl;
	cout<<i+2<<" "<< n<< endl;
	return 0;
}

}

cout << "NO"<< endl;
return 0;
}