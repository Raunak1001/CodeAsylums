#include<bits/stdc++.h>
using namespace std;
#define vi vector<long long int>
#define vvi vector<vector<long long int> >
#define ll long long int 

int main()
 {
ll t;
cin >>t;
vi v(101,1);
for(ll i=3;i<101;i++)
{
    v[i]=v[i-2]+v[i-3];
}
for(ll q=0;q<t;q++){
    ll n;
    cin >>n;
    cout << v[n]<<endl;
    
}

	return 0;
}