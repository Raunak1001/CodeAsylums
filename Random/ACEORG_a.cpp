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

vi E(1000000),firstOccur(1000000,-1),lastOcurr(1000000,-1);
ll ind=0;
vi seg(1000000,0),lazy(1000000,0);


void dfs(vvi &v,ll temp){

	E[temp]=ind;
	lastOcurr[temp]=ind;
	if(firstOccur[temp]==-1){
		firstOccur[temp]=ind;
	}
	ind++;
	/*lastOcurr[temp]=ind;
	ind++;*/

	for(ll i=0;i<v[temp].size();i++){
		dfs(v,v[temp][i]);
		E[temp]=ind;
		lastOcurr[temp]=ind;
	}

return ;
}

ll getAns(ll low,ll high,ll l,ll pos){

	if(lazy[pos]!=0){
		seg[pos]+=lazy[pos];
		lazy[2*pos+1]+=lazy[pos];
		lazy[2*pos+2]+=lazy[pos];
		lazy[pos]=0;
	}
	if(l>high || l<low){
		return -1;
	}
	if(l==low && l==high){
		return seg[pos];
	}
	ll mid=low+(high-low)/2;
	ll a=getAns(low,mid,l,2*pos+1);
	ll b=getAns(mid+1,high,l,2*pos+2);
	if(a!=-1){
		return a;
	}
	return b;

}

void update(ll low,ll high,ll l,ll r,ll pos,ll m){

	if(lazy[pos]!=0){
		seg[pos]+=lazy[pos];
		lazy[2*pos+1]+=lazy[pos];
		lazy[2*pos+2]+=lazy[pos];
		lazy[pos]=0;
	}
	if(l>high || r<low){
		return ;
	}
	if(l<=low && r>=high){
		seg[pos]+=m;
		lazy[2*pos+1]+=m;
		lazy[2*pos+2]+=m;
		return ;
	}
	ll mid=low+(high-low)/2;
	update(low,mid,l,r,2*pos+1,m);
	update(mid+1,high,l,r,2*pos+2,m);
	seg[pos]=seg[2*pos+1]+seg[2*pos+2];
return ;
}




ll newFun(ll n,ll q){
	vi salary(n+1);
		for(ll i=1;i<=n;i++){
			cin >> salary[i];
		}
		vvi v(n+1);
		vi parent(n+1,-1);
		for(ll i=0;i<n-1;i++){
			ll a,b;
			cin >>a>>b;
			v[a].pb(b);
			parent[b]=a;
		}
		ll root=1;
		for(ll i=1;i<=n;i++){
			if(parent[i]==-1){
				root=i;
				break;
			}
		}
		dfs(v,root);

		while(q--){
			ll a;
			cin >> a;
			if(a==0){
				ll b,c;
				cin >> b>> c;
				ll l=firstOccur[b];
				ll r=lastOcurr[b];
				//cout <<l<<" "<<r<<  endl;
				update(0,2*n-1,l,r,0,c);
								//cout <<"Fsad"<< endl;

			}else{

				ll b;
				cin >> b;
				ll l=lastOcurr[b];
				//cout <<getAns(0,2*n-1,l,0)<< endl;	
				cout << getAns(0,2*n-1,l,0)+salary[b]<< endl;
			}

		}

}



void dfs1(ll temp,ll c,vvi &v,vi &dp){
	dp[temp]+=c;
	for(ll i=0;i<v[temp].size();i++){
		dfs1(v[temp][i],c,v,dp);
	}
	return;
}




int main(){
		std::ios::sync_with_stdio(false); 
		cin.tie(NULL);
		cout.tie(NULL);

		ll n,q;
		cin >> n>>q;

		if(n>1000 && q>10000){
			newFun(n,q);
			return 0;
		}

		vi salary(n+1);
		for(ll i=1;i<=n;i++){
			cin >> salary[i];
		}
		vvi v(n+1);
		vi parent(n+1,-1);
		for(ll i=0;i<n-1;i++){
			ll a,b;
			cin >>a>>b;
			v[a].pb(b);
			parent[b]=a;
		}
		ll root=1;
		for(ll i=1;i<=n;i++){
			if(parent[i]==-1){
				root=i;
				break;
			}
		}

		vi dp(n+1,0);
		while(q--){
			ll a;
			cin >>a;
			if(a==0){
				ll b,c;
				cin >>b>> c;
				dp[b]+=c;
				for(ll i=0;i<v[b].size();i++){
					dfs1(v[b][i],c,v,dp);
				}
			}else{
				ll b;
				cin >> b;
				cout << dp[b] + salary[b]<< endl;

			}

		}


	return 0;
}			