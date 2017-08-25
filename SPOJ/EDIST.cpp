#include<bits/stdc++.h>
using namespace std;
#define vi vector<long long int>
#define vvi vector<vector<long long int>  >
#define ll long long int 
#define pr pair<long long int,long long int>
#define mp make_pair
	
int main(){

ll t;
cin >>t;
for(ll q=0;q<t;q++){
	string a;
	string b;
	cin >> a;
	cin >>b;
	if(a.length()>b.length())
{
	swap(a,b);
}
ll n=a.length();
ll m=b.length();
vvi v(n+1,vi(m+1,0));
for(ll i=0;i<=n;i++)
{
	v[i][0]=i;
}
for(ll i=0;i<=m;i++)
{
	v[0][i]=i;
}

for(ll i=1;i<=n;i++){
	for(ll j=1;j<=m;j++){
if(a[i-1]==b[j-1]){
	v[i][j]=min(min(1+v[i][j-1],v[i-1][j-1]),1+v[i-1][j]);
}else{

	v[i][j]=min(min(1+v[i][j-1],1+v[i-1][j-1]),1+v[i-1][j]);

}

	}


}

/*for(ll i=0;i<=n;i++){
	for(ll j=0;j<=m;j++){
cout << v[i][j]<<" ";
	}
	cout << endl;
}*/
cout << v[n][m]<< endl;


}
return 0;

}