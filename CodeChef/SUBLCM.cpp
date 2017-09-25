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
vb sieve(1000001,0);
void preCompute(unordered_map<ll,vi > &m){

sieve[1]=1;
ll n=1000001;
for(ll i=2;i<n;i++){
	if(sieve[i]==0){
		for(ll j=2;i*j<n;j++){
			sieve[i*j]=1;
		}
	}
}

//ll n=11;
for(ll i=2;i<n;i++){
	ll a=i;
	ll j=2;
	while(a>1){
		//cout <<a<< endl;
		if(sieve[a]==0){
			m[i].pb(a);
			break;
		}
		if(a%j==0){
			m[i].pb(j);
			while(a%j==0){
				a/=j;
			}
		}
		j++;
	}
}
return ;
}

void delFun(vi &v,vi &count,ll starti,ll maxi,ll index,unordered_map<ll,vi >  &m){

	for(ll i=starti;i<=maxi;i++){
		ll a=v[starti];
		for(ll k=0;k<m[a].size();k++){
			count[m[a][k]]=-1;
		}

	}

	ll a=v[index];
	
	for(ll k=0;k<m[a].size();k++){

		count[m[a][k]]=index;

	}
	return ;
}

ll myFun(ll a,vi &count,vi &v,ll index,unordered_map<ll,vi > &m,ll prev){
	ll maxi=prev;
	ll temp=0;
	//cout <<a<<endl;
	for(ll k=0;k<m[a].size();k++){
			//cout <<m[a][k]<< " ";
			maxi=max(count[m[a][k]]+1,maxi);
			//cout << m[a][k]<<" "<<index<< endl;
			count[m[a][k]]=index;
	}
	//cout << maxi<< endl;
	return maxi;

}

int main(){
		std::ios::sync_with_stdio(false); 
		cin.tie(NULL);
		cout.tie(NULL);

		ll t;
		scanf("%lld",&t);
		//cout << t<< endl;
		unordered_map<ll,vi > m;
		preCompute(m);
		//cout << m[4].size()<< endl;

		while(t--){
			//cout << t<< endl;	
			ll n;
			
			scanf("%lld",&n);
			vi v(n);
			for(ll i=0;i<n;i++){
				scanf("%lld",&v[i]);
			}

			vi count(1000001,-1);
			
			ll mx=0;
			ll prev=-1;
			for(ll i=0;i<n;i++){
				ll a=myFun(v[i],count,v,i,m,prev);
				prev=a;
				//cout << a<< endl;
				mx=max(i-a+1,mx);
			}
			
			if(mx<=1){
				printf("-1\n");
			}else
			printf("%lld\n",mx )	;

		}

	return 0;
}			