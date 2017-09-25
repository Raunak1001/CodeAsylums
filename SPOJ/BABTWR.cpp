#include<bits/stdc++.h>
using namespace std;
#define vi vector<long long int>
#define vp vector<pair<long long int,long long int > >
#define vc vector<char>
#define vvi vector<vector<long long int>  >
#define vvvi vector< vvi >
#define vvp vector<vector<pair<long long int,long long int> > >
#define vvc vector<vector<char>  >
#define ll long long int 
#define pr pair<long long int,long long int>
#define mp make_pair		
#define pb push_back
#define vb vector<bool>
#define vvb vector< vb >
#define vvvb vector< vvb >

ll myFun(vvi &v,vi &a,vi &b,vi &c,ll i,ll x,ll y,ll z){

	ll n=a.size();
	if(i>=n){
		return 0;
	}
	if(v[x][y]!=-1){
		return v[x][y];
	}
ll count=0;
for(ll i=0;i<n;i++){
	if(a[i]<x && b[i]<y)
	count=max(count,myFun(v,a,b,c,0,a[i],b[i],c[i])+c[i]);
	if(b[i]<x && a[i]<y)
	count=max(count,myFun(v,a,b,c,0,b[i],a[i],c[i])+c[i]);
	if(a[i]<x && c[i]<y)
	count=max(count,myFun(v,a,b,c,0,a[i],c[i],b[i])+b[i]);
	if(b[i]<x && c[i]<y)
	count=max(count,myFun(v,a,b,c,0,b[i],c[i],a[i])+a[i]);
	if(c[i]<x && a[i]<y)
	count=max(count,myFun(v,a,b,c,0,c[i],a[i],b[i])+b[i]);
	if(c[i]<x && b[i]<y)
	count=max(count,myFun(v,a,b,c,0,c[i],b[i],a[i])+a[i]);

}
return v[x][y]=count;

}

int main(){
		std::ios::sync_with_stdio(false); 

		while(1){

			ll n;
			cin >>n;
			if(n==0){
				break;
			}
			ll mx=0;
			vi a(n),b(n),c(n);
			for(ll i=0;i<n;i++){
				cin >> a[i]>> b[i]>> c[i];
				ll temp=max(a[i],max(b[i],c[i]));
				mx=max(mx,temp);
			}

			vvi v(mx+2,vi(mx+2,-1));

			cout << myFun(v,a,b,c,0,mx+1,mx+1,mx+1)<< endl;


		}



	return 0;
}