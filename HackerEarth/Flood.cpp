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
vi E(10000000),L(10000000,-1),H(10000000);
vi parent(100001);
vi seg(10000000);
ll ind=0;
void dfs(vvi &v,ll temp,vb &visited,ll level){

	E[ind]=temp;
	H[ind]=level;
	if(L[temp]==-1){
		L[temp]=ind;
	}
	ind++;
	for(ll i=0;i<v[temp].size();i++){
		if(!visited[v[temp][i]]){
			visited[v[temp][i]]=1;
			parent[v[temp][i]]=temp;
			dfs(v,v[temp][i],visited,level+1);
			E[ind]=temp;
			H[ind]=level;
			ind++;
		}

	}




}


void buildTree(ll l,ll r,ll pos){
	//cout <<l<<" "<<r<< endl;
	if(r<l){
		return;
	}
	if(l==r){
		seg[pos]=l;
		return ;
	}
	
	ll mid=l+(r-l)/2;
	buildTree(l,mid,2*pos+1);
	buildTree(mid+1,r,2*pos+2);
	if(H[seg[2*pos+1]]<H[seg[2*pos+2]]){
		seg[pos]=seg[2*pos+1];
	}else{
		seg[pos]=seg[2*pos+2];
	}
return ;

}


ll getQuery(ll low,ll high,ll l,ll r,ll pos){

	//cout<<low<<" "<<high<<" "<< endl;
	if(l<=low && r>=high){
		//cout << E[seg[pos]]<< endl;
		return seg[pos];

	}

	if(l>high || r<low){
		return -1;
	}
	ll mid=low+(high-low)/2;
	ll a=getQuery(low,mid,l,r,2*pos+1);
	ll b=getQuery(mid+1,high,l,r,2*pos+2);
	if(a==-1){
		return b;
	}else if(b==-1){
		return a;
	}
	
	return (H[a]<H[b])?a:b;


}


ll LCA(ll a,ll b,ll n){
		//cout <<a<<b<<endl;
		//cout <<L[a]<<" "<<L[b]<<endl;
	return E[getQuery(0,n,min(L[a],L[b]),max(L[a],L[b]),0)];


}

ll calculate(vi &dp,ll temp,vi &height,vvi &v,vb &visited){

	ll ans=dp[temp];
	for(ll i=0;i<v[temp].size();i++){
		if(!visited[v[temp][i]]){
		visited[v[temp][i]]=1;
		ans+=calculate(dp,v[temp][i],height,v,visited);
	}
	}
	height[temp]+=ans;
	return ans;

}

int main(){
		std::ios::sync_with_stdio(false); 
		cin.tie(NULL);
		cout.tie(NULL);


		ll n,q;
		cin >> n>> q;
		vvi v(n+1);
		for(ll i=0;i<n-1;i++){
			ll a,b;
			cin >>a>>b;
			v[a].pb(b);
			v[b].pb(a);
		}
		parent[1]=-1;
		vb visited(n+1,0);
		visited[1]=1;
		dfs(v,1,visited,0);

		buildTree(0,2*n,0);
		//show(L);

		vi dp(n+1,0);
		vi height(n+1,0);
		for(ll i=1;i<=n;i++){
			cin >> height[i];
		}

		while(q--){
			ll a,b,c;
			cin >>a>>b>>c;
			ll temp=LCA(a,b,2*n);
			//cout <<temp<< endl;
			dp[a]+=c;
			dp[b]+=c;
			if(temp!=-1)
			dp[temp]-=c;
			if(temp!=-1)
			if(parent[temp]!=-1){
				dp[parent[temp]]-=c;
			}
		}
		visited.clear();
		visited.resize(n+1,0);
		visited[1]=1;
		calculate(dp,1,height,v,visited);

		for(ll i=1;i<=n;i++){
			cout << height[i]<<" ";
		}



	return 0;
}			