#include<bits/stdc++.h>
using namespace std;
#define vi vector<long long int>
#define vvi vector<vector<long long int> >
#define ll long long int


bool myfun(ll n,ll m,ll s1,ll s2){
    if(s1<0 || s2<0 || s1>=n || s2>=m){
        return false ;
    }
    return true;
}


int main()
 {

ll t;
cin >>t;
for(ll p=0;p<t;p++){
    ll n,m;
    cin >>n>>m;
    ll s1,s2,d1,d2;
    cin >>s1>>s2>>d1>>d2;
    vvi v(n*m);
    ll temp;
       for(ll i=0;i<n;i++){
           for(ll j=0;j<m;j++){
               temp=m*i+j;
               if(myfun(n,m,i+1,j+2)){
                   v[temp].push_back(m*(i+1)+j+2);
               }
               if(myfun(n,m,i+1,j-2)){
                   v[temp].push_back(m*(i+1)+j-2);
               }
               if(myfun(n,m,i-1,j+2)){
                   v[temp].push_back(m*(i-1)+j+2);
               }
               if(myfun(n,m,i-1,j-2)){
                   v[temp].push_back(m*(i-1)+j-2);
               }
               if(myfun(n,m,i+2,j+1)){
                   v[temp].push_back(m*(i+2)+j+1);
               }
               if(myfun(n,m,i+2,j-1)){
                   v[temp].push_back(m*(i+2)+j-1);
               }
               if(myfun(n,m,i-2,j+1)){
                   v[temp].push_back(m*(i-2)+j+1);
               }
               if(myfun(n,m,i-2,j-1)){
               /// cout << temp<<endl;
                   v[temp].push_back(m*(i-2)+j-1);
               }
               
           }
       }

  /*for(ll i=0;i<n*m;i++){
    cout << "ver "<<i<<" ";
    for(ll j=0;j<v[i].size();j++){
      cout <<v[i][j]<<" ";
    }
    cout << endl;
  }*/


   vi dis(n*m,1000000);
   s1--;
   s2--;
   d1--;
   d2--;
   queue<ll> q;
   q.push(m*s1+s2);
   dis[m*s1+s2]=0;
   temp=0;
   while(!q.empty()){
       ll node=q.front();
       q.pop();
       for(ll i=0;i<v[node].size();i++){
       if(dis[v[node][i]]>dis[node]+1){
           dis[v[node][i]]=dis[node]+1;
           q.push(v[node][i]);
       }
       if(v[node][i]==m*d1+d2){
temp=1;
           break;
       }
     }
     if(temp){
      break;  
     }
   }
       if(dis[m*d1+d2]==1000000){
           cout <<-1<<endl;
       }else{
           cout << dis[m*d1+d2]<<endl;
       }
   
   
   
    
    
}



	return 0;
}