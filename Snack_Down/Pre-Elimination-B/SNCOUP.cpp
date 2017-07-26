#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
int main(){
ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
long long int t;
cin >>t;
for(long long int q=0;q<t;q++){

long long int m;
cin >>m;
vector<vector<char> > v(2,vector<char>(m,0));
vector<long long int> a(m,0),b(m,0);

long long temp1=0,temp2=0;
for(long long int i=0;i<2;i++){
	for(long long int j=0;j<m;j++){
		cin >> v[i][j];
		if(temp2!=1 && i==1 && v[i][j]=='*'){
			temp2=1;
		}
		if(temp1!=1 && i==0 && v[i][j]=='*'){
			temp1=1;
		}
	}
}
long long int count;
if(temp1 && temp2){
	count=1;
}else{
	count=0;
}
/*if(v[0][m-1]=='*')
	a[m-1]=1;
for(long long int i=m-2;i>=0;i--){

if(v[0][i]=='*')
	a[i]=a[i+1]+1;
else
	a[i]=a[i+1];
} 


if(v[1][m-1]=='*')
	b[m-1]=1;
for(long long int i=m-2;i>=0;i--){

if(v[1][i]=='*')
	b[i]=b[i+1]+1;
else
	b[i]=b[i+1];
} */


/*if(a[0]>0&& b[0]>0){
	count=1;
}
else
	count=0;*/
int tempa=0;
int tempb=0;
for(long long int i=0;i<m;i++){

if(v[0][i]=='*'){
	if(tempa){
		count++;
		tempb=0;
	}else{
		tempa=1;
	}
}
if(v[1][i]=='*'){
if(tempb){
		count++;
		tempa=0;
	}else{
		tempb=1;
	}
}
if(v[0][i]=='*')
{
	tempa=1;
}
if(v[1][i]=='*'){
	tempb=1;
}

}

cout << count << endl;

}




}




