#include<stdio.h>
#include<string.h>


void nextl(int next[],char str[]) {
	// ÿ��λ���ַ�����ǰ׺���׺���ƥ�䳤�ȣ�����������
	//vector<int> next(str.size());
	//int next[20];
	next[0] = -1; //��Ϊ�涨��0��λ�õ�ֵ��-1
	next[1] = 0;
	int i = 2; // ��2��ʼ����str
	// index����ǰ���ĸ�λ�õ��ַ����ں�index+1Ҳ����iλ�ñȽ�
	int index = 0; // index��������Ϊ�±���ʣ�Ҳ��Ϊֵ
	while (i < strlen(str) )
	{
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

	
}

int kmp(char str[],char a[]);
int main() {
	
	int i=0;
	char a[20]={"abcabcd"};
	char c[30]={"abccabcabcd"};
	printf("%d",kmp(c,a));
	
	
	return 0;
}

int kmp(char str[],char a[])
{
	long i=0;
	signed int j=0;
	int next[20];
	nextl(next,a);

	while(i<strlen(str)&&j<(signed int)strlen(a)) //����������ģ�����strlen��intתΪ�޷���������������㣬������Ҫǿ������ת��һ�� 
	{
		if(str[i]==a[j]||j==-1)
		{
			i++;
			j++;
		}
		else 
		{
			j=next[j];
		
		}
	}
	
	
	if(j>=strlen(a))
	{
		return i-j;
	}
	else
	    return 0;
	
}
