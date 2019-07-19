/*
ʡ��������ͨ���̡���Ŀ����ʹȫʡ�κ�������ׯ�䶼����ʵ�ֹ�·��ͨ������һ����ֱ�ӵĹ�·������ֻҪ�ܼ��ͨ����·�ɴＴ�ɣ������������������õ���ͳ�Ʊ����г����п��ܽ��蹫·����������·�ĳɱ����������д���򣬼����ȫʡ��ͨ��Ҫ����ͳɱ��� 
Input
��������������ɲ���������ÿ�����������ĵ�1�и��������ĵ�·���� N����ׯ��ĿM ( < 100 )������ N 
�ж�Ӧ��ׯ���·�ĳɱ���ÿ�и���һ�����������ֱ���������ׯ�ı�ţ��Լ�������ׯ���·�ĳɱ���Ҳ������������Ϊ���������ׯ��1��M��š���NΪ0ʱ��ȫ�������������Ӧ�Ľ����Ҫ����� 
Output
��ÿ��������������1�������ȫʡ��ͨ��Ҫ����ͳɱ�����ͳ�����ݲ����Ա�֤��ͨ���������?���� 
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
