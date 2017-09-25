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

struct Node{
	ll a,b,c,d,e;
};

bool myFun(Node a,Node b){

	return a.a*b.a + a.b*b.b + a.c*b.c + a.d*b.d + a.e*b.e>0;


}


int main(){
		std::ios::sync_with_stdio(false); 
		cin.tie(NULL);
		cout.tie(NULL);


		ll n;
		cin >>n;
		vector<Node> v(n);
		for(ll i=0;i<n;i++){
			cin >>v[i].a>>v[i].b>>v[i].c>>v[i].d>>v[i].e;

		}	
		vi ans;
		ll k=0;
		for(ll i=0;i<n;i++){
			for(ll j=i+1;j<n;j++){
				if(myFun(v[i],v[j])){
				k++;
				ans.pb(i);
				break;	
				}
			}
		}

		cout <<k<< endl;
		for(ll i=0;i<k;i++){
			cout << ans[i]<<endl;
		}



	return 0;
}			