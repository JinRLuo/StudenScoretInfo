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
	int res;
	memset(v,0,sizeof(v));
	while(!q.empty()) q.pop();
	v[n1.x][n1.y]=1;
	v[n2.x][n2.y]=1;
	n1.step=0;
	n2.step=0;
	q.push(n1);
	q.push(n2);
	node n3;
	while(!q.empty()){
		n2=q.front();
		q.pop();
		//cout << n2.x << " " << n2.y << " " << n2.step << endl;
		if(q.empty()&&n2.step!=0)
			res=n2.step;
		for(int i=0;i<4;i++){
			n3.x=n2.x+dx[i];
			n3.y=n2.y+dy[i];
			if(check(n3.x,n3.y)){
				n3.step=n2.step+1;
				v[n3.x][n3.y]=1;
				q.push(n3);
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
				//cout << ans << endl;
				mina=mina>ans?ans:mina;
			}
		}
		if(mina==maxa)
			cout << "Case " << cs << ": " << -1 << endl;
		else
			cout << "Case " << cs << ": " << mina << endl;
		cs++;
	}
	
	
}
