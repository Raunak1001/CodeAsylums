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
ll MAX=1000001;
bool isValid(ll a){
	//cout <<a<< endl;
ll b=sqrt(a);
for(ll i=1;i<=b;i++){
	ll temp=a-i*i;
	ll c=sqrt(temp);
	if(c*c==temp){
		return 1;
	}
}
return 0;

}

ll myFun(ll a,ll b,vvi &dp){

if(a==0){
	return 1;
}
if(a<0){
	return 0;
}

if(dp[a][b]!=-1){
	return dp[a][b];
}
//cout <<a<<" "<<b<< endl;
ll count=0;
for(ll i=b;i>0;i--){
	count+=myFun(a-i,i,dp);
}
return dp[a][b]=count;

}


int main(){
		std::ios::sync_with_stdio(false); 
		cin.tie(NULL);
		cout.tie(NULL);

		vi sieve(MAX-1,1);
		sieve[1]=0;
		for(ll i=2;i<MAX;i++){
			if(sieve[i]){
				for(ll j=2;j*i<MAX;j++){
					sieve[i*j]=0;
				}
			}
		}

		vi v;
		ll i=2;
		ll cnt=0;
		//cout <<isValid(5)<<sieve[2]<< endl;
		while(cnt<501){
			
			if(sieve[i]==0){
				//cout <<i<< endl;
				i++;
				continue;
			}
			if(isValid(i)){
				cnt++;
				
				v.pb(i);
			}
			i++;
		}
		
		ll t;
		cin >>t;
		while(t--){

			ll n,k;
			cin >>n>>k;
			vvi dp(8000,vi(5,-1));
			//cout << v[n-1]<< " ";
			cout << myFun(v[n-1],k,dp)<< endl;
		}


	return 0;
}			