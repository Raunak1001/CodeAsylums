#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define lln long long int 
#define vvi vector<vector<long long int> >	
#define vvc vector<vector<char> >	


bool DFS(lln i,lln j,vvc &v, vvi &a){
	lln n=a[0].size();
if(i<0 || i>=2 || j<0 || j>=n){
	return true;
}
if(a[i][j]==0){
	return false;
}
a[i][j]=0;

if(i==0){
if(v[i+1][j]=='#')
{
	return DFS(i+1,j,v,a);
}else if(j<n-1 && v[i][j+1]=='#'){
	return DFS(i,j+1,v,a);
}

}else{
if(v[i-1][j]=='#')
{
	return DFS(i-1,j,v,a);
}else if(j<n-1 && v[i][j+1]=='#'){
	return DFS(i,j+1,v,a);
}


}

return true;




}


int main(){

lln t;
cin >>t;
for(lln q=0;q<t;q++){
lln n;
cin >> n;
vvc v(2,vector<char>(n));
vvi a(2,vector<long long int>(n,-1));

for(lln i=0;i<2;i++){
	for(lln j=0;j<n;j++){
cin >>v[i][j];
	}
}
int temp=1;
for(lln i=0;i<2;i++){
	for(lln j=0;j<n;j++)
{
if(a[i][0]==0){
	temp=0;
	break;
}
if(v[i][j]=='#'){
if(!DFS(i,j,v,a)){
temp=0;
break;

}

}

}
}
if(temp==0){
	cout <<"No"<<endl;

}else{
	cout << "Yes"<<endl;
}



}


}