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
#define ct(a) cout <<a



int main(){
		std::ios::sync_with_stdio(false); 
		cin.tie(NULL);
		cout.tie(NULL);

		ll t;
		cin >>t;
		while(t--){
			char c='a';
					vi v(10,0);
					string s;
					cin >>s;
			for(ll i=0;i<s.size();i++){
				ll temp=s[i]-'0';
				if(v[temp]!=2){
					v[temp]++;
				}
			}

			for(ll i=65;i<=90;i++){
				char j=i;
				ll a=i%10;
				ll b=i/10;
				if(a==b){
					if(v[a]==2){
						ct(j);
						}
				}else if(v[a]>0 && v[b]>0){
					ct(j);
					}
			}
			cout << endl;

		}


	return 0;
}		