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

ll n,m;
scanf("%lld",&n);
scanf("%lld",&m);
char a[n];
char b[m];
scanf("%s",a);
scanf("%s",b);
vvi v(m);
ll count=0;
ll mini=0;
ll p=1000000;
for(ll i=0;i<m-n+1;i++){
count=0;
for(ll j=0;j<n;j++){
if(b[i+j]!=a[j]){
	count++;
	v[i].push_back(j);
}
}
if(p>count){
	p=count;
	mini=i;
}

}
cout << p<< endl;
for(ll i=0;i<v[mini].size();i++){
	cout << v[mini][i]+1<<" ";
}
cout << endl;
	
}