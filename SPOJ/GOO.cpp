	#include<bits/stdc++.h>
	using namespace std;
	#define vi vector<long long int>
	#define vvi vector<vector<long long int>  >
	#define ll long long int 
	#define pr pair<long long int,long long int>
	#define mp make_pair
		
	int main(){

	ll t;
	cin >> t;

vi  count(51);
vi str(51);
count[1]=1;
str[1]=1;
for(ll i=2;i<=50;i++)
{
str[i]=2*str[i-1];
count[i]=2*count[i-1]+str[i-1];
}

	for(ll q=0;q<t;q++){
	 ll n;
	cin >>n;
	
cout << str[n]<<" "<<count[n]<< endl;
	}



}