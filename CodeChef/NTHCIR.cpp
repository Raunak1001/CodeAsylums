#include<bits/stdc++.h>
using namespace std;
#define ll double 
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

ll myFun(ll i,map<ll,ll> &m){

	if(m.find(i)==m.end()){
		m[i]=myFun(i-1,m);
	}
	ll r1=m[2];
	ll r2=m[i];
	ll temp=sqrt((r1+r2)*(r1+r2) + 4.0*r1*r2)-(r1+r2);
	temp/=2.0;
	return temp;

}

int main(){
		std::ios::sync_with_stdio(false); 
		cin.tie(NULL);
		cout.tie(NULL);

		ll t;
		cin >>t;
		long long int n0,m,p,b;
		cin >>n0>>p>>m>>b;
		ll r1,r2,r3,r4;
		map<double,double> my;
		cin >>r1>>r2>>r3>>r4;
		my[1]=r1;
		my[2]=r2;
		my[3]=r3;
		my[4]=r4;
		ll n;
		while(t--){
			n= ((n0%m)*(p%m))%m+b;
			n0=n;

			my[n]=myFun(n-1,my);
			cout << fixed;
			cout<<setprecision(6);
			cout << my[n]<< endl;

		}




	return 0;
}		