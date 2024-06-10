/*
    bst.c - bstCalc (2024-1 Data Structure Assignment)
    Copyright (C) 2024 Coppermine-SP - <국립창원대학교 컴퓨터공학과 20233063 손유찬>
*/ 

#include "bst.h"

node_t* make_node(void* op, int value){
    node_t* node = (node_t*)malloc(sizeof(node_t));

    node->value = value;
    node->op = op;
    node->weight = 0;

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
    if(root->left == NULL || root->right == NULL)
    {
        *exceptionFlag = true;
        dispose_node(root);
        return 0;
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

static int get_priority(node_t* x) { return (x->op != NULL) ? x->weight + x->op->priority : 0; }

node_t* insert(node_t* root, node_t* x){
    if(root->op == NULL){
        x->left = root;
        return x;
    }

    if(root->right == NULL){
        root->right = x;
        return root;
    }

    if(x->op != NULL){
        if(get_priority(root) >= get_priority(x)){
            x->left = root;
            return x;
        }
        else if(get_priority(root->right) == 0){
            x->left = root->right;
            root->right = x;
            return root;
        }
        else{
            root->right = insert(root->right, x);
            return root;
        }
    }
    else{
        root->right = insert(root->right, x);
        return root;
    }

}