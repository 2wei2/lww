#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<int> getNext(string str) {
	// 每个位置字符串的前缀与后缀最大匹配长度，不包含整串
	vector<int> next(str.size());
	next[0] = -1; //人为规定，0号位置的值是-1
	next[1] = 0;
	int i = 2; // 从2开始遍历str
	// index代表当前是哪个位置的字符，在和index+1也就是i位置比较
	int index = 0; // index既用来作为下标访问，也作为值
	while (i < next.size()) {
		// str[i-1]代表后缀开始的位置, str[index]代表前缀开始的位置
		// index保存了上一次匹配的最大长度, str[index]代表了当前前缀位置, 可以通过这个来进行加速匹配
		if (str[i - 1] == str[index]) {
			// 如果str[i-1](后缀待匹配的字符) 等于 str[index](前缀待匹配的字符) 
			// next数组i位置的值 直接等于上次最大匹配长度+1
			next[i++] = ++index;
		}
		else if (index > 0) {
			// 后缀与前缀没有匹配成功, 并且index还可以往前找 next[index]的前缀, 也就是找当前前缀的前缀开始位置
			index = next[index]; 
		}
		else{
			// index=0, 没有前缀了, 长度记为0
			next[i++] = 0;
		}
	}
	return next;
}

int getIndex(string str1, string str2) {
	vector<int> next = getNext(str2);
	int i = 0;
	int j = 0;
	while (i < str1.size() && j < str2.size()) {
		if (str1[i] == str2[j]) {
			i++;
			j++;
		}else if (next[j] == -1) {
			i++;
		}else{
			j = next[j];
		}
	}
	if (j == str2.size()) {
		return i - j;
	}
	return -1;
}

int main() {
	// 在str1中查找有没有子串str2
	string str1 = "abbcabcccc";
	string str2 = "abcabc";
	//cin >> str1 >> str2;
	int index = getIndex(str1, str2);
	cout << index;
	return 0;
}

