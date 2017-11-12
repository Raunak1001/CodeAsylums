	#include<bits/stdc++.h>
	using namespace std;
	#define pr pair<int,int>
	#define vp vector<pr>
	#define vvp vector<vp>

	void dfs(int vertex,vector<int> &dis,vector<int> &count,vector<bool> &visited,vvp &v,int weight){

		if(vertex!=1 && dis[vertex]==weight){
			count[vertex]++;
		}

		for(int i=0;i<v[vertex].size();i++){
			if(!visited[v[vertex][i].first]){
				visited[v[vertex][i].first]=1;
				dfs(v[vertex][i].first,dis,count,visited,v,weight+v[vertex][i].second);
				visited[v[vertex][i].first]=0;
			}
		}

		return ;

	}



	int main(){


		int vertices;
		cin >> vertices;
		int edge;
		cin >> edge;
		vvp v(vertices+1);
		for(int i=0;i<edge;i++){
			int a,b,cost;
			cin >>a>>b>>cost;
			v[a].push_back(make_pair(b,cost));
			v[b].push_back(make_pair(a,cost));
				
		}
		priority_queue<pr,vp,greater<pr> > pq;
		vector<int> dis(vertices+1,INT_MAX);
		dis[1]=0;
		pq.push(make_pair(0,1));
		while(!pq.empty()){
			pr p=pq.top();
			pq.pop();
			for(int i=0;i<v[p.second].size();i++){
				if(dis[v[p.second][i].first]>dis[p.second]+v[p.second][i].second){
					dis[v[p.second][i].first]=dis[p.second]+v[p.second][i].second;
					pq.push(make_pair(dis[v[p.second][i].first],v[p.second][i].first));
				}
			}
		}
				//cout <<"SAf"<< endl;

		vector<int> count(vertices+1,0);
		vector<bool> visited(vertices+1,0);
		visited[1]=1;
		dfs(1,dis,count,visited,v,0);

		int ans=1;
		for(int i=2;i<=vertices;i++){
			ans*=count[i];
		}

		cout << ans<< endl;


	return 0;

	}