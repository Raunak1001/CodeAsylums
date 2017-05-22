
/*triskelion*/

#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef long double ld;

ll n,query,q,index_end;
ll a[100005];
ll sum[100005];


ll binary1(ll q)
{
    ll lo=0,hi=n-1,mid=0;
    while(lo<hi)
    {
        mid=lo+(hi-lo)/2;
        if(a[mid]>=q)
            hi=mid;
        else
            lo=mid+1;
    }
    if(a[lo]>=q)
        return lo;
    else
        return -1;

}

bool check(ll i)
{
    if(i>=q*(index_end-i)-sum[index_end]+sum[i])
        return true;
    else
        return false;
}

int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(0);
//cout.tie(0);
ll t;
cin>>t;
while(t--)
{
    cin>>n>>query;
    for(ll i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    /*
    for(ll i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<"\n";
    */
    for(ll i=1;i<=n;i++)
        sum[i]=sum[i-1]+a[i-1];//sum of a[0]+a[1]+...+a[i-1] is stored in sum[i] so sum[0]=0, sum[1]=a[0] etc
    /*
    for(ll i=0;i<=n;i++)
        cout<<sum[i]<<" ";
    cout<<"\n";
    */
    while(query--)
    {
        cin>>q;
        ll ans;
        index_end=binary1(q);
        if(index_end==-1)
        {
            //cout<<"index_end "<<index_end<<"\n";
            index_end=n;
            ans=0;
        }
        if(index_end==0)
        {
            index_end=0;
            ans=n;
            cout<<ans<<"\n";
            continue;
        }
        else
        {
            ans=n-index_end;
            //cout<<"index_end "<<index_end<<"\n";
            //cout<<"ans "<<ans<<"\n";
            ll lo=0,hi=index_end-1,mid=0;
            while(lo<hi)
            {
                mid=lo+((hi-lo+1)/2);
                if(check(mid)==true)
                    hi=mid-1;
                else
                    lo=mid;
            }
            //cout<<"low "<<lo<<"\n";
            if(check(lo)==false)
            {
                if(lo+1<=index_end-1)
                    ans+=index_end-(lo+1);
                else
                    ans+=0;
                cout<<ans<<"\n";
            }
            else
            {
                ans+=index_end-lo;       // since check(lo)=true so from very first index its true;
                cout<<ans<<"\n";
            }
        }
    }
}
return 0;
}