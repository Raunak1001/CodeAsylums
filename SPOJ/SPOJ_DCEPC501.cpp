#include<iostream>
#include<vector>
using namespace std;
 
long long int myfun(std::vector<long long int > &a,std::vector<long long int> &v,long long int index)
{
long long int n=v.size();
if(index>=n){
	return 0;
}
if(v[index]!=-1){
	return v[index];
}
long long int sum1=a[index],sum2=0,sum3=0;
if(index+1<n){
	sum2=sum1+a[index+1];
}
if(index+2<n){
	sum3=sum2+a[index+2];
}
v[index]=max(sum1+myfun(a,v,index+2),max(sum2+myfun(a,v,index+4),sum3+myfun(a,v,index+6)));
return v[index];
 
}
 
 
 
 
int main(){
 ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
long long int t;
cin >>t;
for (long long int q=0;q<t;q++){
 
long long int n;
cin >>n;
std::vector<long long int > a(n);
for(int i=0;i<n;i++){
	cin >>a[i];
}
std::vector<long long int > v(n,-1);
long long int sum1=a[0],sum2=0,sum3=0;
 
if(n>1){
	sum2=a[0]+a[1];
}if(n>2){
sum3=sum2+a[2];
}
long long int mmax=0;	
 
v[0]=max(sum1+myfun(a,v,2),max(sum2+myfun(a,v,4),sum3+myfun(a,v,6)));


 cout << v[0]<<endl;
 
}
 
 
} 
  