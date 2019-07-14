#include <iostream>
#include <map>
#include <queue> 
#include <cstring>
using namespace std;

struct node{
	int l,time;
}p1;

int n,k;
int m[100050];
queue<node> q;

int bound(int i){
	if(i<0||i>100000||m[i])
		return 0;
	else
		return 1;
}

int bfs(){
	p1.l=n;
	p1.time=0;
	m[n]=1;
	q.push(p1);
	while(!q.empty()){
		node p2;
		p1=q.front();
		q.pop();
		if(p1.l==k)
			return p1.time;
		p2.time=p1.time+1;
		p2.l=p1.l+1;
		if(bound(p2.l)){
			m[p2.l]=1;
			q.push(p2); 
		}
		p2.l=p1.l-1;
		if(bound(p2.l)){
			m[p2.l]=1;
			q.push(p2);
		}
		p2.l=p1.l*2;
		if(bound(p2.l)){
			m[p2.l]=1;
			q.push(p2);
		}
	}
	return -1;
}

int main(){
	cin >> n >> k;
	while(!q.empty()) q.pop();
	memset(m,0,sizeof(m));
	cout << bfs() << endl;
	return 0;
}
