#include<bits/stdc++.h>
using namespace std;
#define ll unsigned int 
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
 
ll ans=0;
void myFun(vi &v,ll j){
	if(j<0){
		return ;
	}
 
	/*show(v);
	cout << endl;*/
 
		vi s;
		vi ns;
		ll n=v.size();
		for(ll i=0;i<n;i++){
			if(((v[i] & (1<<j))) >0){
				s.pb(v[i]);
			}else{
				ns.pb(v[i]);
			}
		}
		if(s.size()>2){
			myFun(s,j-1);
		}else if(s.size()==2){
			ans=( s[0]&s[1]);
			return ;
		}else{
			//ans[j]=0;
			myFun(ns,j-1);
		}
return ;
 
}
 
 
int main(){
		/*std::ios::sync_with_stdio(false); 
		cin.tie(NULL);
		cout.tie(NULL);*/
 
		ll n;
		scanf("%lld",&n);
		vi v(n);
		for(ll i=0;i<n;i++){
		scanf("%lld",&v[i]);
			
		}
 
		vi s;
		vi ns;
		for(ll i=0;i<n;i++){
			if(((v[i] & (1<<30))) >0){
				s.pb(v[i]);
			}else{
				ns.pb(v[i]);
			}
		}
		if(s.size()>2){
			myFun(s,29);
		}else if(s.size()==2){
			ans=( s[0]&s[1]);
 
		}else if(ns.size()!=0){
			//ans[31]=0;
			myFun(ns,29);
		}
		
		
		printf("%lld",ans);
 
 
	return 0;
}		