#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
vector<long long int> v(100001,0);
 	
int main(){
long long int t;
v[1]=1;
v[2]=2;
long long int a=sqrt(100001);



for(long long int i=3;i<a+1;i+=2){
if(v[i]!=-1){
v[i]=2;
for(long long int j=i;i*j<=100001;j+=2){
	v[i*j]=-1;
}
}

}
for(long long int i=2;i<=100001;i++){
	if(i%2!=0 || i==2 && v[i]<=2)
for(long long int j=i;i*j<=100001;j++){
	if(i==j){
v[i*j]=v[i]+1;
}
	else
	v[i*j]=v[i]+v[j];
}

}

cin >>t;
for(long long int q=0;q<t;q++){
long long int n;
cin >>n;
long long int sum=0;
for(long long int i=1;i<=n;i++){
	sum+=v[i];	
}
cout << sum<< endl;

}


}