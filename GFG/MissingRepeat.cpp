#include<bits/stdc++.h>
using namespace std;
#define vi vector<long long int>
#define vvi vector<vector<long long int> >
#define ll long long int 

int main()
 {
     int t;
     cin >>t;
     for(ll q=0;q<t;q++){
int n;
int x=0;
cin >>n;
        // cout <<n<<endl;

int v[n];
for(int i=0;i<n;i++){
    cin >> v[i];
    x=x^v[i];
}
int count[32]={0};
int twos=0;
for(int i=0;i<32;i++){
	for(int j=0;j<n;j++){

		//cout <<((v[j]>>i &1))<<endl;
		if(v[j]>>i &1){

			count[i]++;
		}
	}
    if(count[i]==2){
    	//cout <"SFS";
    	twos|=(1<<i);
    }
}
x=x^twos;
for(int i=1;i<=n;i++){
	x=x^i;
}
cout << twos<<" "<<x<<endl;

}
	return 0;

}