#include<bits/stdc++.h>
using namespace std;
#define vi vector<long long int>
#define vvi vector<vector<long long int>  >
#define ll long long int 
#define pr pair<long long int,long long int>
#define mp make_pair
	
int main(){

char temp[1001];
string s;
while(scanf("%1000s",temp) !=EOF){
	s=temp;
//cout << s<< endl;
if(s.length()==1){
	cout << 0<< endl;
	continue;
}
ll n= s.length();
for(ll i=0;i<n;i++){
if(s[i]<97){
	s[i]=1;
}else{
	s[i]=0;
}
}
ll count=0;
string a=s;
if(s[0]!=0){
	s[0]=0;
	count++;
}
for(ll i=1;i<n;i++){
if(s[i-1]==s[i]){
	count++;
	s[i-1]==1?s[i]=0:s[i]=1;
}
}
ll ans=count;
count=0;
if(a[0]!=1){
	a[0]=1;
	count++;
}
for(ll i=1;i<n;i++){
if(a[i-1]==a[i]){
	count++;
	a[i-1]==1?a[i]=0:a[i]=1;
}
}
ans=min(ans,count);


cout << ans<< endl;
}

return 0;
}