#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define vi vector<long long int >
#define vvi vector<vector<long long int > >

int main(){

ll a,b,c;
cin >>a>>b>>c;
ll t=abs(a)+abs(b);
if(t>c){
	cout <<"No"<<endl;
	return 0;
}else{

if((c-t)%2==0){
cout <<"Yes"<< endl;
return 0;
}
cout <<"No"<<endl;
return 0;

} 
return 0;

}
