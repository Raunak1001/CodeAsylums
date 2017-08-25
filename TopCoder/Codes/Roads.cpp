	#include<iostream>
#include<vector>

	using namespace std;

	class ColorfulRoad{

	public:
	int getMin(string road){

	int n=road.length();


	int tempR=0,tempG=0,tempB=0;
	vector<int> v(n,1000);
	
	
v[n-1]=0;
	for(int i=n-1;i>0;i--){
	
		if(road[i]=='R'){
	tempR=1;
	}else if(road[i]=='G'){
	tempG=1;
	}else{
	tempB=1;
	}
	if(tempG==1){
	for(int j=i-1;j>=0;j--){

	if(road[j]=='R'){
		//cout << v[i]<< endl;
	tempG=0;
	tempR=1;
	tempB=0;

	v[j]=min(v[j],v[i]+(i-j)*(i-j));

	}
	}

	if(tempG==1){
//cout <<"fsdadf";
	return -1;
}
	}

	else 
	if(tempR==1){
		//cout<<i<<endl;
	for(int j=i-1;j>=0;j--){
	if(road[j]=='B'){
	tempR=0;
	tempG=0;
	tempB=1;
	v[j]=min(v[j],v[i]+(i-j)*(i-j));

	}
	}
	if(tempR==1){
		//cout<<"fsfa";

	return -1;}
	}

	else
	if( tempB==1){
//cout <<i<<endl;
	for(int j=i-1;j>=0;j--){

	if(road[j]=='G'){
		//	cout << j<<endl;
	tempG=1;
	tempB=0;
	tempR=0;
	v[j]=min(v[j],v[i]+(i-j)*(i-j));

	}
	}

	if(tempB==1){
		//cout<<"fsdf";
	return -1;
}
	}

	} 

if(v[0]!=1000){
	return v[0];
}
else{
	return -1;
}


	}




};


int main(){

string s;
cin >> s;
ColorfulRoad ob;

cout<< ob.getMin(s)<<endl;
return 0;
}