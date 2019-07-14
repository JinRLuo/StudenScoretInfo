#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

struct node{
	int x,y;
};

int n,m,k,x1,y1,x2,y2,flag;
char c[15][15];
int v[15][15];
int t[15][15];
queue<node> q;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

int check(int x,int y){
	if(x<1||x>n||y<1||y>m||v[x][y]==1||c[x][y]=='*')
		return 0;
	return 1;
}

void bfs(){
	node n1,n2;
	int nx,ny;
	while(!q.empty()){
		//cout << 1 << endl;
		n1=q.front();
		q.pop();
		nx=n1.x;
		ny=n1.y;
		if(t[nx][ny]>k)
			break;
		if(nx==x2&&ny==y2&&t[nx][ny]<=k){
			flag=1;
			return;
		}
		for(int i=0;i<4;i++){
			nx+=dx[i];
			ny+=dy[i];
			while(check(nx,ny)){
				t[nx][ny]=t[n1.x][n1.y]+1;
				n2.x=nx;
				n2.y=ny;
				v[nx][ny]=1;
				q.push(n2);
				nx+=dx[i];
				ny+=dy[i];
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
		for(int i=1;i<=m;i++)
			for(int j=1;j<=n;j++)
				cin >> c[i][j];
		cin >> k >> x1 >> y1 >> x2 >> y2;
		memset(v,0,sizeof(v));
		memset(t,0x3f,sizeof(t));
		node n1;
		n1.x=x1;
		n1.y=y1;
		v[x1][y1]=1;
		t[x1][y1]=-1;
		q.push(n1);
		bfs();
		
        for(int i=1;i<=m;i++){
           for(int j=1;j<=n;j++)
               cout<<t[i][j]<<" ";
           cout<<endl;
        }
        cout<<k<<endl;
         
		if(flag==1)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
		
	}
}
