#include<bits/stdc++.h>
using namespace std;
#define vvi vector<vector<long long int> >
#define ll long long int 

int main()
 {
ll t;
cin >>t;
for(long long int q=0;q<t;q++){
    ll n;
    cin >>n;
    vector<long long int> v(n);
    vector<long long int> suma(101);
    ll minarr=INT_MAX,maxarr=-1;
    for(ll i=0;i<n;i++){
        cin >> v[i];
        
        minarr=min(minarr,v[i]);
        maxarr=max(maxarr,v[i]);
    }
    ll ans=n+1;
    ll a=abs(maxarr-minarr);
    for(ll d=-a;d<=a;d++)
    {
        if(d==0){
            continue;
        }
        for(long long int i=0;i<101;i++){
                suma[i]=0;
            }
        
        for(ll i=0;i<n;i++){
            suma[v[i]]=1;
            if(v[i]-d>=0 && v[i]-d<=100)
            {
                if(suma[v[i]-d]>0){
                  //  cout << v[i]-d<< " ";
                    suma[v[i]]=suma[v[i]-d]+1;
                    ll p=suma[v[i]-d];
                    ans=ans+p;
                }
            }
            
        }
        
        //cout<< ans<<" ";
        
    }
    
    
    cout << ans<<endl;
}


    return 0;
}