#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define vi vector<long long int >
#define vvi vector<vector<long long int > >

int main(){
ll n;
cin >>n;
string s;
cin >>s;
vi v;
for(ll i=0;i<n;i++){
ll c=s[i]-'0';
if(c!=0 && c!=1){
	if(c%2!=0 && c!=9){
		v.push_back(c);
	}else{
if(c==2){
    v.push_back(c);
}
if(c==4){
v.push_back(3);
v.push_back(2);
		v.push_back(2);

}
if(c==9){
	v.push_back(7);
	v.push_back(2);
	v.push_back(3);
	v.push_back(3);
}

if(c==6){
			v.push_back(5);
					//v.push_back(c);
		v.push_back(3);


}if(c==8){
			v.push_back(7);
		v.push_back(2);
		v.push_back(2);
		v.push_back(2);

}


	}
}


}


sort(v.begin(),v.end());
for(ll i=v.size()-1;i>=0;i--){
	cout << v[i];
}


}