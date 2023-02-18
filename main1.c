#include <iostream>
#include "filo.h"
#include <cstring>

int findTypeBracket(char bracket, char* etalon){
	for(int i = 0; i < 8; i++){
		if(bracket == etalon[i]){
			return i;
		}
	}
	return -1;
}

int findCloseBracket(char* str, int size, char* etalon){
	for(int i = 0; i < size; i++){
		if(findTypeBracket(str[i], etalon) % 2 != 0){
			return i;
		}
	
	}
	return -1;

}

int isOpenBracketRight(char* str,int size, int indexOfClose, char* etalon){
	if(findTypeBracket(str[indexOfClose], etalon) == findTypeBracket(str[indexOfClose - 1], etalon)+1){
		return 1;
	
	}

	return -1;
}

int main(){

	char test_brackets[]  = "(}(({}[]<>\0";
	char etalon_brackets[] = "(){}<>[]\0"; // нечетный индекс -- закрывающаяся скобочка, четный -- открывающаяся скобочка
	int len = strlen(test_brackets);
	struct filo test;
	char temp_bracket;
	initBuffer(&test, len);
	for(int i = 0; i < len; i++){
		if(findTypeBracket(test_brackets[i], etalon_brackets) % 2 == 0){
			putToEnd(&test, test_brackets[i]);
			continue;
		}
		if(findTypeBracket(test_brackets[i], etalon_brackets)  == findTypeBracket(test_brackets[i - 1], etalon_brackets) + 1){
			getFromEnd(&test, &test_brackets[i - 1]);
			continue;
		}
		else{
			deinit(&test);
			std::cout << " false" << std::endl;
			return 1;
		}
		if(i == 0 &&  findTypeBracket(test_brackets[i], etalon_brackets) % 2 != 0){
			deinit(&test);
			std::cout << "false" << std::endl;
			return 1;
		}
	}
 	std::cout << checkBr(&test)<< std::endl;
	deinit(&test);	
	return 0;
}
