#include <gtest/gtest.h>
#include "BinarySearchTree.hpp"
#include <vector>

using namespace datastruct::bst;

typedef unsigned char u8;
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

TEST(TestBinarySearchTree, GivenAnEmptyDataSet_WhenBuildTree_ThenTreeSizeShouldBeZero)
{
	std::vector<KEYTYPE> emptyDataSet;
	BinarySearchTreeInt bstree;
	bstree.build(emptyDataSet);
	EXPECT_EQ(0, bstree.size()) << "An empty dataset should build a tree with zero node";
}

TEST(TestBinarySearchTree, GivenDataSet_WhenBuildTree_ThenTreeSizeShouldEqualToDataSetSize)
{
	const u8 dataSize = 5;
	std::vector<KEYTYPE> dataSet;
	for(u8 i = 0; i < dataSize; i++)
	{
	  dataSet.push_back(i+10);
	}

	BinarySearchTreeInt bstree;
	bstree.build(dataSet);
	EXPECT_FALSE(bstree.isEmptyTree());
	EXPECT_EQ(dataSize, bstree.size()) << "tree size should equal to dataset size";
	//bstree.showTree();
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
