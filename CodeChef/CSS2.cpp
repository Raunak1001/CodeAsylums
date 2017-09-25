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
		map<pr,pr> m;

		for(ll i=0;i<n;i++){
			ll a,b,c,d;
			cin >>a>>b>>c>>d;
			pr p=mp(a,b);
			if(m.find(p)!=m.end()){
				pr t=m[p];
				if(t.second<=d){
					t.second=d;
					t.first=c;
				m[p]=t;
				}
			}else{
				m[p]=mp(c,d);
			}
		}

		while(q--){

			ll a,b;
			cin >>a>>b;	
			pr p=mp(a,b);
			cout << m[p].first<< endl;


		}




	return 0;
}			