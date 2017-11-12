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

bool sortFun(pr a,pr b){
	return a.first<b.first;
}


int main(){
		std::ios::sync_with_stdio(false); 
		cin.tie(NULL);
		cout.tie(NULL);

		ll n;
		cin >> n;
		ll required=0;
		vi a(n+1),b(n+1),d(n+1),sum(n+1),l(n+1);
		for(ll i=0;i<n;i++){
			cin >> a[i];
			required+=a[i];
		}

		for(ll j=0;j<n;j++){
			cin >> b[j];
		}
		vp c;
		for(ll i=0;i<n;i++){
			ll z;
			cin >> z;
			l[i]=z;
			c.pb(mp(z,i));
		}

		for(ll i=0;i<n-1;i++){
			cin >> d[i];
		}
		sort(c.begin(),c.end(),sortFun);

		ll ans=0;
		ll removed=0;
		ll i=0;
		while(removed<required  && i<c.size()){
			if(b[c[i].second]==0){
				i++;
				if(i>=n && removed<required){
				cout << -1<< endl;
				return 0;
			}
				continue;
			}
			ll temp=c[i].first;
			ll capacity=b[c[i].second];
			ll x=min(capacity,a[c[i].second]);
			capacity-=x;
			removed+=x;
			ans+=temp*x;
			//cout << ans<< endl;
			//cout <<"asd"<< endl;
			a[c[i].second]-=x;

			if(a[c[i].second]!=0){
				ll cost=0;
			ll j=c[i].second;
			while(a[c[i].second]!=0){
				b[c[i].second]=0;
				while(j<n-1 && b[j]==0){
					cost+=d[j];
					j++;
				}
				if(j==n-1 && b[n-1]==0){
					cout <<-1<< endl;
					return 0;
				}else{
					if(l[j]<temp){
						ans+=min(b[j],a[c[i].second])*(l[j]+cost);
						ll x=min(b[j],a[c[i].second]);
						a[c[i].second]-=x;
						b[j]-=x;
					}else{
						a[j]+=a[c[i].second];
						ans+=(cost)*a[c[i].second];
						a[c[i].second]=0;
					}
					
				}
			}
			continue;
		}
			ll j=c[i].second;
			ll cost=0;
			while(capacity>0 ){
				while(j>0 && a[j]==0){
					j--;
					if(j>0){
						cost+=d[j];
					}
				}
				if(j<0){
					b[c[i].second]=capacity;
					break;
				}else{
					if(cost+temp<l[j]){
						ll y=min(capacity,a[j]);
						capacity-=y;
						ans+=(cost+temp)*y;
						a[j]-=y;
						removed+=y;
						b[c[i].second]=capacity;
					}else{
						b[c[i].second]=capacity;
					    break;
					}
				}
			}
			//cout << ans<< endl;	
			i++;
			if(i>=n && removed<required){
				cout << -1<< endl;
				return 0;
			}
		}

		cout << ans<< endl;




	return 0;
}			