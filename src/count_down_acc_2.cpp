#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXN 710
#define MAXM 60010
#define MOD 1000000007
#define INF 1000000007
#define FI first
#define SE second
struct node
{
    int a,b,c;
    long long d;
    void init(int aa,int bb,int cc,long long dd)
    {
        a=aa,b=bb,c=cc,d=dd;
    }
};
const char ope[10]="+-*/";
int tar,top;
long long best,num[10];
node state[10];
node ans[10];
void upd(int h,long long now)
{
    for(int i=0;i<h;++i)
        ans[i]=state[i];
    best=now;
    top=h;
}
void print()
{
    printf("Target: %d\n",tar);
    for(int i=0;i<top;++i)
    {
        printf("%d %c %d = %lld\n",ans[i].a,ope[ans[i].b],ans[i].c,ans[i].d);
    }
    printf("Best approx: ");
    cout<<best<<"\n\n";
}
bool dfs(int h,long long arr[])
{
    for(int i=0;i<h;++i)
    {
        if(arr[i]==tar)
        {
            upd(6-h,arr[i]);
            return true;
        }
        else    if(abs(best-tar)>abs(tar-arr[i]))
            upd(6-h,arr[i]);
    }
    if(h==1)    return false;
    long long tmp[6];
    bool res=0;
    for(int i=0;i<h&&!res;++i)
        for(int j=0;j<h&&!res;++j)
            if(i!=j&&(j==0||arr[j]!=arr[j-1]))
                for(int k=0;k<4&&!res;++k)
                {
                    for(int l=0,cnt=0;l<h;++l)
                        if(l!=i&&l!=j)  tmp[cnt++]=arr[l];
                    if(k==0)
                        tmp[h-2]=arr[i]+arr[j],state[6-h].init(arr[i],k,arr[j],tmp[h-2]),res=dfs(h-1,tmp);
                    if(!res&&k==1&&arr[i]>arr[j])
                        tmp[h-2]=arr[i]-arr[j],state[6-h].init(arr[i],k,arr[j],tmp[h-2]),res=dfs(h-1,tmp);
                    if(!res&&k==2)
                        tmp[h-2]=arr[i]*arr[j],state[6-h].init(arr[i],k,arr[j],tmp[h-2]),res=dfs(h-1,tmp);
                    if(!res&&k==3&&(arr[i]%arr[j]==0))
                        tmp[h-2]=arr[i]/arr[j],state[6-h].init(arr[i],k,arr[j],tmp[h-2]),res=dfs(h-1,tmp);

                }
    return res;
}
int main()
{
    int ncase;
    scanf("%d",&ncase);
    for(int hh=1;hh<=ncase;++hh)
    {
        for(int i=0;i<6;++i)    scanf("%lld",&num[i]);
        scanf("%d",&tar);
        best=INF;
        sort(num,num+6);
        dfs(6,num);
        print();
    }
    return 0;
}



