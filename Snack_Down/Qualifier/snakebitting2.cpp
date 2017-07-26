
#include <bits/stdc++.h>

struct query
{
    int val;
    int index;
};

bool myfun(query a,query b){
    return a.val > b.val;
}

int main(){
    int t;
    cin>>t;
    for(int s=0;s<t;s++){
        int n,m;
        cin>>n;
        cin>>m;
        std::vector <int>  v(n,0);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        sort(v.begin(),v.end(),greater<int>(    ));
 std::vector<query> k(m);       
 for(int i=0;i<m;i++){
    
    cin >> k[i].val;
    k[i].index=i;
    //k.push_back(q);
 }

        sort(k.begin(),k.end(),myfun);

        /*for (int i = 0; i < m; ++i)
        {

            cout<<k[i].val<<" ";
        }
cout<<endl;*/

int j=0;
int q=k[j].val;
std::vector<int> a(n,0);
for(int i=0;i<n;i++){
    a[i]=v[i]+(n-i-1);
}
    /*for(int i=0;i<n;i++){
       cout << a[i]<<" ";
    }
    cout <<endl;*/

std::vector<int> finalans;

int count=0;
int temp2=1,temp3=1;




for(int i=0;i<n;i++){
    temp2=1;
    temp3=1;
    count=i;
while(i<=n && v[i]<q){
    
if(a[i]>=q){
    if(temp2==0){
        temp3=0;
        temp2=1;    
        break;

    }
int k=i;
    while(1){
            

if((q<v[k-1] && k>=n || a[k]-(q-v[k-1])<q)){
    temp2=0;
    break;

}
count++;
            k++;
}
i++;
    }else{
        temp3=0;
        break;
    }


}
if(temp3==0){
finalans.push_back(count);
    j++;
    if(j>=m){
        break;
    }
q=k[j].val;
i--;
temp3=1;
}

}


int g=finalans.size();
for (int i = g; i <m; ++i)
{
    finalans.push_back(0);
}

std::vector<int> finalfinalans(m,0);
for(int i=0;i<m;i++){
finalfinalans[k[i].index]=finalans[i];
}

for (int i = 0; i < m; ++i)
{
    cout << finalfinalans[i]<<endl;
}

}





}

