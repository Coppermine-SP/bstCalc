/*
    bst.c - bstCalc (2024-1 Data Structure Assignment)
    Copyright (C) 2024 Coppermine-SP - <국립창원대학교 컴퓨터공학과 20233063 손유찬>
*/ 

#include "bst.h"
#include <stdlib.h>

node_t* make_node(void* op, int value){
    node_t* node = (node_t*)malloc(sizeof(node_t));

    if(op == NULL) node->value = value;
    else node->op = op;

    node->left = NULL;
    node->right = NULL;
    return node;
}

void dispose_node(node_t* node) { free(node); }