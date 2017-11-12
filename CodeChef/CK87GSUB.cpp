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
			string s;
			cin >>s;
			ll n=s.size();

			map<char,ll> m;
			ll count=0;
			ll i=0;
			m[s[0]]=1;
			ll j=1;
			while(i<j && j<n){
				if(s[j]==s[i]){
					count++;
				
				i++;
			}else if(m[s[j]]!=0){
				while(s[i]!=s[j]){
					m[s[i]]=0;
					i++;
				}
				count++;
				i++;
			}else{
				m[s[j]]=1;
				if(j!=n-1)
				j++;
				else
					break;
			}

		}


			cout << count << endl;
		}


	return 0;
}			