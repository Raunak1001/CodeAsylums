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

		ll t;
		cin >> t;
		while(t--){

			string a,b;
			cin >> a>> b;

			ll sum=0;
			vi v;
			v.pb(i);
			ll n=a.size();
			for(ll i=0;i<n;i++){
				if(a[i]!=b[i]){
					if(i!=0)
					v.pb(i);
					sum+=getVal(a[i],b[i]);
				}
			}

			ll count=v.size();
			vb visited(n);
			ll m=count;
			while(count>0){
					ll left;
					ll j=i
					while(v[j]!=-1){
						j--;
						if(j<0){
							j=m-1;
						}
					}
					left=j;
					j=i;
					while(v[j]!=-1){
						j++;
						if(j>=m){
							j=0;
						}
					}
					ll right=j;
				ll a=myFun(i,left);
				ll b=myFun(i,right);
				if(a,left){
					v[left]=-1;
					sum+=a;
				}else{
					sum+=b;
					v[right]=-1;
				}
			}

			cout << sum<< endl;


		}


	return 0;
}			