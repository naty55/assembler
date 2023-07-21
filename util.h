#ifndef __UTIL_H
#define __UTIL_H

typedef enum {
    False = 0,
    True = 1
} Bool;

char * skip_spaces(char * str);
Bool is_str_empty(char * str);
void printBinary(unsigned short value);
Bool string_to_number(char *str, int * number);
char * duplicate_string(char * str);
char * concat(char * str1, char * str2);
void set_all_null(void ** data, int size);
void convertToBase64(unsigned short value, char data[2]);
#endif