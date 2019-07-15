#include <iostream>
#include <string>
#include <queue>
using namespace std;

struct node{
	int x,y,z;
	int step;
};

int l,r,c,ls,rs,cs,le,re,ce;
char s[35][35][35];
queue<node> q;
int dx[6]={1,-1,0,0,0,0};
int dy[6]={0,0,1,-1,0,0};
int dz[6]={0,0,0,0,1,-1};

int check(int x,int y,int z){
	if(x<0||x>=l||y<0||y>=r||z<0||z>=c||s[x][y][z]=='#')
		return 0;
	return 1;
}

int bfs(){
	node n1,n2;
	while(!q.empty()){
		n1=q.front();
		q.pop();
		if(n1.x==le&&n1.y==re&&n1.z==ce){
			return n1.step;
		}
		for(int i=0;i<6;i++){
			n2.x=n1.x+dx[i];
			n2.y=n1.y+dy[i];
			n2.z=n1.z+dz[i];
			if(check(n2.x,n2.y,n2.z)){
				n2.step=n1.step+1;
				s[n2.x][n2.y][n2.z]='#';
				q.push(n2);
			}
		}
	}
	return -1;
}

int main(){
	int pos,ans;
	while(cin>>l>>r>>c){
		if(l==0&&r==0&&c==0)
			break;
		while(!q.empty()) q.pop();
		for(int i=0;i<l;i++){
			for(int j=0;j<r;j++){
				for(int k=0;k<c;k++){
					cin >> s[i][j][k];
					if(s[i][j][k]=='S'){
						ls=i;
						rs=j;
						cs=k;
					}
					if(s[i][j][k]=='E'){
						le=i;
						re=j;
						ce=k;
					}
				}

			}
		}
		node n1;
		n1.x=ls;
		n1.y=rs;
		n1.z=cs;
		s[ls][rs][cs]='#';
		q.push(n1);
		ans = bfs();
		if(ans==-1)
			cout << "Trapped!" << endl;
		else
			cout << "Escaped in " <<ans << " minute(s)." << endl;
	}
}
