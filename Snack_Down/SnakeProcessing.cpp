#include<iostream>
using namespace std;

int main(){

int t;
cin >>t;
for(int q=0;q<t;q++){

int n;
cin >>n;
string s;

cin >>s;
int temp3=0;
int temph=0,tempt=0;
int firsttemp=0;


for(int i=0;i<s.length();i++){
if(s[i]=='H'){

	if(tempt==1 || firsttemp==0){
		temph=1;
		tempt=0;
		firsttemp=1;
	}else{
		temp3=1;
		break;
	}
}else if(s[i]=='T'){
	if(temph==1){
		temph=0;
		tempt=1;
	}else{
		temp3=1;
		break;
	}
}

}

if(temp3==0 && (tempt==1 ||firsttemp==0)){
	cout <<"Valid"<<endl;

}else{
	cout <<"Invalid"<<endl;
}

}



}