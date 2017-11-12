#include<bits/stdc++.h>
using namespace std;
#define vi vector<long long int>
#define vp vector<pair<long long int,long long int > >
#define vc vector<char>
#define vvi vector<vector<long long int>  >
#define vvp vector<vector<pair<long long int,long long int> > >
#define vvc vector<vector<char>  >
#define vb vector<bool>
#define ll long long int 
#define pr pair<long long int,long long int>
#define mp make_pair		
#define pb push_back
ll temp=-1;

void myFun(vvp &v,vb &visited,ll i,ll speed){

	ll n=visited.size()-1;

	if(i==n){
		temp=max(temp,speed);
		return;
	}

	for(ll j=0;j<v[i].size();j++){
		if(!visited[v[i][j].first]){
			visited[v[i][j].first]=1;
			myFun(v,visited,v[i][j].first,min(speed,v[i][j].second));
			visited[v[i][j].first]=0;
		}

	}
	return ;

}




int main(){
std::ios::sync_with_stdio(false); 
		cin.tie(NULL);
		cout.tie(NULL);

ll t;
cin >>t;
for(ll q=0;q<t;q++)
{
temp=0;
ll n,m;
cin >> n>> m;
vvp v(n+1);

	for(ll i=0;i<m;i++){
	 	ll a,b,c;
	 	cin >>a>>b>>c;
	 	v[a].pb(mp(b,c));
	 	v[b].pb(mp(a,c));
	}

	vb visited(n+1,0);
	
ll ans=0;
visited[1]=1;
myFun(v,visited,1,INT_MAX);




cout << temp<< endl;
}
	
}