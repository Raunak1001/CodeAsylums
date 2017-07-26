#include<bits/stdc++.h>
using namespace std;
#define vi vector<long long int>
#define vvi vector<vector<long long int> >
#define ll long long int 
ll mx=-1;
ll myFun(string s,ll index,ll prev,vvi &ans){
    if(mx==0){
        //cout <<"asdf";
        return 0;
    }
    ll n=s.length();
    if(index>=n){
        //cout <<"dsf";
        return 1;
    }
    //cout <<"sf";
    if(prev==-1 && ans[index][0]!=-1){
        return ans[index][0];
    }else if(ans[index][1]!=-1){
        return ans[index][1];
    }
    
    
   
    //ll count=0;
    if(prev==-1){
        if(s[index]=='0'){
            return 0;
            }else{
                ans[index][0]=myFun(s,index+1,s[index]-'0',ans);
        }
        
    }else{
        if(s[index]=='0'){
            if(prev>'2'){
                mx=0;
                return 0;
            }else{
                ans[index][1]=myFun(s,index+1,-1,ans);

            }
        }else{
            //cout <<"dsfa";
           if(prev<=1){
               ans[index][1]=myFun(s,index+1,-1,ans)+myFun(s,index+1,s[index]-'0',ans);
               //cout << s[index]<<"sdfsd"<< endl;

           }else if(prev==2 && s[index]<'7'){
            //cout <<"sfs";
               ans[index][1]=myFun(s,index+1,-1,ans)+myFun(s,index+1,s[index]-'0',ans);
           }else{
                ans[index][1]=myFun(s,index+1,s[index]-'0'  ,ans);
                                   
          }
            
            
        }
    }
    
    if(prev==-1){
    return ans[index][0];
    }
    return ans[index][1];
}



int main()
 {
ll t;
mx=-1;
cin >> t;
for(ll q=0;q<t;q++){
    
    ll n;
    cin >> n;
    string s;
    cin >>s;
    if(n==0 || s[0]=='0'){
        cout <<0<< endl;
        continue;
    }
    vvi ans(n,vi(2,-1));
    
    ll count=0;
    //cout<<"Sfs"<< endl;    
    count=myFun(s,1,s[0]-'0',ans);
    if(mx==0){
        cout << mx<< endl;
    }else{
        cout << count<< endl;
    }

   /* for(ll i=0;i<n;i++){
        for(ll j=0;j<=1;j++){
            cout << ans[i][j]<<" ";
        }
        cout << endl;   
    }*/
}


	return 0;
}