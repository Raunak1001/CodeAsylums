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
#define vb vector<bool>
	map<string,ll> q;
		map<ll,string> p;
		
bool myFun(ll a,ll b){
    
    return p[a] >p[b];
    
}
		
void topo(vvi &v,vb &visited ,stack<ll> &s,ll i){

	visited[i]=true;

	for(ll j=0;j<v[i].size();j++){
		if(!visited[v[i][j]]){
			topo(v,visited,s,v[i][j]);
		}
	}
s.push(i);
return ;

}



int main(){
		std::ios::sync_with_stdio(false); 


		ll n,m;
		cin >>n>>m;
		vvi v(n+1);

		string a,b;
		ll temp=1;
		ll count1,count2;
	p.clear();
	q.clear();
		for(ll i=0;i<m;i++){
			cin >> a>> b;
			if(q.find(a)==q.end()){
				count1=temp;
				temp++;
				p[count1]=a;
				q[a]=count1;
			}else{
				count1=q[a];
			}

			if(q.find(b)==q.end()){
				count2=temp;
				temp++;
				p[count2]=b;
				q[b]=count2;
			}else{
				count2=q[b];
			}
			//cout << count1<< " "<< count2<< endl;
			v[count2].pb(count1);
		}
		//q.clear();
		//cout <<"fsdd"<< endl;	
	    for(ll i=1;i<=n;i++){
	        sort(v[i].begin(),v[i].end(),myFun);
	    }
						//cout <<"SDD"<< endl;

		vb visited(n+1,0);
		stack<ll> s;
		map<string,ll> :: reverse_iterator  it;
		for(it=q.rbegin();it!=q.rend();++it){
			if(!visited[it->second]){
				topo(v,visited,s,it->second);
			}
		}
		if(!s.empty()){
			cout <<p[s.top()];
			s.pop();
		}

		while(!s.empty()){
			cout << " -> ";
			cout <<p[s.top()];
			s.pop();
		}
		

	return 0;
}