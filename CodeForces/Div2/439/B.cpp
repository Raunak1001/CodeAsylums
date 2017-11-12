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

		ll a,b;
		cin >>a>>b;
		if(a==b){
			cout <<1<< endl;
			return 0;
		}
		if((b-a)>=10 || b%10==0){
			cout <<0<< endl;
			return 0;
		}
		else{
			ll temp=a+1;
			ll ans=1;
			while(temp<=b){
				//cout << temp<< endl;
				ll last=temp%10;
				ans*=last;
				ans%=10;
				temp++;
			}
			cout << ans<< endl;
		}

	return 0;
}			