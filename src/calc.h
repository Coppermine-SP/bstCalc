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

bool parse_expression(char* exp, int size, node_t*** out);