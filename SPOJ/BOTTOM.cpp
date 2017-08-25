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

void myFun(vvi &v,vi &visited,ll i,stack<ll> &s){

	visited[i]=1;
	for(ll j=0;j<v[i].size();j++){
		if(!visited[v[i][j]]){
			myFun(v,visited,v[i][j],s);
		}
	}

	s.push(i);
	return;
}

void myFun2(vvi &v,vi &visited,vi &mid,vi &comp, ll k,ll i){

	comp[i]=k;
	visited[i]=1;
	mid.push_back(i);
	for(ll j=0;j<v[i].size();j++){
		if(!visited[v[i][j]]){
			myFun2(v,visited,mid,comp,k,v[i][j]);
		}
	}

return  ;

}

int main(){

while(1){

ll n,m;
cin >>n;
if(n==0){
	break;
}

cin >>m;
vvi v(n+1);
for(ll i=0;i<m;i++){
	ll a,b;
	cin >>a>>b;
	v[a].push_back(b);
}
stack<ll> s;
//cout <<"sdfas"<<endl;

vi visited(n+1,0);
for(ll i=1;i<=n;i++){
	if(!visited[i]){
		myFun(v,visited,i,s);
		s.push(i);
	}
}
vvi newV(n+1);


for(ll i=1;i<=n;i++){
	for(ll j=0;j<v[i].size();j++){
		newV[v[i][j]].push_back(i);
	}
}

for(ll i=1;i<=n;i++){
	visited[i]=0;
}
vi comp(n+1,-1);
vvi fin;
vi mid;
ll k=0;
while(!s.empty()){
	ll temp=s.top();
	s.pop();
	if(!visited[temp]){
		myFun2(newV,visited,mid,comp,k,temp);
		k++;
		fin.push_back(mid);
		mid.clear();
	}
}
ll c=fin.size();
vi outDegree(c,0);

for(ll i=1;i<=n;i++){
for(ll j=0;j<v[i].size();j++){
	if(comp[i]!=comp[v[i][j]]){
		outDegree[comp[i]]++;
	}
}

}
vi ans;
for(ll i=0;i<c;i++){
	if(outDegree[i]==0){
		for(ll j=0;j<fin[i].size();j++){
			ans.pb(fin[i][j]);
		}
	}
}
sort(ans.begin(),ans.end());
for(ll i=0;i<ans.size();i++){
	cout << ans[i]<<" ";
}
cout << endl;

}
	return 0;
}