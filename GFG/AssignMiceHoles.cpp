#include<bits/stdc++.h>
using namespace std;
#define vi vector<long long int>
#define vp vector<pair<long long int,long long int > >
#define vc vector<char>
#define vvi vector<vector<long long int>  >
#define vvp vector<vector<pair<long long int,long long int> > >
#define vvc vector<vector<char>  >
#define ll long long int 
#define pr pair<long long int,long long int>
#define mp make_pair		
#define pb push_back

int main(){
    
    ll t;
    cin >>t;
    while(t--){
        
        ll n;
        cin >>n;
        vi a(n);
        vi b(n);
        for(ll i=0;i<n;i++){
            cin >> a[i];
        }
        
        for(ll i=0;i<n;i++){
            cin >> b[i];
        }
        
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        ll cost=-1;
        for(ll i=0;i<n;i++){
        	//cout << a[i]<<" "<< b[i]<< endl;
            cost=max(cost,abs(a[i]-b[i]));
        }
        
        cout << cost<< endl;
        
    }
    
    
	return 0;
}