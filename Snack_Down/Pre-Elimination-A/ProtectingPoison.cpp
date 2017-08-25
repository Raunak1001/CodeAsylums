#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define lln long long int 
#define vvi vector<vector<long long int> >	
#define vi  vector<long long int>
#define INT_MAX 1000000000


bool myfun(vi a,vi b){
	return a[0]<b[0];
}



int main()
{
long long int  t;
cin >>t;
for(int q=0;q<t;q++){
	long long int  count =0;
long long int  n,k,m;
cin >>n>>k>>m;
vvi x(m,vi(3));
vvi y(m,vi(3));
for(long long int  i=0;i<m;i++){
	cin >> x[i][0];
	cin >> y[i][0];
	cin >> x[i][1];
	cin >> y[i][1];
x[i][2]=i;
y[i][2]=i;
}
sort(x.begin(),x.end(),myfun);
sort(y.begin(),y.end(),myfun);

long long int  yMaxtoGet=((n-k)/2)+1;
long long int  xMintoGet=((n-k)/2)+1;
long long int  xMaxtoGet=xMintoGet+k;
long long int  yMintoGet=yMaxtoGet-k;
long long int  ymax=-1,ymin=INT_MAX,xmin=INT_MAX,xmax=-1;

long long int  snake=-1;
for(int i=0;i<m;i++){
	if(ymin==INT_MAX){
		while(y[i][0]<=yMintoGet){
			if(y[i][1]>=ymax){
				ymax=y[i][1];
				snake=i;
			}
			i++;
			ymin=y[0][0];
    	cout <<snake<<" ";
    	}
    	count++;
	}else{
long long int  tempMax=ymax;

while(y[i][0]<=tempMax){
	if(y[i][1]>ymax){
ymax=y[i][1];
snake=i;
	}
}
cout << snake<<" ";
count++;
	}
}
if(ymin>yMintoGet){
	cout <<"-1"<<endl;
	continue;
}
if(ymax<yMaxtoGet){
cout <<-1<<endl;
continue;
}
cout <<endl;
cout<<count<<endl;


}

for(int i=0;i<m;i++){
	for(int j=0;j<2;j++){
		cout <<x[i][j]<<" ";
	}
	cout << endl;
}

}




}
