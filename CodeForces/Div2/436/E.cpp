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
#define show(a) rep(i,0,a.size()){cout <<a[i]+1<<" ";}
#define ct(a) cout <<a<<endl

struct Node{
	ll t,d,p,i;
};

bool sortFun(Node a,Node b){

	return a.d<b.d;
}

vi myFun(vector<Node> &v, vvvi &dp,ll i,ll time){

	ll n=v.size();
	if(i>=n || time	>2001){
		vi mid;
		return mid;
	}

	if(dp[i][time].size()!=0){
		return dp[i][time];
	}
	vi count=myFun(v,dp,i+1,time);
	ll ans=0;
	for(ll j=0;j<count.size();j++){
		ans+=v[count[j]].p;
	}
	if(time+v[i].t<v[i].d){
		vi k=myFun(v,dp,i+1,time+v[i].t);
		ll ans2=v[i].p;
		for(ll j=0;j<k.size();j++){
		ans2+=v[k[j]].p;
		}
		if(ans<ans2){
			k.pb(i);
			count=k;
		}

}
//cout << i<<" "<< ans<< endl;
return dp[i][time]=count;

}


int main(){
		std::ios::sync_with_stdio(false); 
		cin.tie(NULL);
		cout.tie(NULL);

		ll n;
		cin >>n;
		vector<Node> v(n);
		for(ll i=0;i<n;i++){
			ll t,d,p;
			cin >> t>>d>>p;
			v[i].t=t;
			v[i].d=d;
			v[i].p=p;	
			v[i].i=i;
		}
		sort(v.begin(),v.end(),sortFun);
		/*for(ll i=0;i<n;i++){
			cout << v[i].t<<" "<<v[i].d<< " "<< v[i].p<<" "<< v[i].i<<" "<< endl;
		}*/
		vvvi dp(n+1,vvi(2001));
		vi k=myFun(v,dp,0,0);
		ll ans=0;
		for(ll i=0;i<k.size();i++){
			ans+=v[k[i]].p;
			k[i]=v[k[i]].i;
		} 	
		cout << ans<< endl;
		cout << k.size()<< endl;
		//sort(k.begin(),k.end());
		reverse(k.begin(),k.end());
		show(k);
		cout << endl;	


	return 0;
}			