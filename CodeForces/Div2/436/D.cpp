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
#define MAX 200 000


int main(){
		std::ios::sync_with_stdio(false); 
		cin.tie(NULL);
		cout.tie(NULL);

		ll n;
		cin >> n;
		vi v(n);
		vi a(n+1,0);
		for(ll i=0;i<n;i++){
			cin >> v[i];
			a[v[i]]++;
		}	
		/*show(v);
		cout << endl;*/

		vi b;
		for(ll i=1;i<=n;i++){
			if(a[i]==0){
				b.pb(i);
			}else if(a[i]==1){
				a[i]=-1;
			}
		}
		/*show(b);
		cout << endl;*/
		ll j=0;
		unordered_map<ll,bool> m;
		for(ll i=0;i<n;i++){
			if(a[v[i]]>1){
				a[v[i]]--;
				if(b[j]<v[i] || m[v[i]]==1){
					v[i]=b[j];
					j++;
				}else{
					m[v[i]]=1;
				}
			}else if(a[v[i]]==1 && m[v[i]]==1){
				//cout << i<< endl;
				a[v[i]]--;
				v[i]=b[j];
				j++;
			}
			
		}

		cout << b.size()<< endl;
		show(v);
		cout << endl;


	return 0;
}			