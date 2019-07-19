/*
省政府“畅通工程”的目标是使全省任何两个村庄间都可以实现公路交通（但不一定有直接的公路相连，只要能间接通过公路可达即可）。经过调查评估，得到的统计表中列出了有可能建设公路的若干条道路的成本。现请你编写程序，计算出全省畅通需要的最低成本。 
Input
测试输入包含若干测试用例。每个测试用例的第1行给出评估的道路条数 N、村庄数目M ( < 100 )；随后的 N 
行对应村庄间道路的成本，每行给出一对正整数，分别是两个村庄的编号，以及此两村庄间道路的成本（也是正整数）。为简单起见，村庄从1到M编号。当N为0时，全部输入结束，相应的结果不要输出。 
Output
对每个测试用例，在1行里输出全省畅通需要的最低成本。若统计数据不足以保证畅通，则输出“?”。 
Sample Input
3 3
1 2 1
1 3 2
2 3 4
1 3
2 3 2
0 100
Sample Output
3
?
*/

#include <bits/stdc++.h>
using namespace std;

struct edge{
	int a,b;
	int cost;
}e[105];

int f[105];
int cmp(edge e1,edge e2){
	return e1.cost<e2.cost;
}

void init(int n){
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
}

int find(int a){
	if(f[a]!=a){
		f[a]=find(f[a]);
		return f[a];
	}
	return a;
}

int main(){
	int n,m;
	int x1,x2;
	while(cin >> n >> m){
		int res=0,flag=0;
		memset(f,0,sizeof(f));
		if(n==0)
			break;
		init(m);
		//cin >> m;
		for(int i=1;i<=n;i++){
			cin >> e[i].a >> e[i].b >> e[i].cost;
		}
		sort(e+1,e+1+n,cmp);
		for(int i=1;i<=n;i++){
			x1=find(e[i].a);
			x2=find(e[i].b);
			if(x1!=x2){
				res+=e[i].cost;
				f[x1]=x2;
			}
		}
		for(int i=1;i<=m;i++){
			if(f[i]==i){
				flag++;
			}
		}
		if(flag==1)
			cout << res << endl;
		else
			cout << "?" << endl;
	}
}
