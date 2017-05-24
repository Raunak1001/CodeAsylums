#include<iostream>
#include<vector>
using namespace std;
#define lln long long int 
#define vi vector<long long int>
#define vvi vector<vector<long long int> >
#define INT_MAX 10000000


lln myfun(vvi &v, vvi &a,int i,int j)
{
lln n=v.size();
lln m=v[0].size();
if(i<0 || i>=n || j<0 || j>=m){
	return INT_MAX;
}
if(a[i][j]!=INT_MAX){
	return a[i][j];
}



if(j==0){
a[i][j]=v[i][j]+min(min(myfun(v,a,i,j+1),myfun(v,a,i+1,j)),myfun(v,a,i+1,j+1));

}else if(j==1){
	a[i][j]=v[i][j]+min(min(myfun(v,a,i+1,j-1),myfun(v,a,i+1,j)),min(myfun(v,a,i+1,j+1),myfun(v,a,i,j+1)));
}
else{
	a[i][j]=v[i][j]+min(myfun(v,a,i+1,j),myfun(v,a,i+1,j-1));

}

return a[i][j];
}
int main(){

lln n;
int k=1;
while(1){
	cin >>n;
	if(n==0){
		break;
	}
vvi  v(n,vi(3,0));
vvi  a(n,vi(3,INT_MAX));

for(int i=0;i<n;i++){
	for(int j=0;j<3;j++){
		cin >>v[i][j];
	}
}
a[n-1][0]=v[n-1][0]+v[n-1][1];
a[n-1][1]=v[n-1][1];
a[n-1][2]=INT_MAX;


a[0][1]=v[0][1]+min(min(myfun(v,a,0,2),myfun(v,a,1,2)),min(myfun(v,a,1,0),myfun(v,a,1,1)));

/*for (int i = 0; i < n; ++i)
{
	for (int j = 0; j < 3; j++)
	{
		cout<<a[i][j]<<" ";
	}
cout << endl;
}*/

cout <<k<<". "<<	 a[0][1]<< endl;
k++;
}




}