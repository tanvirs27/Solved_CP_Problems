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
    ll sum,lazy;
}tree[MAX*3];

ll ara[MAX];

node merge (node A, node B)
{
    node C;
    C.sum= A.sum+ B.sum;
    C.lazy= 0;

    return C;
}

void updateNode(int idx, int st, int ed, ll value)
{
    tree[idx].sum+= value* (ed-st+1);
    tree[idx].lazy+= value;
}

void updateLazy(int idx, int st, int ed)
{
    if(st==ed)
    {
        tree[idx].lazy=0;
        return;
    }

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

void update(int idx, int st, int ed, int i, ll x)
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

void update_range(int idx, int st, int ed, int i,int j, ll x)
{
    if(i>ed || j<st)
        return;
    if(st>=i && ed<=j)
    {
        updateNode(idx,st,ed,x);
        return;
    }

    int mid= (st+ed)/2;

    if(tree[idx].lazy)
        updateLazy(idx,st,ed);

    update_range(cllft,i,j,x);
    update_range(clrght,i,j,x);

    tree[idx]=merge(tree[idx*2],tree[idx*2+1]);
}

node query(int idx, int st, int ed, int i, int j)
{
    if(i>ed || j<st)
    {
        node A;
        A.sum=A.lazy=0;
        return A;
    }
    if(i<=st && j>=ed)
        return tree[idx];

    int mid=(st+ed)/2;

    if(tree[idx].lazy)
        updateLazy(idx,st,ed);

    node a= query(cllft,i,j);
    node b= query(clrght,i,j);

    return merge(a,b);

}

int main()
{
  //  READ;

    int cas,t,n,q,a,b,i,j,k,x;
    ll v;

    sf(t);

    for(cas=1;cas<=t;cas++)
    {
        mem(ara,0);
        //mem(tree,0);
        sff(n,q);
        init(1,1,n);
        pf("Case %d:\n",cas);

        while(q--)
        {
            sf(x);

            if(x==0)
            {
                sff(a,b);
                scanf("%lld",&v);

                update_range(1,1,n,a+1,b+1,v);
            }
            else if(x==1)
            {
                sff(a,b);

                node ans=query(1,1,n,a+1,b+1);

                pf("%lld\n",ans.sum);
            }
        }
    }


    return 0;
}


