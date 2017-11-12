#include<bits/stdc++.h>
using namespace std;
#define ll long long int
typedef vector<vector<ll> > vvi;
typedef vector<ll > vi;
typedef vector<vector<pair<ll,ll> > > vvp;
typedef vector<pair<ll,ll> > vp;
typedef map<ll, ll > mi;
typedef map<ll, vector<ll> > mvi;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repr(i,a,b) for(int i=b;i>=a;i--)
#define show1(v) rep(i,0,v.size()){cout<<v[i]<<" ";}
#define show2(v) rep(i,0,v.size()){rep(j,0,v[i].size()){cout<<v[i]<<" ";}cout<<endl;} 
#define pr pair<ll,ll >
#define pb push_back
#define mp make_pair
#define sot sort
#define _file std::ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
struct val{
	ll cost;
	ll x;
	ll y;
};
bool fun(val a,val b){
	return a.cost>b.cost;
}

ll myFun(ll startx,ll endx,ll starty,ll endy,vector<val> &v,ll n,ll m,ll k){

   // cout <<startx<<" "<<endx<<" "<<starty<<" "<<endy<< endl;

	if(startx+1==endx &&  starty+1==endy){
		return 0;
	}

	for(ll i=k;i<v.size();i++){
		if(v[i].x!=0 && v[i].x<endx && v[i].x>startx){
			return myFun(startx,v[i].x,starty,endy,v,n,m,i+1) +myFun(v[i].x,endx,starty,endy,v,n,m,i+1)+v[i].cost; 
		}else if(v[i].y!=0 && v[i].y<endy && v[i].y>starty){
		return myFun(startx,endx,starty,v[i].y,v,n,m,i+1) +myFun(startx,endx,v[i].y,endy,v,n,m,i+1)+v[i].cost;
		
		}
	}

return 0;


}



int main(){
	_file;
    int t;
    cin >>t;
    while(t--){
    ll n,m;
    cin>>n>>m;
    vi x(n-1),y(m-1);
    vector<val> v;
    for(ll i=0;i<n-1;i++){
    	val temp;
    	cin>>temp.cost;
    	temp.x= i+1;
    	temp.y=0;
    	v.pb(temp);
    }
    for(ll i=0;i<m-1;i++){
    	val temp;
    	cin>>temp.cost;
    	temp.y= i+1;
    	temp.x=0;
    	v.pb(temp);
    }
    sot(v.begin(),v.end(),fun);
    cout << myFun(0,n,0,m,v,n,m,0)<< endl;
}
	return 0;
}