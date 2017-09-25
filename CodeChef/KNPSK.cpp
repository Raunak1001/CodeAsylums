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
#define show(a) rep(i,1,a.size()){cout <<a[i]<<" ";}
#define ct(a) cout <<a<<endl



int main(){
		std::ios::sync_with_stdio(false); 
		cin.tie(NULL);
		cout.tie(NULL);

		ll n;
		cin >>n;
		vi one;
		vi two;
		one.pb(0);
		two.pb(0);
		ll sum=0;
		for(ll i=0;i<n;i++){
			ll a,b;
			cin >>a>>b;
			if(a==1){
				one.pb(b);
			}else{
				two.pb(b);
			}
			sum+=a;

				}
		sort(one.begin(),one.end());
		sort(two.begin(),two.end());
		
		ll j=two.size()-1;
		ll i=one.size()-1;
		vi ans(sum+1,0);
		ans[1]=one[i];
		//i--;
		for(ll k=2;k<=sum;k+=2){
			ans[k]=ans[k-2];
			if(i<=0 && j<=0){
				ans[k]=ans[k-2];
			}else if(i<=0){
				ans[k]+=two[j];
				j--;
			}else if(j<=0){
				ans[k]+=one[i]+one[i-1];
				i-=2;
			}else{
				if(one[i]+one[i-1]>two[j]){
					ans[k]+=one[i]+one[i-1];
					i-=2;
				}else{
						ans[k]+=two[j];
						j--;
				}
			}
		}

		i=one.size()-1;
		j=two.size()-1;
		ans[1]=one[i];
		i--;
		for(ll k=3;k<=sum;k+=2){
			ans[k]=ans[k-2];
			if(i<=0 && j<=0){
				ans[k]=ans[k-2];
			}else if(i<=0){
				ans[k]+=two[j];
				j--;
			}else if(j<=0){
				ans[k]+=one[i]+one[i-1];
				i-=2;
			}else{
				if(one[i]+one[i-1]>two[j]){
					ans[k]+=one[i]+one[i-1];
					i-=2;
				}else{
						ans[k]+=two[j];
						j--;
				}
			}
		}


		
		show(ans);

	return 0;
}			
