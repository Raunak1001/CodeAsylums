#include<bits/stdc++.h>
using namespace std;
#define vi vector<long long int>
#define vp vector<pair<long long int,long long int > >
#define vc vector<char>
#define vvi vector< vi >
#define vvvi vector< vvi >
#define vvp vector<vector<pair<long long int,long long int> > >
#define vvc vector<vector<char>  >
#define ll long long int 
#define pr pair<long long int,long long int>
#define mp make_pair		
#define pb push_back
#define vb vector<bool>
#define vvb vector< vb >
#define vvvb vector< vvb >
ll n=100000;
vvc v(n+1,vc(2,'c'));
char myFun(ll i,ll temp,ll l,ll k){
//cout <<i<<endl;
if(i==n+1){
	if(temp){
		return 'a';
	}
	return 'b';
}
if(i>n){
	return 'c';
}

if(v[i][0]!='c'){
	return v[i][0];
}
char c=myFun(i+1,!temp,l,k);
char h;
if(temp){
	h='b';
}else{

	h='a';
}

if(c==h){
	return v[i][0]=c;
}
c=myFun(i+l,!temp,l,k);
if(c==h){
	return v[i][0]=c;
}
c=myFun(i+k,!temp,l,k);
if(c==h){
	return v[i][0]=c;
}
if(temp){
	return v[i][0]='a';
}
return v[i][0]='b';


}


int main(){
		std::ios::sync_with_stdio(false); 

		ll k,l;
		cin >>k>>l;
		

		myFun(1,0,l,k);
		//cout <<"Fas"<< endl;
		ll m;
		cin >> m;
		string s="";
		while(m--){
			ll a;
			cin >>a;
			if(v[n-a+1][0]=='a'){
				s+='A';
			}else{
				s+='B';
			}
		}
		cout << s<< endl;

	return 0;
}