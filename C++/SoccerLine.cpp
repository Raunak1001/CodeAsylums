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

void makeValue(vi &v,ll i,ll c,vi &a){

ll temp=a[i];
ll k=1;
while((c-k)>0 && k<=temp){
v[c-k]++;
k++;
}
k=1;
while(c+k<v.size() && k<=temp ){
	v[c+k]++;
	k++;
}

return ;


}

void myFun(vi &a,vi &v,ll i,ll count){

	ll m=a.size();
	if(count >=m){
		return ;
	}
	ll n=v.size();
	if(i>=n || i<=0){
		return ;
	}

	makeValue(v,count,i,a);

	myFun(a,v,i+a[count],count+1);
	myFun(a,v,i-a[count],count+1);
return ;

}


int main(){
		std::ios::sync_with_stdio(false); 

		ll t;
		cin >>t;
		while(t--){

			ll n,m,c;
			cin >>n>>m>>c;
			vi a(m);
			for(ll i=0;i<m;i++){
				cin >> a[i];
			}

			vi v(n+1,0);
			//cout << c<< endl;
			v[c]=1;
			if(m==0){
				for(ll i=0;i<n;i++){
					cout <<0<<" ";
				}
				cout << endl;
				return 0;
			}
			makeValue(v,0,c,a);
			myFun(a,v,c+a[0],1);
			myFun(a,v,c-a[0],1);


			for(ll i=1;i<=n;i++){
				cout << v[i]<<" ";
			}
			cout << endl;

		}


	return 0;
}