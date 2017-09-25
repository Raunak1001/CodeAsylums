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
#define mod 1000000007


int main(){
		std::ios::sync_with_stdio(false); 
		cin.tie(NULL);
		cout.tie(NULL);

		ll ax,ay,bx,by,cx,cy;
		cin >>ax>>ay>>bx>>by>>cx>>cy;
		ll m1=(((by-ay)%mod)*((cx-bx)%mod))%mod;
		ll m2=(((cy-by)%mod)*((bx-ax)%mod))%mod;
		if(m1==m2){
			cout <<"NO"<< endl;
		}else{
			cout << "YES"<< endl;
		}


	return 0;
}			