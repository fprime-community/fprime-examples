// ======================================================================
// \title  WorkerTester.hpp
// \author mstarch
// \brief  hpp file for Worker component test harness implementation class
// ======================================================================

#ifndef ManagerWorker_WorkerTester_HPP
#define ManagerWorker_WorkerTester_HPP

#include "ManagerWorker/Worker/Worker.hpp"
#include "ManagerWorker/Worker/WorkerGTestBase.hpp"

namespace ManagerWorker {

class WorkerTester : public WorkerGTestBase {
  public:
    // ----------------------------------------------------------------------
    // Constants
    // ----------------------------------------------------------------------

    // Maximum size of histories storing events, telemetry, and port outputs
    static const FwSizeType MAX_HISTORY_SIZE = 10;

    // Instance ID supplied to the component instance under test
    static const FwEnumStoreType TEST_INSTANCE_ID = 0;

    // Queue depth supplied to the component instance under test
    static const FwSizeType TEST_INSTANCE_QUEUE_DEPTH = 10;

  public:
    // ----------------------------------------------------------------------
    // Construction and destruction
    // ----------------------------------------------------------------------

    //! Construct object WorkerTester
    WorkerTester();

    //! Destroy object WorkerTester
    ~WorkerTester();

  public:
    // ----------------------------------------------------------------------
    // Tests
    // ----------------------------------------------------------------------

    //! Test: start work and done work
    void test_start_done();

  private:
    // ----------------------------------------------------------------------
    // Helper functions
    // ----------------------------------------------------------------------

    //! Connect ports
    void connectPorts();

    //! Initialize components
    void initComponents();

  private:
    // ----------------------------------------------------------------------
    // Member variables
    // ----------------------------------------------------------------------

    //! The component under test
    Worker component;
};

}  // namespace ManagerWorker

#endif
