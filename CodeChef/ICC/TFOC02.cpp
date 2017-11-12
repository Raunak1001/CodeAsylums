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



int main(){
		std::ios::sync_with_stdio(false); 
		cin.tie(NULL);
		cout.tie(NULL);

		ll n;
		cin >> n;
		string s;
		vi v(n);
		for(ll i=0;i<n;i++){
			ll a;
			cin >> v[i];
		}
ll rem=0;
ll ans=0;
vi a=v;
reverse(v.begin(),v.end());
while(rem<n){
vvi dp(n+1,vi(n+1,0));
/*show(a);
cout << endl;
show(v);
cout << endl;*/	

/*for(ll i=0;i<=n;i++){
	//dp[i][0]=1;
	dp[0][i]=1;
}*/
ll mx=0;
for(ll i=1;i<=n;i++){
	for(ll j=1;j<=n;j++){
		if(a[i-1]==v[j-1] && a[i-1]!=-1 && v[j-1]!=-1){
			dp[i][j]=1+dp[i-1][j-1];
			mx=max(mx,dp[i][j]);
		}else{
			dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
}

/*for(ll i=1;i<=n;i++){
	for(ll j=1;j<=n;j++){
		cout << dp[i][j]<<" ";
	}
	cout << endl;
}*/

ll i=n;
ll j=n;
while(i>=1 && j>=1){
	if(dp[i-1][j-1]+1==dp[i][j] && a[i-1]==v[j-1]){
		a[i-1]=-1;
		//v[n-i]=-1;
		i--;
		j--;

	}else{
		if(dp[i-1][j]==dp[i][j]){
			i--;
		}else{
			j--;
		}
	}
}

for(ll i=0;i<n;i++){
	if(a[i]==-1){
		v[n-i-1]=-1;
	}
}

	/*show(a);
	cout << endl;
	show(v);
	cout << endl;
*/
if(mx==1){
	ans+=(n-rem);
	rem=n;
	continue;
}

ans+=1;
rem+=mx;
//cout << rem<< endl;


}

cout << ans<< endl;

	return 0;
}			