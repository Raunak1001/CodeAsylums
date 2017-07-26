#include<bits/stdc++.h>
using namespace std;
#define vi vector<long long int>
#define vvi vector<vector<long long int> >
#define ll long long int 

int main()
 {
     ll t;
     cin >>t;
     for(ll i=0;i<t;i++){
     string m="",c="",s;

cin >>s;
ll n= s.length();
for(ll i=0;i<n;i++){
    if(s[i]-'0'>=0 && s[i]-'0'<=9){
        if(c=="" && s[i]=='0'){
            continue;
        }
        c=c+s[i];
        if(c.length()>m.length()){
           // cout <<c<<" "<<m<<endl;
            m=c;
            
            
        }else if(c.length()==m.length())
        m=max(m,c);
            
    }else{
        c="";
    }
    
    
}

       cout <<m<<endl;   
}


    return 0;
}