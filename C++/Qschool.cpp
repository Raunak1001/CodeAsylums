#include<iostream>
using namespace std;

int main(){

long long int n,t;
cin >>n>>t;
string a,b="";
cin >>a;
for(int i=0;i<n;i++){
b=b+'G';
}
int last=n-1;
int j;
for(int i=n-1;i>=0;i--){
if(a[i]=='B'){
j=i+t;
if(j>last){
	b[last]='B';
}else{
	b[j]='B';
	last=j-1;
}
}

}

cout <<b<<endl;


}