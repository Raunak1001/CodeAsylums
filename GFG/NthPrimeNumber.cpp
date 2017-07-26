#include<bits/stdc++.h>
using namespace std;
#define vi vector<long long int>
#define vvi vector<vector<long long int> >
#define ll long long int 

int main()
 {
ll t;
cin >>t;
/*ll a=100000;
vi v(a,1);
for(ll i=3;i<a;i+=2)
{
    if(v[i]!=-1 && v[i]%2!=0)
    for(ll j=3;i*j<a;j+=2){
        v[i*j]=-1;
    }
}

vi fin;
for(ll i=2;i<n;i++)
if(v[i]==1 && v[i]%2!=0){
    fin.push_back(v[i]);
}*/

vi v(4);
v[0]=2;
v[1]=3;
v[2]=5;
v[3]=7;

for(ll q=0;q<t;q++){
    ll n;
    cin >>n;
    ll count=4;
    if(n<=4){
    	cout<< v[n-1]<<endl;
    	continue;
    }
    ll k=0;
    while(count<n){
    k++;
    ll done=0;
    for(ll i=0;i<4;i++){
        ll p=pow(10,k);
        ll temp=v[i];
        temp=p*v[i];
        p/=10;
        for(ll j=0;j<4;j++){
            ll newTemp=temp+v[j]*(p);
        count++;
        if(count==n){
            cout << newTemp<<endl;
            done=1;
        }
            
        }
        if(done){
            break;
        }
    }
    
    
    }
    
}



	return 0;
}