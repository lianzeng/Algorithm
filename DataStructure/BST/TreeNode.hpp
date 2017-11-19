
#ifndef TREE_NODE_HPP_
#define TREE_NODE_HPP_

#ifndef NULL
#define NULL 0
#endif


namespace datastruct {
namespace bst {


template<typename Key>
struct TreeNode
{
typedef TreeNode<Key>* TreeNodePtr;//TODO: use std::shared_ptr<TreeNode>

  TreeNode():lchild(NULL),rchild(NULL),parent(NULL)
  {
  }
  TreeNode(const Key& _key):lchild(NULL),rchild(NULL),parent(NULL),key(_key)
  {
  }
  bool isEmptyNode() const
  {
	  return (NULL == lchild) && (NULL == rchild) && (NULL == parent);
  }

  friend bool operator< (const TreeNode<Key>& left, const TreeNode<Key>& right)//non-member function
  {
    return (left.key) < (right.key);
  }

  friend bool operator>= (const TreeNode<Key>& left, const TreeNode<Key>& right)//non-member function
  {
    return !(left < right);
  }

TreeNodePtr lchild;
TreeNodePtr rchild;
TreeNodePtr parent;
Key key;
};




}//bst
}//datastruct

#endif
