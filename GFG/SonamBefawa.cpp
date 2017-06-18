#include<bits/stdc++.h>
using namespace std;
#define vi vector<long long int>
#define vvi vector<vector<long long int> >
#define ll long long int 

struct Node{
    ll index;
    ll val;
};


int main()
 {
     ll t;
     cin >>t;
     for(ll z=0;z<t;z++){
      ll n,q;
      cin >>n>>q;
      ll a,b;
      vector<pair<ll,ll> > v(n);
      for(ll i=0;i<n;i++){
          cin >>a>>b;
          v[i]=make_pair(a,b);
      }
         vector<pair<ll,ll> > p(q);
         for(ll i=0;i<q;i++){
             cin >>a;
             p[i]=make_pair(a,i);
             
         }
         ll k=0;
         pair<ll,ll> topPair;
         topPair=make_pair(-1,-1);
    //     sort(p.begin(),p.end(),myfun);
         vi l(q);
         ll currRank=0;
         for(ll i=0;i<q;i++){
             ll temp=p[i].first;
             
             for(ll j=k;j<n;j++){
              //  cout << currRank<<endl;
                 topPair=v[j];
             if(currRank+topPair.second-topPair.first+1>=temp){
                 ll ans=temp-currRank+topPair.first;
                 cout << temp<<" "<<topPair.first<<" "<<currRank<<endl;
                 l[p[i].second]=ans;
                 j--;
                 k=j;
                 break;
                     }else{
                         currRank+=(topPair.second-topPair.first);
                     }
             }
             
         }
         for(ll i=0;i<q;i++){
             cout<<l[i]<<" ";
         }
         
         
         
     }
     
     return 0;
}