/*
    bst.c - bstCalc (2024-1 Data Structure Assignment)
    Copyright (C) 2024 Coppermine-SP - <국립창원대학교 컴퓨터공학과 20233063 손유찬>
*/ 

#include "bst.h"

node_t* make_node(void* op, int value){
    node_t* node = (node_t*)malloc(sizeof(node_t));

    node->value = value;
    node->op = op;

    node->left = NULL;
    node->right = NULL;
    return node;
}

void dispose_node(node_t* node) { if(node != NULL) free(node); }

int evaluate(node_t* root, bool* exceptionFlag){
    if(root == NULL) return 0;
    if(*exceptionFlag) {
        dispose_node(root);
        return 0;
    }

    if(root->op == NULL){
        int value = root->value;
        dispose_node(root);
        return value;
    }
    else{
        int lhs = evaluate(root->left, exceptionFlag);
        int rhs = evaluate(root->right, exceptionFlag);
        int result = 0;
        
        if(*exceptionFlag || !((operator_t*)root->op)->operation(lhs, rhs, &result)) *exceptionFlag = true;
        dispose_node(root);
        return result;
    }
}