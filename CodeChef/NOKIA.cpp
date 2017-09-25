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


ll myFun(ll n,vi &v){
if(n<=0){
	return 0;
}
	//cout << n<< endl;
	if(v[n]!=-1){
		return v[n];
	}
ll count=INT_MAX;
	for(ll i=1;i<=n;i++){
		count=min(count,i+myFun(i-1,v)+myFun(n-i,v)+n+1-i);
	}

	return v[n]=count;


}


int main(){
		std::ios::sync_with_stdio(false); 
		cin.tie(NULL);
		cout.tie(NULL);

		ll t;
		cin >>t;
		vi v(31,-1);
		myFun(30,v);
		while(t--){
			//cout << v[3]<< endl;
			ll p,m;
			cin >>p>>m;
			ll sum=0;
			for(ll i=1;i<=p;i++){
				sum+=1+p+1-i;
			}
			if(sum<=m){
				cout << m-sum<< endl; 
			}else if(v[p]>m){
				cout << -1<< endl;
			}else{
				cout << 0<< endl;
			}





		}


	return 0;
}			