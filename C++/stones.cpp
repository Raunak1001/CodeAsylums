#include<iostream>
using namespace std;

int main(){

long long int n;
cin >>n;
string s;
cin >> s;
int count=0;
char prev='t';

for(int i=0;i<n-1;i++){
if(s[i]==s[i+1]){
	count++;
}

}

cout << count <<endl;
}
