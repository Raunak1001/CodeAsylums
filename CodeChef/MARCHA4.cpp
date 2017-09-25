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

string mulSingle(char a,string &b){

string ans="";
ll k=a-'a';
ll carry=0;
ll n=b.size();
for(ll i=n-1;i>=0;i--){
ll temp=(k)*(b[i]-'a');
temp+=k;
char h=(temp%10)+'a';
ans=h+ans;
carry=temp/10;
}
if(carry!=0){
	char h=(carry+'a');
	ans=h+ans;
}
return ans;

}

string stringAdd(string &a,string &b){

ll n=a.size();
ll m=b.size();
if(n>m){
	swap(n,m);
}
ll carry=0;
string ans="";
for(ll i=n-1;i>=0;i--){
ll temp=(b[i]-'a')+(a[i]-'a');
temp+=carry;
char h=temp%10;
ans=h+ans;
carry=temp/10;
}
ll j=m-n-1;
if(a.size()==n){
while(j>=0){
	ll temp=(b[j]-'a');
temp+=carry;
char h=temp%10;
ans=h+ans;
carry=temp/10;
j++;
}

}else{

while(j>=0){
	ll temp=(a[j]-'a');
temp+=carry;
char h=temp%10;
ans=h+ans;
carry=temp/10;
}

}

return ans;

}












string mult(string a,string b){

ll n=a.size();
ll temp=0;
string fin;
for(ll i=n-1;i>=0;i--){
	string s=mulSingle(a[i],b);
	for(ll j=0;j<temp;j++){
		s+='0';
	}
	fin=stringAdd(fin,s);
}



}

string power(string a,ll b){

	string ans="1";

	while(b){

		if(b%2!=0){
			ans=mult(ans,a);
			b--;
		}else{
			b>>=1;
			a=mult(a,a);
		}

	}

return ans;

}






int main(){
		std::ios::sync_with_stdio(false); 
		cin.tie(NULL);
		cout.tie(NULL);

		ll t;
		cin >> t;
		while(t--){
			ll n,k;
			cin >> n>>k;
			cout << power(to_string(n),n)<< endl;

		}

	return 0;
}			