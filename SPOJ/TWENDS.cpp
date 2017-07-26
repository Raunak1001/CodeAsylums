#include<bits/stdc++.h>
using namespace std;
#define vi vector<long long int>
#define vvi vector<vector<long long int>  >
#define ll long long int 
#define pr pair<long long int,long long int>
#define mp make_pair

ll second=0;

/*ll myFun1(vi &v,vvi &a,ll start,ll end,ll temp){
if(start>end){
	return 0;
}
if(a[start][end]!=-1){
	return a[start][end];
}

if(temp){
	if(v[start]>=v[end]){
		//second+=v[start];
		a[start][end]=myFun1(v,a,start+1,end,0);
	}else{
		//second+=v[end];
		a[start][end]=myFun1(v,a,start,end-1,0);
	}
}else{
	a[start][end]=min(v[end]+myFun1(v,a,start,end-1,1),v[start]+myFun1(v,a,start+1,end,1));
}

return a[start][end];

}
*/





ll myFun(vi &v,vvi &a,ll start,ll end,ll temp){
if(start>end){
	return 0;
}
if(a[start][end]!=-1){
	return a[start][end];
}

if(temp){
	if(v[start]>=v[end]){
		//second+=v[start];
		a[start][end]=myFun(v,a,start+1,end,0);
	}else{
		//second+=v[end];
		a[start][end]=myFun(v,a,start,end-1,0);
	}
}else{
	a[start][end]=max(v[end]+myFun(v,a,start,end-1,1),v[start]+myFun(v,a,start+1,end,1));
}

return a[start][end];

}


int main(){
	ll k=0;
	while(1){
		k++;
	second=0;
	ll n;
	cin >>n;
	if(n==0){
		break;
	}
vi v(n,0);
for(ll i=0;i<n;i++){
	cin >> v[i];
	second+=v[i];
}
vvi a(n+1,vi(n+1,-1));
ll ans=myFun(v,a,0,n-1,0);
for(ll i=0;i<=n;i++){
	for(ll j=0;j<=n;j++){
		a[i][j]=-1;
	}
}
cout <<"In game " <<k<<", the greedy strategy might lose by as many as "<< abs(second-2*ans)<<" points."<<endl;
/*ll ans2=myFun1(v,a,0,n-1,0);
cout << second<< " "<<ans2<<endl;
cout<< max(abs(second-2*ans),abs(second-2*ans2))<< endl;
*/
/*fill(v.begin(),v.end(),0);
mmin=max(mmin,abs(second-myFun1(v,a,0,n-1,0)));*/
//
}


}