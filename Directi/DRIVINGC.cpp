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

ll countV(vvb &visited){
ll count=0;
ll n=visited.size();
ll m=visited[0].size();
for(ll i=0;i<n;i++){
	for(ll j=0;j<m;j++){
		if(visited[i][j]){
			count++;
			visited[i][j]=0;
		}
	}
}
return count;

}



void myFun(vvc &v,ll i,ll j,vvb &visited,ll pi,ll pj){

ll n=v.size();
ll m=v[0].size();
if(i<0 || i>=n || j<0 ||j >=m){
	return ;
}

visited[i][j]=1;
if(v[i][j]=='r')
{
	if(pi+1==i){
		myFun(c,i,j-1,visited,i,j);
	}else if(pi-1==i){
		myFun(c,i,j+1,visited,i,j);
	}else if(pj+1==j){
			myFun(c,i+1,j,visited,i,j);
		}else{
			myFun(c,i-1,j,visited,i,j);
		}
	
}else if(v[i]=='l'){
	if(pi+1==i){
		myFun(c,i,j+1,visited,i,j);
	}else if(pi-1==i){
		myFun(c,i,j-1,visited,i,j);
	}else if(pj+1==j){
			myFun(c,i-1,j,visited,i,j);
		}else{
			myFun(c,i+1,j,visited,i,j);
		}
}
else{
	if(pi+1==i){
		myFun(c,i+1,j,visited,i,j);
	}else if(pi-1==i){
		myFun(c,i-1,j,visited,i,j);
	}else if(pj+1==j){
			myFun(c,i,j+1,visited,i,j);
		}else{
			myFun(c,i,j-1,visited,i,j);
		}
}
return ;



}

int main(){
		std::ios::sync_with_stdio(false); 
		cin.tie(NULL);
		cout.tie(NULL);

		ll t;
		while(t--){
		ll n,m;
		cin >> n>> m;
		vvc v(n,vc(m));
		vvb visited(n,vb(m,0));
		for(ll i=0;i<n;i++){
			for(ll j=0;j<m;j++){
				cin >> v[i][j];
			}
		}
		ll ans=0;
		for(ll i=0;i<n;i++){
			for(ll j=0;j<m;j++){
				if(v[i][j]=='.'){
					visited[i][j]=1;
					myFun(v,i+1,j,jvisited,i,j);
					ans=max(ans,countV(visited));
					myFun(v,i-1,j,visited,i,j);
					ans=max(ans,countV(visited));
					myFun(v,i,j+1,visited,i,j);
					ans=max(ans,countV(visited));
					myFun(v,i,j-1,visited,i,j);
					ans=max(ans,countV(visited));
						
				}
			}
		}

		cout << ans<< endl;
}
	return 0;
}			