/* 
 * File:   main.cpp
 * Author: mnemonic
 *
 * Created on November 2, 2013, 7:50 PM
 */

#include <cstdlib>
#include <iostream>
#include "Tree.h"

using namespace std;

/* project tentang traversing tree dengan postorder, inorder, postorder.
 * 
 */
int main(int argc, char** argv) {
    
    Tree tree;
    int level = 3;
    int numofchilds = 3;
    
    cout<<"Tree Depth / Level = ";
    cin>>level;
    
    cout<<"Number Of Childs = ";
    cin>>numofchilds;
    
    initTree(&tree, level, numofchilds);
    generateBalanceTree(&tree, NULL, 1);
        
    //cout<<"Tree size = "<<sizeOfTree(level, numofchilds)<<"\n\n";
    
    cout<<"Print Tree\n";
    printTree(tree.root, "");
    cout<<"\n\n";
    
    // searching data XX
    int datatosearch;
    cout<<"Search data (1-100) = ";
    cin>>datatosearch;
    cout<<"\n";
    
    // searching data using BFS
    cout<<"BFS\n";
    cout<<"Level-Order\n";
    levelOrder(tree, tree.root, datatosearch);
    cout<<"\n\n";
    
    // searching data using DFS
    cout<<"DFS\n";
    cout<<"Pre-Order\n";
    preOrder(tree.root, datatosearch);
    cout<<"\n";
    
    cout<<"In-Order\n";
    inOrder(tree.root, datatosearch);
    cout<<"\n";
    
    cout<<"Post-Order\n";
    postOrder(tree.root, datatosearch);
    cout<<"\n";    
    
    cout<<"\n";
    return 0;
}

