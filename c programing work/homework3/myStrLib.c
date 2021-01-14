#include<stdio.h>
#include"myStrLib.h"
unsigned int my_strlen(const char *str){
    if (str == NULL){
		return 0;
	}
	unsigned int len = 0;
	while (*str != '\0') {
		len++;
		str++;
	}
	return len;
}
char * my_strcpy( char *dest, const char *src){
    if (dest == NULL || src == NULL){
		return NULL;
	}
	char* p = dest;
	while (*src != '\0'){
		*p = *src;
		p++;
		src++;
	}
	*p = '\0';
	return dest;
}
int my_strcmp(const char * str1, const char * str2){
	while(*str1==*str2)
	{
		if(*str1=='\0')
			return 0;
	
			str1++;
			str2++;
	
	}
	if(*str1>*str2)
		return 1;
	if(*str1<*str2)
		return -1;
}