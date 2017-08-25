#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define vi vector<long long int >
#define vvi vector<vector<long long int > >

int main(){
ll t;
cin >>t;
for(ll q=0;q<t;q++){
	ll n;
	cin >>n;

ll count=0;
while(n){
	n=n/5;
	count+=n;

}
cout << count<<endl;
}


}
