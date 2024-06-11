/*
    main.c - bstCalc (2024-1 Data Structure Assignment)
    Copyright (C) 2024 Coppermine-SP - <국립창원대학교 컴퓨터공학과 20233063 손유찬>
*/ 

#include <stdio.h>
#include <stdbool.h>
#include "calc.h"

#define STRING_SIZE 150

int main(void){
    while(true){
        char exp[STRING_SIZE];

        printf(">> ");
        fgets(exp, STRING_SIZE, stdin);
    
        if(exp[0] == '\n') return 0;

        //수식 파싱
        node_t** inline_exp;
        int size;
        if(!parse_expression(exp, STRING_SIZE, &inline_exp, &size)){
            printf("Input Error\n\n");
            continue;
        }

        //수식 트리 생성
        node_t* root;
        if(!make_expression_tree(inline_exp, &root, size)){
            printf("Input Error\n\n");
            continue;
        }

        //수식 평가
        bool exception_flag = false;
        int result = evaluate(root, &exception_flag);
        if(!exception_flag) printf("result: %d\n\n", result);
  }
}