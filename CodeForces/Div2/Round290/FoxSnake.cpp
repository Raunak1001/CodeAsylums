#include<bits/stdc++.h>
using namespace  std;
int main(){
long long int n,m;
cin >>n>>m;
std::vector<std::vector<char> > v(n+1,std::vector<char>(m+1,'.'));

for(long long int i =1;i<=n;i+=2){
	for (int j = 1; j <=m ; j++)
	{
		v[i][j]='#';
	}
}
int temp=0;
for(int i=2;i<=n;i+=2){
if(!temp){
	v[i][m]='#';
	temp=1;
}else{
	v[i][1]='#';
	temp=0;
}
}

for(long long int i=1;i<=n;i++){
	for(long long int j=1;j<=m;j++){
		cout <<v[i][j];
	}
	cout << endl;
}

}