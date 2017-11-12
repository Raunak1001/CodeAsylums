#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
using namespace std;

int main(){


int t;
scanf("%d",&t);
vector<int> v(1000001,0);
v[1]=1;
for(int i=2;i<=1000000;i++){
	int temp=0;
	int a=sqrt(i);
	for(int j=1;j<=a;j++){
		if(i%j==0){
			temp++;
		}
	}
	v[i]=v[i-1]+temp;
}

while(t--){

int n;
scanf("%d",&n);
printf("%d\n",v[n]);



}


}