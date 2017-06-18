#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define vi vector<long long int >
#define vvi vector<vector<long long int > >


int main(){

ll sum=0;
ll sum1=0;
char c;
while(scanf("%c",&c)!=EOF){
if(c=='q'){
sum+=9;
}
if(c=='r'){
sum+=5;

}if(c=='b'){
sum+=3;

}if(c=='n'){
sum+=3;

}if(c=='p'){
sum+=1;

}
//safadsfasdfs

if(c=='Q'){
sum1+=9;
}
if(c=='R'){
sum1+=5;

}if(c=='B'){
sum1+=3;

}if(c=='N'){
sum1+=3;

}if(c=='P'){
sum1+=1;

}



}

if(sum==sum1){
	cout <<"Draw"<<endl;
	return 0;
}

if(max(sum,sum1)==sum1){
	cout <<"White"<< endl;
return 0;
}

cout <<"Black"<< endl;
return 0;


}

