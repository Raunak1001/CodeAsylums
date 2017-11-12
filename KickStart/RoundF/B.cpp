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
		for(ll q=0;q<t;q++){
		ll s,n;
		cin >>s>> n;
		vi v(n);
		for(ll i=0;i<n;i++){
			cin >> v[i];
		}

		sort(v.begin(),v.end());
		ll l=0;
		ll r=n-1;
		ll honor=0;

		while(l<=r){


		if(s>v[l]){
			s-=v[l];
			honor++;
			l++;
		}else{
			if(l==r){
				break;
			}
			if(s+v[r]>v[l] && honor>0){
				s+=v[r];
				r--;
				honor--;
			}else{
				break;
			}
		}


}
cout <<"Case #"<<q+1<<": "<<honor<< endl;

}
	return 0;
}			