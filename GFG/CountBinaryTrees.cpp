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
    ll n;
    ll INT=1000000;
    cin >>n;
    vi v(n);
    vi exist(1000000,0);
    vi  count(1000000,0);
    for(ll i=0;i<n;i++){
        cin >> v[i];
        exist[v[i]]=1;
        count[v[i]]=1;
    }
    ll ans=n;
    sort(v.begin(),v.end());
    for(ll i=0;i<n;i++){
        ll  k=sqrt(v[i]);
        for(ll j=1;j<k+1;j++)
        {
            if(v[i]%j==0 && exist[j] && exist[v[i]/j] ){

 count[v[i]]+= (count[j] *count[v[i]/j]);
 
                // Condition for possiblity when left
                // chid became right child and vice versa.
                if (j != v[i]/j)
                count[v[i]]+= (count[j] *count[v[i]/j]);


                
            }
        }
        ans+=count[v[i]];	
        
    }
    
   cout << ans<< endl; 
}


	return 0;
}