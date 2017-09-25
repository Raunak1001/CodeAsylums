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

		ll n,m,k;
		cin >>n>>m>>k;
		vb v(n);
		vi diff;
		for(ll i=0;i<n;i++){
			ll a;
			cin >>a;
			v[i]=a;
			if(a==1){
				diff.pb(i);
			}
		}
		if(diff.size()<m){
			cout <<-1<<endl;
			return 0;
		}
		//show(diff);
		ll time=diff[0];
		ll c=1;
		for(ll i=1;i<m;i++){
			time+=(c*(diff[i]-diff[i-1]))*k;
			c++;
		}
		ll nt;
		ll prevTime=time;
		ll j=0;
		if(m==1){
			cout << time<< endl;
			return 0;
		}
		//cout << endl;
		//cout << time<< endl;
		for(ll i=m;i<diff.size();i++){
			//cout <<"SADF"<< endl;
			nt=prevTime;
			nt+=diff[j+1]-diff[j];
			//cout << nt<< endl;
			nt-=(diff[i-1]-diff[j])*k;
			//cout << nt<< endl;
			nt+=(m-1)*(diff[i]-diff[i-1])*k;
			//cout << nt<< endl;
			time=min(time,nt);
			prevTime=nt;
			j++;

		}

		cout << time<< endl;



	return 0;
}		