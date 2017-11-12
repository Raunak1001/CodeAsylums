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

struct Node
{
	ll a,b,c;
	Node(ll x,ll y,ll z):a(x),b(y),c(z){}
};


bool sortFun(Node a,Node b){
	return a.c<b.c;
}

ll find(ll a,vi &parent){

	if(parent[a]!=a){
		return parent[a]=find(parent[a],parent);
	}
	return parent[a];

}

void unin(ll a,ll b, vi &parent)
{

parent[find(a,parent)]=parent[find(b,parent)];
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
			vector<Node> v;

			for(ll i=1;i<=n;i++){
				string s;
				cin >> s;
				ll m;
				cin >> m;
				for(ll j=0;j<m;j++){
					ll a,b;
					cin >> a>> b;
					v.pb(Node(i,a,b));
				}

			}
				sort(v.begin(),v.end(),sortFun);
				vi parent(n+1);
				for(ll i=1;i<=n;i++){
					parent[i]=i;			
				}

			
			ll ans=0;
			for(ll i=0;i<v.size();i++){

				Node a=v[i];
				ll b=find(a.a,parent);
				ll c=find(a.b,parent);
				if(b!=c){
					ans+=a.c;
					unin(b,c,parent);
				}

			}

			cout << ans<< endl;

		}

	return 0;
}			