#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "Tree.h"

using namespace std;

int MINRANDOM = 0;
int MAXRANDOM = 0;

TreeNodeType makeNode(IdType id) {
    TreeNode *treenode;
    treenode = (TreeNodeType) malloc(sizeof (TreeNode_tag));
    if (treenode == NULL) {
        cout << "memori tidak cukup!";
        exit(1);
    } else {
        treenode->id = id;
        treenode->info = -1;
        treenode->parent = NULL;
        treenode->firstChild = NULL;
        treenode->nextBrother = NULL;
        treenode->prevBrother = NULL;
    }
    return treenode;
}

void initTree(Tree *T, int level, int numofchilds) {
    (*T).root = NULL;
    (*T).level = level;
    (*T).numOfChilds = numofchilds;
}

int sizeOfTree(int level, int numchild) {
    int size = 0;
    for (int i = 0; i <= level; i++) {
        size = size + pow(numchild, i);
    }
    return size;
}

void setRangeRandom(int min, int max) {
    MINRANDOM = min;
    MAXRANDOM = max;
}

int randomNumber() {
    return rand() % MAXRANDOM + MINRANDOM;
}

void generateBalanceTree(Tree *T, TreeNode *parent, int curlevel) {
    if ((*T).root == NULL) {
        TreeNode *newroot;
        newroot = makeNode(1);
        newroot->info = randomNumber();
        (*T).root = newroot;

        parent = (*T).root;
        generateBalanceTree(T, parent, curlevel);
    } else if (curlevel <= (*T).level) {
        //(curlevel)++;

        TreeNode *prechild = NULL;
        for (int i = 1; i <= (*T).numOfChilds; i++) {
            TreeNode *newchild = makeNode(i);
            newchild->info = randomNumber();
            newchild->parent = parent;

            if (parent->firstChild == NULL)
                parent->firstChild = newchild;
            else
                prechild->nextBrother = newchild;

            prechild = newchild;

            generateBalanceTree(T, newchild, ++curlevel);
            curlevel--;
        }
        //(curlevel)--;
    }
}

char *strconcat(char *s1, char *s2) {
    size_t old_size;
    char *t;

    old_size = strlen(s1);

    t = (char*) malloc(old_size + strlen(s2) + 1);
    strcpy(t, s1);
    strcpy(t + old_size, s2);
    return t;
}

bool isRoot(TreeNode *treenode) {
    return treenode->parent == NULL;
}

void printTree(Tree tree, TreeNodeType treenode, char *prefix) {
    if (treenode == NULL) {
        cout << prefix << "+- <null>\n";
        return;
    }

    if (isRoot(treenode))
        cout << prefix << "[" << treenode->id << "]-" << treenode->info << "\n";
    else if (treenode->id == tree.numOfChilds) {
        cout << prefix << "\b|__[" << treenode->id << "]-" << treenode->info << "\n";
        if (treenode->firstChild == NULL)
            cout << prefix << "\n";
    } else
        cout << prefix << "__[" << treenode->id << "]-" << treenode->info << "\n";

    TreeNode *child;
    char *s;

    for (child = treenode->firstChild; child != NULL; child = child->nextBrother) {
        if (child->nextBrother != NULL) {
            s = strconcat(prefix, "   |");
        } else
            s = strconcat(prefix, "    ");

        printTree(tree, child, s);
    }

    //printTree(child, s);
}

void printNodePath(TreeNode *node) {
    int paths[100];
    int length = 0;
    while (node != NULL) {
        paths[length] = node->id;
        node = node->parent;

        length++;
    }

    for (int i = length - 1; i >= 0; i--) {
        cout << paths[i] << " ";
    }

    cout << "\n";
}

void printLevelN(TreeNodeType treenode, int level, InfoType datatosearch) {
    if (treenode == NULL)
        return;
    if (level == 0) {
        //cout << "[" << treenode->id << "] " << treenode->info << "\n";
        if (treenode->info == datatosearch) {
            //cout << "Jalur menuju data " << treenode->info << " dari ROOT adalah : ";
            printNodePath(treenode);
        } else {
            //cout << treenode->id << "  ";
        }
    } else if (level > 0) {
        for (TreeNode *child = treenode->firstChild; child != NULL; child = child->nextBrother) {
            printLevelN(child, level - 1, datatosearch);
        }
    }
}

void levelOrder(Tree t, TreeNodeType treenode, InfoType datatosearch) {
    for (int level = 0; level <= t.level; level++) {
        printLevelN(treenode, level, datatosearch);
    }
}

void preOrder(TreeNodeType treenode, InfoType datatosearch) {
    //cout << "[" << treenode->id << "] " << treenode->info << "\n";
    if (treenode->info == datatosearch) {
        //cout << "Jalur menuju data " << treenode->info << " dari ROOT adalah : ";
        printNodePath(treenode);
    } else {
        //cout << treenode->id << "  ";
    }

    for (TreeNode *child = treenode->firstChild; child != NULL; child = child->nextBrother) {
        preOrder(child, datatosearch);
    }
}

void inOrder(TreeNodeType treenode, InfoType datatosearch) {
    TreeNode *child = treenode->firstChild;
    if (child != NULL) {
        inOrder(child, datatosearch);
        child = child->nextBrother;
    }

    //cout << "[" << treenode->id << "] " << treenode->info << "\n";
    if (treenode->info == datatosearch) {
        //        cout << "Jalur menuju data " << treenode->info << " dari ROOT adalah : ";
        printNodePath(treenode);
    } else {
        //cout << treenode->id << "  ";
    }

    for (; child != NULL; child = child->nextBrother) {
        inOrder(child, datatosearch);
    }
}

void postOrder(TreeNodeType treenode, InfoType datatosearch) {
    //if (found) return;

    for (TreeNode *child = treenode->firstChild; child != NULL; child = child->nextBrother) {
        postOrder(child, datatosearch);
    }

    //cout << "["<<treenode->id<<"] "<<treenode->info << "\n";
    if (treenode->info == datatosearch) {
        //        cout << "Jalur menuju data " << treenode->info << " dari ROOT adalah : ";
        printNodePath(treenode);
    } else {
        //cout << treenode->id << "  ";
    }
}
