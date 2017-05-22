#include<iostream>
#include<vector>
using namespace std;

int  main(){

long long int t;
cin >>t;
for(int q=0;q<t;q++){
long long int n;
cin >>n;
vector<vector<long long int> > v(n+1,vector<long long int>(2,0));
vector<long long int > a(n,0);

for(long long int i=0;i<n;i++){

	cin >> a[i];
}

for(int i=1;i<=n;i++){

v[i][0]=max(v[i-1][0],v[i-1][1]);
v[i][1]=v[i-1][0]+a[i-1];
}

cout << "Case  "<<q+1<<": "<<max(v[n][0],v[n][1])<<endl;
}


}