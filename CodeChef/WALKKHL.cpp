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

bool upDate(vb &tree,ll low,ll high,ll l,ll pos){

	if(low>high)
	{
		return 0;
	}

	if(l>high || l<low){
		return 0;
	}
	if(l==low && low==high){
		tree[pos]=1;
	}else{
		ll  mid=low+(high-low)/2;
		ll a=upDate(tree,low,mid,l,2*pos+1) || upDate(tree,mid+1,high,l,2*pos+2);
		tree[pos]=a;
		return a;
	}



}

bool getVal(vb &tree,ll low,ll high,ll l,ll  r,ll pos){

if(r<0){
	return 0;
}
if(low>high){
	return 0;
}

if(l>high || r<low){
		return 0;
	}
if(l<=low && r>=high){
	return tree[pos];
}else{
	ll mid=low+(high-low)/2;
	return getVal(tree,low,mid,l,r,2*pos+1) || getVal(tree,mid+1,high,l,r,2*pos+2);
}


}



int main(){
		std::ios::sync_with_stdio(false); 
		cin.tie(NULL);
		cout.tie(NULL);

		ll t;
		cin >>t;
		while(t--)
		{

			ll n;
			cin >>n;
			vi v(n);
			for(ll i=0;i<n;i++){
				cin >> v[i];
			}
			ll u,k;
			cin >>u>>k;
			vb tree(3*1000000);
			vi count(1000000,0);
			for(ll i=0;i<n;i++){
				ll temp=u-v[i];
				if(temp>=0){
					count[temp]++;
					upDate(tree,0,n-1,temp,0);
				}
			}
			ll temp=0;
			for(ll i=0;i<n;i++){
				ll r=u-v[i];
				ll l=u-v[i]-k;
				if(r>=0){
					if(count[r] || getVal(tree,0,n-1,l,r-1,0)){
						cout <<"Safe"<< endl;
						ll temp=1;
						break;
					}
				}
			}
			if(!temp){
				cout <<"Unsafe"<< endl;
			}

		}

	return 0;
}			