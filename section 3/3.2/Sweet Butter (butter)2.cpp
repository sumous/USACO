/*ID:maosong1
LANG:C++
PROB:butter
*/
/*****************************************
一直以为floyd是找出点对最短路径的最优算法
这题彻底打破了我的梦。floyd和SPFA都在第9
个数据点挂了，TLE。看了一下别人的解题报告。
才知道有链式前向星这种优化方法，不错。
关于链式前向星：http://malash.blog.163.com/blog/static/11934159720099180493847/
******************************************/
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <queue>
#define INF 2139062143
using namespace std;
struct node
{
    int end, value;
}adj[805][805];

int N, P, C, cow[505], cnt[805], d[805];
bool vis[805];
void load()
{
    cin>>N>>P>>C;
    for(int i = 0;i < N;i ++) cin>>cow[i];
    memset(cnt, 0, sizeof(cnt));
    for(int i = 0;i < C;i ++)
    {
        int a, b, w;
        cin>>a>>b>>w;
        adj[a][cnt[a]].end = b, adj[a][cnt[a]].value = w, cnt[a]++;
        adj[b][cnt[b]].end = a, adj[b][cnt[b]].value = w, cnt[b]++;
    }
}
int spfa(int s)
{
    memset(d, 127, sizeof(d));
    memset(vis, false, sizeof(vis));
    queue <int> q;
    q.push(s);
    vis[s] = true;
    d[s] = 0;
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        vis[cur] = false;
        for(int i = 0;i < cnt[cur];i ++)
        {
            int tmp = adj[cur][i].end;
            if(d[tmp] > d[cur]+adj[cur][i].value)
            {
                d[tmp] = d[cur]+adj[cur][i].value;
                if(!vis[tmp])
                {
                    q.push(tmp);
                    vis[tmp] = true;
                }
            }
        }
    }

    int sum = 0;

    for(int i = 0;i < N;i ++)
       sum += d[cow[i]];
    return sum;

}

int main()
{
    freopen("butter.in","r",stdin);
	freopen("butter.out","w",stdout);
	load();
	int min = INF;
	for(int i = 1;i <= P;i ++)
	{
        int sum = spfa(i);
        if(sum<min) min = sum;
	}
    cout<<min<<endl;
    return 0;
}
