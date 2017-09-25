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
vi count0(3*1000000,0);
vi count1(3*1000000,0);
vi count2(3*1000000,0);
vi lazy(3*1000000,0);


ll createTree(ll low,ll high,ll pos){
	//cout <<pos<<" "<<low<<" "<<high<< endl;
	if(low>high){
		return 0;
	}
if(low==high){
	count0[pos]=1;
	return 1;
}
ll mid=low+(high-low)/2;
return count0[pos]+=createTree(low,mid,2*pos+1)+createTree(mid+1,high,2*pos+2);

}

ll upDate(ll l,ll r,ll pos,ll low,ll high){
if(low>high){
	return 0;
}
if(lazy[pos]!=0){
	lazy[pos]%=3;
	if(lazy[pos]==1){
		ll temp=count2[pos];
		count2[pos]=count1[pos];
		count1[pos]=count0[pos];
		count0[pos]=temp;
	}
	if(lazy[pos]==2){
		ll temp=count2[pos];
		count2[pos]=count0[pos];
		count0[pos]=count1[pos];
		count1[pos]=temp;
	}
	lazy[2*pos+1]+=lazy[pos];
	lazy[2*pos+2]+=lazy[pos];
	lazy[pos]=0;
}

if(r<low || l> high){
	return 0;
}

if(low>=l && high <=r){
	//cout <<l<<" "<<r<< endl;
	lazy[2*pos+1]+=1;
	lazy[2*pos+2]+=1;
	ll temp=count2[pos];
		count2[pos]=count1[pos];
		count1[pos]=count0[pos];
		count0[pos]=temp;
}else{

	ll mid=low+(high-low)/2;
	upDate(l,r,2*pos+1,low,mid);
	upDate(l,r,2*pos+2,mid+1,high);
	count1[pos]=count1[2*pos+1]+count1[2*pos+2];
	count0[pos]=count0[2*pos+1]+count0[2*pos+2];
	count2[pos]=count2[2*pos+1]+count2[2*pos+2];
}



}


ll myFun(ll l,ll r,ll pos,ll low,ll high){
if(low>high){
	return 0;
}
if(lazy[pos]!=0){
	lazy[pos]%=3;
	if(lazy[pos]==1){
		ll temp=count2[pos];
		count2[pos]=count1[pos];
		count1[pos]=count0[pos];
		count0[pos]=temp;
	}
	if(lazy[pos]==2){
		ll temp=count2[pos];
		count2[pos]=count0[pos];
		count0[pos]=count1[pos];
		count1[pos]=temp;
	}
	lazy[2*pos+1]+=lazy[pos];
	lazy[2*pos+2]+=lazy[pos];
	lazy[pos]=0;
}

if(r<low || l> high){
	return 0;
}

if(low>=l && high<=r){
	return count0[pos];
}else{
ll mid=low+(high-low)/2;
ll a=myFun(l,r,2*pos+1,low,mid)+myFun(l,r,2*pos+2,mid+1,high);
	count1[pos]=count1[2*pos+1]+count1[2*pos+2];
	count0[pos]=count0[2*pos+1]+count0[2*pos+2];
	count2[pos]=count2[2*pos+1]+count2[2*pos+2];
	return a; 
}


}




int main(){
		std::ios::sync_with_stdio(false); 
		cin.tie(NULL);
		cout.tie(NULL);


		ll n,q;
		scanf("%lld",&n);
		scanf("%lld",&q);


		createTree(0,n-1,0);
/*for(ll i=0;i<9;i++){
					cout<< count0[i]<< " ";
				}
				cout << endl;*/
		while(q--){

			ll a,l,r;
			scanf("%lld",&a);
			scanf("%lld",&l);
			scanf("%lld",&r);
		
			if(a==0){
				upDate(l,r,0,0,n-1);

				/*for(ll i=0;i<9;i++){
					cout<< count0[i]<< " ";
				}
				cout << endl;*/
			}else{
				ll a=myFun(l,r,0,0,n-1);
				printf("%lld\n",a);
			}



		}



	return 0;
}			