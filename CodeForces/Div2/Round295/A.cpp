#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define vi vector<long long int >
#define vvi vector<vector<long long int > >

int main(){
ll n;
cin >>n;
string s;
cin >>s;
vi v(26,0);
ll temp;
for(ll i=0;i<n;i++)
{
	if(s[i]<97){
temp=s[i]-'A';
	}else{
		temp=s[i]-'a';
	}
	v[temp]=1;
}

for(ll i=0;i<26;i++){
	if(!v[i]){
		cout <<"NO"<<endl;
		return 0;
	}
}
cout <<"YES"<<endl;

}