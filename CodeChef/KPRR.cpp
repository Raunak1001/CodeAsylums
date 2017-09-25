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
		while(t--){
    ll count=0;
			string s;
			cin >>s;
			map<ll,bool> m;
			if(s=="6174"){
			    cout << 0<< endl;
			    continue;
			}
			while(1){
			    count++;
			sort(s.begin(),s.end());
			string ns=s;
			reverse(ns.begin(),ns.end());
			while(s.size()<4){
				s+='0';
			}

			ll n=stoi(s);
			ll  nm=stoi(ns);
			ll temp=n-nm;
			if(temp==6174){
				cout << count<< endl;
				break;
			}
			if(m[temp]){
				cout <<0<< endl;
				break;
			}
			m[temp]=1;
			s=to_string(temp);
		}
		}


	return 0;
}			