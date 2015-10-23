#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>
using namespace std;

#define ll long long int
#define db double
#define mem(a,b) memset((a),b,sizeof(a))
#define READ freopen("c:\\Users\\Rifat\\Desktop\\in.txt", "r", stdin)
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d%d", &a, &b)
#define sfff(a,b,c) scanf("%d%d%d", &a, &b, &c)
#define pf printf
#define gc getchar()
#define DBG(a) printf("in %d\n",a)
#define all(V) V.begin(),V.end()
#define max(a,b) (a>b) ? (a):(b)
#define min(a,b) (a<b) ? (a):(b)
#define inf         ((1 << 30) - 1)
#define eps         1e-9
#define cllft 2*idx,st,mid
#define clrght 2*idx+1,mid+1,ed
#define MOD         100007
#define MAX         100005

struct node
{
    int sum,lazy;
}tree[MAX*3];

int ara[MAX];

node merge (node A, node B)
{
    node C;
    C.sum= A.sum+ B.sum;
    C.lazy=0;

    return C;
}

void updateNode(int idx, int st, int ed, int value)
{
    tree[idx].sum+= value;
    tree[idx].lazy= 0;
}

void updateLazy(int idx, int st, int ed)
{
    int mid= (st+ed)/2;
    updateNode(cllft,tree[idx].lazy);
    updateNode(clrght,tree[idx].lazy);
    tree[idx].lazy=0;
}

void init(int idx, int st, int ed)
{
    if(st==ed)
    {
        tree[idx].sum=ara[st];
        tree[idx].lazy=0;
        return;
    }

    int mid= (st+ed)/2;

    init(cllft);
    init(clrght);

    tree[idx]=merge(tree[idx*2],tree[idx*2+1]);

}

void update(int idx, int st, int ed, int i, int x)
{
    if(i>ed || i<st)
        return;
    if(st==i && ed==i)
    {
        updateNode(idx,st,ed,x);
        return;
    }

    int mid= (st+ed)/2;

    update(cllft,i,x);
    update(clrght,i,x);

    tree[idx]=merge(tree[idx*2],tree[idx*2+1]);
}

int query(int idx, int st, int ed, int i, int j)
{
    if(i>ed || j<st)
        return 0;
    if(i<=st && j>=ed)
        return tree[idx].sum;

    int mid=(st+ed)/2;

    if(tree[idx].lazy)
        updateLazy(idx,st,ed);

    int a= query(cllft,i,j);
    int b= query(clrght,i,j);

    return a+b;

}

int main()
{
   // READ;

    int cas,t,n,q,i,j,k,ans,a,b;

    sf(t);

    for(cas=1;cas<=t;cas++)
    {
        sff(n,q);

        for(i=1;i<=n;i++)
        {
            sf(ara[i]);
        }

        init(1,1,n);

        pf("Case %d:\n",cas);

        for(j=1;j<=q;j++)
        {
            sf(a);

            if(a==1)
            {
                sf(i);
                ans=query(1,1,n,i+1,i+1);
                update(1,1,n,i+1,-ans);
                pf("%d\n",ans);
            }
            else if(a==2)
            {
                sff(i,b);
                update(1,1,n,i+1,b);
            }
            else if(a==3)
            {
                sff(i,k);
                ans=query(1,1,n,i+1,k+1);

                pf("%d\n",ans);
            }

        }
    }

    return 0;
}




