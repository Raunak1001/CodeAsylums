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

void myFun(vvi &v,vi &visited,ll i){

	visited[i]=1;
	for(ll j=0;j<v[i].size();j++){
		if(!visited[v[i][j]]){
			myFun(v,visited,v[i][j]);
		}
	}
return ;

}

bool isValid(vi &visited){

for(ll i=1;i<visited.size();i++){
	if(visited[i]!=1){
		return false;
	}
}

return true;
}



int main(){
	
	ll t;
	cin >>t;
	while(t--){
		ll n;
		cin >> n;
		vvi v(n+1);
		for(ll i=1;i<=n;i++){
			ll a;
			cin>>a;
			for(ll j=0;j<a;j++){
				ll b;
			cin >> b;
			v[b].push_back(i);
			}
		}

	vi visited(n+1,0);

ll count=0;
	for(ll i=1;i<=n;i++){
		myFun(v,visited,i);
		if(isValid(visited)){
			count++;
		}
		for(ll j=0;j<=n;j++){
			visited[j]=0;
		}

	}


cout << count<< endl;

	}


}