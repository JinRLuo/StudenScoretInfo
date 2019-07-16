#include <iostream>
#include <queue>
#include <cstring>
#define maxa 10000
using namespace std;

struct node{
	int x,y;
	int step;
};

int n,m;
char s[15][15];
int v[15][15];
node nd[105];
queue<node> q;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

int check(int x,int y){
	if(x<0||x>=n||y<0||y>=m||v[x][y]==1||s[x][y]=='.')
		return 0;
	return 1;
}

int bfs(node n1,node n2){
	int res=0;
	memset(v,0,sizeof(v));
	while(!q.empty()) q.pop();
	v[n1.x][n1.y]=1;
	v[n2.x][n2.y]=1;
	n1.step=0;
	n2.step=0;
	q.push(n1);
	q.push(n2);
	while(!q.empty()){
		node n3,n4;
		n3=q.front();
		q.pop();
		if(q.empty()&&n3.step!=0)
			res=n3.step;
		for(int i=0;i<4;i++){
			n4.x=n3.x+dx[i];
			n4.y=n3.y+dy[i];
			if(check(n4.x,n4.y)){
				n4.step=n3.step+1;
				v[n4.x][n4.y]=1;
				q.push(n4);
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(s[i][j]=='#'&&v[i][j]==0)
				return maxa;
		}
	}
	return res;
}

int main(){
	int T,cs=1,sum,ans,mina;
	cin>>T;
	while(T--){
		int flag=0;
		mina=maxa;
		sum=0;
		cin >> n >> m;
		for(int i=0;i<n;i++){
			cin >> s[i];
			for(int j=0;j<m;j++){
				if(s[i][j]=='#'){
					nd[sum].x=i;
					nd[sum].y=j;
					sum++;
				}
			}
		}
		for(int i=0;i<sum;i++){
			for(int j=0;j<sum;j++){
//				cout << "i: " << nd[i].x << " " << nd[i].y << endl;
//				cout << "j: " << nd[j].x << " " << nd[j].y << endl;
				ans=bfs(nd[i],nd[j]);
				flag=1;
				//cout << ans << endl;
				mina=mina>ans?ans:mina;
			}
		}
		if(mina==maxa&&flag==1)
			cout << "Case " << cs << ": " << -1 << endl;
		else{
			if(mina==maxa)
				cout << "Case " << cs << ": " << 0 << endl;
			else
				cout << "Case " << cs << ": " << mina << endl;
		}
		cs++;
	}
	
	
}
