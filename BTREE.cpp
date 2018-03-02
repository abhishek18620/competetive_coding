/*
 * BTREE.cpp
 * Copyright (C) 2018 abhi <abhi@abhi-HP-Notebook>
 *
 * Distributed under terms of the MIT license.
 */

#include "bits/stdc++.h"



void rec()
{
    queue q;
    node* left=root->left;
    node* rigth=root->right;
    print(root->data);
    node* root;
    while(!q.empty())
    {
        root=q.front();
        q.pop();
        if(root->left!=NULL)
            q.push(left);
        if(root->right!=NULL)
            q.push(right);
    }

}

void rec(node * root , int level)
{
    if(level ==1)
    {
        print(root->data);
    }
    else if(level>1)
    {
        if(root->left!=NULL)
        {
        // store[level].emplace_back(left);
            rec(left,level-1);
        }
        if(root->right!=NULL)
        {
            //store[level].emplace_back(right);
            rec(right,level-1);
        }
    }
    return;
}

int find_level(node * root)
{
    if(node==NULL)
        return 0;
    else
    {
        int left_level=find_level(node->left);
        int right_level=find_level(node->right);
        if(left_level>right_level)
            return left_level+1;
        else
            return right_level+1;
    }
}
void find_root_level(node* root)
{
    int level=find_level(root);
    for(int i=0;i<level;i++)
        rec(root,i)
}

