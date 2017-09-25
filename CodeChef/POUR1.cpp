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
ll A,B,C;

ll gcd(ll a,ll b){
	if(a==0){
		return b;
	}
	return gcd(b%a,a);
}


ll myFun(ll b,ll a, vvi &dp,vvb &visited){

//cout << a<< b<< endl;
if(a<0 || b<0 || a>A || b>B){
	return INT_MAX-1;
}
if(visited[a][b]){
	return INT_MAX-1;
}

if(a==C  || b==C){
	return 0;
}
if(dp[a][b]!=-1){
	return dp[a][b];
}
visited[a][b]=1;

ll count=INT_MAX;


if(a==0){
	count=min(count,myFun(b-A,A,dp,visited)+1);
}else if(b==0){
	count=min(count,myFun(A,0,dp,visited)+1);
}else{
	count=min(count,myFun(b,0,dp,visited)+1);
	count=min(count,myFun(0,a,dp,visited)+1);
	count=min(count,myFun(b+a,0,dp,visited)+1);
	count=min(count,myFun(B,a-(B-b),dp,visited)+1);
	count=min(count,myFun(b-(A-a),A,dp,visited)+1);
}

return dp[a][b]=count;




}


int main(){
		

		ll t;
		scanf("%lld",&t);
		while(t--){
			
			scanf("%lld",&A);
			scanf("%lld",&B);
			scanf("%lld",&C);

			if(A>B){
				swap(A,B);
			}

			if(C>B){
				printf("-1\n");
				continue;
			}
			ll temp=0;
			if(C==A || C==B){
				printf("1\n");
				continue;
			}
			if(C%gcd(A,B)!=0){
				printf("-1\n");
				continue;
			}
			
			vvi dp(B+1,vi(A+1,-1));
			vvb visited(A+1,vb(A+1,-1));

			ll count=INT_MAX;
			
			count=myFun(B,0,dp,visited)+1;
			
			count=min(count,myFun(0,A,dp,visited)+1);

			if(count==INT_MAX){
				cout <<-1<< endl;
			}else
				printf("%lld\n",count);


		}



	return 0;
}			