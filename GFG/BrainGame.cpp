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
vi v(1000,1);
v[1]=-1;
for(ll i=3;i<1000;i+=2){
    
    if(v[i]==1){
        for(ll j=3;i*j<1000;j++){
            v[i*j]=1;
        }
    }
    
}
while(t--){
    ll n;
    cin >> n;
    vi a;
    ll temp;
    ll count=0;
    ll count2=0;
    for(ll i=0;i<n;i++){
        cin >> temp;
        if(v[temp]==1){
            count2++;
            ll b=sqrt(temp);
            for(ll j=2;j<=b;j++){
                if(temp%j==0){
                    if(v[temp/j]!=1){
                        temp/=j;
                        count++;
                    }
                }
            }
        }
    }
    
    if(count%2==0){
        if(count2%2==0){
            cout << 'A'<<endl;
            continue;
        }else{
             cout << 'B'<<endl;
            continue;
    }
    
}else{
    if(count2%2==0){
            cout << 'B'<<endl;
            continue;
        }else{
             cout << 'A'<<endl;
            continue;
    }
    
}



}
return 0;
}