#include<iostream>
using namespace std;

int main(){

long long int n,t;
cin >>n>>t;
string a,b="";
cin >>a;
int count=0;
while(count<t){
for(int i=0;i<n-1;i++){
if(a[i]=='B'){
	if(a[i+1]=='G'){
		swap(a[i],a[i+1]);
		i+=1;
	}
}

}
count++;
}
cout <<a<<endl;


}