/*
    bst.h - bstCalc (2024-1 Data Structure Assignment)
    Copyright (C) 2024 Coppermine-SP - <국립창원대학교 컴퓨터공학과 20233063 손유찬>
*/ 

#pragma once
#include <stdlib.h>

typedef struct _node{
    int value;
    void* op;

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