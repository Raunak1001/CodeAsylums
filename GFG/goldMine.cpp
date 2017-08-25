#include<bits/stdc++.h>
using namespace std;
#define vi vector<long long int>
#define vvi vector<vector<long long int> >
#define ll long long  


ll myfun(vvi &a,vvi &v,ll i,ll j){
    ll n=a.size();
    ll m=a[0].size();
    if(i<0 || i>=n || j<0 || j>=m){
        return 0;
    }
    if(a[i][j]!=-1){
        return a[i][j];
    }
    return a[i][j]=v[i][j]+max(myfun(a,v,i,j+1),max(myfun(a,v,i-1,j+1),myfun(a,v,i+1,j+1)));
    
}



int main()
 {
	ll t;
	cin >> t;
	for(ll q=0;q<t;q++){
	    ll n,m;
	    cin >>n>>m;
	    vvi v(n,vi(m));
	    vvi a(n,vi(m,-1));
	    for(ll i=0;i<n;i++){
	        for(ll j=0;j<m;j++){
	            cin >> v[i][j];
	        }
	    }
	    
	    for(int i=0;i<n;i++){
	        a[i][0]=v[i][0]+max(myfun(a,v,i,1),max(myfun(a,v,i-1,1),myfun(a,v,i+1,1)));
	    }
	    
	    
	  	ll max=0;
	for(ll i=0;i<n;i++){
	    if(a[i][0]>max){
	        max=a[i][0];
	    }
	}
	
	cout << max<<endl;
	    
	}

	return 0;
}