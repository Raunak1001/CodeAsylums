#include<iostream>
#include<vector>
using namespace std;






bool chck(int a,int b,int c,int d){

int temp=a;
a=min(a,b);
b=max(temp,b)
temp=c;
c=min(c,d);
d=max(temp,d)



if((a>=c && a<=d)|| (b>=c && b<=d) || (c>=a && c<=b) || (d>=a && d<=b)){
	return true;
}
return false;
}

int main(){

long long int t;
for(int q=0;q<t;q++){
cin >>t;
long long int a,b,c,d;
long long int e,f,g,h;
cin >> a>>b>>c>>d;
cin >> e>>f>>g>>h;
double m1,m2;
m1=(d-b)/(c-a);

m2=(h-f)/(g-e);

if(m1==m2){
if(!chck(a,c,e,h) && !chck(b,d,f,h))
cout << "no"<<endl;
}else{

02


}



}







}