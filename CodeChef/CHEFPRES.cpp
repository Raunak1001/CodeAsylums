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
#define show(a) rep(i,1,a.size()){cout <<a[i]<<" ";}
#define ct(a) cout <<a<<endl

ll ans=0;
ll mn;
void myFun(vvi &v,ll start,vi &dis,ll distance,vi &prod,ll end,ll p){
	
	//cout << start<< endl;
	if(prod[start]==end){
		if(mn<min(dis[start],distance)){
			mn=min(dis[start],distance);
			ans=start;
		}

		if(mn==min(dis[start],distance)){
			if(ans==0 || ans>start){
				ans=start;
			}
		}
	}
	distance=min(distance,dis[start]);
	for(ll i=0;i<v[start].size();i++){
		if(v[start][i]!=p)
		myFun(v,v[start][i],dis,distance,prod,end,start);
	}


return ;

}

int main(){
		std::ios::sync_with_stdio(false); 
		cin.tie(NULL);
		cout.tie(NULL);

		ll n,k;
		cin >>n>>k;
		ll b;
		cin >> b;
		vvi v(n+1);

		for(ll i=0;i<n-1;i++){
			ll a,c;
			cin >>a>>c;
			v[a].pb(c);
			v[c].pb(a);
		}

		queue<ll> q;
		vi  dis(n+1,INT_MAX);
		dis[b]=0;
		q.push(b);
		while(!q.empty()){
			ll temp=q.front();
			q.pop();
			for(ll i=0;i<v[temp].size();i++){
				if(dis[v[temp][i]]>dis[temp]+1){
					dis[v[temp][i]]=dis[temp]+1;
					q.push(v[temp][i]);
				}
			}


		}
		//show(dis);
		vi prod(n+1);
		for(ll i=1;i<=n;i++){
			cin >>prod[i];
		}

		ll t;
		cin >>t;
		while(t--){
			ll start,end;
			cin >>start>>end;
			ans=0;
			mn=0;
			myFun(v,start,dis,dis[start],prod,end,-1);
			
				/*if(prod[start]==end){
					cout << start<< endl;
					continue;
				}*/
			
				if(ans==0){
					cout <<-1<< endl;
				}else{
					cout << ans<< endl;
				}
		}









	return 0;
}		