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
#define vb vector<bool>

ll myFun(vi &a,ll i,ll n,map<ll,ll> &m,vvi &dp){

	if(i>=n){
		return 0;
	}
	ll temp=0;
	if(m[a[i]]==1){
		temp=1;
	}

	if(dp[i][temp]!=-1){
		return dp[i][temp];
	}

	ll count=0;
	if(temp==0 && a[i]!=INT_MAX){
		m[a[i]+1]=1;
		count=a[i]+myFun(a,i+1,n,m,dp);
		m[a[i]+1]=0;
		count =max(count,myFun(a,i+1,n,m,dp));
	}else{
				count =max(count,myFun(a,i+1,n,m,dp));

	}
	return dp[i][temp]=count ;

}

ll myFun2(vi &a,ll i,ll n,map<ll,ll> &m,vvi &dp,ll flag){

	if(i>=n){
		if(flag)
		return 0;
	else
		return 100000000;
	}
	ll temp=0;
	if(m[a[i]]==1){
		temp=1;
	}

	if(dp[i][temp]!=-1){
		return dp[i][temp];
	}

	ll count=10000;
	if(temp==0 ){
		m[a[i]+1]=1;
		count=a[i]+myFun2(a,i+1,n,m,dp,1);
		m[a[i]+1]=0;
		count =min(count,myFun2(a,i+1,n,m,dp,0));
	}else{
				count =min(count,myFun2(a,i+1,n,m,dp,1));

	}
	//cout << count << endl;
	return dp[i][temp]=count ;

}



int main(){
		std::ios::sync_with_stdio(false); 

		ll n;
		ll ans=0;
		cin >>n;
		vi a(n);
						map<ll,ll> m;

		for(ll i=0;i<n;i++){
			cin >> a[i];
			m[a[i]]++;
		}

		for(ll i=0;i<n;i++){
			//cout << a[i]+1<<" "<< a[i]-1<<endl;
			if(m.find(a[i]+1)==m.end() && m.find(a[i]-1)==m.end()){
				ans+=a[i];
				a[i]=INT_MAX;

			}
		}
		m.clear();
		vvi dp(n,vi(2,-1));
		sort(a.begin(),a.end());
		ll start=0;
		ll i=0;
		while(i<n && a[i]<=	0){
			a[i]*=-1;
			i++;
		}
		start=i;
		//cout <<start << endl;
		ll count =myFun(a,start,n,m,dp);
		//cout << count << endl;
		sort(a.begin(),a.begin()+start);
		ll sum=0;
		for(ll i=0;i<start;i++){
			if(a[i]!=INT_MAX);
			sum+=a[i];
		}
		ll y=myFun(a,0,start,m,dp);
		cout << count +ans+y-sum<< endl;



	return 0;
}