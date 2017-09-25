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

		ll n,q;
		cin >>n>>q;
		map<string,ll> m;
		string s;
		while(n--){
			cin >>s;
			m[s]=1;
		}				

		string a;
		while(q--){
			cin >>a;
			vi v;
			for(ll k=0;k<a.length();k++){
				if(a[k]=='?'){
					v.pb(k);
				}
			}

			if(v.size()==0){

				if(m[a]==1){
					cout << 1<< endl;
					continue;
				}
			}
			if(v..size()==1){
				ll count=0;
				ll i=v[0];
				string temp=s;
					s[i]=(k+'a');
					if(m[s]==1){
						ccount++;
					}
				}
				s=s.substring(0,i)+s.substring(i+1,s.length());
				if(m[s]){
					count++;
				}
				cout << count<< endl;
				continue;

			}else if(v.size()==2){
				ll count=0;
				ll i=v[0];
				ll j=v[1];
				string temp=s;
				for(ll k=0;k<=5;k++){
					s=temp;
					if(k==5){
						s.erase(i);
					}else{
						s[i]=('a'+k);
					}
					for(ll l=0;l<=5;l++){
						if(k==)


					}
				}





			}




		}


	return 0;
}		