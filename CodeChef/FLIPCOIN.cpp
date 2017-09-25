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

void upDate(vi &lazy,vi &v,ll l,ll r,ll pos,ll low,ll high){
	
//cout <<l<<" "<<r<<" "<<low<<" "<<high<<endl;
if(lazy[pos]==1){
	v[pos]=high-low+1-v[pos];
	lazy[2*pos+1]=1-lazy[2*pos+1];
	lazy[2*pos+2]=1-lazy[2*pos+2];
	lazy[pos]=0;
}

if(r<low || l>high){
	return ;
}



if(l<=low && r>=high){
	v[pos]=high-low+1-v[pos];
	lazy[pos]=0;
	ll left=2*pos+1;
	ll right=2*pos+2;
	lazy[2*pos+1]=1-lazy[2*pos+1];
	lazy[2*pos+2]=1-lazy[2*pos+2];
}
else{
	ll mid=low+(high-low)/2;
	upDate(lazy,v,l,r,2*pos+1,low,mid);
	upDate(lazy,v,l,r,2*pos+2,mid+1,high);
	v[pos]=v[2*pos+1]+v[2*pos+2];

}
return;

}

ll myFun(vi &lazy,vi &v,ll l,ll r,ll pos,ll low,ll high){

if(r<low || l>high){
	return 0;
}

	if(lazy[pos]!=0){
		v[pos]=high-low+1-v[pos];
		lazy[2*pos+1]=1-lazy[2*pos+1];
		lazy[2*pos+2]=1-lazy[2*pos+2];
		lazy[pos]=0;
	}
	if(l<=low && r>=high){
		return v[pos];
}else{
		ll mid=low+(high-low)/2;

	return myFun(lazy,v,l,r,2*pos+1,low,mid)+myFun(lazy,v,l,r,2*pos+2,mid+1,high);
}


}


int main(){
		std::ios::sync_with_stdio(false); 
		cin.tie(NULL);
		cout.tie(NULL);
		ll n,q;
		cin>>n>>q;
		vi v(3*1000000,0);
		vi lazy(3*1000000,0);
		while(q--){
			ll a,l,r;
			cin >>a>>l>>r;
			//cout <<a<< endl;
			if(a==0){

				upDate(lazy,v,l,r,0,0,n-1);
				//show(v);
			}else{
				cout <<myFun(lazy,v,l,r,0,0,n-1)<<  endl;	

			}

		}
	


	return 0;
}		