/*
    calc.h - bstCalc (2024-1 Data Structure Assignment)
    Copyright (C) 2024 Coppermine-SP - <국립창원대학교 컴퓨터공학과 20233063 손유찬>
*/ 

#pragma once
#include "bst.h"

/// @brief 연산자 문자에 맞는 연산자 참조를 반환합니다.
/// @param c 연산자 문자
/// @return (nullable) 연산자 참조.
const operator_t* get_operator(char c);

/// @brief infix 수식 문자열을 파싱합니다.
/// @param exp 문자 배열
/// @param size 문자 배열의 크기
/// @param out 노드 포인터 배열의 참조 (배열의 끝이 NULL)
/// @param terms_out 노드 포인터 배열 크기를 저장할 intptr
/// @return 파싱이 성공하면 true, 실패하면 false를 반환합니다.
bool parse_expression(char* exp, int size, node_t*** out, int* terms_out);

/// @brief infix 수식을 수식 트리로 만듭니다.
/// @param exp 변환 할 infix 수식 배열
/// @param out 변환된 수식 트리 root 노드의 참조
/// @param terms 노드 포인터 배열의 크기
/// @return 변환이 성공하면 true, 실패하면 false를 반환합니다.
bool make_expression_tree(node_t** exp, node_t** out, int terms);