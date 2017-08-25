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
ll temp=0;
ll myFun(ll i, vvi &v, vi &visited){
ll  n =v.size();
if(visited[i]!=-1){
	return visited[i];
}
if(i==n-1){
	temp=1;
	return 1000000;
}

visited[i]=0;
ll ans=-1;
ll temp2=0;
for(ll j=1;j<n;j++){
	if(v[i][j]!=0){
	temp2=1;
		ll count=min(v[i][j],myFun(j,v,visited));
		ans=max(ans,count);
		//cout << j<<" "<<ans<< endl;
	}
}

if(temp2)
return visited[i]=ans;
else
	return -1;

}


int main(){

ll t;
cin >>t;
for(ll q=0;q<t;q++)
{
temp=0;
ll n,m;
cin >> n>> m;
vvi v(n+1,vi(n+1,0));

	for(ll i=0;i<m;i++){
		ll a,b,c;
		cin >>a>>b>>c;
		v[a][b]=max(v[a][b],c);
		v[b][a]=max(v[b][a],c);
	}
	vi visited(n+1,-1);
	/*for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++){
			cout << v[i][j]<<" ";
		}
		cout << endl;

	}*/
ll ans=0;
visited[1]=0;
for(ll i=2	;i<=n;i++){
	if(v[1][i]!=0){
		ll count=min(v[1][i],myFun(i,v,visited));
ans=max(ans,count);
	}
}

/*for(ll i=1;i<=n;i++){
	cout << visited[i]<<" ";
}*/

if(temp)
cout << ans<< endl;
else{
	cout << -1<< endl;	
}
}
	
}