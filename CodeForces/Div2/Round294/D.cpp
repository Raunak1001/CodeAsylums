#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define vi vector<long long int >
#define vvi vector<vector<long long int > >

int main(){


vi v(26,0);
for(ll i=0;i<26;i++){
	cin >> v[i];
}



string s;
cin >>s;
ll sum=0;
ll count=0;
ll temp=0;
ll n = s.length();
for(ll i=0;i<n-1;i++){
	sum=0;
	for(ll j=i+1;j<n;j++){
		//cout << sum<<" ";
		//cout << s[i]<<" "<<s[j]<<endl;
if(s[j]==s[i] && sum==0){
	count++;
}
temp=s[j]-'a';
sum+=v[temp];

	}

}
cout << count<< endl;



	}
