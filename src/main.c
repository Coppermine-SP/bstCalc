/*
    main.c - bstCalc (2024-1 Data Structure Assignment)
    Copyright (C) 2024 Coppermine-SP - <국립창원대학교 컴퓨터공학과 20233063 손유찬>
*/ 

#include <stdio.h>
#include <stdbool.h>
#include "bst.h"
#include "calc.h"

#define STRING_SIZE 100

int main(void){
    while(true){
        char exp[STRING_SIZE];

        printf(">> ");
        fgets(exp, STRING_SIZE, stdin);
    
        if(exp[0] == '\n') return 0;
        printf("%s\n", exp);
    }
}