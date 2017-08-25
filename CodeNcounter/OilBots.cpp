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
	#define vb std::vector<bool> 
	ll mod=1000000007;
	struct Node{
		ll a;
		ll b;
		ll d;
	};

	bool sortFun(Node* a, Node* b){
		return a->d < b->d;
	}

	bool sortF(pr a,pr b){
		return a.second<b.second;	
	}

	ll findP(ll a,vi &parent){

	while(parent[a]!=a){

		ll temp=parent[a];
		parent[a]=parent[parent[a]];
		a=temp;
	}

	return parent[parent[a]];

	}

	void un(ll a,ll b,vi &parent){

		findP(a,parent);
		findP(b,parent);
		parent[parent[a]]=parent[parent[b]];


	}






	int main(){
			std::ios::sync_with_stdio(false); 


			ll n,start;
			cin >>n>> start;
			ll a,b,c;
			vector<Node*> v;
			vvp g(n+1);
			//priority_queue<pr,vp,greater<pr> > pq;
			while(1){
				cin >>a;
				if(a==0){
					break;
				}
				cin >>b;
				cin >>c;
				Node* node=new Node();
				node->a=a;
				node->b=b;
				node->d=c;
				v.pb(node);
			}

			vb visited(n+1,0);
			sort(v.begin(),v.end(),sortFun);

			vi parent(n+1);
			for(ll i=1;i<=n;i++){
				parent[i]=i;
			}

			for(ll i=0;i<v.size();i++){
				Node* node=v[i];
				//pq.pop();
				if((findP(node->a,parent) != findP(node->b,parent))){
					visited[node->a]=1;
					visited[node->b]=1;
					g[node->a].pb(mp(node->b,node->d));
					g[node->b].pb(mp(node->a,node->d));
					un(node->a,node->b,parent);
				}


			}


			for(ll i=0;i<=n;i++){
				visited[i]=0;
			}
			vi dis(n+1,0);
			queue<ll> q;
			q.push(start);
			dis[start]=0;
			//cout <<start<<" ";
			visited[start]=1;
			ll ans=0;

	for(ll i=1;i<=n;i++){
		sort(g[i].begin(),g[i].end(),sortF);
	}
	if(n==0){
		return 0;
	}
	
	vp newV;
	
			while(!q.empty()){
				ll temp=q.front();
			//	cout << temp<< " ";
				newV.pb(mp(temp,dis[temp]));
				q.pop();
				for(ll i=0;i<g[temp].size();i++){
					//cout << g[temp][i].first<<" ";
					if(!visited[g[temp][i].first]){
					dis[g[temp][i].first]=(dis[temp]%mod + (g[temp][i].second)%mod)%mod;
					ans=(ans%mod + dis[g[temp][i].first]%mod)%mod;
					visited[g[temp][i].first]=1;
					q.push(g[temp][i].first);
				}
				}


			}
			
			sort(newV.begin(),newV.end(),sortF);
			for(ll i=0;i<newV.size();i++){
			    cout << newV[i].first<<" ";
			}
			
			cout << endl;
			cout <<ans << endl;
			

		return 0;
	}