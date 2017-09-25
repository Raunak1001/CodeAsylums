#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define pr pair<ll,ll>
#define vi vector<ll>
#define vvi vector< vi >
#define vvvi vector< vvi >
#define vp vector<pr >
#define vvp vector<vp >
#define vc vector<char>
#define vvc vector<vc  >
#define mp make_pair		
#define pb push_back
#define vb vector<bool>
#define vvb vector< vb >
#define vvvb vector< vvb >
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,b,a) for(ll i=b;i>=a;i--)
#define show(a) rep(i,0,a.size()){cout <<a[i]<<" ";}
#define ct(a) cout <<a<<endl


ll findP(ll a,vi &parent){

	if(parent[a]!=a){
		return parent[a]=findP(parent[a],parent);
	}
	return a;
}

void unin(ll a,ll b,vi &parent){
	parent[findP(a,parent)]=parent[findP(b,parent)];
	return;
}


int main(){

	ll n,m;
	cin >>n>>m;
	vi parent(n+1);
	rep(i,1,n+1){
		parent[i]=i;
	}
	ll k=2;
	while(m--){
		ll a,b;
		cin >>a>>b;
		if(findP(a,parent)==findP(b,parent)){
			k--;
		}else{
			unin(a,b,parent);
		}
	}

	vi v(n+1,0);
	for(ll i=1;i<=n;i++){
		ll temp=findP(i,parent);
		v[temp]++;
	}

	ll ans=0;
	vi fin;
	for(ll i=1;i<=n;i++){
		if(v[i]!=0){
			ans+=v[i]*(v[i]-1);
			fin.pb(v[i]);
		}
	}
	if(k<=0){
		cout << ans<< endl;
		return 0;
	}
	ll i=0;
	sort(fin.begin(),fin.end());
	while(i<fin.size() && fin[i]==1){
		i++;
	}
	if(i>=fin.size()){
		cout <<0<< endl;
		return 0;
	}
	ans-=(fin[i]-1)*2;
		fin[i]--;
	if(k==1){
		cout << ans<< endl;
		return 0;
	}
	while(i<fin.size() && fin[i]==1){
		i++;
	}
	if(i>=fin.size()){
		cout <<0<< endl;
		return 0;
	}
	ans-=(fin[i]-1)*2;
		cout << ans<< endl;

	return 0;

}