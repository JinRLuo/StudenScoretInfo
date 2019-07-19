/*
省政府“畅通工程”的目标是使全省任何两个村庄间都可以实现公路交通（但不一定有直接的公路相连，只要能间接通过公路可达即可）。现得到城镇道路统计表，表中列出了任意两城镇间修建道路的费用，以及该道路是否已经修通的状态。现请你编写程序，计算出全省畅通需要的最低成本。 
Input
测试输入包含若干测试用例。每个测试用例的第1行给出村庄数目N ( 1< N < 100 )；随后的 N(N-1)/2 行对应村庄间道路的成本及修建状态，每行给4个正整数，分别是两个村庄的编号（从1编号到N），此两村庄间道路的成本，以及修建状态：1表示已建，0表示未建。 

当N为0时输入结束。
Output
每个测试用例的输出占一行，输出全省畅通需要的最低成本。
Sample Input
3
1 2 1 0
1 3 2 0
2 3 4 0
3
1 2 1 0
1 3 2 0
2 3 4 1
3
1 2 1 0
1 3 2 1
2 3 4 1
0
Sample Output
3
1
0
*/

#include <bits/stdc++.h>
using namespace std;

struct edge{
	int a,b;
	int cost;
}e[5000];

int f[105];

bool cmp(edge e1,edge e2){
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

void merge(int a,int b){
	int x1,x2;
	x1=find(a);
	x2=find(b);
	if(x1!=x2){
		f[x1]=x2;
	}
}

int main(){
	ios::sync_with_stdio(false);
	int n,d,x1,x2;
	while(cin>>n){
		int res=0;
		if(n==0)
			break;
		init(n);
		for(int i=0;i<n*(n-1)/2;i++){
			cin >> e[i].a >> e[i].b >> e[i].cost >> d;
			if(d==1){
				merge(e[i].a,e[i].b);
			}
		}
		sort(e,e+n*(n-1)/2,cmp);
		for(int i=0;i<n*(n-1)/2;i++){
			x1=find(e[i].a);
			x2=find(e[i].b);
			if(x1!=x2){
				merge(x1,x2);
				res+=e[i].cost;
			}
		}
		cout << res << endl;
	}
}
