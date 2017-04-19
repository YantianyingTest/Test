#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int lns(char *str){			//参数为输入字符串
	int length, max = 1, temp;//max最大字符长度
	int i, j;
	int a[26];				//存储最大字符
	length = strlen(str);
	i = 0;
	while(i < 26)
		a[i++] = 0;
	a[str[0] - 'a'] = 1;
	i = 0;
	j = 1;
	temp = 1;
	while((j < length) && (i < length - max)){
		if(a[str[j] - 'a'] == 0){     //头指针跟尾指针是否一样
			a[str[j] - 'a'] = 1;       
			temp++;
			if(max < temp)
				max = temp;
			j++;
		}
		else{
			a[str[i] - 'a'] = 0;      //初始化头指针
			i++;
			temp--;
		}
	}
	return max;						//返回max
}

int main(){
	char str[1024];
	scanf("%s", str);
	printf("length of longest non-repete substring: %d\n", lns(str));
	system("pause");
	return 0;	
}