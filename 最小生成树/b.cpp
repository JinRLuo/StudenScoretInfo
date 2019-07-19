/*
ʡ��������ͨ���̡���Ŀ����ʹȫʡ�κ�������ׯ�䶼����ʵ�ֹ�·��ͨ������һ����ֱ�ӵĹ�·������ֻҪ�ܼ��ͨ����·�ɴＴ�ɣ����ֵõ������·ͳ�Ʊ������г���������������޽���·�ķ��ã��Լ��õ�·�Ƿ��Ѿ���ͨ��״̬���������д���򣬼����ȫʡ��ͨ��Ҫ����ͳɱ��� 
Input
��������������ɲ���������ÿ�����������ĵ�1�и�����ׯ��ĿN ( 1< N < 100 )������ N(N-1)/2 �ж�Ӧ��ׯ���·�ĳɱ����޽�״̬��ÿ�и�4�����������ֱ���������ׯ�ı�ţ���1��ŵ�N����������ׯ���·�ĳɱ����Լ��޽�״̬��1��ʾ�ѽ���0��ʾδ���� 

��NΪ0ʱ���������
Output
ÿ���������������ռһ�У����ȫʡ��ͨ��Ҫ����ͳɱ���
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
