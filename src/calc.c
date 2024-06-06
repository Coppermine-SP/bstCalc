/*
    calc.c - bstCalc (2024-1 Data Structure Assignment)
    Copyright (C) 2024 Coppermine-SP - <국립창원대학교 컴퓨터공학과 20233063 손유찬>
*/

#include <stdio.h>
#include "calc.h"

#define MAX_DIGITS 10
#define MAX_TERM 30

/*연산자: 연산자 구조체는 연산의 우선 순위와 문자, 연산 함수를 포함하고 있습니다.
각 연산자는 모두 전역 상수로 정의되어 있으며, get_operator() function으로 각 연산 문자에 맞는 연산자 구조체를 const ptr로 제공받게 됩니다.
연산 함수는 좌변, 우변과 결과를 저장할 intptr를 받고, 연산이 성공하면 true, 예외(division by zero)가 발생하면 false를 반환합니다.
*/
static bool add_func(int lhs, int rhs, int* out) { *out = lhs + rhs; return true; }
static const operator_t add = {2, '+', &add_func};

static bool minus_func(int lhs, int rhs, int* out) { *out = lhs - rhs; return true; }
static const operator_t minus = {2, '-', &minus_func};

static bool multiply_func(int lhs, int rhs, int* out) { *out = lhs * rhs; return true; }
static const operator_t multiply = {3, '*', &multiply_func };

static bool divide_func(int lhs, int rhs, int* out) {
    if(rhs == 0) printf("Divide by zero\n"); return false;
    *out = lhs / rhs; return true;
}
static const operator_t divide = {3, '/', &divide_func};

static bool modulo_func(int lhs, int rhs, int* out) { 
    if(rhs == 0) printf("Modulo by zero\n"); return false;
    *out = lhs % rhs; return true;
}
static const operator_t modulo = {3, '%', &modulo_func};

static bool power_func(int lhs, int rhs, int* out) {
    int result = 1;
    for(int i = 0; i < rhs; i++){ result *= lhs; }
    *out = result; return true;
}
static const operator_t power = {1, '^', &power_func};
static const operator_t* operators[] = {&add, &minus, &multiply, &divide, &modulo, &power, NULL};

const operator_t* get_operator(char c){
    const operator_t** element = operators;
    while(*(element) != NULL) if((*element)->character == c) return *(element); else element++;
    return NULL;
}

bool parse_expression(char* exp, int size, node_t*** out){
    char numeric_cache[MAX_DIGITS];
    int numeric_length = 0;
    int terms = 0;

    node_t** arr = (node_t**)malloc(sizeof(node_t*) * MAX_TERM);
    *out = arr;

    for(int i = 0; i < size; i++){
        char c = *(exp + i);
        if(c == '\n') break;
        if(c == ' ') continue;

        if((c == '-') || (c >= 48 && c < 58))
        {
            if(numeric_length >= MAX_DIGITS) return false; //숫자가 최대 자릿수보다 큰 경우
            numeric_cache[numeric_length++] = c;
        }
        else{
            numeric_cache[numeric_length] = '\0';
            arr[terms++] = make_node(NULL, atoi(numeric_cache));
            numeric_length = 0;

            const operator_t* op = get_operator(c);
            if(op == NULL) return false;
            arr[terms++] = make_node((void*)op, 0);
        }
    };

    if(numeric_length != 0){
        numeric_cache[numeric_length] = '\0';
        arr[terms++] = make_node(NULL, atoi(numeric_cache));
        numeric_length = 0;
    }

    arr[terms] = NULL;
    return true;
}