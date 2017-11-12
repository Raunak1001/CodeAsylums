#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define pr pair<ll,ll>
#define vi vector<ll>
#define vvi vector< vi >
#define vvvi vector< vvi >
#define vp vector<pr >
#define vvp vector<vp >
#define vc vector<char>
#define vvc vector<vc  >
#define mp make_pair		
#define pb push_back
#define vb vector<bool>
#define vvb vector< vb >
#define vvvb vector< vvb >
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,b,a) for(ll i=b;i>=a;i--)
#define show(a) rep(i,0,a.size()){cout <<a[i]<<" ";}
#define ct(a) cout <<a<<endl

ll i=0;

void myFun(string &s,ll col,map<ll,vc> &m){
	//cout <<i<<endl;
	ll n=s.size();
	if(i>=n){
		return ;
	}

	if(s[i]=='.'){
		i++;
		return ;
	}
	m[col].pb(s[i]);
	i+=2;
myFun(s,col-1,m);
while(i<n && s[i]==')'){
	i++;
}
myFun(s,col+1,m);
while(i<n && s[i]==')'){
	i++;
}
return;

}


string printColX (int col, string s){
	
	map<ll,vc> m;
	ll n=s.size();

	if(n==0 || s[0]=='('){
		return "";
	}
	i=0;
	myFun(s,0,m);
	string ans="";
	vc mid=m[col];
	if(mid.size()==0){
		
		return "Hallelujah!";
	}
	for(ll j=0;j<mid.size();j++){
		ans+=mid[j];
	}


sort(ans.begin(),ans.end());


	return ans;
}

int main (){
	int T;
	cin >> T;
	for (int i=0; i<T; i++){
		int col;
		string tree;
		cin >> col >> tree;
		cout << printColX (col, tree) << endl ;
	}
	return 0;
}