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

while(1){

ll amount,n;
cin >>amount>>n;
if(amount==0 && n==0){
	return 0;
}
vvi fin(n+1,vi(amount+1,0));
vi party(n);
vi v(n);
for(ll i=0;i<n;i++){
	cin >>party[i]>>v[i];
}
ll mx=0,mxj=0;
for(ll i=1;i<=n;i++){
	for(ll j=1;j<=amount;j++){
		if(j<party[i-1]){
			fin[i][j]=fin[i-1][j];
		}else{
			fin[i][j]=max(fin[i-1][j],v[i-1]+fin[i-1][j-party[i-1]]);
			if(fin[i][j]>mx){
			mx=fin[i][j];
			
			//if(fin[i][j]==)
			//mxj=j;
		}
		}
		
		
	}
}



/*for(ll i=1;i<=n;i++){
	for(ll j=1;j<=amount;j++){

if(fin[i][j]==mx){
	mxj=j;
	break;
}

	}
}*/

/*for(ll i=1;i<=n;i++){
	for(ll j=1;j<=amount;j++){
		cout<< fin[i][j]<< " ";
	}
	cout << endl;
}*/

cout << mxj<< " "<< mx<< endl;

}
return 0;
}