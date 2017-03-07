#include <gtest/gtest.h>
#include "BinarySearchTree.hpp"
#include <vector>

using namespace datastruct::bst;

typedef int KEYTYPE ;
typedef BinarySearchTree<KEYTYPE> BinarySearchTreeInt;


class TestBinarySearchTree : public ::testing::Test
{
public:
  void SetUp()
  {
    //code here be executed before test case
  }

  void TearDown()
  {
    //Code here be executed after test case
  }


};

TEST(TestBinarySearchTree, GivenANewTree_WhenNoOperation_ThenShouldBeAEmptyTree)
{
  BinarySearchTreeInt bstree;
  EXPECT_EQ(true, bstree.isEmptyTree()) << "A new tree should be Empty";
}

TEST(TestBinarySearchTree, GivenAnEmptyDataSet_WhenBuildTree_ThenShouldContainZeroNode)
{
	std::vector<KEYTYPE> emptyDataSet;
	BinarySearchTreeInt bstree;
	EXPECT_EQ(0, bstree.build(emptyDataSet)) << "An empty dataset should build a tree with zero node";
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
