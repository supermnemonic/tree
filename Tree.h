/* 
 * File:   Tree.h
 * Author: mnemonic
 *
 * Created on November 2, 2013, 8:08 PM
 */

#ifndef TREE_H
#define	TREE_H

#include <iostream>

using namespace std;

typedef int InfoType;
typedef int IdType;

typedef struct TreeNode_tag *TreeNodeType;
typedef struct TreeNode_tag{
    InfoType info;
    IdType id;
    TreeNodeType parent;
    TreeNodeType firstChild;
    TreeNodeType nextBrother;
    TreeNodeType prevBrother;
} TreeNode;

typedef struct {
    TreeNodeType root;
    int level;
    int numOfChilds;
} Tree;

/* Prototipe */
int sizeOfTree(int level, int numchild);
TreeNodeType makeNode(IdType id);

void initTree(Tree *T, int level, int numofchilds);
void generateBalanceTree(Tree *T, TreeNode *parent, int curlevel);

void printLevelN(TreeNodeType treenode, int level, InfoType datatosearch);

void levelOrder(Tree t, TreeNodeType treenode, InfoType datatosearch);
void preOrder(TreeNodeType treenode, InfoType datatosearch);
void inOrder(TreeNodeType treenode, InfoType datatosearch);
void postOrder(TreeNodeType treenode, InfoType datatosearch);

char *strconcat(char *s1, char *s2);
void printTree(TreeNodeType treenode, char *prefix);
void printNodePath(TreeNode *node);

#endif	/* TREE_H */

