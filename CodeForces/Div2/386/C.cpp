#include<bits/stdc++.h>
using namespace std;
#define vi vector<long long int>
#define vc vector<char>
#define vvi vector<vector<long long int>  >
#define vvc vector<vector<char>  >
#define ll double
#define pr pair<long long int,long long int>
#define mp make_pair

int main(){
 ll s,x1,x2;
 cin >>s>>x1>>x2;
 ll t1,t2;
 cin >> t1>>t2;
 ll tpos,tdir;
 ll distance;
 cin >> tpos>> tdir;
 ll mydir;

 if(x2>x1){
 	mydir=1;
 }else{
 	mydir=-1;
 }
if(tdir!=mydir){
	//cout << mydir<< endl;
	if(mydir>0){
		//cout <<"fasdf";
		distance=tpos+x1;
		if(x1==tpos){
	distance=2*x1;
}
	}else{
		distance=2*s-tpos-x1;
		if(x1==tpos){
	distance=2*(s-x1);
}
	}


}else{
	if(mydir>0){
		if(tpos>x1){
			distance=s-tpos+s+x1;
		}else{
			distance=x1-tpos;
		}
	}else{
		if(tpos<x1){
			distance=tpos+s+s-x1;
		}else{
			distance=tpos-x1;
		}
	}

}
//cout << distance<< endl;
ll timeIndi=abs(x2-x1)*t2;

if(t2<=t1){
	cout << timeIndi<<endl;
	return 0;
}

ll timeReq=((distance)*t1*t2)/(t2-t1);

if(timeIndi<=timeReq){
	cout << timeIndi<< endl;
	return 0;
}
ll distanceLeft=abs(x2-x1)-(timeReq/t2);
ll totalTime=timeReq+distanceLeft*t1;
cout << totalTime<< endl;





return 0;
}