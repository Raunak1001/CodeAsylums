#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class PrimeSoccer{

public:
vector<double> fact;
vector<double> v;

public:
PrimeSoccer(){
	fact.resize(18);
fact[0]=1;
for(int i=1;i<18;i++){
	fact[i]=fact[i-1]*(i+1);
}
v.resize(7);

	v[0]=fact[17]/(fact[14]*fact[2]);
v[1]=fact[17]/(fact[12]*fact[4]);
	v[2]=fact[17]/(fact[10]*fact[6]);
	v[3]=fact[17]/(fact[6]*fact[10]);
	v[4]=fact[17]/(fact[4]*fact[12]);
	v[5]=18;
	v[6]=153;

//cout << fact[17];
}

double getProbability(int skillOfTeamA, int skillOfTeamB){

double p1=((double)skillOfTeamA)/100;
double a=(v[6]*pow(p1,2)*pow(1-p1,16)+v[0]*pow(p1,3)*pow(1-p1,15)+v[1]*pow(p1,5)*pow(1-p1,13)+v[2]*pow(p1,7)*pow(1-p1,11)+v[3]*pow(p1,11)*pow(1-p1,7)+v[4]*pow(p1,13)*pow(1-p1,5)+v[5]*pow(p1,17)*(1-p1));
p1=((double)skillOfTeamB)/100;
double b=(v[6]*pow(p1,2)*pow(1-p1,16)+v[0]*pow(p1,3)*pow(1-p1,15)+v[1]*pow(p1,5)*pow(1-p1,13)+v[2]*pow(p1,7)*pow(1-p1,11)+v[3]*pow(p1,11)*pow(1-p1,7)+v[4]*pow(p1,13)*pow(1-p1,5)+v[5]*pow(p1,17)*(1-p1));

return ((a*b)+(a*(1-b))+(b*(1-a)));
}

};


int main(){

PrimeSoccer ob;
cout<< ob.getProbability(12,89)<<endl;

}