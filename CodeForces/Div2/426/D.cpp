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

ll myFun(vi &v,ll start,ll x, vvi &fin){

	ll n=v.size();
	if(x==0 && start==n){
		return 0;
	}
	if(x<0 || start>=n){
		return 100000;
	}

	if(fin[start][x]!=-1){
		return fin[start][x];
	}
	ll a=100000;
	ll distinct=0;
	map<int,int> m;
	for(ll i=start;i<n;i++){
		if(m[v[i]]==0){
			distinct++;
			m[v[i]]=1;
		}

		a=min(a,1+myFun(v,i+1,x-distinct,fin));
	}
	return fin[start][x]=a;

}


ll getCont(vi &v,ll x){

	ll n=v.size();
	vvi fin(n,vi(x+1,-1));
	ll a=100000;
	ll distinct=0;
	map<int,int>  m;
	for(ll i=0;i<n;i++){
		if(m[v[i]]==0){
			distinct++;
			m[v[i]]=1;
		}

		a=min(a,1+myFun(v,i+1,x-distinct,fin));
	}
return a;

}

int main(){

	ll n,k;
	cin >>n>>k;
	vi v(n);
	map<ll,ll> m;
	ll low=0;
	for(ll i=0;i<n;i++){
		cin >>v[i];
		if(m[v[i]]==0){
			low++;
			m[v[i]]=1;
		}
	}

	ll high=n;
	if(k==1){
		cout <<low<< endl;
		return 0;
	}

	while(low<high){

		//cout <<low<<" "<<high<< endl;
		ll mid=low+(high-low)/2;
		if(low==mid){
			ll q=getCont(v,high);
			if(q==k){
				low=high;
			}
break;
		}
		ll a=getCont(v,mid);
		if(a<=k){
			low=mid;
		}else{
			high=mid;
		}
	}

	cout << low<< endl;

	
	return 0;
}