#include<bits/stdc++.h>
using namespace std;
#define ll int 
#define vi vector<char >
#define vvi vector<vector<char > >

int main(){

ll n,m;
cin >>n>>m;
vvi v(n+2,vi(m+2,'*'));

for(ll i=1;i<=n;i++){
	for(ll j=1;j<=m;j++)
{
	cin >> v[i][j];
}
}

for(ll i=1;i<=n;i++){
	for(ll j=1;j<=m;j++)
{
	cout << v[i][j];
}
cout <<endl;
}

int temp=0;
int x,y,a;
int q=0;
while(q<2){
for(ll i=1;i<=n;i++){
	for(ll j=1;j<=m;j++){
		temp=0;
		if(v[i][j]=='.'){
if(v[i+1][j]=='.'){
	temp=1;
	x=i+1;
y=j;
}if(v[i-1][j]=='.'){
	if(temp){
		continue;
	}
	temp=1;
	x=i-1;
y=j;
}if(v[i][j+1]=='.'){
	if(temp){
		continue;
	}
	temp=1;
	x=i;
y=j+1;
}if(v[i][j-1]=='.'){
	if(temp){
		continue;
	}
	temp=1;
	x=i;
y=j-1;
}
if(temp){
	if(i==x){
int a=min(j,y);
int b=max(j,y);
v[i][a]='<';
v[i][b]='>';
	}else{
		int a=min(i,x);
		int b=max(i,x);
v[a][j]='^';
v[b][j]='v';
	}
	temp=0;
}else{
	cout <<"Not unique"<<endl;
	return 0;
}
}else{
	temp=1;
}
}
}
q++;
}
/*for(ll i=1;i<=n;i++){
	for(ll j=1;j<=m;j++)
{
	cout << v[i][j];
}
cout <<endl;
}*/

//sdaffffffffffffffffffffffffffff

for(ll i=1;i<=n;i++){
	for(ll j=1;j<=m;j++){
		temp=0;
		if(v[i][j]=='.'){
if(v[i+1][j]=='.'){
	temp=1;
	x=i+1;
y=j;
}
if(v[i-1][j]=='.'){
	if(temp){
	cout <<"Not unique"<<endl;
	return 0;

	}
	temp=1;
	x=i-1;
y=j;
}
if(v[i][j+1]=='.'){
	if(temp){
			cout <<"Not unique"<<endl;
	return 0;
	}

	temp=1;
	x=i;
y=j+1;
}if(v[i][j-1]=='.'){
	if(temp){
	cout <<"Not unique"<<endl;
	return 0;
	}
	temp=1;
	x=i;
y=j-1;
}
if(temp){
	if(i==x){
int b=max(j,y);
int a=min(j,y);
v[i][a]='<';
v[i][b]='>';
	}else{
int a=min(i,x);
		int b=max(i,x);
v[a][j]='^';
v[b][j]='v';
	}
	temp=0;
}else{
	cout <<"Not unique"<<endl;
	return 0;
}







		}else{
			temp=1;
		}
	}
}


/*for(ll i=1;i<=n;i++){
	for(ll j=1;j<=m;j++)
{
	cout << v[i][j];
}
cout <<endl;
}*/






}
