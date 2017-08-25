#include<bits/stdc++.h>
using namespace std;
#define vi vector<long long int>
#define vp vector<pair<long long int,long long int > >
#define vc vector<char>
#define vvi vector<vector<long long int>  >
#define vvp vector<vector<pair<long long int,long long int> > >
#define vvc vector<vector<char>  >
#define ll long long int 
#define pr pair<long long int,long long int>
#define mp make_pair		
#define pb push_back

int main(){

	ll k;
	cin >>k;
	string s;
	cin >>s;
ll n=s.length();
ll sum=0;
	for(ll i=0;i<n;i++){
	sum+=(s[i]-'0');
}
if(sum>=k){
	cout <<0<< endl;
	return 0;
}
	sort(s.begin(),s.end());


ll count=0;

for(ll i=0;i<n;i++){
	ll temp=s[i]-'0';

	sum=sum+(9-temp);
	count++;
	if(sum>=k){
		cout << count<< endl;
		return 0;
	}

}

return 0;
	
}