// ======================================================================
// \title  ManagerTester.hpp
// \author mstarch
// \brief  hpp file for Manager component test harness implementation class
// ======================================================================

#ifndef ManagerWorker_ManagerTester_HPP
#define ManagerWorker_ManagerTester_HPP

#include "ManagerWorker/Manager/Manager.hpp"
#include "ManagerWorker/Manager/ManagerGTestBase.hpp"

namespace ManagerWorker {

class ManagerTester : public ManagerGTestBase {
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

    //! Construct object ManagerTester
    ManagerTester();

    //! Destroy object ManagerTester
    ~ManagerTester();

  public:
    // ----------------------------------------------------------------------
    // Tests
    // ----------------------------------------------------------------------

    //! Test: Start work
    void test_start_work();

    //! Test: Cancel work
    void test_cancel_work();

    //! Test: Done work
    void test_done_work();

    //! Test: Responsiveness
    void test_responsiveness();

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
    Manager component;
};

}  // namespace ManagerWorker

#endif
