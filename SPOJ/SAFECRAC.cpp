#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vp vector<pair<long long int,long long int > >
#define vc vector<char>
#define vvi vector<vector<int>  >
#define vvvi vector< vvi >
#define vvp vector<vector<pair<long long int,long long int> > >
#define vvc vector<vector<char>  >
#define ll long long int 
#define pr pair<long long int,long long int>
#define mp make_pair		
#define pb push_back

ll mod=1000000007;


bool isValid(ll i,ll j){

if(i<0 || i>=4 || j<0 || j>=3){
	return false;
}

if(i==3){
	if(j!=0){
		return false;
	}
}
return true;
}


ll myFun(vvvi &v,ll i,ll j,ll cur,ll n){

if(cur==n){
	return 1;
}
if(v[i][j][cur]!=-1){
	return v[i][j][cur]%mod;
}

ll count =0;
if(isValid(i+1,j)){
count +=(myFun(v,i+1,j,cur+1,n)%mod);
count%=mod;
}

if(isValid(i,j+1)){
count +=myFun(v,i,j+1,cur+1,n)%mod;
count%=mod;

}

if(isValid(i-1,j)){
count +=myFun(v,i-1,j,cur+1,n)%mod;
count%=mod;

}


if(isValid(i,j-1)){
count +=myFun(v,i,j-1,cur+1,n)%mod;
count%=mod;

}

	return v[i][j][cur]=count%mod;

}


ll getSum(vvi &v,ll i,ll j){

ll sum=0;

if(i==0){
	sum+=v[7][j-1]%mod;
	return sum%mod;
}
if(i==1){
	sum+=v[2][j-1]%mod+v[4][j-1]%mod;
}
if(i==2){
	sum+=v[1][j-1]%mod+v[3][j-1]%mod+v[5][j-1]%mod;
}
if(i==3){
	sum+=v[2][j-1]%mod+v[6][j-1]%mod;
}
if(i==4){
	sum+=v[1][j-1]%mod+v[5][j-1]%mod+v[7][j-1]%mod;
}
if(i==5){
	sum+=v[2][j-1]%mod+v[4][j-1]%mod+v[6][j-1]%mod+v[8][j-1]%mod;
}
if(i==6){
	sum+=v[3][j-1]%mod+v[5][j-1]%mod+v[9][j-1]%mod;
}
if(i==7){
	sum+=v[4][j-1]%mod+v[8][j-1]%mod+v[0][j-1]%mod;
}
if(i==8){
	sum+=v[7][j-1]%mod+v[9][j-1]%mod+v[5][j-1]%mod;
}
if(i==9){
	sum+=v[6][j-1]%mod+v[8][j-1]%mod;
}


return sum%mod;
}

int main(){
		std::ios::sync_with_stdio(false); 

		ll t;
		cin >>t;
		 ll n=100000;

		vvi  v(10,vi(100000,1));
		vi ans(n+1,0);
		ans[1]=10;
		
		for(ll i=2;i<=n;i++){
			ll sum=0;
			for(ll j=0;j<=9;j++){
				v[j][i]=getSum(v,j,i);
			sum+=v[j][i]%mod;
			sum%=mod;
			}
			ans[i]=sum%mod;
		}

		while(t--){
			cin >>n;
			
			cout << ans[n] << endl;
		}


	return 0;
}	