#include<bits/stdc++.h>
using namespace std;
#define vi vector<long long int>
#define vp vector<pair<long long int,long long int > >
#define vc vector<char>
#define vvi vector<vector<long long int>  >
#define vvp vector<vector<pair<long long int,long long int> > >
#define vvc vector<vector<char>  >
#define ll long long int 
#define pr pair<long long int,long long int>
#define mp make_pair		
#define pb push_back
#define vvvi vector<vector<vector<long long int> > >

ll get2(ll a){

	ll count=0;
	while(a%2==0){
		count++;
		a=a>>1;
	}
return count;
}


ll get5(ll a){

	ll count=0;
	while(a%5==0){
		count++;
		a/=5;
	}
return count;
}


vi myFun(vvi &count,ll i,vvvi &v,ll k){

	ll n=count.size();
	
	if(k<0 || i>=n){
		vi mid;
		for(int i=0;i<4;i++){
			mid.pb(-100000);
		}
		return mid;
	}

	if(k==0){
		vi mid;
		for(int i=0;i<4;i++){
			mid.pb(0);
		}
		return mid;
	}

	

	if(v[i][k][0]!=-1){
		return v[i][k];
	}
ll ans=0;

vi mid=myFun(count,i+1,v,k-1);
v[i][k][0]=max(mid[0]+count[0][0];
v[i][k][1]=mid[1]+count[0][1];
mid=myFun(count,i+1,v,k);
v[i][k][2]=mid[0];
v[i][k][3]=mid[1];
return v[i][k];
}


int main(){
	
	ll n,k;
	cin >>n>>k;
	vi a(n);
	vvi count(n,vi(2,0));
	for(ll i=0;i<n;i++){
		cin >>a[i];
		count[i][0]=get2(a[i]);
		count[i][1]=get5(a[i]);
	}

	vvvi v(n,vvi(k+1,vi(4,-1)));

	if(n==0){
		cout << 0<< endl;
		return 0;
			}

ll ans=0;
vi mid=myFun(count,1,v,k-1);
ans=max(min(mid[0]+count[0][0],mid[1]+count[0][1]),min(mid[2]+count[0][0],mid[3]+count[0][1]));
mid=myFun(count,1,v,k);
ans=max(ans,max(min(mid[0],mid[1]),min(mid[2],mid[3])));

for(int i=0;i<n;i++){
	for(int j=0;j<k;j++){
		for(int l=0;l<4;l++){
		cout << v[i][j][l]<<" ";
	}
	}
	cout << endl;
}


if(ans<0){
	ans=0;
}

cout << ans<< endl;


	return 0;
}