#include<bits/stdc++.h>
using namespace std;
#define vi vector<long long int>
#define vvi vector<vector<long long int>  >
#define ll long long int 
#define pr pair<long long int,long long int>
#define mp make_pair
	
int main(){
double a,b;
cin >> a>>b;
double p=(b-a);
double q=(a+b);
double ans1=INT_MAX,ans2=INT_MAX;
double i=0;
if(p<0){
ll i=p/b;
i=i%2==0?i:i+1;
if(i!=0)
ans1=p/i;
}
ll j=q/b;
j=j%2==0?j:j-1;
if(j!=0)
ans2=q/j;

ans1=min(ans1,ans2);
cout << std::fixed;
cout <<std::setprecision(9);
if(ans1==INT_MAX){
	cout << -1<<endl;
}else
cout<< ans1<< endl;

}