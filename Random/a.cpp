#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define pr pair<ll,ll>
#define vi vector<ll>
#define vvi vector<vi >
#define vvvi vector<vvi >
#define vs vector<string>
#define vvs vector<vs >
#define vp vector<pr >
#define vvp vector<vp >
#define vc vector<char>
#define vvc vector<vc >
#define mp make_pair		
#define pb push_back
#define vb vector<bool>
#define vvb vector<vb >
#define vvvb vector<vvb >
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,b,a) for(ll i=b;i>=a;i--)
#define show(a) rep(i,0,a.size()){cout <<a[i]<<" ";cout << endl;}
#define ct(a) cout <<a<<endl


void myFun(vvi &v,vb &visited,ll i){
    
    
    for(ll j=0;j<v[i].size();j++){
        if(!visited[v[i][j]]){
            visited[v[i][j]]=1;
            myFun(v,visited,v[i][j]);
        }
    }
    return ;
}

int main(){
		std::ios::sync_with_stdio(false); 
		cin.tie(NULL);
		cout.tie(NULL);
		
		ll t;
		cin >> t;
		while(t--){
		    ll n;
		    cin >> n;
		    vvi v(n);
		    ll e;
		    cin >> e;
		    while(e--){
		        ll a,b;
		        cin >>a>>b;
		        v[a].pb(b);
		        v[b].pb(a);
		    }
		    
		    vb visited(n,0);
		    ll ans=0;
		    for(ll i=0;i<n;i++){
		        if(!visited[i]){
		            myFun(v,visited,i);
		            ans++;
		        }
		    }
		    
		    cout << ans<< endl;
		    
		}
		
		
		
		
		

}