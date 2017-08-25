#include<bits/stdc++.h>
using namespace std;

int main(){
vector<vector<int> >v(4,vector<int>(4,0));
for(int i=0;i<4;i++){
	for(int j=0;j<4;j++){
		cin >> v[i][j];
	}
}
for(int i=0;i<4;i++){
	if(v[i][3]==1){
		for(int j=0;j<3;j++){
			if(v[i][j]==1){
				cout <<"YES"<<endl;
				return 0;
			}
		}
	}
}
cout <<"NO"<< endl;

}