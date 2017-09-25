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
		cin >>t;
		ll k=1;
		while(t--){
			ll ans=0;
			string s;
			cin >>s;
			ll n=s.size();
			vb v(26,0);
			for(ll i=0;i<n;i++){
				ll temp;
				if(s[i]<93){
					temp=s[i]-'A';
				}
				else temp=(s[i]-'a');
				//cout << temp<< endl;
				v[temp]=1;
			}
			for(ll i=0;i<26;i++){
				if(!v[i]){
					ans+=(i+1);
				}
			}
			ans%=26;
			if(ans==0){
				cout <<"Nothing is missing"<< endl;
			}else{
				cout <<"String "<< k <<" Representative is = "<< char(ans-1+'a')<< endl;
			}
			k++;
		}


	return 0;
}			