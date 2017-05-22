#include<iostream>
using namespace std;

int main(){

string s;
while(1){
	cin >>s;
int count=0;
if(s[0]=='0'){
	break;
}

int n=s.length();
for(int i=1;i<n;i++){
int a=s[i]-'0';
int b=s[i-1]-'0';
int c;

if(i==n-1){
c=7;
}else{
	c== s[i+1]-'0';
}


if(c==0){
if(a>2 || a==0){
	break;
}
count++;
}else
if(a>6){
	count++;
}else if(a<6)
if(a!=0){
if(b<=2){
	count+=2;
}else{
	count++;
}
}

}

cout << count<< endl;

}


}