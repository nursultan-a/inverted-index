#include "InvertedIndex.hpp"

#include <fstream>

InvertedIndex::InvertedIndex() {

}

InvertedIndex::InvertedIndex(const InvertedIndex &obj) {

    this->invertedIndex = obj.invertedIndex; // uses operator= of BST
}

InvertedIndex::~InvertedIndex() {

}

BST<IIData> &InvertedIndex::getInvertedIndex() {

    return invertedIndex;
}

InvertedIndex &InvertedIndex::addDocument(const std::string &documentName) {

    std::ifstream file(documentName.c_str(), std::ifstream::in);
    std::cout << documentName<< std::endl;

    std::string word;
    for (int position = 1; (file >> word); ++position) {
        BSTNode<IIData> *theNode = invertedIndex.find(IIData(word));
        /* TODO */
        if(theNode == NULL){
            IIData newWord(word);
            newWord.addOccurrence(documentName, position);
            invertedIndex.insert(newWord);
        }
        else(theNode->data.addOccurrence(documentName, position));
        
    }

    file.close();

    return *this;
}

InvertedIndex &InvertedIndex::removeDocument(const std::string &documentName) {
    /* TODO */
    removeDocumentHelper(documentName, this->invertedIndex.getRoot());
    return *this;
}

void InvertedIndex::removeDocumentHelper(const std::string &documentName, BSTNode<IIData>*current){
    if(current == NULL){
        return;
    }
    else{
        current->data.removeOccurrences(documentName);
        removeDocumentHelper(documentName, current->left);
        removeDocumentHelper(documentName, current->right);

    }
}

InvertedIndex &InvertedIndex::searchWord(const std::string &word) {

    BSTNode<IIData> *theNode = invertedIndex.find(IIData(word));

    if (theNode == NULL) {
        std::cout << "The word \"" << word << "\" does not exist in inverted index." << std::endl;
    } else {
        std::cout << theNode->data << std::endl;
    }

    return *this;
}

InvertedIndex &InvertedIndex::printInvertedIndex() {

    invertedIndex.printInorder();

    return *this;
}

InvertedIndex &InvertedIndex::operator=(const InvertedIndex &rhs) {

    this->invertedIndex = rhs.invertedIndex; // uses operator= of BST

    return *this;
}
