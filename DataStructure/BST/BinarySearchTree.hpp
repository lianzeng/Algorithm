
#ifndef BINARY_SEARCH_TREE_HPP_
#define BINARY_SEARCH_TREE_HPP_

#include "TreeNode.hpp"
#include <cstddef>
#include <vector>
#include <iostream>


namespace datastruct {
namespace bst {


template<typename Key>
class BinarySearchTree
{
	typedef TreeNode<Key> BSTNode;
	typedef BSTNode* BSTNodePtr;
public:
	BinarySearchTree():rootNode(NULL) {}
	~BinarySearchTree() {}
    bool isEmptyTree() const
    {
    	return (NULL == rootNode) || (0 == size());
    }
    size_t size() const {return Nodes.size();}

    void build(const std::vector<Key>& dataSet)
    {
      for(const auto& data: dataSet )
      {
        insert(data);
      }
    }

    void showTree() const
    {
      scanInMiddleOrder(rootNode);
    }

private:
    void scanInMiddleOrder(const BSTNodePtr& nodePtr) const
    {
        if(NULL != nodePtr)
        {
        	scanInMiddleOrder(nodePtr->lchild);
        	std::cout << "key is: " << nodePtr->key << std::endl;
        	scanInMiddleOrder(nodePtr->rchild);
        }
    }
    void insert(const Key& data)
    {
      Nodes.push_back(BSTNode(data));
      BSTNode& newNode = *(Nodes.end()-1);
      if(isEmptyTree())
      {
    	rootNode = &newNode;
      }
      else
      {

      }

    }

private:
	BinarySearchTree(const BinarySearchTree&);
	BinarySearchTree& operator= (const BinarySearchTree&);

private:
	BSTNodePtr rootNode;

	std::vector<BSTNode> Nodes;
};



}//bst
}//datastruct

#endif
