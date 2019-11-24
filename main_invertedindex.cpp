#include <iostream>

#include "InvertedIndex.hpp"

int main() {

    // Testing IIData and InvertedIndex together ...
    std::cout << "Testing IIData and InvertedIndex together ..." << std::endl;

    InvertedIndex ii;

    ii.addDocument("0.txt");
    ii.addDocument("1.txt");
    ii.addDocument("document_1.txt");
    ii.addDocument("document_2.txt");
    ii.addDocument("document_3.txt");
    ii.addDocument("document_4.txt");
    ii.addDocument("document_5.txt");
    ii.printInvertedIndex();
    std::cout <<"remove document 0.txt"<<std::endl;
    ii.removeDocument("0.txt");
    ii.printInvertedIndex();

    std::cout <<"remove document 1.txt"<<std::endl;
    ii.removeDocument("1.txt");
    ii.removeDocument("document_1.txt");
    ii.removeDocument("document_2.txt");
    ii.removeDocument("document_3.txt");
    ii.removeDocument("document_4.txt");
    ii.removeDocument("document_5.txt");
    ii.printInvertedIndex();

    return 0;
}
