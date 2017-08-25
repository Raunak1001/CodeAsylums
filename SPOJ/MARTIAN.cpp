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

ll maxa=0,maxb=0;
vvi v(4,vi(4,0));

ll myFun(vvi &a, vvi &b,ll temp,ll sum, ll i,ll j){

	if(i<0 || j<0){
		return sum;
	}
	ll c=0;
	if(temp){
		c=max(myFun(a,b,1,sum+a[i][j],i,j-1)+myFun(a,b,0,0,i-1,j),myFun(a,b,0,b[i][j],i-1,j)+myFun(a,b,1,0,i,j-1));
	}else{
		c=max(myFun(a,b,1,a[i][j],i,j-1)+myFun(a,b,0,0,i-1,j),myFun(a,b,0,sum+b[i][j],i-1,j)+myFun(a,b,1,0,i,j-1));

	}
	v[i][j]=c;

return c;

}

int main(){
	
	
		ll n,m;
		while(1){
			cin >>n>>m;
			if(n==0 && m==0){
				break;
			}

			vvi a(n,vi(m));
			vvi b(n,vi(m));
			for(ll i=0 ;i<n;i++){
				for(ll j=0;j<m;j++){
					cin >> a[i][j];
				}
			}

			for(ll i=0 ;i<n;i++){
				for(ll j=0;j<m;j++){
					cin >> b[i][j];
				}
			}
			cout <<myFun(a,b,0,b[n-1][m-1],n-2,m-1)<< endl;

			cout << max(myFun(a,b,0,b[n-1][m-1],n-2,m-1)+myFun(a,b,1,0,n-1,m-2),myFun(a,b,1,a[n-1][m-1],n-1,m-2)+myFun(a,b,0,0,n-2,m-1))<< endl;


			for(ll i=0;i<n;i++){
				for(ll j=0;j<n;j++){
					cout<< v[i][j]<< " ";
				}
				cout << endl;
			}

		}

	

	return 0;
}