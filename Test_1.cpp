#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int lns(char *str){			//����Ϊ�����ַ���
	int length, max = 1, temp;//max����ַ�����
	int i, j;
	int a[26];				//�洢����ַ�
	length = strlen(str);
	i = 0;
	while(i < 26)
		a[i++] = 0;
	a[str[0] - 'a'] = 1;
	i = 0;
	j = 1;
	temp = 1;
	while((j < length) && (i < length - max)){
		if(a[str[j] - 'a'] == 0){     //ͷָ���βָ���Ƿ�һ��
			a[str[j] - 'a'] = 1;       
			temp++;
			if(max < temp)
				max = temp;
			j++;
		}
		else{
			a[str[i] - 'a'] = 0;      //��ʼ��ͷָ��
			i++;
			temp--;
		}
	}
	return max;						//����max
}

int main(){
	char str[1024];
	scanf("%s", str);
	printf("length of longest non-repete substring: %d\n", lns(str));
	system("pause");
	return 0;	
}