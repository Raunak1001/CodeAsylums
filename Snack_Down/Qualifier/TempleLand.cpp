#include<iostream>
#include<vector>
using namespace std;

int main(){

int s;
cin >>s;
for(int q=0;q<s;q++){

int n;
cin >>n;
int temp=0;
vector<int> v(n,0);
for(int i=0;i<n;i++){
cin >>v[i];

}
if(v.size()%2==0){
	temp=1;
	cout << "no"<<endl;
continue;
}
for(int i=0;i<n/2;i++){
if(v[i]!=i+1 || v[n-1-i]!=i+1)
{temp=1;
	break;
}
}

if(temp!=1 && v[n/2]-v[(n/2)-1]==1){
	cout << "yes"<<endl;
}else{
	cout << "no"<<endl;
}

}

}