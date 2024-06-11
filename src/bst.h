/*
    bst.h - bstCalc (2024-1 Data Structure Assignment)
    Copyright (C) 2024 Coppermine-SP - <국립창원대학교 컴퓨터공학과 20233063 손유찬>
*/ 

#pragma once
#include <stdlib.h>
#include <stdbool.h>

/// @brief 연산자 구조체 타입
typedef struct _operator{
    unsigned priority;
    char character;
    bool (*operation)(int, int, int*);
} operator_t;

/// @brief 노드 구조체 타입
typedef struct _node{
    int value;
    int weight;
    struct _operator* op;

    struct _node* left;
    struct _node* right;
} node_t;

/// @brief 새 노드를 생성합니다.
/// @param op 연산자 구조체의 참조를 지정합니다. (NULL이 아닐 경우, 노드가 연산자 노드가 됩니다.)
/// @param value 값을 지정합니다. (연산자 노드일 경우 값이 무시됩니다.)
/// @return 노드의 참조를 반환합니다.
node_t* make_node(void* op, int value);

/// @brief 노드를 메모리에서 제거합니다.
/// @param node 제거할 노드의 참조를 지정합니다.
void dispose_node(node_t* node);

/// @brief post-order traversal을 통해 트리 수식을 평가합니다.
/// @param root 평가를 시작할 루트 노드를 지정합니다.
/// @param exceptionFlag 연산 중 예외가 발생했는지 여부를 저장할 bool형 변수 ptr를 지정합니다.
/// @return 연산 결과를 지정합니다.(예외 발생시 0 반환)
int evaluate(node_t* root, bool* exceptionFlag);

/// @brief 규칙에 따라 노드를 삽입합니다.
/// @param root 루트 노드를 지정합니다.
/// @param x 삽입할 노드를 지정합니다.
/// @return 새 루트 노드를 반환합니다.
node_t* insert(node_t* root, node_t* x);