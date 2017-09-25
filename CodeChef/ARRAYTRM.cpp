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
		ll n,k;
		cin >>n>>k;
		vi 	a(n);
		k++;
		rep(i,0,n){
			cin >> a[i];
			a[i]%=k;
		}
		if(n==2){
			cout <<"YES"<< endl;
			continue;
		}

		sort(a.begin(),a.end());

		ll count=1;
		ll i=0;

			if(a[0]==a[1]){
			while(i<n-1 && a[i]==a[i+1]){
				count++;
				i++;
			}
		}else if(a[n-1]==a[n-2]){

			i=n-1;
			while(i>=1 && a[i]==a[i-1]){
				count++;
						i--;
					}
		}
		if(count>=n-1){
			cout <<"YES"<< endl;			
		}else{
			cout << "NO"<< endl;
		}


}
	return 0;
}		