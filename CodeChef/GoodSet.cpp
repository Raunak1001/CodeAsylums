#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define vi vector<long long int >
#define vvi vector<vector<long long int > >

int main(){

ll t;
cin >>t;
for(ll q=0;q<t;q++){
ll n;
cin >>n;
if(n>=1)
cout << 1<<" ";
if(n>=2)
cout <<2<<" ";
if(n>=3)
cout <<4<<" ";
ll a=4;
for(ll 	i=4;i<=n;i++){
cout <<a+3<<" ";
a+=3;
}
cout << endl;
}
return 0;
}
