#include<bits/stdc++.h>
using namespace std;
#define vi vector<long long int>
#define vvi vector<vector<long long int> >
#define ll long long int 

int main()
 {

ll t;
cin >> t;
for(ll q=0;q<t;q++){
    ll n,m;
    cin >>n>>m;
    vvi v(n+1,vi(n+1,100000));
    ll a,b,c;
   for(ll i=0;i<m;i++){
       cin >>a>>b>>c;
       v[a][b]=c;
   }
    
   /* for(ll i=0;i<=n;i++){
        for(ll j=0;j<=n;j++){
            cout << v[i][j]<<" ";
        }
        cout << endl;
    }*/
    
   /* for(ll i=0;i<n;i++){
        v[i][i]=0;
    }*/
    ll temp=0;
    
    for(ll i=0;i<=n;i++){
        for(ll j=0;j<=n;j++){
            for(ll k=0;k<=n;k++){
                if(v[i][j]>v[i][k]+v[k][j]){
                    v[i][j]=v[i][k]+v[k][j];
                }
            }
            if(v[i][j]+v[j][i]<0){
                temp=1;
                break;
            }
        }
        if(temp){
            break;
        }
    }
    
    /*for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            cout << v[i][j]<<" ";
        }
        cout << endl;
    }*/
    
    if(temp){
        cout <<1<<endl;
    }else{
        cout <<0<< endl;
    }
    
}

	return 0;
}