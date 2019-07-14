#include <bits/stdc++.h>
using namespace std;

struct node{
	int h,step;
}p1,p2;

int n,a,b;
int f[205];
int v[205];
int come[205][2];
queue<node> q;

int bfs(){
	int hight;
	while(!q.empty()){
		p1=q.front();
		hight=p1.h;
		v[hight]=1;
		q.pop();
		if(hight==b)
			return p1.step;
		if(hight+f[hight]<=n){
			if(v[hight+f[hight]]==0){
				p2.h=hight+f[hight];
				p2.step=p1.step+1;
				q.push(p2);
			}
		}
		if(hight-f[hight]>0){
			if(v[hight-f[hight]]==0){
				p2.h=hight-f[hight];
				p2.step=p1.step+1;
				q.push(p2);
			}
		}
	}
	return -1;
}

int main(){
	while(cin>>n){
		memset(v,0,sizeof(v));
		if(n==0){
			break;
		}
		cin >> a >> b;
		while(!q.empty()) q.pop();
		for(int i=1;i<=n;i++)
			cin >> f[i];
		p1.h=a;
		p1.step=0;
		q.push(p1);
		cout << bfs() << endl;
	}
}
