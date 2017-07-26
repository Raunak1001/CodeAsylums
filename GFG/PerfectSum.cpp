#include<bits/stdc++.h>
using namespace std;
#define vi vector<long long int>
#define vvi vector<vector<long long int> >
#define ll long long int 

int main()
 {
ll t;
cin >>t;
while(t--){
    ll n;
    cin >> n;
    vi v(n);
    for(ll i=0;i<n;i++){
        cin >> v[i];
    }
    ll k;
    cin >> k;
    vi fin(k+1,0);
    for(ll i=0;i<n;i++){
        //fin[v[i]]++;
        for(ll j=0;j<=k;j++){
            if(fin[j]!=0){
         if(j+v[i]<=k){
             fin[j+v[i]]++;
         }else{ 
             break;
         }
            }
        }
        fin[v[i]]++;
        
    }
    cout << fin[k]<< endl;
}

	return 0;
}