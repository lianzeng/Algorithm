#include <gtest/gtest.h>


class TestGame : public ::testing::Test
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

TEST(TestGame, startFromHere)
{
  //FAIL()<<"start from here!";
}


int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  
  return RUN_ALL_TESTS();
}
