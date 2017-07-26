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
string s;
cin >>s;
char c[n];
ll count;
ll temp;
if(n%2==0){
	temp=(n/2)-1;
	c[temp]=s[0];
	count=1;
}else{
	temp=n/2;
	c[temp]=s[0];
	count=0;
}
ll k=1;
ll first=0;
for(ll i=1;i<n;i++){
if(count){
c[temp+k]=s[i];
count=0;

}else{
	c[temp-k]=s[i];
count=1;
}
if(first){
	k++;
	first=0;
}else{
	first=1;
}

}
for(ll i=0;i<n;i++){
	cout <<c[i];
}
cout << endl;

}