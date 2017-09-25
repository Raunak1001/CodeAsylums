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
#define show(a) rep(i,1,a.size()){cout <<i<<" "<<a[i]<<endl;}
#define ct(a) cout <<a<<endl

bool hp(ll a,ll b,vvi &w,ll bandi){
ll n=w.size()-1;

for(ll i=1;i<=n;i++){

if(w[bandi][i]==a){
	return 1;
}else if(w[bandi][i]==b){
	return 0;
}

}




}



void myFun(vvi &w,vvi &mn,ll i,vb &visited,ll j,vb &av,vi &kisko){


	if(visited[mn[i][j]]){
			myFun(w,mn,i,visited,j+1,av,kisko);
		}

	if(av[mn[i][j]]==0){
		av[mn[i][j]]=1;
		kisko[mn[i][j]]=i;
		return ;
	}else{

		ll temp=kisko[mn[i][j]];
		if(hp(temp,i,w,mn[i][0])){
			visited[mn[i][j]]=1;
			myFun(w,mn,i,visited,j+1,av,kisko);
		}else{
			kisko[mn[i][j]]=i;
			visited[mn[i][j]]=1;
			myFun(w,mn,temp,visited,1,av,kisko);
		}
	}


}

int main(){
		std::ios::sync_with_stdio(false); 
		cin.tie(NULL);
		cout.tie(NULL);

		ll t;
		cin >>t;
		while(t--){
			ll n;
			cin >>n;
			
			vvi w(n+1,vi(n+1));
			vvi mn(n+1,vi(n+1));

			for(ll i=1;i<=n;i++){
				ll a;
				cin >>a;
				for(ll j=1;j<=n;j++){
				
					cin>> w[i][j];
				}
			}
			for(ll i=1;i<=n;i++){
				ll a;
				cin >>a;
				for(ll j=1;j<=n;j++){
					cin>>mn[i][j];
				}
			}	
			//cout <<"AS"<< endl;

			vb av(n+1,1);
			vi kisko(n+1,0);

			ll free=0;
			while(free<n){
				ll i;
				for(i=1;i<=n;i++){
					if(av[i]){
						break;
					}
				}
				//cout <<i<< endl;
				vb visited(n+1,0);
				for(ll j=1;j<=n;j++){

					if(kisko[mn[i][j]]==0){
						kisko[mn[i][j]]=i;
						av[i]=0;
						free++;
						break;
					}else{
						if(visited[mn[i][j]]){
							continue;
						}else{
							visited[mn[i][j]]=1;
							if(hp(i,kisko[mn[i][j]],w,mn[i][j])){
								av[kisko[mn[i][j]]]=1;
								av[i]=0;
								kisko[mn[i][j]]=i;
								break;
							}
						}
					}
				}



			}
			
				vi ans(n+1);
				for(ll i=1;i<=n;i++){
					ans[kisko[i]]=i;
				}

				show(ans);
				
				

		}


	return 0;
}			