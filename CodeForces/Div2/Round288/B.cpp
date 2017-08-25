#include<iostream>
using namespace std;

int main(){
string s;
cin >>s;
long long int n=s.length();
int temp=1;
int max=0;
int maxEven=0;
int maxEvenIndex;
int maxIndex;
int FirsEven=-1;
int FirsEvenIndex;
for(int i=0;i<n;i++){
	int a=s[i]-'0';
	if(a%2==0){
		temp=0;
		if(FirsEven==-1){
			FirstEven=a;
FirsEvenIndex=i;
		}
		if(a>maxEven){
			maxEven=a;
			maxEvenIndex=i;
		}
	}
	if(a>max){
		max=a;
		maxIndex=i;
	}
}

if(temp==1){
	if((s[n-1]-'0')%2!=0){
		cout << -1<<endl;
	}else{
		cout << s<<endl;
	}
return 0;
}else{
	if((s[n-1]-'0')%2==0){
s
	}
}



}