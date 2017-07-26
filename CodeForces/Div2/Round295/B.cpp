	#include<bits/stdc++.h>
	using namespace std;
	#define ll long long int 
	#define vi vector<long long int >
	#define vvi vector<vector<long long int > >

	int main(){
	ll n,m;
	cin >>n>>m;
if(n>m){
	cout << n-m<<endl;
	return 0;
} 

	vvi v(2*m+1);
	for(ll i=1;i<=2*m;i++){
	if(i<=m){
		v[i].push_back(i*2);
	}
	v[i].push_back(i-1);

	}
	vi dis(2*m+1,100000000);
	dis[n]=0;
	queue<ll> q;
	/*for(ll i=1;i<=2*n;i++){
		cout <<"ver"<<i <<" ";
	for(ll j=0;j<v[i].size();j++){
		cout<< v[i][j]<<" ";
	}
	cout << endl;
	}*/
	ll temp2=0;
	q.push(n);
	while(!q.empty()){
		ll temp=q.front();
		q.pop();
		for(ll i=0;i<v[temp].size();i++){
	if(dis[v[temp][i]]>dis[temp]+1)
	{
		dis[v[temp][i]]=dis[temp]+1;
		q.push(v[temp][i]);
	}
	if(v[temp][i]==m){
		temp2=1;
		break;
		}
	}
	if(temp2){
		break;
	}
	}

	cout << dis[m]<<endl;


	}