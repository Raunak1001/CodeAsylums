#include<iostream>
#include<cmath>
using namespace std;
#define ll int


bool isPrime(ll n){

if(n==1){
	return false;
}
	ll sq=sqrt(n);
	for(ll i=2;i<=sq;i++){
		if(n%i==0){
			return false;
		}
	}
	return true;
}

ll main(){
		
		ll t;
		cin >> t;
		ll prev=0;
		while(t--){

			ll a,b;
			cin >> a>>b;
			while(a<=b){
				if(isPrime(a)){
					cout << a<< endl;
				}
				a++;
			}
			cout << endl;
		}



	return 0;
}		