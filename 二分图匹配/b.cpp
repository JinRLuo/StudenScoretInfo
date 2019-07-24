#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int maxn=305;
int sc[maxn][maxn];
int use[maxn];
int st[maxn];
int P,N;

int dfs(int x){
	for(int i=1;i<=N;i++){
		if(sc[x][i]&&!use[i]){
			use[i]=1;
			if(!st[i]||dfs(st[i])){
				st[i]=x;
				return 1;
			}
		}
	}
	return 0;
}

int main(){
	//ios::sync_with_stdio(false);
	int T,count,res,std;
	scanf("%d",&T);
	while(T--){
		memset(sc,0,sizeof(sc));
		memset(st,0,sizeof(st));
		res=0;
		//cin >> P >> N;
		scanf("%d%d",&P,&N);
		for(int i=1;i<=P;i++){
			//cin >> count;
			scanf("%d",&count);
			while(count--){
				//cin>>std;
				scanf("%d",&std);
				sc[i][std]=1;
			}
		}
		for(int i=1;i<=P;i++){
			memset(use,0,sizeof(use));
			if(dfs(i))
				res++;
		}
		//cout << "res:" << res << endl;
		if(res==P){
			printf("YES\n");
			//cout << "YES" << endl;
		}else
			printf("NO\n");
			//cout << "NO" << endl;
	}
}
