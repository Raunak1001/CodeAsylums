#include<iostream>
#include<vector>
using namespace std;
int main()
 {
	//code
	
	long long int t;
	cin >>t;
	for(long long int q=0;q<t;q++){
	    long long int a,b;
	    cin >> a>>b;
	    int temp=1;
	    long long int count=0;
	    for(long long int i=2002;i<=b;i++){
	        if(i<a){
	            count=0;
	        }
	        if((i-1)%4!=0){
	            temp++;
	        }else{
	        	temp+=2;
	        }
	        if(temp==9){
	        	temp=2;
	        }

	        if(temp>7){
	            temp=1;
	        }
	        if(temp==7){
	            count++;
	        }
	    }
	    if(a<2001){
	    for(long long int i=2000;i>=a;i--){
	        if((i)%4!=0){
	            temp--;
	        }else{
	        	temp-=2;
	        }
	        if(temp==-1){
	        	temp=6;
	        }
	        if(temp<=0){
	            temp=7;
	        }
	        if(temp==7){
	            count++;
	        }
	    }
	    
	        
	    }
	    cout << count<<endl;
	    
	}
	
	return 0;
}