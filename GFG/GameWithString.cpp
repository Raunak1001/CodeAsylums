#include<bits/stdc++.h>
using namespace std;
#define vi vector<long long int>
#define vvi vector<vector<long long int> >
#define ll long long int 

int main()
 {

ll t;
cin >>t;
for(ll q=0;q<t;q++){
    string s;
    cin >>s;
    ll k;
    cin >>k;
    ll n= s.length();
vi v(26,0);
ll temp;
for(ll i=0;i<n;i++){
    temp=s[i]-'a';
    v[temp]++;
}
n=26;
        sort(v.begin(),v.end());
/*for(ll i=0;i<n;i++){
    cout<<v[i]<<' ';
}*/
       // cout <<"Sdfsdf";
ll a,b;
while(1){
    a=v[n-1];
    b=v[n-2];
    //cout <<a<<b<<k<<endl;
    if(a-b>=k){
        v[n-1]-=k;
        break;
    }else{
                k=k-(v[n-1]-v[n-2]+1);  
        v[n-1]=v[n-2]-1;
        sort(v.begin(),v.end());
    }
    
}
ll ans=0;

for(ll i=0;i<26;i++){
    ans+=v[i]*v[i];
}

cout << ans<<endl;
}
    return 0;
}