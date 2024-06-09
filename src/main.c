/*
    main.c - bstCalc (2024-1 Data Structure Assignment)
    Copyright (C) 2024 Coppermine-SP - <국립창원대학교 컴퓨터공학과 20233063 손유찬>
*/ 

#include <stdio.h>
#include <stdbool.h>
#include "calc.h"

#define STRING_SIZE 100

void print_array(node_t** arr){
    int idx = 0;
    node_t* element = arr[idx];

    while(element != NULL){
        if(element->op == NULL) printf("%d ", element->value);
        else printf("%c ", element->op->character);

        element = arr[++idx];
    }
    printf("\n");
}

int main(void){
    while(true){
        char exp[STRING_SIZE];

        printf(">> ");
        fgets(exp, STRING_SIZE, stdin);
    
        if(exp[0] == '\n') return 0;

        //수식 파싱
        node_t** inline_exp;
        if(!parse_expression(exp, STRING_SIZE, &inline_exp)){
            printf("Input Error\n\n");
            continue;
        }
        print_array(inline_exp);

        //infix => postfix
        node_t** postfix_exp;
        if(!infix_to_postfix(inline_exp, &postfix_exp)){
            printf("Input Error\n\n");
            continue;
        }
        print_array(postfix_exp);

        //수식 트리 생성
        node_t* root;
        if(!make_expression_tree(postfix_exp, &root)){
            printf("Input Error\n\n");
            continue;
        }

        //수식 평가
        bool exception_flag = false;
        int result = evaluate(root, &exception_flag);
        if(!exception_flag) printf("result: %d\n\n", result);
  }
}