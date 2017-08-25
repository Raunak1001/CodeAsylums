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


struct Node
{
	ll a;
	ll b;
	ll cost;
};

Node* newNode(ll a,ll b,ll c){
Node* n=new Node();
n->a=a;
n->b=b;
n->cost=c;
return n;
}

ll root(ll a, vi &parent){
 	
 	while(parent[a]!=a){
 		ll temp=parent[a];
 		parent[a]=parent[parent[a]];
 		a=temp;
 	 	}
 	 	return a;
}

void unin(ll a,ll b, vi &parent, vi &v){

		//cout << a<< b<<endl;


	if(v[root(a,parent)]){
		parent[root(b,parent)]=parent[root(a,parent)];

		return ;
	}
		parent[root(a,parent)]=parent[root(b,parent)];
		return;


}

bool myFun(Node* a,Node* b){
	return a->cost < b->cost;
}

int main(){
		
	ll t;
	cin >>t;
	for(ll q=0;q<t;q++){
		ll n,m;
		cin >>n>>m;
		vi v(n+1);
		for(ll i=1;i<=n;i++){
			cin >> v[i];
		}

		 vector<Node*> g(m);

		 for(ll i=0;i<m;i++){
		 	ll a,b,c;
		 	cin >> a>>b>>c;
		 	g[i]=newNode(a,b,c);
		 }

		 sort(g.begin(), g.end(),myFun);

		 vi parent(n+1);
		 for(ll i=1;i<=n;i++){
		 	parent[i]=i;
		 }
   		
   		ll  cost =0;

/*for(ll i=0;i<m;i++){
	cout << g[i]->a<<" "<< g[i]->b<<" "<< g	[i]->cost<< endl;
}
*/
		 for(ll i=0;i<m;i++){
		 	Node* node =g[i];
		 			 		//cout << v[root(n->a,parent)]<<" "<<v[root(n->b,parent)]<< endl;

		 	if(root(node->a,parent)!=root(node->b,parent) && (v[root(node->a,parent)]!=1 || v[root(node->b,parent)]!=1)){
		 		cost+=node->cost;
		 		unin(node->a,node->b,parent,v);
		 	}

/*		 	 for(ll j=1;j<=n;j++)
		 {
		 	cout << parent[j]<< " ";
		 }
		 cout << endl;*/
		 }


		
		 ll temp=0;
		for(ll i=1;i<=n;i++){
			if(!v[root(i,parent)]){
				cout <<"impossible"<< endl;
				temp=1;
				break;
			}
		}
		if(!temp)
		cout << cost<< endl;

	}



}