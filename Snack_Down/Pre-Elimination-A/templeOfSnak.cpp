#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define lln long long int 
#define vi vector<long long int>	
lln mmax=0;
lln mindex=-1;
lln getCost(lln count,lln index,vi &v,vi &a){
lln n = v.size();
if(index>=n){
	return 0;
}


if(index>=mindex && count==1){
a[index]=min(a[index],min(v[index]+getCost(1,index+1,v,a),abs(v[index]-1)+getCost(0,index+1,v,a)));

}else if(index>=mindex)
{
a[index]=min(abs(count-v[index])+getCost(count-1,index+1,v,a),a[index]);

}else if(count ==1){
a[index]=min(a[index],min(v[index]+getCost(1,index+1,v,a),abs(a[0]-1)+getCost(2,index+1,v,a)));

}else{
a[index]=min(abs(count-v[index])+getCost(count+1,index+1,v,a),a[index]);

}

return a[index];

}



int main(){
lln t;
cin >>t;
for(int q=0;q<t;q++){

lln n;
cin >>n;

vi v(n,0);
vi a(n,1000000000)	;
for(long long int i=0;i<n;i++){
	cin >> v[i];
	if(v[i]>mmax){
		mmax=v[i];
		mindex=i;
	}
}

a[0]=min(v[0]+getCost(1,1,v,a),abs(v[0]-1)+getCost(2,1,v,a));

for(int i=0;i<n;i++){
	cout <<a[i]<<	" ";
}

cout <<a[0]<<endl;


}



}

