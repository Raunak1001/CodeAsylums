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
			ll n;
			ll last;
			cin >> n>> last;
			if(n==1){
				cout << last<< endl;
				continue; 
			}
			if(n==2){
				cout << last-1<< endl;
				continue;
			}
			n--;
			ll d=1;
			while(1){
				ll a=last-n*d;
				if(a%d!=0){
					cout << a<< endl;
					break;
				}else{
					ll temp=a/d;
					ll mn=n-(n-1+n-2);
					ll mx=n-(1);
					if(temp<mn || temp > mx){
						cout <<a<< endl;
						break;
					}
				}
				d+=2;
			}
		}


	return 0;
}			