/*
    calc.c - bstCalc (2024-1 Data Structure Assignment)
    Copyright (C) 2024 Coppermine-SP - <국립창원대학교 컴퓨터공학과 20233063 손유찬>
*/

#include <stdio.h>
#include "calc.h"

#define MAX_DIGITS 9
#define MAX_TERMS 50

#define IS_LB(x) (x->op->character == '(')
#define IS_RB(x) (x->op->character == ')')
#define IS_OP(x) (x->op != NULL)

/*
    연산자: 연산자 구조체는 연산의 우선 순위와 문자, 연산 함수를 포함하고 있습니다.

    각 연산자는 모두 전역 상수로 정의되어 있으며, get_operator() function으로 각 연산 문자에 맞는 연산자 구조체를 const ptr로 제공받게 됩니다.
    연산 함수는 좌변, 우변과 결과를 저장할 intptr를 받고, 연산이 성공하면 true, 예외(division by zero)가 발생하면 false를 반환합니다.
*/
static bool add_func(int lhs, int rhs, int* out){ *out = lhs + rhs; return true; }
static const operator_t add = {2, '+', &add_func};

static bool minus_func(int lhs, int rhs, int* out){ *out = lhs - rhs; return true; }
static const operator_t minus = {2, '-', &minus_func};

static bool multiply_func(int lhs, int rhs, int* out){ *out = lhs * rhs; return true; }
static const operator_t multiply = {3, '*', &multiply_func };

static bool divide_func(int lhs, int rhs, int* out){
    if(rhs == 0) { printf("Divide by zero\n\n"); return false; }
    *out = lhs / rhs; return true;
}
static const operator_t divide = {3, '/', &divide_func};

static bool modulo_func(int lhs, int rhs, int* out){ 
    if(rhs == 0){ printf("Modulo by zero\n\n"); return false; }
    *out = lhs % rhs; return true;
}
static const operator_t modulo = {3, '%', &modulo_func};

static bool power_func(int lhs, int rhs, int* out){
    int result = 1;
    for(int i = 0; i < rhs; i++){ result *= lhs; }
    *out = result; return true;
}
static const operator_t power = {4, '^', &power_func};
static const operator_t open_bracket = {0, '(', NULL};
static const operator_t close_bracket = {0, ')', NULL}; 

static const operator_t* operators[] = {&add, &minus, &multiply, &divide, &modulo, &power, &open_bracket, &close_bracket, NULL};

const operator_t* get_operator(char c){
    const operator_t** element = operators;
    while(*(element) != NULL) if((*element)->character == c) return *(element); else element++;
    return NULL;
}

bool parse_expression(char* exp, int size, node_t*** out, int* terms_out){
    char numeric_cache[MAX_DIGITS];
    int numeric_length = 0;
    int terms = 0;

    node_t** arr = (node_t**)malloc(sizeof(node_t*) * MAX_TERMS);
    arr[0] = NULL;

    for(int i = 0; i < size; i++){
        char c = *(exp + i);
        if(c == '\n') break;
        if(c == ' ') continue;
        if(terms > MAX_TERMS - 2) goto parse_exit; //최대 항 개수를 초과한 경우

        if((c >= 48 && c < 58))
        {
            if(numeric_length >= MAX_DIGITS) goto parse_exit; //숫자가 최대 자릿수보다 큰 경우
            numeric_cache[numeric_length++] = c;
        }
        else{
            if(numeric_length > 0){
                numeric_cache[numeric_length] = '\0';
                arr[terms++] = make_node(NULL, atoi(numeric_cache));
                numeric_length = 0;
            }

            const operator_t* op = get_operator(c);
            if(op == NULL) goto parse_exit; //연산자가 올바르지 않은 경우       
            arr[terms++] = make_node((void*)op, 0);
        }
    };

    if(terms == 0) goto parse_exit; //항이 없는 경우
    if(numeric_length != 0){
        numeric_cache[numeric_length] = '\0';
        arr[terms++] = make_node(NULL, atoi(numeric_cache));
        numeric_length = 0;
    }

    arr[terms] = NULL;
    *terms_out = terms;
    *out = arr;
    return true;

    parse_exit:
    for(int i = 0; i <= terms; i++) dispose_node(arr[i]); //모든 node dispose
    free(arr);
    return false;
}

bool make_expression_tree(node_t** exp, node_t** out, int terms){
    int idx = 0;
    int weight = 0;
    node_t* root = NULL;
    node_t* prev = NULL;
    node_t* element = exp[idx];
    bool is_prev_op = false;
    bool is_prev_lb = false;

    while(element != NULL){
        if(IS_OP(element) && (IS_LB(element) || IS_RB(element))) {
            is_prev_lb = IS_LB(element);
            weight += (is_prev_lb) ? 10 : -10;
            dispose_node(element);
            exp[idx] = NULL;

            if(weight < 0) goto make_exit; //닫는 괄호가 여는 괄호보다 많은 경우
        }
        else{
            if(root == NULL){
                if(IS_OP(element)) goto make_exit; //수식이 연산자로 시작하는 경우
                root = element;
                prev = element;
            }
            else{
                is_prev_op = (prev == NULL) ? false : (IS_OP(prev) ? true : false);
                if(prev != NULL && ((is_prev_op && IS_OP(element)) || (!is_prev_op && !IS_OP(element)))) goto make_exit; //연산자 짝이 올바르지 않은 경우
                if(is_prev_lb && IS_OP(element)) goto make_exit; //여는 괄호 다음이 연산자인 경우
                
                is_prev_lb = false;
                element->weight = weight;
                root = insert(root, element);
            }
            prev = element;
        }
        
        element = exp[++idx];
    }
    is_prev_op = (prev == NULL) ? false : (IS_OP(prev) ? true : false);

    if(weight != 0) goto make_exit;
    else if(is_prev_op) goto make_exit;

    free(exp);
    *out = root;
    return true;

    make_exit:
    for(int i = 0; i <= terms; i++) dispose_node(exp[i]); //모든 node dispose
    free(exp);
    return false;
}