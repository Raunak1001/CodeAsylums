#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define pr pair<ll,ll>
#define vi vector<ll>
#define vvi vector< vi >
#define vvvi vector< vvi >
#define vd vector<double>
#define vvd vector< vd >
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

void getDistance(vvi &v,ll n,vvi &dis){

	 for (ll i = 1; i <= n; i++){
        for (ll j = 1; j <=n; j++){
            dis[i][j] = v[i][j];
       
    	}
	}

    for (ll k = 1; k <=n; k++){
       
        for (ll i = 1; i <=n; i++)
        {
                 for (ll j = 1; j <=n; j++)
            {
                if (dis[i][k] + dis[k][j] < dis[i][j])
                    dis[i][j] = dis[i][k] + dis[k][j];
            }
        }
    }
    



}


double myFun(vvi &v, vvi &dis, ll n, ll s, ll p,vvd &dp){
    if(p == 0){ 
    	return 0;
    }
    if(dp[s][p] != -1) return dp[s][p];
    double total = 0;
    
    for(ll i=1; i<=n; i++){
        if(i == s) continue;
        total += (double) (dis[s][i]  + myFun(v, dis, n, i, p-1,dp)) / (n-1);
    }

    return dp[s][p] = total;
}




int main(){
		std::ios::sync_with_stdio(false); 
		cin.tie(NULL);
		cout.tie(NULL);

		ll t;
		cin >>t;
		for(ll  q=0;q<t;q++){
			ll n,m,p;
			cin >>n>>m>>p;
			vvi v(n+1,vi(n+1,INT_MAX));

			ll a,b,c;
			for(ll i=0;i<m;i++){
				cin >>a>>b>>c;
				v[a][a]=0;
				v[b][b]=0;
				v[a][b]=c;
				v[b][a]=c;
			}
			vvd dp(n+1,vd(201,-1));
			vvi dis(n+1,vi(n+1,INT_MAX));
			getDistance(v,n,dis);
			double ans=myFun(v,dis,n,1,p,dp);

			cout << fixed;
			cout << setprecision(6);
			cout<<"Case #"<<q+1<<": "<<ans<< endl;

		}


	return 0;
}			