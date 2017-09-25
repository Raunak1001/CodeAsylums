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
#define show(a) rep(i,a,b){cout <<a[i]<<" ";}
#define ct(a) cout <<a<<endl

ll cnt=0;
bool myFun(map<ll,ll> &visited, vp &v, ll j,ll required){
	
	ll n=v.size();
	if(required==0){
		return 1;
	}
	if(j==(pow(2,n))-1){
		return 1;
	}
	/*if(visited[j]==1){
		return 0;
	}*/
	//cout <<j<< endl;	
ll copy=j;
ll newCopy;
	rep(i,0,n){

		copy=j;
		if((j & (1<<i))!=0){
			//cout <<" fass "<<j<<" "<<i<< endl;
			continue;
		}
		copy=(copy^((1<<i)));
		//cout << "fsadfsdf"<<copy<<" ";
		newCopy=copy;
		if(v[i].first==required){
			//cout << "saf " <<i<<endl;
			if(v[i].second==0){
				if(copy==(pow(2,n))-1){
					return 1;
				}else{
					continue;
				}
			}
			if(myFun(visited,v,copy,v[i].second)){
				return 1;
			}
			continue;
		}
		rep(k,i+1,n){
			copy=newCopy;
			//cout<<i<<" "<<v[i].first+v[k].first<<" "<<k<<endl;
			if(v[i].first+v[k].first==required && ((j & (1<<k))==0)){
				copy=(copy^((1<<k)));
				//cout <<"asdf"<<copy<<endl;
				ll temp=1;
				if(v[i].second!=0){
					temp=myFun(visited,v,copy,v[i].second);
				}
				if(v[k].second!=0){
					temp =temp & myFun(visited,v,copy,v[k].second);
				}
				if(v[i].second==0 && v[k].second==0 && copy==(pow(2,n))-1 )
				{
					return 1;
				}else{
					continue;
				}
				
				if(temp){
					temp;
				}
				}
		}
		
	}

return 0;
}



int main(){
		std::ios::sync_with_stdio(false); 
		cin.tie(NULL);
		cout.tie(NULL);

		ll t;
		cin >>t;
		while(t--){
			cnt=0;
			ll n;
			cin >>n;
			vp v(n);
			rep(i,0,n){
				ll a,b;
				cin >>a>>b;
				v[i].first=a;
				v[i].second=b;
			}
			map<ll,ll> visited;
			map<ll,ll> ans;
			rep(i,0,n){
				if(myFun(visited,v,(1<<i),v[i].second)){
					ct(v[i].first);
				}
			}
	
		}



	return 0;
}		