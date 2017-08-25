#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define vi vector<long long int >
#define vvi vector<vector<double > >

int main(){

ll p;
cin >> p;
for(ll q=0;q<p;	q++){
ll k,a,b;
cin >>k>>a>>b;
vvi v;
vector<double> z(1,k);
v.push_back(z);
for(ll i=1;i<a;i++){
std::vector<double> t;
for(ll j=0;j<i+1;j++){
	//cout << i<<" "<<j<<endl;
if(j==0 ){
	if(v[i-1][j]-1>0){
	t.push_back((v[i-1][0]-1)/2);
}else 
{ 
	t.push_back(0);
}

	}else{
		double u=0;
		if(v[i-1][j-1]>1){
u=(v[i-1][j-1]-1)/2;
}
		if(j<i && v[i-1][j]>1){
u+=(v[i-1][j]-1)/2;
}
	t.push_back(u);
}
}


		v.push_back(t);	

}

/*for(int l=0;l<v.size();l++){
	for(int o=0;o<v[l].size();o++){
		cout<< v[l][o]<< " ";
	}
	cout << endl;
}*/

if(v[a-1][b-1]<=1)
cout << v[a-1][b-1]<< endl;
else
	cout <<1<<endl;
}


}