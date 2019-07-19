/*
某省调查乡村交通状况，得到的统计表中列出了任意两村庄间的距离。省政府“畅通工程”的目标是使全省任何两个村庄间都可以实现公路交通（但不一定有直接的公路相连，只要能间接通过公路可达即可），并要求铺设的公路总长度为最小。请计算最小的公路总长度。 
Input
测试输入包含若干测试用例。每个测试用例的第1行给出村庄数目N ( < 100 )；随后的N(N-1)/2行对应村庄间的距离，每行给出一对正整数，分别是两个村庄的编号，以及此两村庄间的距离。为简单起见，村庄从1到N编号。 
当N为0时，输入结束，该用例不被处理。 
Output
对每个测试用例，在1行里输出最小的公路总长度。 
Sample Input
3
1 2 1
1 3 2
2 3 4
4
1 2 1
1 3 4
1 4 1
2 3 3
2 4 2
3 4 5
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
	int n,x1,x2;
	while(cin>>n){
		int res=0;
		if(n==0)
			break;
		init(n);
		for(int i=0;i<n*(n-1)/2;i++){
			cin >> e[i].a >> e[i].b >> e[i].cost;
		}
		sort(e,e+n*(n-1)/2,cmp);
		for(int i=0;i<n*(n-1)/2;i++){
			x1=find(e[i].a);
			x2=find(e[i].b);
			if(x1!=x2){
				f[x1]=x2;
				res+=e[i].cost;
			}
		}
		cout << res << endl;
	}
}
