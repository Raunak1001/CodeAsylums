#include<bits/stdc++.h>
using namespace std;
#define vi vector<long long int>
#define vp vector<pair<long long int,long long int > >
#define vc vector<char>
#define vvi vector<vector<long long int>  >
#define vvp vector<vector<pair<long long int,long long int> > >
#define vvc vector<vector<char>  >
#define ll long long int 
#define pr pair<long long int,long long int>
#define mp make_pair		
#define pb push_back

bool isValid(vvi &v,ll i){

ll n=v[0].size();
char a=v[i][0];
for(ll j=0;j<n;j++){
	if(v[i][j]!=a){
		return false;
	}
}
return true;

}


bool isValid2(vvi &v,ll i){

ll n=v.size();
char a=v[0][i];
for(ll j=0;j<n;j++){
	if(v[j][i]!=a){
		return false;
	}
}
return true;

}




int main(){
	
	ll n,m;
	cin >>n>>m;
	vvi v(n,vi(m,0));
	vi count(4,0);
	char a;
	for(ll i=0;i<n;i++){
		for(ll j=0;j<m;j++){
			cin >>a;
			if(a=='R'){
				v[i][j]=1;
			}
			if(a=='G'){
				v[i][j]=2;
			}
			if(a=='B'){
				v[i][j]=3;
			}
		}
	}

ll prev=-1;
ll temp=0;
for(ll i=0;i<n;i++){
if(prev==-1){
	prev=v[i][0];
if(isValid(v,i)){
	count[prev]++;
}else{
	temp=1;
	break;
}

}else if(prev==v[i][0]){
	if(isValid(v,i)){
	count[prev]++;
}else{
	temp=1;
	break;
}
}else if(prev!=v[i][0]){
	prev=v[i][0];
	if(count[prev]!=0){
		temp=1;
		break;
	}

	if(isValid(v,i)){
	count[prev]++;
}else{
	temp=1;
	break;
}

}

}

if(!temp){
	if(count[1]==count[2] && count[1]==count[2]){
		cout <<"YES"<< endl;
		return 0;
	}
}
	count[1]=count[2]=count[3]=0;


prev=-1;
temp=0;
for(ll j=0;j<m;j++){
if(prev==-1){
	prev=v[0][j];
if(isValid2(v,j)){
	count[prev]++;
}else{
	temp=1;
	break;
}

}else if(prev==v[0][j]){
	if(isValid2(v,j)){
	count[prev]++;
}else{
	temp=1;
	break;
}
}else if(prev!=v[0][j]){
	prev=v[0][j];
	if(count[prev]!=0){
		temp=1;
		break;
	}

	if(isValid2(v,j)){
	count[prev]++;
}else{
	temp=1;
	break;
}

}

}

if(!temp){
	if(count[1]==count[2] && count[1]==count[2]){
		cout <<"YES"<< endl;
		return 0;
	}
}

cout <<"NO"<< endl;
return 0;


	return 0;
}