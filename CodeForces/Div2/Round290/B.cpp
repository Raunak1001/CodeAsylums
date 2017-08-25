	#include<bits/stdc++.h>
	using namespace std;


	bool myfun(long long i,int j,int parentx,int parenty,vector<vector<int> > &a,vector<string> &v)
	{
	if(i<0 || j<0 || i>=a.size() || j>=a[0].size() || v[parentx][parenty]!=v[i][j]){
		return false;
	}
	if(a[i][j]!=0){
		//cout <<parentx<<" "<<parenty<<" "<<i<<" "<<j;
		return true;
	}
	a[i][j]=1;
	if(i-1!=parentx || j!=parenty){
	if(myfun(i-1,j,i,j,a,v)){
		return true;
	}
	}

	if(i+1!=parentx || j!=parenty){
	if(myfun(i+1,j,i,j,a,v)){
		return true;
	}
	}
	if(i!=parentx || j-1!=parenty){
	if(myfun(i,j-1,i,j,a,v)){
		return true;
	}
	}
	if(i!=parentx || j+1!=parenty){
	if(myfun(i,j+1,i,j,a,v)){
		return true;
	}
	}

	return false;



	}

	int main(){
	long long int n,m;
	cin >>n>>m;
	std::vector<string> v(n);
	vector<vector<int> > a(n,vector<int>(m,0));
	for(long long int i=0;i<n;i++){
		cin >> v[i];
	}

	long long int parentx=0;
	long long  int parenty=0;
	for(long long int i=0;i<n;i++){
		for(long long int j=0;j<m;j++){
			parentx=i;
			parenty=j;
			if(a[parentx][parenty]==0){
			if(myfun(parentx-1,parenty,parentx,parenty,a,v) || myfun(parentx,parenty-1,parentx,parenty,a,v) ||myfun(parentx+1,parenty,parentx,parenty,a,v) ||myfun(parentx,parenty+1,parentx,parenty,a,v))
	{
		cout <<"Yes"<<endl;
		return 0;
	}
			}
		}
	}
	cout <<"No"<< endl;
	}		