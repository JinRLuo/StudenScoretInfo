#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

struct node{
	int x,y;
};

int n,m,k,x1,y1,x2,y2,flag;
char c[105][105];
int v[105][105];
int t[105][105];
queue<node> q;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

int check(int x,int y){
	if(x<1||x>m||y<1||y>n||c[x][y]=='*')
		return 0;
	return 1;
}

void bfs(){
	node n1,n2;
	int nx,ny;
	while(!q.empty()){
		n1=q.front();
		q.pop();
		if(t[n1.x][n1.y]>k)
			break;
		if(n1.x==x2&&n1.y==y2&&t[n1.x][n1.y]<=k){
			flag=1;
			return;
		}
		if(t[n1.x][n1.y]==k)
			continue;
		//n2=n1;
		for(int i=0;i<4;i++){
			n2.x=n1.x+dx[i];
			n2.y=n1.y+dy[i];
			while(check(n2.x,n2.y)){
				if(v[n2.x][n2.y]==0){
					t[n2.x][n2.y]=t[n1.x][n1.y]+1;
					v[n2.x][n2.y]=1;
					q.push(n2);
				}
				n2.x+=dx[i];
				n2.y+=dy[i];
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while(T--){
		flag=0;
		cin >> m >> n;
		while(!q.empty()) q.pop();
		for(int i=1;i<=m;i++)
			for(int j=1;j<=n;j++)
				cin >> c[i][j];
		cin >> k >> y1 >> x1 >> y2 >> x2;
		memset(v,0,sizeof(v));
		memset(t,0x3f,sizeof(t));
		node n1;
		n1.x=x1;
		n1.y=y1;
		v[x1][y1]=1;
		t[x1][y1]=-1;
		q.push(n1);
		bfs();
		
//        for(int i=1;i<=m;i++){
//           for(int j=1;j<=n;j++)
//               cout<<t[i][j]<<" ";
//           cout<<endl;
//        }
//        cout<<k<<endl;
         
		if(flag==1)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
		
	}
}
