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

ll myFun(ll i){
    
    float ans=i;
    
    for(ll j=2;j*j<=i;j++){
        
            if(i%j==0){
                while(i%j==0){
                ans*=(1-(1/(float)j));
                //cout << ans<< endl;
                i/=j;
            }
            }       
        
    }
    if(i>1){
        ans*=(1-(1/(float)i));
        //cout<< ans<< endl;
    }

    return (ll)ceil(ans);
    
}


int main(){
    
    ll t;
    scanf("%lld",&t);
   vi v(1000001);
   for(ll i=2;i<=1000000;i++){
      v[i]=i-myFun(i);
   }
   //cout << myFun(6);
   //cout <<"asdd"<< endl;
    while(t--){
        
        ll n;
    scanf("%lld",&n);
           //cout <<"asdd"<< endl;

        if(n==1){
            printf("0\n");
            continue;
        }
printf("%lld\n",v[n]);        
    }
    
    
	return 0;
}