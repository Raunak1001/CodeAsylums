#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define pr pair<ll,ll>
#define vi vector<ll>
#define vvi vector< vi >
#define vvvi vector< vvi >
#define vf vector<double>
#define vvf vector<vf>
#define vvvf vector<vvf>
#define vvvvf vector<vvvf>
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

double myFun(vvvvf &v,ll r,ll b,ll g,ll temp){

	
	if(r==0 && b==0 && g>0){
		return 1;
	}
	

	/*if(g==0 && temp==2){
		return 1;
	}	*/
	if(g==0){
		return 0;
	}

	if(v[r][g][b][temp]!=-1){
		return v[r][g][b][temp];
	}

	double ans=0;
	if(temp==0){
		if(r==0){
			ans=((myFun(v,r,b-1,g,1)*(b)/(r+b+g))+myFun(v,r,b,g-1,1)*(g)/(r+b+g));
			
		}
		else if(b==0){
			ans=(myFun(v,r-1,b,g,1)*(r)/(r+b+g)+myFun(v,r,b,g-1,1)*(g)/(r+b+g));
			//ans/=2.0;
		}else{
			ans=(myFun(v,r-1,b,g,1)*(r)/(r+b+g)+myFun(v,r,b,g-1,1)*(g)/(r+b+g)+myFun(v,r,b-1,g,1)*(b)/(r+b+g));
			//ans/=3.0;
		}

	}else if(temp==1){
		if(r==0){
			ans=(myFun(v,r,b-1,g,2)*(b)/(r+b));
		}
		else if(b==0){
			ans=(myFun(v,r-1,b,g,2)*(r)/(r+b));
		}else{
			ans=(myFun(v,r-1,b,g,2)*(r)/(r+b)+myFun(v,r,b-1,g,2)*(b)/(r+b));
			
		}
	}else if(temp==2){
			ans=myFun(v,r,b,g-1,0);
	}
	return v[r][g][b][temp]=ans;


}

int main(){
		std::ios::sync_with_stdio(false); 
		cin.tie(NULL);
		cout.tie(NULL);

		ll t;
		cin >>t;
		cout << fixed;
		cout <<setprecision(15);
		while(t--){

			ll r,g,b;
			cin >>r>>b>>g;
			vvvvf v(r+1,vvvf(g+1,vvf(b+1,vf(4,-1))));
			cout <<myFun(v,r,b,g,0)<< endl;


		}

	return 0;
}			