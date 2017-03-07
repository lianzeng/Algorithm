
#ifndef BINARY_SEARCH_TREE_HPP_
#define BINARY_SEARCH_TREE_HPP_

#include "TreeNode.hpp"
#include <cstddef>
#include <vector>



namespace datastruct {
namespace bst {


template<typename Key>
class BinarySearchTree
{
public:
	BinarySearchTree():rootNode(EMPTY_NODE),nodeCount(0) {}
	~BinarySearchTree() {}
    bool isEmptyTree() const {return rootNode.isEmptyNode();}

    size_t build(const std::vector<Key>& dataSet)
    {
      for(const auto& data: dataSet )
      {
        insert(data);
      }
      return nodeCount;
    }

private:
    void insert(const Key&)
    {

    }

private:
	BinarySearchTree(const BinarySearchTree&);
	BinarySearchTree& operator= (const BinarySearchTree&);

private:
	const TreeNode<Key> EMPTY_NODE;
	TreeNode<Key> rootNode;

	size_t        nodeCount;
};



}//bst
}//datastruct

#endif
