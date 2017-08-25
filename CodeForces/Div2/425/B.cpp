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
	vi v(26,0);
	ll n,m;
bool myFun(string &a,string &s,ll i,ll j){


if(i>=n && j>=m){
	return true;
}
if(j>=m){
	return false;
}
if(i>=n){
	while(j<m){
		if(s[j]!='*'){
			return false;
		}
		j++;
	}
	return true;
}

if(a[i]==s[j]){
	//cout << i<<" "<<j<< endl;
	return myFun(a,s,i+1,j+1);
}
if(s[j]=='?'){
	ll temp=a[i]-'a';
	if(v[temp]){
		return myFun(a,s,i+1,j+1);
	}
	return false;

}

if(s[j]=='*'){
	ll temp=a[i]-'a';
	if(v[temp]){
		return myFun(a,s,i,j+1);
	}else{
		return (myFun(a,s,i+1,j+1) || myFun(a,s,i,j+1)) || myFun(a,s,i+1,j);
	}
	//return false;

}
return false;

}


int main(){
	
	string s;
	cin >>s;
	for(ll i=0;i<s.length();i++){
		ll temp=s[i]-'a';
		v[temp]=1;
	}
	cin >>s;
	ll k;
	cin >> k;
	//	cout << k<< endl;
	for(ll i=0;i<k;i++){
		string a;
		cin >>a;

		n=a.length();
		m=s.length();


		if(myFun(a,s,0,0)){
			cout << "YES"<< endl;
		}else{
			cout <<"NO"<< endl;
		}


	}




	return 0;
}