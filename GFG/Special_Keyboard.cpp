#include<bits/stdc++.h>
using namespace std;
#define vi vector<long long int>
#define vvi vector<vector<long long int>  >
#define ll long long int 
#define pr pair<long long int,long long int>
#define mp make_pair
ll  n;



int main(){
 ll t;
 cin >> t;
 for(ll q=0;q<t;q++){
cin >> n;
 vi v(n+1,0);
 if(n<6){
 	cout << n<< endl;
 	continue;
 }
for(ll i=1;i<=5;i++){
	v[i]=i;
}

for(ll i=6;i<=n;i++){
//cout << v[i-3]<<endl;
for(ll j=6;j<=i;j++){
	ll curr=(v[j-3])*(i-j+2);
	//cout << curr<<" "<<v[i]<<endl;
	if(curr>v[i]){
		v[i]=curr	;
	}
}

}

cout << v[n]<<endl;



}


}