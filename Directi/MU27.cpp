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
#define vvb vector< vb >
#define vvvb vector< vvb >
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,b,a) for(ll i=b;i>=a;i--)
#define show(a) rep(i,0,a.size()){cout <<a[i]<<" ";}
#define ct(a) cout <<a<<endl

ll ans=INT_MAX;

void myFun(string &a,string &b,ll i, vi &va,vi &vb){

ll n=a.size();
if(i>=n){
	ll count1=0;
	ll count2=0;
	for(ll i=0;i<26;i++){
		if(va[i]>0){
			count1++;
		}
		if(vb[i]>0){
			count2++;
		}
	}
	//cout << count1<<" "<<count2<< endl;	
	ans=min(ans,max(count1,count2));
	return ;
}

myFun(a,b,i+1,va,vb);
ll temp1=a[i]-'a';
ll temp2=b[i]-'a';
va[temp1]--;
vb[temp2]--;
va[temp2]++;
vb[temp1]++;
myFun(a,b,i+1,va,vb);
va[temp1]++;
vb[temp2]++;
va[temp2]--;
vb[temp1]--;

return ;

}



int main(){
		std::ios::sync_with_stdio(false); 
		cin.tie(NULL);
		cout.tie(NULL);

		ll t;
		cin >> t;
		while(t--){
			ans=INT_MAX;
			ll n;
			cin >> n;
			string a,b;
			cin >> a>>b;
			vi va(26,0);
			vi vb(26,0);
			for(ll i=0;i<n;i++){
				ll temp1=a[i]-'a';
ll temp2=b[i]-'a';
va[temp1]++;
vb[temp2]++;
			}
			ll i=0;
			myFun(a,b,i+1,va,vb);
			ll temp1=a[i]-'a';
ll temp2=b[i]-'a';
va[temp1]--;
vb[temp2]--;
va[temp2]++;
vb[temp1]++;
myFun(a,b,i+1,va,vb);
va[temp1]++;
vb[temp2]++;
va[temp2]--;
vb[temp1]--;

			cout << ans<< endl;

		}

	return 0;
}			