#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<int> getNext(string str) {
	// ÿ��λ���ַ�����ǰ׺���׺���ƥ�䳤�ȣ�����������
	vector<int> next(str.size());
	next[0] = -1; //��Ϊ�涨��0��λ�õ�ֵ��-1
	next[1] = 0;
	int i = 2; // ��2��ʼ����str
	// index����ǰ���ĸ�λ�õ��ַ����ں�index+1Ҳ����iλ�ñȽ�
	int index = 0; // index��������Ϊ�±���ʣ�Ҳ��Ϊֵ
	while (i < next.size()) {
		// str[i-1]�����׺��ʼ��λ��, str[index]����ǰ׺��ʼ��λ��
		// index��������һ��ƥ�����󳤶�, str[index]�����˵�ǰǰ׺λ��, ����ͨ����������м���ƥ��
		if (str[i - 1] == str[index]) {
			// ���str[i-1](��׺��ƥ����ַ�) ���� str[index](ǰ׺��ƥ����ַ�) 
			// next����iλ�õ�ֵ ֱ�ӵ����ϴ����ƥ�䳤��+1
			next[i++] = ++index;
		}
		else if (index > 0) {
			// ��׺��ǰ׺û��ƥ��ɹ�, ����index��������ǰ�� next[index]��ǰ׺, Ҳ�����ҵ�ǰǰ׺��ǰ׺��ʼλ��
			index = next[index]; 
		}
		else{
			// index=0, û��ǰ׺��, ���ȼ�Ϊ0
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
	// ��str1�в�����û���Ӵ�str2
	string str1 = "abbcabcccc";
	string str2 = "abcabc";
	//cin >> str1 >> str2;
	int index = getIndex(str1, str2);
	cout << index;
	return 0;
}

