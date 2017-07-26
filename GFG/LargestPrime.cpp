#include<bits/stdc++.h>
using namespace std;
#define vi vector<long long int>
#define vvi vector<vector<long long int> >
#define ll long long int 

bool checkPrime(ll n){
    ll a=sqrt(n);
    
    for(ll i=2;i<a+1;i++){
        if(n%i==0){
            return .0;
        }
    }    
    return 1;
    
}

int main()
 {

ll t;
cin>>t;
ll p=1000000;
vi v(p,0);
for(ll i=3;i<p;i++){
    for(ll j=3;i*j<p;j+=2){
        v[i*j]=-1;
    }
}
v[1]=-1;

for(ll q=0;q<t;q++){
ll n;
cin >> n;
//cout << n<<endl;
ll a= sqrt(n);
ll mmax=0;
for(ll i=1;i<=a;i++){
    if(n%i==0)
    {
     //   cout << i<< endl;
        if(i%2!=0 && v[i]==0){
         mmax=max(mmax,i);   
        }
        if((n/i)%2!=0 ){
            if((n/i)<1000000){
            if(v[(n/i)]==0){
            mmax=max(mmax,n/i);
            break;
            }
            }else{
                if(checkPrime(n/i))
                {
                    mmax=max(mmax,(n/i));
                    break;
                }
            }
        }
    }
}

    cout << mmax<<endl;

}

    return 0;
}