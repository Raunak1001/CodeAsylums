#include<bits/stdc++.h>
using namespace std;
#define vi vector<long long int>
#define vvi vector<vector<long long int> >
#define ll long long int 

ll myfun(vvi &a,vvi &v,ll i,ll j,ll parentx,ll parenty){
ll n= v.size();    
    if(i==n-1 && j==n-1){
        //cout <<"aya"<<endl;
        return v[i][j];
    }
    if(i<0 || i>=n ||j<0 ||j>=n){
        return 10000000;
    }
    if(a[i][j]!=-1){
        return a[i][j];
    }
           // cout <<"aya"<<endl;

a[i][j]=100000000;
for(ll k=-1;k<2;k++){
    for(ll p=-1;p<2;p++){
        if(k==p){
            continue;
        }
if(i+k!=parentx || j+p!=parenty){
    a[i][j]=min(a[i][j],myfun(a,v,i+k,j+p,i,j));
    }
}
}
return a[i][j]=a[i][j]+v[i][j];
}


int main()
 {

ll t;
cin >>t;
for(ll q=0;q<t;q++){
    ll n;
    cin >>n;
    vvi v(n,vi(n,0)),a(n,vi(n,-1));
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            cin >>v[i][j];
        }
    }
    a[0][0]=v[0][0]+min(myfun(a,v,1,0,0,0),myfun(a,v,0,1,0,0));
    
    cout << a[0][0]<<endl;
    
    

    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            cout << a[i][j]<<" ";
        }
        cout << endl;
    }
}

	return 0;
}