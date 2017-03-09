
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

    BSTNodePtr findElement(const Key key) const
    {
      return findElementRecursive(rootNode, key);
    }

    void getKeyInAscendOrder(std::vector<Key>& orderKey) const
    {
      scanInMiddleOrder(rootNode, orderKey);
    }

private:
    BSTNodePtr findElementRecursive(const BSTNodePtr& treeRoot, const Key& key)const
    {
      if(NULL == treeRoot) return NULL;
      if(key == treeRoot->key) return treeRoot;
      else if(key > treeRoot->key)
        return findElementRecursive(treeRoot->rchild, key);
      else
        return findElementRecursive(treeRoot->lchild, key);
    }
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
      insertToTree(NULL, rootNode, newNodePtr);
    }

   void insertToTree(const BSTNodePtr parent, BSTNodePtr& treeRoot, BSTNodePtr& newNode)
   {
     if(NULL != treeRoot)
     {
       if(*newNode < *treeRoot)
         insertToTree(treeRoot, treeRoot->lchild, newNode);
       else
         insertToTree(treeRoot, treeRoot->rchild, newNode);
     }
     else
     {
       treeRoot = newNode;
       treeRoot->parent = parent;
     }
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
