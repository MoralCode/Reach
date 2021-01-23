#include "model/field.h"

#include "gtest/gtest.h"


// The fixture for testing class ReachGUI.
class FieldTest : public ::testing::Test {
protected:
	// You can remove any or all of the following functions if their bodies
	// would be empty.
	Field *field;

	FieldTest() {
		// You can do set-up work for each test here.
		field = new Field("type", "Label", "value") ;
	}

	~FieldTest() override {
		// You can do clean-up work that doesn't throw exceptions here.
		delete field;
	}

	// If the constructor and destructor are not enough for setting up
	// and cleaning up each test, you can define the following methods:

	void SetUp() override {
		// Code here will be called immediately after the constructor (right
		// before each test).

	}

	void TearDown() override {
		// Code here will be called immediately after each test (right
		// before the destructor).
	}

	// Class members declared here can be used by all tests in the test suite
	// for Foo.
};

// // Tests that the Foo::Bar() method does Abc.
// TEST_F(ReachGUITest, MethodBarDoesAbc) {
// 	const std::string input_filepath = "this/package/testdata/myinputfile.dat";
// 	const std::string output_filepath =
// 		"this/package/testdata/myoutputfile.dat";
// 	Foo f;
// 	EXPECT_EQ(f.Bar(input_filepath, output_filepath), 0);
// }

TEST_F(FieldTest, CanRetrieveType) { EXPECT_EQ(field->getType(), "type"); }
TEST_F(FieldTest, CanRetrieveLabel) { EXPECT_EQ(field->getLabel(), "Label"); }
TEST_F(FieldTest, CanRetrieveValue) { EXPECT_EQ(field->getValue(), "value"); }

//test for equality
