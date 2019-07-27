/*
hdu 1251

Ignatius最近遇到一个难题 , 老师交给他很多单词 ( 只有小写字母组成 , 不会有重复的单词出现 ),现在老师要他统计出以某个字符串为前缀的单词数量( 单词本身也是自己的前缀 ).
Input
输入数据的第一部分是一张单词表 , 每行一个单词 , 单词的长度不超过10 , 它们代表的是老师交给Ignatius统计的单词 ,一个空行代表单词表的结束.第二部分是一连串的提问, 每行一个提问 , 每个提问都是一个字符串 . 

注意 : 本题只有一组测试数据 , 处理到文件结束 .

Output
对于每个提问 , 给出以该字符串为前缀的单词的数量 .

Sample Input
	
banana 
band 
bee 
absolute
acm

ba 
b 
band
abc

Sample Output

2 
3 
1 
0
*/
#include <string>
#include <iostream>
using namespace std;

struct node{
	int a;
	node *next[27];
	bool isword;
}*root;

void insert(string s){
	node *tmp=root;
	for(int i=0;i<s.length();i++){
		int p=s[i]-'a'+1;
		if(tmp->next[p]==NULL){
			tmp->next[p]=new node();
		}
		tmp=tmp->next[p];
		tmp->a++;
		if(i==s.length()-1)
			tmp->isword=true;
	}
}

int stat(string s){
	node *tmp=root;
	for(int i=0;i<s.length();i++){
		int a=s[i]-'a'+1;
		if(tmp->next[a]==NULL){
			return 0;
		}
		tmp=tmp->next[a];
	}
	return tmp->a;
}

int main(){
	string s;
	root=new node();
	while(1){
		getline(cin,s);
		//cout << "s:" << s << endl;
		if(s=="")
			break;
		insert(s);
	}
	while(getline(cin,s)){
		if(s=="")
			break;
		cout << stat(s) << endl;
	}
}
