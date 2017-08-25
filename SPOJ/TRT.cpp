	#include<bits/stdc++.h>
	using namespace std;
	#define vi vector<long long int>
	#define vvi vector<vector<long long int>  >
	#define vvvi vector<vector<vector<long long int>  > >
	#define ll long long int 
	#define pr pair<long long int,long long int>
	#define mp make_pair

	vvi v(2001,vi(2001,-1));

	ll myfun(vi &a,ll age,ll start,ll end){
	if(start>end){
		return 0;
	}
	if(v[start][end]!=-1){
		return v[start][end];
	}
	return v[start][end]=max(a[start]*age+myfun(a,age+1,start+1,end),a[end]*age+myfun(a,age+1,start,end-1));

	}


	int main(){
	ll n;
	cin >>n;
	vi a(n);
	for(ll i=0;i<n;i++)
	{
		cin >> a[i];
	}

	myfun(a,1,0,n-1);

	cout << v[0][n-1]<<endl;

	}
