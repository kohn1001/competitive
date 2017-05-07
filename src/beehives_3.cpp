#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define N 510
#define M 20100
using namespace std;

int n,m;
struct Edge{
	int v,next;
}edge[M*2];
int head[N],cnt;

void init(){
	memset(head,-1,sizeof(head));
	cnt=0;
}

void addedge(int u,int v){
	edge[cnt].v=v;
	edge[cnt].next=head[u];
	head[u]=cnt++;
}

int ok[N],d[N],ans,pre[N];

/*void dfs(int u,int fa){
	if(fa!=-1) d[u]=d[fa]+1;
	else d[u]=0;
	ok[u]=1;
	for(int i=head[u];i!=-1;i=edge[i].next){
		int v=edge[i].v;
		if(v==fa)continue;
		if(!ok[v])dfs(v,u);
		else if(v==uu) ans=min(ans,d[u]+d[v]+1);
	}
}
*/

void bfs(int u){
	queue<int>q;
	q.push(u);
	d[u]=0;
	ok[u]=1;
	pre[u]=-1;
	//memset(pre,-1,sizeof(pre));
	while(!q.empty()){
		int v=q.front();
		q.pop();
		for(int i=head[v];i!=-1;i=edge[i].next){
			int vv=edge[i].v;
			if(pre[v]==vv) continue;
			if(!ok[vv]){
				if(d[v]+1+1>=ans)continue;
				ok[vv]=1;
				d[vv]=d[v]+1;
				pre[vv]=v;
				q.push(vv);
			}
			else ans=min(ans,d[vv]+d[v]+1);
		}
	}
}
int main(){
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++){
		init();
		scanf("%d %d",&n,&m);
		for(int i=1;i<=m;i++){
			int u,v;
			scanf("%d %d",&u,&v);
			addedge(u,v),addedge(v,u);
		}
		ans=1000;
		for(int i=0;i<n;i++){
			memset(ok,0,sizeof(ok));
			bfs(i);
		}
		if(ans==1000) printf("Case %d: impossible\n",t);
		else printf("Case %d: %d\n",t,ans);
	}
    return 0;
}
