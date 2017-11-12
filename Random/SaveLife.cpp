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
		    cin >> s;
		    ll n;
		    cin >> n;
		    vc v(n);
		    for(ll i=0;i<n;i++){
		        cin >> v[i];
		    }

		    map<char,ll> m;
		    for(ll i=0;i<n;i++){
		        ll a;
		        cin >> a;
		        m[v[i]]=a;
		    }
		       ll currentMax=0;
		       ll totalMax=0;
		       ll currentstart=0,currentend=0;
		       ll mainstart=0,mainend=0;
		    for(ll i=0;i<s.size();i++){
		        if(m.find(s[i])!=m.end()){
		            currentMax+=m[s[i]];
		        }else{
		            s[i]<'a' ? currentMax+=s[i]-	'A' : currentMax+=s[i]-'a';
		        }
		        currentend=i;
		        if(currentMax<=0){
		            currentMax=0;
		            currentstart=i+1;
		            currentend=i+1;
		        }else if(currentMax>totalMax){
		            totalMax=currentMax;
		            mainstart=currentstart;
		            mainend=currentend;
		        }
		        
		    }
		    
		    for(ll i=mainstart;i<=mainend;i++){
		        cout << s[i];
		    }
		    cout << endl;
		    
		    
		    
		}

	return 0;
}