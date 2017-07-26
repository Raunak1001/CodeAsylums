#include<bits/stdc++.h>
using namespace std;
#define vi vector< int>
#define vc vector<char>
#define vvi vector<vector<int>  >
#define vvc vector<vector<char>  >
#define ll long long int 
#define pr pair<long long int,long long int>
#define mp make_pair

ll myFun(ll i,ll j,int A[][20], vvi &ans){
if(i>=20 || i<0 || j<0 || j>=20){
	return 1000000;
}
if(ans[i][j]!=-1){
	return ans[i][j];
}
if(i==20-1 && j==20-1){
return -(A[20-1][20-1])+1;
}
ll a= myFun(i+1,j,A,ans);
ll b=myFun(i,j+1,A,ans);
a=min(a,b);


if(a<0){
if(A[i][j]>0){
	ans[i][j]=0;
}else if(A[i][j]==0){
ans[i][j]=1;
}else{
	ans[i][j]=1-A[i][j];

}
}else{
if(A[i][j]-a>0){
		ans[i][j]=0;
}else if(A[i][j]-a==0){
	if(A[i][j]==0){
ans[i][j]=1;
	}else{
		ans[i][j]=0;
	}
}else{
	if(a==0){
		ans[i][j]=-(A[i][j]-a)+1;
	}else
	ans[i][j]=-(A[i][j]-a);
}

}

return ans[i][j];

}

int calculateMinimumHP(int A[][20]) {
    
ll n=20;
ll m= 20;
vvi v(n,vi(m,-1));

myFun(0,0,A,v);

for(ll i=0;i<n;i++){
    for(ll j=0;j<m;j++)
    {
        cout <<  v[i][j] <<" ";
    }
    cout << endl;
    
}


cout << v[0][0]<< endl;


    
}

int main(){

int A[20][20];
for(ll i=0;i<20;i++){
	for(ll j=0;j<20;j++){
		cin >> A[i][j];
	}
}

for(ll i=0;i<20;i++){
	for(ll j=0;j<20;j++){
		cout << A[i][j]<<" ";
	}
cout << endl;
}
cout << endl;
cout << calculateMinimumHP(A)<< endl;
	return 0;
}



