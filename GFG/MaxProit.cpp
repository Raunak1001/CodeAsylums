#include<bits/stdc++.h>
using namespace std;
#define vi vector<long long int>
#define vvi vector<vector<long long int> >
#define vvvi vector<vector<vector<long long int> > >
#define ll long long int 
ll transac;

ll myFun(ll amount, ll k,ll temp,ll index,vi &v, vvvi &dp)
{
    if(index>=v.size()){
        return amount;
    }
    if(k>=transac){
        return amount;
    }

    if(dp[index][temp][k]!=-1){
        return dp[index][temp][k];
    }
    
    /*if(k==transac){
        if(temp){
            cout << amount+v[index]<< endl;
            dp[index][temp][k]= max(amount+v[index],myFun(amount,k,1,index+1,v,dp));
            return dp[index][temp][k];
        }else{
            return amount;
        }
    }*/
    
    if(temp)
    dp[index][temp][k]= max(myFun(amount+v[index],k+1,0,index+1,v,dp),myFun(amount,k,1,index+1,v,dp));
    else
    {
    dp[index][temp][k]= max(myFun(amount-v[index],k,1,index+1,v,dp),myFun(amount,k,0,index+1,v,dp));

    }
    
    return dp[index][temp][k];
}

int main()
 {

ll t;
cin >> t;
for(ll q=0;q<t;q++){
    ll n;
    cin >>transac;
    cin >> n;
    vi v(n);
    for(ll i=0;i<n;i++)
    {
        cin >> v[i];
    }
    vvvi dp(32,vvi(2,vi(11,-1)));
    ll amount=0;
   myFun(0,0,0,0,v,dp);
    
    cout << dp[0][0][0]<< endl;
}

    return 0;
}