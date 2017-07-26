#include<iostream>
#include<vector>
using namespace std;

bool check(int a,int b,int c){

if(b>6){
	if(a==1){
		return true;
	}else{
		return false;
	}
}else if (b==0){
return false;
}else{
	if(a>2){
		return false;
	}
}
return true;

}


int main(){

string s;
while(1){
cin >>s;
if(s[0]=='0'){
	break;
}

int n=s.length();

std::vector<int > v(n,0);
int a=s[0]-'0';
if(n==1){
	v[0]=1;
	continue;
}
int b=s[1]-'0';


int c=-1;
if(n>2){
c=s[2]-'0';
}
if(c==0 && b>2){
	break;
}
if(c!=0 && check(a,b,c)){
	v[1]=2;
}else{
	v[1]=1;
}
v[0]=1;
for(int i=2;i<n;i++){
a=s[i-1]-'0';
b=s[i]-'0';
if(i==n-1)
{
	c=-1;
}else{
	c=s[i+1]-'0';
}


if(c==0 && b>2){
	break;
}

if(c!=0 && check(a,b,c)){
	v[i]=v[i-1]+v[i-2];
}else{
	v[i]=v[i-1];
}

}
cout <<v[n-1]<<endl;

}

}