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
vi tree(3*1000000,0);

ll buildTree(ll l,ll low,ll high,ll pos){

if(l>high || l<low){
	return 0;
}

if(l==low && l==high){
	tree[pos]=1;
	return 1;
}else{
ll mid=low+(high-low)/2;
ll a=buildTree(l,low,mid,2*pos+1)+buildTree(l,mid+1,high,2*pos+2);
tree[pos]=tree[2*pos+1]+tree[2*pos+2];
return a;
}

}
ll getAns(ll l,ll r,ll low,ll high,ll pos){

	if(l>high || r<low){
		return 0;
	}
	if(l<=low && r>=high){
		return tree[pos];
	}else{
		ll mid=low+(high-low)/2;
ll a=getAns(l,r,low,mid,2*pos+1)+getAns(l,r,mid+1,high,2*pos+2);
return a;


	}


}




int main(){
		std::ios::sync_with_stdio(false); 
		cin.tie(NULL);
		cout.tie(NULL);

		ll n,q,k;
		vi v(n);
		map<ll,ll> m;
		ll sum=0;
		for(ll  i=0;i<n;i++){
			cin >> v[i];
			m[v[i]]=i;
			sum+=v[i];
		}
		for(ll i=0;i<k;i++){
			ll a;
			cin >>a;
			buildTree(m[a],0,n-1,0);
		}
		while(q--){
			ll a,b,c;
			cin >> a>>b>>c;
			ll temp=getAns(a,b,0,n-1,0);
			cout << sum+(c*(b-a+1)-c*(temp))<< endl;
		}







	return 0;
}			