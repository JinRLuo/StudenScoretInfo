#include <iostream>
#include <queue>
#include <stack>
using namespace std;
struct node{
	int x,y;
	int prex,prey;
}n[5][5];

int c[5][5];
//int v[5][5];
queue<node> q;
stack<node> s;

int check(int x,int y){
	if(c[x][y]==1||x>=5||x<0||y>=5||y<0)
		return 0;
	else
		return 1;
}

node bfs(){
	while(!q.empty()){
		int x,y;
		node n1;
		n1=q.front();
		q.pop();
		if(n1.x==4&&n1.y==4){
			return n1;
		}
		x=n1.x+1;
		y=n1.y;
		if(check(x,y)){
			n[x][y].x=x;
			n[x][y].y=y;
			n[x][y].prex=n1.x;
			n[x][y].prey=n1.y;
			c[x][y]=1;
			q.push(n[x][y]);
		}
		x=n1.x-1;
		y=n1.y;
		if(check(x,y)){
			n[x][y].x=x;
			n[x][y].y=y;
			n[x][y].prex=n1.x;
			n[x][y].prey=n1.y;
			c[x][y]=1;
			q.push(n[x][y]);
		}
		x=n1.x;
		y=n1.y+1;
		if(check(x,y)){
			n[x][y].x=x;
			n[x][y].y=y;
			n[x][y].prex=n1.x;
			n[x][y].prey=n1.y;
			c[x][y]=1;
			q.push(n[x][y]);
		}
		x=n1.x;
		y=n1.y-1;
		if(check(x,y)){
			n[x][y].x=x;
			n[x][y].y=y;
			n[x][y].prex=n1.x;
			n[x][y].prey=n1.y;
			c[x][y]=1;
			q.push(n[x][y]);
		}
	}
}

int main(){
	int x,y;
	node n1;
	for(int i=0;i<5;i++)
		for(int j=0;j<5;j++)
			cin >> c[i][j];
	n[0][0].x=0;
	n[0][0].y=0;
	n[0][0].prex=-1;
	n[0][0].prey=-1;
	q.push(n[0][0]);
	c[0][0]=1;
	n1 = bfs();
	while(x!=-1&&y!=-1){
		//cout << x << " " << y << endl;
		s.push(n1);
		x=n1.prex;
		y=n1.prey;
		n1=n[x][y];
	}
	while(!s.empty()){
		n1=s.top();
		cout << "(" << n1.x << ", " << n1.y << ")" << endl;
		s.pop();
	}
}
