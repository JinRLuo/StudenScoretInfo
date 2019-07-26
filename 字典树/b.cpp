/*
hdu 1075

Problem Description
Ignatius is so lucky that he met a Martian yesterday. But he didn't know the language the Martians use. The Martian gives him a history book of Mars and a dictionary when it leaves. Now Ignatius want to translate the history book into English. Can you help him?
 

Input
The problem has only one test case, the test case consists of two parts, the dictionary part and the book part. The dictionary part starts with a single line contains a string "START", this string should be ignored, then some lines follow, each line contains two strings, the first one is a word in English, the second one is the corresponding word in Martian's language. A line with a single string "END" indicates the end of the directory part, and this string should be ignored. The book part starts with a single line contains a string "START", this string should be ignored, then an article written in Martian's language. You should translate the article into English with the dictionary. If you find the word in the dictionary you should translate it and write the new word into your translation, if you can't find the word in the dictionary you do not have to translate it, and just copy the old word to your translation. Space(' '), tab('\t'), enter('\n') and all the punctuation should not be translated. A line with a single string "END" indicates the end of the book part, and that's also the end of the input. All the words are in the lowercase, and each word will contain at most 10 characters, and each line will contain at most 3000 characters.
 

Output
In this problem, you have to output the translation of the history book.
 

Sample Input
START
from fiwo
hello difh
mars riwosf
earth fnnvk
like fiiwj
END
START
difh, i'm fiwo riwosf.
i fiiwj fnnvk!
END
 

Sample Output
hello, i'm from mars.
i like earth!
*/

#include <iostream>
#include <string>
using namespace std;

struct node{
	node *next[27];
	string word;
}*root;

void insert(string s,string w){
	node *tmp=root;
	for(int i=0;i<s.length();i++){
		int p=s[i]-'a'+1;
		if(tmp->next[p]==NULL){
			tmp->next[p]=new node();
		}
		tmp=tmp->next[p];
		if(i==s.length()-1)
			tmp->word=w;
	}
}

string trans(string s){
	node* tmp=root;
	for(int i=0;i<s.length();i++){
		int p=s[i]-'a'+1;
		if(tmp->next[p]==NULL){
			return "";
		}
		tmp=tmp->next[p];
	}
	return tmp->word;
}

int main(){
	root=new node();
	string s1,s2;
	int begin,len;
	while(cin>>s1){
		if(s1=="START")
			continue;
		else if(s1=="END")
			break;
		cin>>s2;
		insert(s2,s1);
	}
	getchar();
	while(getline(cin,s1)){
		if(s1=="START")
			continue;
		else if(s1=="END")
			break;
		begin=0;
		len=0;
		for(int i=0;i<s1.length();i++){
			if(s1[i]>='a'&&s1[i]<='z'){
				len++;
			}else{
				s2=trans(s1.substr(begin,len));
				if(s2==""){
					cout << s1.substr(begin,len);
				}else
					cout << s2;
				cout << s1[i];
				begin=i+1;
				len=0;
			}
		}
		cout << endl;
	}
}
