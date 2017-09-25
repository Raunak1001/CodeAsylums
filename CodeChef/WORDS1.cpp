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
#define vs vector<string>
#define mp make_pair		
#define pb push_back
#define vb vector<bool>
#define vvb vector< vb >
#define vvvb vector< vvb >
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,b,a) for(ll i=b;i>=a;i--)
#define show(a) rep(i,0,a.size()){cout <<a[i]<<" ";}
#define ct(a) cout <<a<<endl

void DFS(vvi &g,vb &visited,ll i){
	//cout <<i<< endl;
	ll temp=0;
	for(ll j=0;j<g[i].size();j++){
		if(!visited[g[i][j]]){
			temp=1;
			visited[g[i][j]]=1;
			DFS(g,visited,g[i][j]);
		}
	}

	

return ;

}




int main(){
		std::ios::sync_with_stdio(false); 
		cin.tie(NULL);
		cout.tie(NULL);

		ll t;
		cin >>t;
		for(ll z=0;z<t;z++){
			//cout <<t<< endl;
			ll cnt=0;
			vvi g(26);
			vi a(26,0),b(26,0);
			ll n;
			cin >>n;
		 vs v(n);
		 for(ll i=0;i<n;i++){
		 	cin >> v[i];
		 	char c=v[i][0];
		 	char p=v[i][v[i].size()-1];
		 	g[c-'a'].pb(p-'a');
		 	g[p-'a'].pb(c-'a');
		 	a[c-'a']++;
		 	b[p-'a']++;
		 }
		 
		 vb visited(n,0);

		 for(ll i=0;i<26;i++){
		 	if(g[i].size()%2!=0){
		 		cnt++;
		 	}
		 }
if(cnt>2){
			cout << "The door cannot be opened."<< endl;
			continue;
		}
		ll l=0;
		for(l=0;l<26;l++){
			if(g[l].size()!=0){
				break;
			}
		}
		visited[l]=1;
		if(g[l].size()==1){
			cnt++;
		}
		DFS(g,visited,l);

		
		ll temp=0;
		for(ll i=0;i<26;i++){
			if(visited[i]==0 && g[i].size()!=0){
				temp=1;
				cout<<"The door cannot be opened."<< endl;
				//cout <<"fsaf"<< endl;
				break;
			}
		}
		if(temp){
			continue;
		}
		ll one=0,two=0;
		for(ll i=0;i<26;i++){
			if(abs(a[i]-b[i])>=2){
				temp=1;
				cout<<"The door cannot be opened."<< endl;
				//cout <<"fsaf"<< endl;
				break;
			}
			if(a[i]-b[i]==1){
				two++;
			}
			if(b[i]-a[i]==1){
				one++;
			}

		}
		if(temp){
			continue;
		}

		if(one>1 || two >1){
			cout<<"The door cannot be opened."<< endl;
		}else if(!temp){
			cout <<"Ordering is possible."<< endl;
		}



		}

	return 0;
}			