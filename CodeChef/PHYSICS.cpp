#include<bits/stdc++.h>
using namespace std;
#define ll int 
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



int main(){
		std::ios::sync_with_stdio(false); 
		cin.tie(NULL);
		cout.tie(NULL);

		ll t;
		scanf("%d",&t);
		while(t--){
		ll n,f;
		scanf("%d",&n);
		scanf("%d",&f);
		vi v(n);
		map<ll,ll> a,b,visited;
		ll mx=-1;
		for(ll i=0;i<n;i++){
		scanf("%d",&v[i]);
			b[v[i]]++;
			mx=max(mx,v[i]);
		}
		sort(v.begin(),v.end());
		ll ans=0;
		
		for(ll i=0;i<n;i++){
			if(visited[v[i]]){
				continue;
			}
			visited[v[i]]=1;
			double temp= (double)v[i]/ (double)f;
			//cout << temp<< endl;
			
			ll d=b[v[i]];
			if(temp!=floor(temp)){
				//cout <<"S"<< endl;
				ll newans=(d*(d-1))/2;
				ans+=newans;
				continue;
			}
			//cout <<"SDAF "<< temp<< endl;	
			ll c=a[(ll)temp]+b[(ll)temp];
			if(c==0){
				while(temp && c==0){
					temp= (double)temp/ (double)f;
					c=a[(ll)temp]+b[(ll)temp];
				}
			}
			//cout <<c<< endl;
			ll newans=c*d + (d*(d-1))/2 ;
			a[v[i]]=c;
			ans+=newans;
			//cout << ans<< endl;
		}
		cout << ans<< endl;

}
	return 0;
}			