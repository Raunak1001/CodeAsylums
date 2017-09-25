#include<bits/stdc++.h>
using namespace std;
#define vi vector<double>
#define vp vector<pair<long long int,long long int > >
#define vc vector<char>
#define vvi vector< vi >
#define vvvi vector< vvi >
#define vvp vector<vector<pair<long long int,long long int> > >
#define vvc vector<vector<char>  >
#define ll long long int 
#define pr pair<long long int,long long int>
#define mp make_pair		
#define pb push_back
#define vb vector<bool>
#define vvb vector< vb >
#define vvvb vector< vvb >


bool calCulateArea(vi &mid){


vi count(4,0);
map<double,ll> m;


for(ll i=0;i<4;i++){

	m[mid[i]]++;
}
map<double,ll> :: iterator it;
double a=-1,b=-1,c=-1;
for(it=m.begin();it!=m.end();++it){
	if(it->second==1 && a==-1){
		a=it->first;
	}else if(it->second==1 && b==-1){
		b=it->first;
	}else if(it->second==2){
		c=it->first;
	}else{
		return 0;
	}
}

if(a==-1 || b==-1 || c==-1){
	return 0;
}
double h=sqrt(4.0*c*c - ((a-b)*(a-b)));
double a1=((a*h)/2.0) + ((b*h)/2.0); 
double a2= (h*(a+b))/2.0;
return a1==a2;

}


ll myFun(vi &v,vi &mid,ll i){

ll n=v.size();
if(mid.size()==4){
if(calCulateArea(mid)){
	return 1;
}else{
	return 0;
}

}
if(i>=n){return 0;}


mid.pb(v[i]);
ll count=0;
for(ll j=i+1;j<n;j++){
	count+=myFun(v,mid,j);
}
mid.pop_back();
return count;

}


int main(){
		std::ios::sync_with_stdio(false); 

		ll t;
		cin >>t;
		while(t--){
			ll n;

			cin >>n;
			vi v(n);
			for(ll i=0;i<n;i++){
				cin >> v[i];
			}
			vi mid;
			ll count=0;
	for(ll j=0;j<n;j++){
		count+=myFun(v,mid,j);
	}
	cout << count << endl;

		}

	return 0;
}