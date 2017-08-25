#include<bits/stdc++.h>
using namespace std;
long long int c=1000000007;


long long int myfun(long long int a,long long int b)
{long long int ans=1;
	while(b !=0 ) {
     
           if(b%2 == 1) {          
             ans = ans*a ; 
              ans = ans%c;      
   a = a*a; 
   a %= c;                   
   b /= 2;                   
}
}
return ans%c;
}

int main(){

long long int t;
cin >> t;
for(long long q=0;q<t;q++){

long long int n;

cin >> n;

long long int sum=0;
long long int sum1=0,sum2=0;
for(long long i=0;i<n;i++){
cin >> v[i];
if(i==0){
	sum1=v[i];
}else{
		
}

}
cout << sum1<< endl;
}



}