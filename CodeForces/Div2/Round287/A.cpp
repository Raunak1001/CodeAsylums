#include<iostream>
#include<vector>
using namespace std;
#define ll long long 
#define vi vector<long long int >
#define vvi vector<vector<long long int> >

int main(){
 ll n,k;

 cin >>n>>k;
 vi a(n);
vvi v(n+1,vi(k+1,0));
 for(ll i =0;i<n;i++){
cin >> a[i];
 }

 for(ll i=1;i<=n;i++){
for(ll j=1;j<=k;j++){
	if(j>=a[i-1]){
v[i][j]=max(1+v[i-1][j-a[i-1]],max(v[i-1][j],v[i][j-1]));

	}else{

		v[i][j]=max(v[i-1][j],v[i][j-1]);
	}
}

 }
//cout <<v[n][k]<<endl;

vi g;
ll sum=0;
ll j=k;
ll temp=0;
for(ll i=n;i>0;i--){
while(j>0 && v[i][j]==v[i][j-1] && v[i][j]!=0)
{
	j--;
}
if(j==0 || v[i][j]>v[i-1][j]){
	g.push_back(a[i-1]);
	sum+=a[i-1];
}
if(j>0 && v[i][j]==v[i-1][j]){
	temp=a[i-1];
}


}
cout << sum<< endl;	
if(sum<k){
	g.push_back(temp);
}

//cout << endl;
cout << g.size()<<endl;
for(ll i=0;i<g.size();i++)
{

cout << g[i]<<" ";



}

/*for(int i=1;i<=n;i++){

	for(int j=1;j<=k;j++){
		cout << v[i][j]<<" ";
	}
	cout << endl;
}*/


}

