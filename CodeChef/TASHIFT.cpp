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

ll myFun(string &a,string &b,ll i,ll j){

if(j>=a.size() || i>=b.size() || a[j]!=b[i]){
	return 0;
}

return myFun(a,b,i+1,j+1)+1;


}

int main(){
		std::ios::sync_with_stdio(false); 
		cin.tie(NULL);
		cout.tie(NULL);

		ll n;
		cin >>n;
		string a,b;
		cin >>a>>b;
		vi v(2*n,0);
		ll j=0;
		b+=b;
		for(ll i=1;i<2*n;i++){
			if(b[i]==b[j]){
				v[i]=j+1;
				j++;
			}else{
				if(j==0){
					v[i]=0;

				}else{
				j=v[j-1];
				i--;
			}
			}
		}
		//show(v);
		ll count=0;
		ll start=-1;
		ll mx=0;
		j=0;	
		for(ll i=0;i<2*n;i++){
			//sss	cout <<i<<" ";
			if(a[j]==b[i]){
				count++;
				j++;
			}else{
				if(count >mx){
					if(i-count >=n){
						break;
					}
					start=i-count;
					mx=count;
					//cout <<count <<" "<<start<<endl;;
				}
				if(j!=0){
				count =v[j-1];
				j=v[j-1];
				i--;
			}

			}
			if(j>=n || count>=n){
				start=i-count;
				break;
			}
		}
		if(start==-1){
			cout << 0<< endl;
		}else
		cout << start<< endl;

	return 0;
}			