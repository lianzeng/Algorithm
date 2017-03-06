
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
typedef TreeNode<Key>* TreeNodePtr;

  TreeNode():lchild(NULL),rchild(NULL),parent(NULL)
  {
  }
  bool isEmptyNode() const
  {
	  return (NULL == lchild) && (NULL == rchild) && (NULL == parent);
  }

TreeNodePtr lchild;
TreeNodePtr rchild;
TreeNodePtr parent;
Key key;
};



}//bst
}//datastruct

#endif
