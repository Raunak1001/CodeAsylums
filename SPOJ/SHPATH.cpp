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



int main(){
/*ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
*/
ll t;
scanf("%lld",&t);
for(ll z=0;z<t;z++){

ll n;
scanf("%lld",&n);
vvi v(n+1,vi(n+1,0));
map<string,ll> m;
for(ll i=1;i<=n;i++)
{	string s;
	cin >>s;
	m[s]=i;
	ll m;
scanf("%lld",&m);
	for(ll j=0;j<m;j++){
		ll a, b;
scanf("%lld",&a);
scanf("%lld",&b);
		v[i][a]=b;

	}
}


/*for(ll i=1;i<=n;i++){
	for(ll j=1;j<=n;j++){
		cout << dis[i][j]<<" ";
	}
	cout << endl;

}*/





ll q;
cin >> q;
for(ll i=0;i<q;i++){
string a,b;
cin >>a;
cin >>b;
ll j=m[a];
ll k=m[b];
vi dis(n+1,200001);
dis[j]=0;
priority_queue<pr,vp,greater<pr> > pq;
pq.push(mp(0,j));
while(!pq.empty()){
pr p=pq.top();
pq.pop();
for(ll i=1;i<=n;i++){
	if(v[p.second][i]!=0){
		if(dis[i]>dis[p.second]+v[p.second][i]){
			dis[i]=dis[p.second]+v[p.second][i];
			pq.push(mp(dis[i],i));
		}

	}
}

}
printf("%lld\n",dis[k]);

}



}


}