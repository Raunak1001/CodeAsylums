#include<bits/stdc++.h>
using namespace std;
#define vi vector<long long int>
#define vvi vector<vector<long long int> >
#define ll long long int 

int main()
 {
	
	ll t;
	cin >>t;
	for(ll q=0;q<t;q++){
	    string s;
	    cin >> s;
	    vi countIndex(26,0);
	    int temp=0;
	    int c;
	    int n =s.length();
	    int distinct=0;
	    int currentDistinct=0;
	    vi visited(26,0);
	    for(ll i=0;i<n;i++){
	        c=s[i]-'a';
	        //cout << s<<" ";	
	        countIndex[c]++;
	        if(countIndex[c]==1){
	            distinct++;
	        }
	    }
	     /*
	        for(int i=0;i<n;i++){
	        	cout << countIndex[i]<<" ";
	        }*/
	    
	        
	        int leng=0;
	        for(ll i=0;i<n;i++){	
	            c=s[i]-'a';
	            if(!temp){
	              countIndex[c]--;
	              	          //    cout <<c<<" "<<countIndex[c]<<endl;

	              if(countIndex[c]==0){
	                  temp=1;
	              }

	            }
	            
	            if(temp){
	                if(!visited[c]){
	                    currentDistinct++;
	                }
	                leng++;
	                if(currentDistinct==distinct){
	                    break;
	                }
	            }
	            
	            
	            }
	            cout << leng<<endl;
	            
	        }
	    
	    
	    
	    
	return 0;
}