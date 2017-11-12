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
			ll n,a;
			cin >>n>>a;

			if(a==1){
				cout << n<<" ";
				while(n){
					cout << "a";
					n--;
				}
				cout << endl;
				continue;
			}
			if(a>=3 || n==2){
				cout << 1<<" ";
				ll temp=0;
				while(n){
					cout <<char(temp+'a');
					temp++;
					temp%=a;
					n--;
				}
				cout << endl;
				continue;
			}

			if(n==3 || n==4 ){
				cout << 2<<" ";
				cout <<"aab";
				if(n==4){
					cout <<"b";
				}
				cout << endl;
				continue;
			}

			string s="aaababb";
			cout <<3<<" ";
			ll i=n;
			while(i-7>=0){
				cout <<s;
				i=i-7;
			}
			ll count=0;
			while(i>0 && count<3){
				cout <<"a";
				i--;
				count++;
			}
			if(i>0){
				cout <<"b";
				i--;
			}
			if(i>0){
				cout <<"a";
				i--;
			}
			count=0;
			while(i>0 && count<2){
				cout <<"b";
				count++;
				i--;
			}

			cout << endl;
		}


	return 0;
}			