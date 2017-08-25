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
bool isValid(ll a){
    
    ll count=0;
    ll i=2;
    while(a>1){
        if(a%i==0){
            while(a%i==0){
                a/=i;
            }
            count++;
        }
        i++;
        if(count>=3){
            return 1;
        }
    }
   return 0; 
    
}



ll myFun(ll a){
    
    ll count=0;
    while(a--){
        //cout << a<< endl;
        if(isValid(a)){
            count++;
        }
        
    }
    return count;
}



int main(){

    ll t;
    cin >> t;

    while(t--){
        ll n;
        cin>>n;
        ll low=1;
        ll high=1000000;
        while(low<high){
            ll mid=low+(high-low)/2;
            if(low==mid){
                break;
            }
            ll a=myFun(mid);
            cout << a<< endl;
            if(a>=n){
                high=mid;
            }else{
                low=mid;
            }
        }
        
        cout << high<< endl;
    }
    
    
    
	return 0;
}