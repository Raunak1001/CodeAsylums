#include<stdio.h>
#include<iostream>
#include<vector>
#include<map>
using namespace std;

std::map<long long int,long long int> v;

long long int getans(long long int n){

if(v.find(n)==v.end()){
	v[n]=max(getans(n/2)+getans(n/3)+getans(n/4),n);
}
return v.find(n)->second;

}


int main(){
	
long long int n;
	
int maxin=-1;
for(int i=0;i<12;i++){
	v[i]=i;
}

while(scanf("%lld",&n)!=EOF)
{
cout << getans(n)	<<endl;


}
}




