#include <gtest/gtest.h>
#include "BinarySearchTree.hpp"

using namespace datastruct::bst;

typedef BinarySearchTree<int> BinarySearchTreeInt;
typedef BinarySearchTree<char> BinarySearchTreeChar;

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
  EXPECT_EQ(true, bstree.isEmptyTree()) << "The Tree Initial State is Not Empty";
}


int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
