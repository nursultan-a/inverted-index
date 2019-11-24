#include <iostream>

#include "BST.hpp"

int main()
{

    // Testing BSTNode ...
    std::cout << "Testing BSTNode ..." << std::endl;

    BSTNode<int> node(11, NULL, NULL);

    std::cout << "node : " << node << std::endl;

    // Testing BST ...
    std::cout << "Testing BST ..." << std::endl;

    BST<int> tree;

    tree.insert(10);
    tree.insert(15);
    tree.insert(5);
    tree.insert(13);

    tree.printInorder();

    BST<int> tree2(tree);
    std::cout << "tree agter three 2 constructed using tree" << std::endl;
    tree.printInorder();
    std::cout << "tree2" << std::endl;
    tree2.printInorder();

    return 0;
}
