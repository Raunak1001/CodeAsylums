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

struct Node{
	ll x;
	ll y;
	ll s;
};

bool myFun(Node a,Node b){
return a.x<b.x;

}

bool myFun2(Node a,Node b){
return a.y<b.y;

}



ll binary2(vector<Node> &v,ll a){

ll low=0;
ll high=v.size();
while(low<high){
	ll mid=low+(high-low)/2;

	if(low==mid){
		return low;
	}

	if(v[mid].x>a){
		high=mid;
	}else{
		low=mid;
	}

}
return low;

}


ll binary(vector<Node> 	&v,ll a){

ll low=0;
ll high=v.size();
while(low<high){
	ll mid=low+(high-low)/2;

	if(low==mid){
		return low;
	}

	if(v[mid].x>=a){
		high=mid;
	}else{
		low=mid;
	}

}
return low;

}

int main(){
	
	ll n,q,c;
	cin >>n>>q>>c;
	vector<Node> v(n);

	for(ll i=0;i<n;i++){
		ll a,b,d;
		cin >>a>>b>>d;
		v[i].x=a;
		v[i].y=b;
		v[i].s=d;
	}

	sort(v.begin(),v.end(),myFun);

/*for(ll i=0;i<n;i++){
	cout <<v[i].x<<" "<<v[i].y<<" "<<v[i].s<<endl;
}*/


	while(q--){
		ll t;
		ll x1,x2,y1,y2;
		cin >>t>>x1>>y1>>x2>>y2;

		ll a,b;
		if(v[0].x>=x1){
			a=0;
		}else{
			a=binary(v,x1);
			if(v[a].x<x1){
				a++;
			}
		}

		if(v[n-1].x<x2){
			b=n-1;
		}else{
			b=binary2(v,x2);
			if(b==n || v[b].x>x2){
				b--;
			}
		}
		//a=binary(v,x1);
		//b=binary(v,x2);

		if(a>b){
			cout <<0<< endl;
			continue;
		}
		//cout <<a<<" "<<b<< endl;

		ll ans=0;
		vector<Node> ::const_iterator first = v.begin()+a;
		vector<Node> ::const_iterator last = v.begin()+b+1;
		vector<Node> nv(first,last);
		sort(nv.begin(),nv.end(),myFun2);

		/*for(ll i=0;i<nv.size();i++){
				cout <<nv[i].x<<" "<<nv[i].y<<" "<<nv[i].s<<endl;

		}*/

		ll m=nv.size();
		ll p,r;
		if(nv[0].y>=y1){
			p=0;
		}else{
			p=binary(nv,y1);
			if(nv[p].y<y1){
				p++;
			}
		}

		if(nv[m-1].y<y2){
			r=m-1;
		}else{
			r=binary2(nv,y2);
			if(r==m || v[r].y>y2){
				r--;
			}
		}
		for(ll i=p;i<=r;i++){
			if(nv[i].y>=y1 && nv[i].y<=y2 && nv[i].x>=x1 && nv[i].x<=x2){
				ans+=(nv[i].s + t)%(c+1);
			}
		}


		cout << ans<< endl;

	}





	return 0;
}