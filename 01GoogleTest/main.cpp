#include <gtest/gtest.h>
#include <cstdlib>

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	auto res = RUN_ALL_TESTS();
	system("pause");

}