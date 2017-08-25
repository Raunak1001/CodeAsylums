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

bool myFun(pr a,pr b){
	return a.second*a.first < b.second*b.first;
}


int main(){
	
	ll n,a,b;
	cin >>n>>a>>b;
	ll temp=min(a,b);
	b=max(a,b);
	a=temp;
  	
  	vp v;
  	ll c,d;
  	for(int i=0;i<n;i++){
  		cin >>c>>d;
  		temp=min(c,d);
  		d=max(c,d);
  		c=temp;
  		if(c<=a && d<=b){
  			v.pb(mp(c,d));
  		}

  	}

  	//sort(v.begin(),v.end(),myFun);
  	n=v.size();

ll ans=0;
if(n==0){
	cout <<"0"<< endl;
	return 0;
}

/*for(int i=0;i<n;i++){
	cout <<v[i].first<<" "<<v[i].second<< endl;
}*/

for(ll i=0;i<n;i++){
	for(ll j=i+1;j<n;j++){
		if(v[i].first+v[j].first<=a || v[i].second+v[j].second<=b){
			ans=max(ans,v[i].first*v[i].second + v[j].first*v[j].second);
		}
	}
}





cout << ans<< endl;




	return 0;
}