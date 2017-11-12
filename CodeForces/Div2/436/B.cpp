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
		cin>> n;
		string s;
		cin >> s;
		ll start=0;
		ll end=0;
		ll count=0;
		ll mx=0;
		map<char,ll> m;
	while(end<n){

		if(s[end]-'a' >=0 && s[end]-'a'<=26){
			end++;
		}else{
			m.clear();
			//cout << start<<" "<< end<< endl;
			ll temp=0;
			for(ll i=start;i<end;i++){
				if(m[s[i]]==0){
					temp++;
					m[s[i]]=1;
				}
			}
			mx=max(mx,temp);
			end++;
			start=end;
		}

	}

	ll temp=0;
	m.clear();
			for(ll i=start;i<end;i++){
				if(m[s[i]]==0){
					temp++;
					m[s[i]]=1;
				}
			}
			mx=max(mx,temp);


	cout << mx<< endl;
	return 0;
}			