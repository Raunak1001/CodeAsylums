#include<iostream>
#include<vector>
#include <math.h>
using namespace std;

long long int getpow(int i,int j){

long long int mi=1000000007;
long long  int ans=1;
while(j!=0){

if(j%2==1){
	ans=ans*i;
	ans%=mi;
}
i=i*i;
i%=mi;
j/=2;
}
return ans;
}

void fun1(std::vector<long long int > &v,long long int l,long long int r,long long int x)
{
for(long long int i=l-1;i<=r-1;i++){

	v[i]=x;
}

}

void fun2(std::vector<long long int > &v,long long int l,long long int r,long long int k)
{
	//cout <<l<<r<<k<<endl;
 long long int mi=1000000007;
long long int sum=0;
for(long long int i=l-1;i<=r-1;i++){
	 //cout<<"AYA"<<endl;

	
	sum=sum+(v[i])*getpow(i-l+2,k);
sum%=mi;

}
cout << sum << endl;
}


int main(){

long long int n,m;
cin >>n>>m;
std::vector<long long int > v(n,0);
for (long long int i = 0; i < n; ++i)
{
	cin >> v[i];
}

long long int a,b,x;
char s;
//cout <<m<<endl;
for(int i=0;i<m;i++){
cin >>s;
cin >>a;
cin >>b;
cin >>x;


if(s=='='){
	fun1(v,a,b,x);
// 	for (int i = 0; i < n; ++i)
// {
// 	/* code */cout <<v[i]<< " ";
// }
}else{
	fun2(v,a,b,x);
}


}


}