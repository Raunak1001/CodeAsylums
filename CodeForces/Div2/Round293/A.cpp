#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define vi vector<long long int >
#define vvi vector<vector<long long int > >

int main(){
string a,b;
cin >>a>>b;
ll n = a.size();
ll index=-1;
int temp=0;
for(ll i=0;i<n;i++){

if(temp ){
	if(b[i]!='a'){
b[i]=b[i]-1;
	cout << b<<endl;
	return 0;	
}else{
	if(a[i]!='z'){
		b[index]=b[index]-1;
		b[i]=a[i]+1;
		cout << b<< endl;
		return 0;
	}
}
}


if(a[i]!=b[i]){

	if(b[i]-a[i]>=2){
	b[i]=b[i]-1;
	cout << b<<endl;
	return 0;
	}else{
		index=i;
		temp=1;
	}
}

}

cout << "No such string"<<endl;
return 0;

}