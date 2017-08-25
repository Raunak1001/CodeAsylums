#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int LCS(string a,string b){

long long int n=a.length();
std::vector<vector<long long int> > v(n+1,vector<long long int>(n+1,0));

for(int i=1;i<=n;i++){

for(int j=1;j<=n;j++){

if(a[i-1]==b[j-1]){
v[i][j]=v[i-1][j-1]+1;

}else{
	v[i][j]=max(v[i-1][j],v[i][j-1]);
}

}

}

return v[n][n];
}


int main(){

long long int t;
cin >>t;
for(int i=0;i<t;i++){
string s;
cin >>s;
string a=s;
reverse(a.begin(),a.begin()+a.length());

cout << s.length()-LCS(s,a)<< endl;


}


}