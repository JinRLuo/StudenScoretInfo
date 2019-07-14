#include <bits/stdc++.h>
using namespace std;

struct water{
	int cup[3];
	int step;
}w1,w2;

int a,b,c;
queue<water> q;
int v[101][101][101];

int check(water w){
	if(w.cup[0]+w.cup[1]==a&&w.cup[0]==w.cup[1])
		return 1;
	else if(w.cup[0]+w.cup[2]==a&&w.cup[0]==w.cup[2])
		return 1;
	else if(w.cup[1]+w.cup[2]==a&&w.cup[1]==w.cup[2])
		return 1;
	return 0;
}

int bfs(){
	while(!q.empty()){
		w1=q.front();
		q.pop();
		if(check(w1))
			return w1.step;
//		if(w1.step>10)
//			return -1;
		w1.step++;
		if(w1.cup[0]>0){
			w2=w1;
			if(b-w2.cup[1]>=w2.cup[0]){
				w2.cup[1]+=w2.cup[0];
				w2.cup[0]=0;
				if(v[w2.cup[0]][w2.cup[1]][w2.cup[2]]==0){
					v[w2.cup[0]][w2.cup[1]][w2.cup[2]]=1;
					q.push(w2);
				}
			}else{
				w2.cup[0]-=b-w2.cup[1];
				w2.cup[1]=b;
				if(v[w2.cup[0]][w2.cup[1]][w2.cup[2]]==0){
					v[w2.cup[0]][w2.cup[1]][w2.cup[2]]=1;
					q.push(w2);
				}
			}
			w2=w1;
			if(c-w2.cup[2]>=w2.cup[0]){
				w2.cup[2]+=w2.cup[0];
				w2.cup[0]=0;
				if(v[w2.cup[0]][w2.cup[1]][w2.cup[2]]==0){
					v[w2.cup[0]][w2.cup[1]][w2.cup[2]]=1;
					q.push(w2);
				}
			}else{
				w2.cup[0]-=c-w2.cup[2];
				w2.cup[2]=c;
				if(v[w2.cup[0]][w2.cup[1]][w2.cup[2]]==0){
					v[w2.cup[0]][w2.cup[1]][w2.cup[2]]=1;
					q.push(w2);
				}
			}
		}
		if(w1.cup[1]>0){
			w2=w1;
			if(a-w2.cup[0]>=w2.cup[1]){
				w2.cup[0]+=w2.cup[1];
				w2.cup[1]=0;
				if(v[w2.cup[0]][w2.cup[1]][w2.cup[2]]==0){
					v[w2.cup[0]][w2.cup[1]][w2.cup[2]]=1;
					q.push(w2);
				}
			}else{
				w2.cup[1]-=a-w2.cup[0];
				w2.cup[0]=a;
				if(v[w2.cup[0]][w2.cup[1]][w2.cup[2]]==0){
					v[w2.cup[0]][w2.cup[1]][w2.cup[2]]=1;
					q.push(w2);
				}
			}
			w2=w1;
			if(c-w2.cup[2]>=w2.cup[1]){
				w2.cup[2]+=w2.cup[1];
				w2.cup[1]=0;
				if(v[w2.cup[0]][w2.cup[1]][w2.cup[2]]==0){
					v[w2.cup[0]][w2.cup[1]][w2.cup[2]]=1;
					q.push(w2);
				}
			}else{
				w2.cup[1]-=c-w2.cup[2];
				w2.cup[2]=c;
				if(v[w2.cup[0]][w2.cup[1]][w2.cup[2]]==0){
					v[w2.cup[0]][w2.cup[1]][w2.cup[2]]=1;
					q.push(w2);
				}
			}
		}
		if(w1.cup[2]>0){
			w2=w1;
			if(a-w2.cup[0]>=w2.cup[2]){
				w2.cup[0]+=w2.cup[2];
				w2.cup[2]=0;
				if(v[w2.cup[0]][w2.cup[1]][w2.cup[2]]==0){
					v[w2.cup[0]][w2.cup[1]][w2.cup[2]]=1;
					q.push(w2);
				}
			}else{
				w2.cup[2]-=a-w2.cup[0];
				w2.cup[0]=a;
				if(v[w2.cup[0]][w2.cup[1]][w2.cup[2]]==0){
					v[w2.cup[0]][w2.cup[1]][w2.cup[2]]=1;
					q.push(w2);
				}
			}
			w2=w1;
			if(b-w2.cup[1]>=w2.cup[2]){
				w2.cup[1]+=w2.cup[2];
				w2.cup[2]=0;
				if(v[w2.cup[0]][w2.cup[1]][w2.cup[2]]==0){
					v[w2.cup[0]][w2.cup[1]][w2.cup[2]]=1;
					q.push(w2);
				}
			}else{
				w2.cup[2]-=b-w2.cup[1];
				w2.cup[1]=b;
				if(v[w2.cup[0]][w2.cup[1]][w2.cup[2]]==0){
					v[w2.cup[0]][w2.cup[1]][w2.cup[2]]=1;
					q.push(w2);
				}
			}
		}
		
	}
	return -1;
}

int main(){
	int ans;
	while(cin>>a>>b>>c){
		while(!q.empty()) q.pop();
		if(a==0&&b==0&&c==0)
			break;
		memset(v,0,sizeof(v));
		w1.cup[0]=a;
		w1.cup[1]=0;
		w1.cup[2]=0;
		w1.step=0;
		q.push(w1);
		v[a][0][0]==1;
		ans=bfs();
		//cout << "ans:" << ans << endl;
		if(ans==-1)
			cout << "NO" << endl;
		else 
			cout << ans << endl;
		
	}
}
