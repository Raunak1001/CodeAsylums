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
#define mod 1000000007
struct Node{
	ll a,l,r;
};

void upDate(vi &lazy,vi &s,ll l,ll r,ll low,ll high,vector<Node> &v,ll pos){

	if(low>high){
		return ;
	}

	if(lazy[pos]!=0){
		//s[pos]+=lazy[pos];
		lazy[2*pos]+=lazy[pos];
		lazy[2*pos+1]+=lazy[pos];
		lazy[pos]=0;
	}

	if(r<low || l>high){
		return;
	}
	if(l<=low && r>=high){
		//s[pos]+=1;
		lazy[2*pos]+=1;
		lazy[2*pos+1]+=1;

	}else{
		ll mid=low+(high-low)/2;
		upDate(lazy,s,l,r,low,mid,v,2*pos);
		upDate(lazy,s,l,r,mid+1,high,v,2*pos+1);


	}



}


ll getVal(vi &lazy,vi &s,ll l,ll r,ll low,ll high,ll pos){
	if(low>high){
		return 0;
	}
if(lazy[pos]!=0){
		//s[pos]+=lazy[pos];
	//cout << l<< endl;
		lazy[2*pos]+=lazy[pos];
		lazy[2*pos+1]+=lazy[pos];
		lazy[pos]=0;
	}

	if(r<low || l>high){
		return -1;
	}
	if(l<=low && r>=high){
		return lazy[2*pos+1];
	}else{

		ll mid=low+(high-low)/2;
		ll a=getVal(lazy,s,l,r,low,mid,2*pos);
		ll b=getVal(lazy,s,l,r,mid+1,high,2*pos+1);	
		if(a!=-1){
			return a;
		}	
					return b;

	}


}



void myFun(vi &lazy,vi &s,ll l,ll r,vector<Node> &v,ll n){

	for(ll i=l;i<=r;i++){
		if(v[i].a==1){
			upDate(lazy,s,v[i].l,v[i].r,1,n,v,1);
		}else{
			myFun(lazy,s,v[i].l,v[i].r,v,n);

		}
	}


}



int main(){
		std::ios::sync_with_stdio(false); 
		cin.tie(NULL);
		cout.tie(NULL);

		ll t;
		cin >>t;

		while(t--){

			ll n,q;
			cin >>n>>q;
			vector<Node> v(q+1);
			vi s(3*1000000,0);
			vi lazy(3*1000000,0);
			for(ll i=1;i<=q;i++){
			ll a,l,r;
			cin >>a>>l>>r;
			v[i].a=a;
			v[i].l=l;
			v[i].r=r;

			if(a==1){
				upDate(lazy,s,l,r,1,n,v,1);
			}else{
				myFun(lazy,s,l,r,v,n);
			}

			}

       vi ans(n+1,0);
       for(ll i=1;i<=n;i++){
       	ans[i]=getVal(lazy,s,i,i,1,n,1);
       }
       show(ans);
       cout << endl;

		}



		

	return 0;
}		



