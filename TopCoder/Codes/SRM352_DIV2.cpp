#include<iostream>
#include<vector>
using namespace std;
#define  vvi vector<vector<int> > 
	class NumberofFiboCalls{

public: 
		vector<int> fiboCallsMade(int n){
			vvi v(n+1,vector<int>(2,0));
			v[0][0]=1;
			v[1][1]=1;
			for(int i=2;i<=n;i++)
{
	v[i][0]=v[i-1][0]+v[i-2][0];
    v[i][1]=v[i-1][1]+v[i-2][1];

}

std::vector<int> ans;
ans.push_back(v[n][0]);
ans.push_back(v[n][1]);
return ans;
		}


	};


	int main()
	{

NumberofFiboCalls ob;
std::vector<int>  a=ob.fiboCallsMade(3);
cout << a[0]<<" "<<a[1]<<endl;
return 0;
	}