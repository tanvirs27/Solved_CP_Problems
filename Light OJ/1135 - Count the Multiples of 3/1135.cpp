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
#define FRA(i,a,b) for(int i=a; i<b; i++)
#define FRAE(i,a,b) for(int i=a; i<=b; i++)
#define FRD(i,a,b) for(int i=a; i>b; i--)
#define FRDE(i,a,b) for(int i=a; i>=b; i--)
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
    int one,two,three,lazy;
}tree[MAX*3];

int ara[MAX];

node merge (node A, node B)
{
    node C;
    C.one= A.one+ B.one;
    C.two= A.two+ B.two;
    C.three= A.three+ B.three;
    C.lazy= 0;

    return C;
}

void updateNode(int idx, int st, int ed, int value)
{
    if(value==1)
    {
        int temp=tree[idx].one;
        tree[idx].one=tree[idx].three;
        tree[idx].three=tree[idx].two;
        tree[idx].two= temp;

    }
    else if(value==2)
    {
        int temp=tree[idx].one;
        tree[idx].one=tree[idx].two;
        tree[idx].two=tree[idx].three;
        tree[idx].three= temp;
    }

    tree[idx].lazy=(tree[idx].lazy+ value)%3;
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

void update_range(int idx, int st, int ed, int i,int j, int x)
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
        A.one=A.two=A.three=A.lazy=0;
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

void init(int idx, int st, int ed)
{
    if(st==ed)
    {
        tree[idx].three=1;
        tree[idx].two=0;
        tree[idx].one=0;
        tree[idx].lazy=0;
        return;
    }

    int mid= (st+ed)/2;

    init(cllft);
    init(clrght);

    tree[idx]=merge(tree[idx*2],tree[idx*2+1]);

}


int main()
{
  // READ;

   int t,n,q,j,a,b,x;
   node A;

   sf(t);

   FRAE(cas,1,t)
   {
       sff(n,q);

       //mem(tree,0);
       init(1,1,n);
       pf("Case %d:\n",cas);

       FRA(i,0,q)
       {
           sf(x);

           if(x==0)
           {
               sff(a,b);

               update_range(1,1,n,a+1,b+1,1);
           }
           else
           {
               sff(a,b);

               A=query(1,1,n,a+1,b+1);

               pf("%d\n",A.three);
           }
       }
   }


   return 0;
}


