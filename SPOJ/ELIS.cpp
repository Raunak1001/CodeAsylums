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
vi v(n,0);
for(ll i=0;i<n;i++){
cin >> v[i];
}
ll m=1;

vi ans(n,1);
for(ll i=0;i<n;i++){
	for(ll j=i+1;j<n;j++){
if(v[j]>v[i]){
ans[j]=max(ans[j],ans[i]+1);
m=max(ans[j],m);
	}
}
}
cout << m<< endl;


}