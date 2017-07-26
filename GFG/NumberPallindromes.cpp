#include<bits/stdc++.h>
using namespace std;
#define vi vector<long long int>
#define vp vector<pair<long long int,long long int > >
#define vc vector<char>
#define vvi vector<vector<long long int>  >
#define vvp vector<vector<pair<long long int,long long int> > >
#define vvc vector<vector<char>  >
#define ll long long int 
#define pr pair<long long int,long long int>
#define mp make_pair		
#define pb push_back

int main(){
    
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        string s;
        cin >>s;
        vvi v(n,vi(n,0));
        
        for(ll i=0;i<n;i++){
            v[i][i]=1;
        }
        
       for(ll j=1;j<n;j++){
      for(ll i=0;i<n;i++){
         
              if(i+j<n){
                  if(j==1){
                      if(s[i]==s[i+j]){
                          v[i][i+j]=1;
                      }
                    }else{
                       // cout << s[i]<<" "<< s[i+j]<< endl;    
                          if(s[i]==s[i+j] && v[i+1][i+j-1]!=0){
                              v[i][i+j]=v[i+1][i+j-1]+1;
                          }
                      }
                  
              }else{
                break;
              }
              
              
          }
      }
      
     ll count=0;
     for(ll i=0;i<n;i++){
         for(ll j=0;j<n;j++){
             if(v[i][j]!=0){
              count++;
             }
         }
         
     }
       

cout << count-n<< endl; 

    }
    
    
	return 0;
}