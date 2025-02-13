// ======================================================================
// \title  ManagerTestMain.cpp
// \author mstarch
// \brief  cpp file for Manager component test main function
// ======================================================================

#include "ManagerTester.hpp"

TEST(Nominal, StartWork) {
    ManagerWorker::ManagerTester tester;
    tester.test_start_work();
}

TEST(Nominal, CancelWork) {
    ManagerWorker::ManagerTester tester;
    tester.test_cancel_work();
}

TEST(Nominal, DoneWork) {
    ManagerWorker::ManagerTester tester;
    tester.test_done_work();
}


TEST(Nominal, Responsiveness) {
    ManagerWorker::ManagerTester tester;
    tester.test_responsiveness();
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
