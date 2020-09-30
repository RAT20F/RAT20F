#include <iostream>
#include <cstring>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string>

// checks for tokens
// Returns 'true' if the string is a KEYWORD.
bool isKeyword(char* str)
{
    if (!strcmp(str, "if") || !strcmp(str, "else") ||
        !strcmp(str, "while") || !strcmp(str, "do") ||
        !strcmp(str, "for") ||
         !strcmp(str, "fi") || !strcmp(str, "return")
        || !strcmp(str, "int") || !strcmp(str, "true")
        || !strcmp(str, "false") || !strcmp(str, "put")
        || !strcmp(str, "cout") || !strcmp(str, "cin")
        || !strcmp(str, "bool") || !strcmp(str, "get")
        || !strcmp(str, "empty") || !strcmp(str, "function")){
            return (true);
        }

    return (false);
}

// Returns 'true' if the character is a DELIMITER.
bool isDelimiter(char ch)
{
    if (ch == ' ' || ch == '+' || ch == '-' || ch == '*' ||
        ch == '/' || ch == ',' || ch == ';' || ch == '>' ||
        ch == '<' || ch == '=' || ch == '(' || ch == ')' ||
        ch == '[' || ch == ']' || ch == '{' || ch == '}'){
            return (true);
        }

    return (false);
}

bool isReal(char ch){
    if (ch == '0' || ch == '1' || ch == '2' || ch == '3'||
        ch == '4' || ch == '5' || ch == '6' || ch == '7'||
        ch == '8' || ch == '9'){
    return true;
        }
}

// Extracts the SUBSTRING.
char* subString(char* str, int left, int right)
{
    int i;
    char* subStr = (char*)malloc(
                  sizeof(char) * (right - left + 2));

    for (i = left; i <= right; i++)
        subStr[i - left] = str[i];
    subStr[right - left + 1] = '\0';
    return (subStr);
}


// Parsing the input STRING.
void parse(char* str)
{
    int left = 0, right = 0;
    int len = strlen(str);
    char realStr[strlen(str)];

    while (right <= len && left <= right) {
        if (isReal(str[right]) == false) {
            right ++;
        }
        while (isReal(str[right]) == true) {
            strcat(realStr, str[right]);
            puts (realStr);
            right ++;
            if(str[right] == '.'){
                strcat(realStr, str[right]);
                puts (realStr);
                right ++;
            }
            printf("'%r' IS A REAL\n", realStr);
        }
        if (isDelimiter(str[right]) == false)
            right++;

        if (isDelimiter(str[right]) == true && left == right) {

                 printf("'%c' IS AN OPERATOR\n", str[right]);

            right++;
            left = right;
        } else if (isDelimiter(str[right]) == true && left != right || (right == len && left != right)) {
            char* subStr = subString(str, left, right - 1);

            if (isKeyword(subStr) == true){
                printf("'%s' IS A KEYWORD\n", subStr);
            }

            left = right;
        }


    }
    return;
}

// DRIVER FUNCTION
int main(){
     // maximum legth of string is 100 here
    char str[100] = "while(fahr <= upper) a = 23.00;";

    char testStr2[100] = "if(fahr >= upper) a = 15.00;";
    parse(str); // calling the parse function

    parse(testStr2);

    return 0;
}
