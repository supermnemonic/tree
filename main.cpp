/* 
 * File:   main.cpp
 * Author: mnemonic
 *
 * Created on November 2, 2013, 7:50 PM
 */

#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include "Tree.h"

using namespace std;

/* project tentang traversing tree dengan preorder, inorder, postorder.
 * 
 */
int main(int argc, char* argv[]) {
    
    if (argc < 9){
        cout<<"Specify the options!\n";
        cout<<argv[0]<<" -d val -b val -r val -s val \n";
        return 1;
    }
    
    // seed random number generator.
    srand(time(NULL));

    int level = 0;
    int numofchilds = 0;
    int maxrandom = 1;
    int datatosearch;
    
    int c;
    
    while ((c = getopt(argc, (char **) argv, "d:b:r:s:?")) != -1) {
//        cout << "Option: " << (char) c;
//        if (optarg)
//            cout << ", argument: " << optarg;
//        cout << '\n';
        switch (c) {
            case 'd':
                level = atoi(optarg);
                break;
            case 'b':
                numofchilds = atoi(optarg);
                break;
            case 'r':
                maxrandom = atoi(optarg);
                break;
            case 's':
                datatosearch = atoi(optarg);
                break;
            case '?':
                if (optopt == 'c')
                    printf("Option -%c requires an argument.\n", optopt);
                else if (isprint(optopt))
                    printf("Unknown option `-%c'.\n", optopt);
                else
                    printf("Unknown option character `\\x%x'.\n", optopt);
                return 1;
            default:
                cout<<"Invalid option. \n";
                abort();
        }
    }
    
    Tree tree;

//        cout << "Tree Depth / Level = ";
//        cin >> level;
//        cout << "Number Of Childs = ";
//        cin >> numofchilds;

    // set range for random number generator.
    setRangeRandom(1, maxrandom);

    // make empty tree, root=NULL
    initTree(&tree, level, numofchilds);

    // generate balance tree, root is not NULL; d level, b branch, random number each node.
    generateBalanceTree(&tree, NULL, 1);

    //cout<<"Tree size = "<<sizeOfTree(level, numofchilds)<<"\n\n";

    cout << "Print Tree\n";
    printTree(tree, tree.root, "");
    cout << "\n";

    // searching data XX
//    cout << "Search data (1-100) = ";
//    cin >> datatosearch;
//    cout << "\n";

    cout<<"Search = "<<datatosearch<<"\n\n";
    
    // searching data using BFS
    cout << "BFS :\n";
    cout << "Level-Order\n";
    levelOrder(tree, tree.root, datatosearch);
    cout << "\n\n";

    // searching data using DFS
    cout << "DFS :\n";
    cout << "Pre-Order\n";
    preOrder(tree.root, datatosearch);
    cout << "\n";

    cout << "In-Order\n";
    inOrder(tree.root, datatosearch);
    cout << "\n";

    cout << "Post-Order\n";
    postOrder(tree.root, datatosearch);
    cout << "\n";

    cout << "\n";
    return 0;
}

