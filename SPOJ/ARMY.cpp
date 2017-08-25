#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define vi vector<long long int >
#define vvi vector<vector<long long int > >

int main(){
ll t;
cin>>t;
for(ll q=0;q<t;q++){
ll n,m;
cin >>n>>m;
vi a(n),b(m);
ll maxa=0;
ll maxb=0;
for(ll i=0;i<n;i++){
	cin >> a[i];
	maxa=max(maxa,a[i]);
}

for(ll i=0;i<m;i++){
	cin >> b[i];
	maxb=max(maxb,b[i]);
}

if(maxa>=maxb){
	cout <<"Godzilla"<<endl;
}else{
	cout <<"MechaGodzilla"<<endl;;
}


}

return 0;
}
