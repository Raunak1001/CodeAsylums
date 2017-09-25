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

void myFun(vi &count,ll a){
ll i=0;
while(a){

if(a%2!=0){
	count[i]++;
	
}
a=a>>1;
i++;
}
return ;

}

int main(){
		std::ios::sync_with_stdio(false); 
		cin.tie(NULL);
		cout.tie(NULL);

		ll n;
		cin >>n;
		vi v(n);
		vi count(33,0);
		for(ll i=0;i<n;i++){
			cin >> v[i];
			myFun(count,v[i]);
		}

		ll ans=0;
		//show(count);
		for(ll i=0;i<33;i++){
			count[i]=((count[i])*(count[i]-1))/2;
			ans+=(count[i])*(pow(2,i));
		}
		cout << ans<< endl;




	return 0;
}			