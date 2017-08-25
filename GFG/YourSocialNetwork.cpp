#include<bits/stdc++.h>
using namespace std;
#define vi vector<long long int>
#define vvi vector<vector<long long int> >
#define ll long long int 

ll myFun(ll temp,ll count,ll parent,vvi &v, vvi &a){
	    // cout <<"fsad"<<endl;

    a[parent][temp]=count;
    for(ll j=0;j<v[temp].size();j++){
        myFun(v[temp][j],count+1,parent,v,a);
    }
    
}



int main()
 {

ll t;
cin>>t;
for(ll q=0;q<t;q++){
    ll n;
    cin >>n;
    vvi v(n+1);
    for(ll i=1;i<n;i++){
        ll s;
        cin >>s;
        v[i+1].push_back(s);
    }
    vvi a(n+1,vi(n+1,0));
    for(ll i=1;i<=n;i++)
{
    for(ll j=0;j<v[i].size();j++){
        myFun(v[i][j],1,i,v,a);
    }
}    

for(ll i=1;i<=n;i++){
    for(ll j=1;j<i;j++){
        if(a[i][j]>0){
            cout << i<<" "<<j<<" "<<a[i][j]<<" ";
        }
    }
    
}
cout << endl;

}

	return 0;
}