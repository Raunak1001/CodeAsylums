  #include<bits/stdc++.h>
  using namespace std;

  int main(){
  long long int  t;
  cin>>t;
  for(long long int r=0;r<t;r++){

  long long int  changex[8]={-1,-1,-1,1,1,1,0,0};
  long long int  changey[8]={-1,0,1,-1,0,1,-1,1};
  vector<vector<long long int> >  a(600,vector<long long int>(600));
  vector<vector<bool> > visited(600,vector<bool>(600,0));
  vector<vector<long long int> >  height(600,vector<long long int>(600,-1));
     
      long long int  n,m,maxa=0,maxb=0;
     
      cin>>n>>m;
      for(long long int  i=0;i<n;i++){
      for(long long int  j=0;j<m;j++){
      
        cin>>a[i][j];
      if(a[i][j]>maxa){
     
         maxa=a[i][j];
         }
         }
      }
      queue<pair<long long int ,long long int> > q;
      for(long long int  i=0;i<n;i++){
       for(long long int  j=0;j<m;j++){
       
    if(a[i][j]==maxa){

          visited[i][j]=1;
         q.push(make_pair(i,j));
            height[i][j]=0;
      
          }
          }
      }
      while(!q.empty()){
       pair<long long int ,long long int> p=q.front();
        q.pop();
      for(long long int  i=0;i<8;i++){
      
      if(p.first+changex[i]<=n-1 && p.first+changex[i]>=0 && p.second+changey[i]<=m-1 && p.second+changey[i]>=0){
      
      if(visited[p.first+changex[i]][p.second+changey[i]]==0){
          
          height[p.first+changex[i]][p.second+changey[i]]=height[p.first][p.second]+1;  
        q.push(make_pair(p.first+changex[i],p.second+changey[i]));
         visited[p.first+changex[i]][p.second+changey[i]]=1;
          
          }
         else if(height[p.first+changex[i]][p.second+changey[i]]>height[p.first][p.second]+1){
        
        height[p.first+changex[i]][p.second+changey[i]]=height[p.first][p.second]+1;
        q.push(make_pair(p.first+changex[i],p.second+changey[i]));
        visited[p.first+changex[i]][p.second+changey[i]]=1;
       
         }
           }
      }
     }
      for(long long int  i=0;i<n;i++){
      for(long long int  j=0;j<m;j++){
     
       if(height[i][j]>maxb)
       maxb=height[i][j];
     }
     }
    cout<<maxb<<endl;;
  }
  return 0;
  }