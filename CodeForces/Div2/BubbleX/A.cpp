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
		cin >>n;
		string s;
		char a;
		ll sum=0;
		while(n--){
			cin >>a;
			sum+=(a-'0');
			if(n!=1)
			cout <a<"+";
			else
				cout <<a<< endl;
		}
		s=to_string(sum);
		n=s.size();
		sum=0;
		for(ll i=0;i<n;i++){
			a=s[i];
			sum+=('a'-0);
			if(i!=n-1){
				cout <<a<<"+";
			}else{
				cout <<a<< endl;
			}

		}

		s=to_string(sum);
		n=s.size();
		sum=0;
		for(ll i=0;i<n;i++){
			a=s[i];
			sum+=('a'-0);
			if(i!=n-1){
				cout <<a<<"+";
			}else{
				cout <<a<< endl;
			}

		}





	return 0;
}		