#include<bits/stdc++.h>
using namespace std;
#define vi vector<long long int>
#define vc vector<char>
#define vvi vector<vector<long long int>  >
#define vvc vector<vector<char>  >
#define ll long long int 
#define pr pair<long long int,long long int>
#define mp make_pair

int main(){
 
 ll n,k,g,b;
 cin >>n>>k>>g>>b;
ll temp=0;
if(g<b){
temp=1;
swap(g,b);
}
ll sets=(g)/k;
ll reqb=sets-1;
if(g%k!=0){
reqb++;
}
b-=reqb;
if(b<0){
	cout <<"NO"<< endl;
	return 0;
}
vc v;
ll countSets=0;
while(countSets<sets){
ll i=0;
while(i<k){
v.push_back('G');
if(i!=k-1 && b>0){
	v.push_back('B');
	b--;
}
g--;
i++;
}
if(countSets!=sets-1){
v.push_back('B');
reqb--;
}
countSets++;
}
if(g>0){
	v.push_back('B');
	reqb--;
	while(g>0){
		v.push_back('G');
		g--;
	}
}
if(reqb>0 || b>0){
	v.push_back('B');
}
for(ll i=0;i<n;i++){
if(temp){
	if(v[i]=='G'){
		cout <<'B';
	}else{
		cout <<'G';
	}

}else{
	cout << v[i];
}



}


cout << endl;





return 0;

}