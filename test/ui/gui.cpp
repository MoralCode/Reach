#include "ui/gui.h"
#include <gtkmm.h>
#include <string>

#include "gtest/gtest.h"

namespace G {

// The fixture for testing class ReachGUI.
class ReachGUITest : public ::testing::Test {
protected:
	// You can remove any or all of the following functions if their bodies
	// would be empty.
	G::ReachGUI gui;

	// ReachGUITest(std::string appid) {
	// 	// You can do set-up work for each test here.
	// 	gui = ReachGUI(appid);
	// }

	~ReachGUITest() override {
		// You can do clean-up work that doesn't throw exceptions here.
	}

	// If the constructor and destructor are not enough for setting up
	// and cleaning up each test, you can define the following methods:

	void SetUp() override {
		// Code here will be called immediately after the constructor (right
		// before each test).

		// "com.adriancedwards.reach.test"
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

// TEST_F(ReachGUITest, SignalClosesAndHidesWindow) {
// 	// gui::close_hide_window()
// }

} // namespace G