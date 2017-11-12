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
		for(ll q=0;q<t;q++){
			ll n;
			ll temp=0;
			cin >> n;
			vi v(n);
			for(ll i=0;i<n;i++){
				cin >> v[i];
			}

			vi a=v;
			sort(a.begin(),a.end());
			ll start=0;
			ll end=n-1;
			ll mid=(n-1)/2;
			ll l=mid;
			ll r=mid;
			ll count=n;
			while(l>=0 && r<=n-1){
				if(count<=2){
					break;
				}
				if(v[mid]==a[start] || v[mid]==a[end]){

					if(v[mid]==a[start]	){
						start++;
					}else{
						end--;
					}

					if(count%2==0){
						r++;
						mid=r;
					}else{
						l--;
						mid=l;
					}
					count--;

				}else{
					temp=1;
					break;
				}


			}

			if(temp){
				cout <<"Case #"<<q+1<<": NO"<< endl;
			}else{
				cout << "Case #"<<q+1<<": YES"<<endl;
			}



		}




	return 0;
}			