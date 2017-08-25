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

bool myFun(Node* a,Node* b){
	return a->cost < b->cost;
}

Node* newNode(ll a,ll b,ll c){
Node* n = new Node();
n->a=a;
n->b=b;
n->cost=c;
return n;
}

ll root(ll a, vi &parent)
{
	while(parent[a]!=a){
		ll temp=parent[a];
		parent[a]=parent[parent[a]];
		a=temp;
	}
	return a;
}

void unin(ll a,ll b, vi &parent){

parent[root(a,parent)]=parent[root(b,parent)];
return ;

}

int main(){
	while(1){
ll n,m;
cin >> n>>m;
if(n==0 && m==0) {
	break;
}
ll mainCost=0;
vector<Node*> v(m);
for(ll i=0;i<m;i++){
 ll a,b,c;
 cin >> a>> b>> c;
 v[i]=(newNode(a,b,c));
 mainCost+=c;
}
sort(v.begin(),v.end(),myFun);
//cout <<"ASf"<<endl;

vi parent(n);
for(ll i=0;i<n;i++){
	 parent[i]=i;
}

/*for(ll i=0;i<m;i++){
	cout <<v[i]->a<<" "<<v[i]->b<<" "<< v[i]->cost<< endl;
}*/
ll cost=0;
for(ll i=0;i<m;i++){
	Node* n= v[i];
	if(root(n->a,parent)!=root(n->b,parent)){
		unin(n->a,n->b,parent);
		cost+=n->cost;	
		//cout << i<< endl;
	}
}
/*for(ll i=0;i<n;i++){
	cout << parent[i]<< " ";
}
*/

cout << mainCost-cost<< endl;






	}


}