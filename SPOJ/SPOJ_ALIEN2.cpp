#include<iostream>
#include<vector>	
using namespace std;
int main(){

long long int n,k;
cin >>n>>k;

std::vector<long long int > station1(n,0);
std::vector<long long int > station2(n,0);
std::vector<vector<long long int> > v(n+1,vector<long long int>(n+1,0));

for(int i=0;i<n;i++)
{
	cin >> station1[i];
}


for(int i=0;i<n;i++)
{
	cin >> station2[i];
}




for(int i=1;i<=n;i++){

v[i][0]=min(v[i-1][0]+station1[i-1],v[i-1][1]+station1[i-1]+station1[i-2]);
v[i][1]=min(v[i-1][1]+station2[i-1],v[i-1][0]+station2[i-2]+station2[i-1]);
if(min(v[i][0],v[i][1])==k){
	cout<<i<<" "<<min(v[i][0],v[i][1])<<endl;
	return 0;
}else if(min(v[i][0],v[i][1])>k){
	cout<<i-1<<" "<<min(v[i-1][0],v[i-1][1])<<endl;
	return 0;
}

}


/*for (int i = 1; i <=n; ++i)
{
	for(int j=0;j<2;j++)
{
	cout<<v[i][j]<<" ";
}
cout <<endl;
}*/

cout<<n<<" "<<min(v[n][0],v[n][1])<<endl;
return 0;

}