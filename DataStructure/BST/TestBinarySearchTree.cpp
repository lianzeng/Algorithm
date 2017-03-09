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

TEST(TestBinarySearchTree, GivenAscendOrderDataSet_WhenBuildBST_ThenShouldKeepSameOrder)
{
	std::vector<KEYTYPE> dataSet = {1,2,3,4,5};
	BinarySearchTreeInt bstree;
	bstree.build(dataSet);
	EXPECT_FALSE(bstree.isEmptyTree());
	EXPECT_EQ(dataSet.size(), bstree.size()) << "tree size should equal to dataset size";

	std::vector<KEYTYPE> dataSetInAscendOrder;
	bstree.getKeyInAscendOrder(dataSetInAscendOrder);
	EXPECT_TRUE(dataSet == dataSetInAscendOrder) << "tree should keep same order for already ordered data";
}

TEST(TestBinarySearchTree, GivenDscendOrderDataSet_WhenBuildBST_ThenShouldInAscendOrder)
{
  std::vector<KEYTYPE> dataSet = {5,4,3,2,1};
  BinarySearchTreeInt bstree;
  bstree.build(dataSet);
  EXPECT_FALSE(bstree.isEmptyTree());
  EXPECT_EQ(dataSet.size(), bstree.size()) << "tree size should equal to dataset size";

  std::vector<KEYTYPE> expectDataSet = {1,2,3,4,5};
  std::vector<KEYTYPE> dataSetInAscendOrder;
  bstree.getKeyInAscendOrder(dataSetInAscendOrder);
  EXPECT_TRUE(expectDataSet == dataSetInAscendOrder) << "tree should in ascend order for data";
}

TEST(TestBinarySearchTree, GivenRandomOrderDataSet_WhenBuildBST_ThenShouldInAscendOrder)
{
  std::vector<KEYTYPE> dataSet = {5,0,-2,3,-1,6,8,4};
  BinarySearchTreeInt bstree;
  bstree.build(dataSet);
  EXPECT_FALSE(bstree.isEmptyTree());
  EXPECT_EQ(dataSet.size(), bstree.size()) << "tree size should equal to dataset size";

  std::vector<KEYTYPE> expectDataSet = {-2,-1,0,3,4,5,6,8};
  std::vector<KEYTYPE> dataSetInAscendOrder;
  bstree.getKeyInAscendOrder(dataSetInAscendOrder);
  EXPECT_TRUE(expectDataSet == dataSetInAscendOrder) << "tree should in ascend order for data";
}

TEST(TestBinarySearchTree, GivenASpecialDataSet_WhenBuildBST_ThenTheParentRelationShouldOk)
{
//    5
//  3   6
//2       7
  std::vector<KEYTYPE> dataSet = {5,3,6,2,7};
  BinarySearchTreeInt bstree;
  bstree.build(dataSet);

  EXPECT_EQ(3,(bstree.findElement(2))->parent->key);
  EXPECT_EQ(5,(bstree.findElement(3))->parent->key);
  EXPECT_EQ(6,(bstree.findElement(7))->parent->key);
  EXPECT_EQ(5,(bstree.findElement(6))->parent->key);
  EXPECT_EQ(NULL,(bstree.findElement(5))->parent);

}



int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
