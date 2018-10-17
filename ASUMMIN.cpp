#include <bits/stdc++.h>

using namespace std;
ifstream fin("ASUMMIN.INP");
ofstream fout("ASUMMIN.OUT");
typedef long long ll;
int n,m;
ll dem=INT_MAX;
int vt1,vt2;
ll a[100000+5];
pair <ll,ll> b[100000+5];

void in()
{
    fin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        fin>>a[i];
    }
    for(int i=1; i<=m; i++)
    {
        ll x;
        fin>>x;
        b[i].first=x;
        b[i].second=i;
    }

}
void process()
{
    sort(b+1,b+m+1);
    for(int i=1; i<=n; i++)
    {
        int l=1,r=m,mid;
        mid=(l+r)/2;
        while(l<=mid&&mid<=r)
        {
            if(a[i]+b[mid].first>=0)
            {
                if(dem>a[i]+b[mid].first)
                {
                    dem=a[i]+b[mid].first;
                    vt1=i;
                    vt2=b[mid].second;
                }
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
            mid=(l+r)/2;
        }
    }
    for(int i=1; i<=n; i++)
    {
        int l=1,r=m,mid;
        mid=(l+r)/2;
        while(l<=mid&&mid<=r)
        {
            if(a[i]+b[mid].first<=0)
            {
                if(dem>abs(a[i]+b[mid].first))
                {
                    dem=abs(a[i]+b[mid].first);
                    vt1=i;
                    vt2=b[mid].second;
                }
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
            mid=(l+r)/2;
        }
    }
    fout<<vt1<<" "<<vt2;
}
int main()
{
in();
process();
}
