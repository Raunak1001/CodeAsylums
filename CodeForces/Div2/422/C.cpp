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

ll z=1000000000000000;

struct Node
{
	ll l;
	ll r;
	ll cost;
};

bool isValid(Node* a,Node* b){

if(a->l > b->r || b->l > a-> r){
	return true;
}
return false;
}


bool myFun(Node* a, Node* b){
	if(a->l==b->l){
		if(a->r==b->r){
			return a->cost < b->cost;
		}else{
			return a->r < b->r;
		}
	}
	return a->l < b->l;
}

Node* newNode(ll a, ll b,ll c){
	Node* n= new Node();
	n->l=a;
	n->r=b;
	n->cost=c;
	return n;
}

/*ll NewFun(vector<Node*> &v,vvi &ans, ll i,ll l,ll r,ll x){
	//cout << i<< endl;
	ll n=v.size();
	//cout << n<< endl;	
if(x<0 || (i>=n && x!=0)){
	return z;
}

if(x==0){
	return 0;
}

if(ans[i][x]!=-1){
	return ans[i][x];
}

if(i==n-1)
{
	if(x-(v[i]->r-v[i]->l+1)!=0){
		return z;
	}else{
		return ans[i][x]=v[i]->cost;
	}
}

 ll fin=NewFun(v,ans,i+1,l,r,x);
for(ll j=i+1;j<n;j++){
//cout << i<< endl;
if(isValid(v[j],l,r)){
//cout << j<<" "<<x<< endl;
	fin=min(NewFun(v,ans,j,v[i]->l,v[i]->r,x-(v[i]->r-v[i]->l+1))+v[i]->cost,fin);
}
}
return ans[i][x]=fin;
}
*/
int main(){

ll n,x;
scanf("%lld",&n);
scanf("%lld",&x);
vector<Node*> v(n);
vector<vector<Node*> > duration(x+1);
for(ll i=0;i<n;i++){
	ll a,b,c;
	scanf("%lld",&a);
	scanf("%lld",&b);
	scanf("%lld",&c);
	v[i]=newNode(a,b,c);
	Node* n= v[i];
	ll dur=b-a+1;
	if(dur<=x){
		duration[dur].push_back(v[i]);
	}
}

//sort(v.begin(),v.end(),myFun);
ll minCost=z;
ll minj=-1;

ll cost=0;
//cout <<x<< endl;
for(ll i=0;i<n;i++){

ll dur=v[i]->r-v[i]->l+1;
if(dur>x){
	continue;
}
for(ll j=0;j<duration[x-dur].size();j++){
Node* n = duration[x-dur][j];
if(isValid(n,v[i])){
	cost=v[i]->cost+n->cost;
minCost=min(minCost,cost);
}


}

}

if(minCost==z){
	cout << -1<<endl;
}
else{
	cout << minCost<< endl;
}


/*for(ll i=0;i<n;i++){
	cout << v[i]->l<<" "<<v[i]->r<<" "<<v[i]->cost<< endl;
}*/


/*vvi ans(n,vi(x+1,-1));

ll fin= NewFun(v,ans,0,-1,-1,x) ;
if(fin==-1 || fin ==z){
	cout << -1<< endl;
}
else{
	cout << fin << endl;
}*/
/*for(ll i=0;i<n;i++){
	for(ll j=0;j<x+1;j++){
		cout << ans[i][j]<<" ";
	}
	cout << endl;
}
*/
return 0;
	
}