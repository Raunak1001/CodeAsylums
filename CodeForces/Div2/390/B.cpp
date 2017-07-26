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

vvc v(4,vc(4));
for(ll i=0;i<4;i++){
	for(ll j=0;j<4;j++){
		cin >> v[i][j];
	}
}

ll countx=0;
ll temp=0;
for(ll i=0;i<4;i++){
	countx=0;
	temp=0;
	for(ll j=0;j<4;j++){
		if(v[i][j]=='x'){
			countx++;
		}else if(v[i][j]=='.'){
			if(temp){
				countx=0;
				temp=0;
			}else{
				//cout <<countx<<endl;
				countx++;
				temp=1;
			}
		}else{
			countx=0;
			temp=0;
		}
		if(countx>=3){
			cout <<"YES"<< endl;
			return 0;
		}

	}
}
countx=0;
temp=0;
for(ll j=0;j<4;j++){
	countx=0;
	temp=0;
	for(ll i=0;i<4;i++){
		if(v[i][j]=='x'){
			countx++;
		}else if(v[i][j]=='.'){
			if(temp){
				countx=0;
				temp=0;
			}else{
				countx++;
				temp=1;
			}
		}else{
			countx=0;
			temp=0;
		}
		if(countx>=3){
			cout <<"YES"<< endl;
			return 0;
		}

	}
}
countx=0;
temp=0;
for(ll i=0;i<4;i++){
if(v[i][i]=='x'){
	countx++;
}else if(v[i][i]=='.')
{
	if(temp){
		countx=0;
		temp=0;
	}else{
		countx++;
		temp=1;
	}
}else{
	countx=0;
	temp=0;
}
if(countx>=3){
			cout <<"YES"<< endl;
			return 0;
		}


}
countx=0;
temp=0;
for(ll i=0;i<4;i++){
if(v[i][3-i]=='x'){
	countx++;
}else if(v[i][3-i]=='.')
{
	if(temp){
		countx=0;
		temp=0;
	}else{
		countx++;
		temp=1;
	}
}else{
	countx=0;
	temp=0;
}
if(countx>=3){
		//cout <<"ABC";

			cout <<"YES"<< endl;
			return 0;
		}


}




cout << "NO"<< endl;




}