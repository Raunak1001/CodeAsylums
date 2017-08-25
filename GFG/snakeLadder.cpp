#include<bits/stdc++.h>
using namespace std;
//#define INT_MAX 10000;


int myfun(vector<int > &v,map<int,int> &m,int index){
	if(index >=30){
		return 0;
	}
if(index>=24){
	return 1;
}
if(v[index]!=50){
	return v[index];
}
if(m[index]!=0){
	//cout << m.find(index)->second<< endl;	
	v[index]=min(v[index],myfun(v,m,m[index]));
}else{
	for(int i=1;i<=6;i++){
		//cout << i<< endl;
v[index]=min(v[index],myfun(v,m,index+i));
}
v[index]+=1;
}

return v[index];

}


int main(){

long long int t;
cin >>t;


for(int q=0;q<t;q++){
map<int,int> m;
int n;
vector<int >v(31,50);
cin >>n;
int a,b;
for(int i=0;i<n;i++){
	cin >>a>>b;
m[a]=b;

}
//cout<< myfun(v,m,2)<<endl;
v[1]=myfun(v,m,1);
cout <<v[1]<<endl;

}


}