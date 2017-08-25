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
	cin >>n;
	vi v(6);
	 v[0]=1;
	 v[1]=3;
	 for(ll i=2;i<6;i++){
	 	v[i]=v[i-1]-v[i-2];
	 }
	 vi sum(6);
	 sum[0]=v[0];
	 for(ll i=1;i<6;i++){
	 	sum[i]=sum[i-1]+v[i];
	 }
n%=6;
if(n==0){	
	cout << 0<<endl;
}else{
	cout << sum[n-1]<<endl;
}

}

return 0;
}
