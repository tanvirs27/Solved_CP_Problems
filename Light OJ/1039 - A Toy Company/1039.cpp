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
#define all(V) V.begin(),V.end()
#define max(a,b) (a>b) ? (a):(b)
#define min(a,b) (a<b) ? (a):(b)
#define inf         ((1 << 30) - 1))
#define eps         1e-9
#define MOD         100007
#define MAX         100000

map <string,int> mp;
map <string,int> visited;
queue <string> Q;
int level[MAX];
int fx[6]={1,-1,0,0,0,0};
int fy[6]={0,0,1,-1,0,0};
int fz[6]={0,0,0,0,1,-1};

char circle(char ch)
{
    if(ch=='a'-1)
    {
   //     pf("yes\n");
        return 'z';
    }

    if(ch=='z'+1)
    {
   //     pf("yes\n");
        return 'a';
    }


    return ch;
}

int bfs(char S[5],char F[5])
{
    if(mp[S]!=0 || mp[F]!=0)
        return -1;
    if(strcmp(S,F)==0)
        return 0;

    int ind=1,i;
    string u,temp,finish;
    visited.clear();
    mem(level,0);
    finish=F;

    visited[S]=ind++;
    level[ind-1]=0;
    Q.push(S);

    while(!Q.empty())
    {
        u= Q.front();
        temp=u;

        for(i=0;i<6;i++)
        {
            temp[0]=u[0]+fx[i];
            temp[0]=circle(temp[0]);
            temp[1]=u[1]+fy[i];
            temp[1]=circle(temp[1]);
            temp[2]=u[2]+fz[i];
            temp[2]=circle(temp[2]);
            temp[3]=0;


            if(mp[temp]==0 && visited[temp]==0)
            {
                visited[temp]=ind++;

                level[ind-1]=level[visited[u]]+1;

          //      cout << temp << " "<< visited[temp] << " "<< level[ind-1] <<endl;

                if(temp==finish)
                    return level[ind-1];

                Q.push(temp);
            }
        }
        Q.pop();


    }
    return -1;

}

void clear_all()
{
    mp.clear();

    while(!Q.empty())
        Q.pop();
}

int main()
{
    READ;
   // freopen("out.txt","w",stdout);

    int t,cas,i,j,k,ind,n;
    char S[5],F[5],X[30],Y[30],Z[30],dummy[5];

    sf(t);

    for(cas=1;cas<=t;cas++)
    {
        gc;
        gc;

        ind=1;

        scanf("%s%s%d",S,F,&n);

   //     pf("%s %s\n",S,F);

        while(n--)
        {
            scanf("%s%s%s",X,Y,Z);

            for(i=0;i<strlen(X);i++)
            {
                for(j=0;j<strlen(Y);j++)
                {
                    for(k=0;k<strlen(Z);k++)
                    {
                        dummy[0]=X[i];
                        dummy[1]=Y[j];
                        dummy[2]=Z[k];
                        dummy[3]=0;

                        if(mp[dummy]==0)
                            mp[dummy]=ind++;

     //                   puts(dummy);
       //                 pf("%d\n",mp[dummy]);
                    }
                }
            }
        }

        int ans=bfs(S,F);


        pf("Case %d: %d\n",cas,ans);

        clear_all();
    }

    return 0;
}

