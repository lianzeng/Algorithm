
#ifndef BINARY_SEARCH_TREE_HPP_
#define BINARY_SEARCH_TREE_HPP_

#include "TreeNode.hpp"

namespace datastruct {
namespace bst {


template<typename Key>
class BinarySearchTree
{
public:
	BinarySearchTree():rootNode(EMPTY_NODE) {}
	~BinarySearchTree() {}
    bool isEmptyTree() const {return rootNode.isEmptyNode();}

private:
	BinarySearchTree(const BinarySearchTree&);
	BinarySearchTree& operator= (const BinarySearchTree&);

private:
	const TreeNode<Key> EMPTY_NODE;
	TreeNode<Key> rootNode;
};



}//bst
}//datastruct

#endif
