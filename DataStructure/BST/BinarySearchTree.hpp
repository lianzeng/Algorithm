
//left child < root < right child

#ifndef BINARY_SEARCH_TREE_HPP_
#define BINARY_SEARCH_TREE_HPP_

#include "TreeNode.hpp"
#include <cstddef>
#include <iostream>
#include <vector>

namespace datastruct {
namespace bst {


template<typename Key>
class BinarySearchTree
{
	typedef typename TreeNode<Key>::TreeNodePtr BSTNodePtr;
	typedef TreeNode<Key> BSTNode;
public:
	BinarySearchTree():rootNode(NULL),nodeCount(0) {}
	~BinarySearchTree()
	{
	  //TODO: free Node memory
	}
    bool isEmptyTree() const
    {
    	return (NULL == rootNode) || (0 == size());
    }
    size_t size() const {return nodeCount;}

    void build(const std::vector<Key>& dataSet)
    {
      for(const auto& data: dataSet )
      {
        insert(data);
      }
    }

    void getKeyInAscendOrder(std::vector<Key>& orderKey) const
    {
      scanInMiddleOrder(rootNode, orderKey);
    }

private:
    void scanInMiddleOrder(const BSTNodePtr& nodePtr,std::vector<Key>& orderKey) const
    {
        if(NULL != nodePtr)
        {
        	scanInMiddleOrder(nodePtr->lchild, orderKey);
        	orderKey.push_back(nodePtr->key);
        	scanInMiddleOrder(nodePtr->rchild, orderKey);
        }
    }
    void insert(const Key& data)
    {
      BSTNodePtr newNodePtr = createNewNode(data);
      assert(newNodePtr != NULL);
      insertToTree(rootNode, newNodePtr);
    }

   void insertToTree(BSTNodePtr& treeRoot, BSTNodePtr& newNode)
   {
     if(NULL != treeRoot)
     {
       if(*newNode < *treeRoot)
         insertToTree(treeRoot->lchild, newNode);
       else
         insertToTree(treeRoot->rchild, newNode);
     }
     else
       treeRoot = newNode;
   }


    BSTNodePtr createNewNode(const Key& data)
    {
      nodeCount ++;
      return new BSTNode(data);
    }

private:
	BinarySearchTree(const BinarySearchTree&);
	BinarySearchTree& operator= (const BinarySearchTree&);

private:
	BSTNodePtr rootNode;
	size_t     nodeCount;

};



}//bst
}//datastruct

#endif
