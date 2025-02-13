// ======================================================================
// \title  WorkerTestMain.cpp
// \author mstarch
// \brief  cpp file for Worker component test main function
// ======================================================================

#include "WorkerTester.hpp"

TEST(Nominal, StartDone) {
    ManagerWorker::WorkerTester tester;
    tester.test_start_done();
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
