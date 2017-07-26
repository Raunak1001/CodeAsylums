#include<bits/stdc++.h>
using namespace std;
#define vi vector<long long int>
#define vvi vector<vector<long long int>  >
#define ll long long int 
#define pr pair<long long int,long long int>
#define mp make_pair

int main(){

ll n;
cin >> n;
ll count=0;
while(n){
if(n%2!=0){
count++;
n--;

}
n=n>>1;
}
cout << count<< endl;


}

