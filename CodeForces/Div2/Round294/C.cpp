#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define vi vector<long long int >
#define vvi vector<vector<long long int > >

int main(){

ll n,m;
cin >>n>>m;
ll a=(n+m)/3;
ll mmin=min(a,n);
mmin=min(mmin,m);
cout << mmin<< endl;


}