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
#define vb vector<bool>

double myFun(vvi &v,vb &visited, ll j){

visited[j]=1;
double count=0.0;
double k=0.0;
for(int i=0;i<v[j].size();i++){
	if(!visited[v[j][i]]){
	count+=myFun(v,visited,v[j][i]);
	k++;
	}
}
visited[j]=0;
double ans=0.0 ;
if(k!=0)
ans=(count+k)/k ;
return ans;

}


int main(){
		std::ios::sync_with_stdio(false); 

		ll n;
		cin >>n;
		vvi v(n+1);
ll a,b;
for(int i=0;i<n;i++){
	cin >>a>>b;
	v[a].pb(b);
	v[b].pb(a);
}

vb visited(n+1,0);

visited[1]=1;

double count=0.0;
double k=0.0;
visited[1]=1;
for(int i=0;i<v[1].size();i++){
	if(!visited[v[1][i]]){
	count+=myFun(v,visited,v[1][i]);
	k++;
	}
}
double ans=0.0;
if(k!=0)
ans=(count+k)/k ;
cout << fixed;
cout << setprecision(6);
cout <<ans<<  endl;


	return 0;
}