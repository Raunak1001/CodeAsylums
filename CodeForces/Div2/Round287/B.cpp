#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int main(){

double r,x1,y1,x2,y2;
cin >> r>>x1>>y1>>x2>>y2;

double a=((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2));
r*=2;
r*=r;
a/=r;

double b= sqrt(a);
if(b-int(b)==0){
	cout << (int)b<<endl;
}else{
	cout <<(int)b+1<<endl;
}

}