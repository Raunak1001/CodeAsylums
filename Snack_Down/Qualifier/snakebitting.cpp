/*#include<iostream>
#include<algorithm>
#include<vector>*/
#include<bits/stdc++.h>

using namespace std;


long long  n,Q,q,index_last;
vector<long long>  v(100005);
std::vector<long long> sum(100005);

bool getbool(long long i){

if(i>=q*(index_last-i)-sum[index_last]+sum[i])    
    {return true;
    }
    else{
        return false;
    }
}


long long  binary_search(long long q){
long long  low=0,high=n-1,mid=0;
    while(low<high){
        mid=low+(high-low)/2;
        if(v[mid]>=q){
            high=mid;
        }
        else{
            low=mid+1;
        }
    }

 if(v[low]>=q){
      return low;
}else{  return -1;
}
}

int main(){

long long t;
cin>>t;
while(t--){

    cin>>n;
    cin>>Q;
    for(long long i=0;i<n;i++){
        cin>>v[i];
    }
     
   //cout << endl;
    sort(v.begin(),v.begin()+n);
/*for(int i=0;i<n;i++){
    cout<<v[i]<<" ";
   }*/
    for(long long i=1;i<=n;i++){
        sum[i]=sum[i-1]+v[i-1];
    }

    while(Q--){

        cin>>q;
        long long finalans;
        index_last=binary_search(q);
        if(index_last==-1){
            
            index_last=n;
            finalans=0;
        }
        if(index_last==0){

            index_last=0;
            finalans=n;
            cout<<finalans<<"\n";
            continue;
        }
        else{   

            finalans=n-index_last;
           
            long long low=0,high=index_last-1,mid=0;
            while(low<high){
                mid=low+((high-low+1)/2);
                if(getbool(mid)==true){
                    high=mid-1;
                }
                else{
                    low=mid;
                }
            }
            
            if(getbool(low)==false){
                if(low+1<=index_last-1){
                    finalans+=index_last-(low+1);
                }
                else{
                    finalans+=0;
                }
                cout<<finalans<<endl;
            }
            else{
                finalans+=index_last-low;       
                cout<<finalans<<endl;
            }
        }
    }
}
return 0;
}
