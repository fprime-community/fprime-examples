// ======================================================================
// \title  Worker.cpp
// \author mstarch
// \brief  cpp file for Worker component implementation class
// ======================================================================
#include <Os/Task.hpp>
#include "ManagerWorker/Worker/Worker.hpp"

namespace ManagerWorker {

// ----------------------------------------------------------------------
// Component construction and destruction
// ----------------------------------------------------------------------

Worker ::Worker(const char* const compName) : WorkerComponentBase(compName), m_cancel(false) {}

Worker ::~Worker() {}

// ----------------------------------------------------------------------
// Handler implementations for typed input ports
// ----------------------------------------------------------------------

void Worker ::cancelWork_handler(FwIndexType portNum) {
    this->m_cancel = true;
}

void Worker ::startWork_handler(FwIndexType portNum) {
    FwSizeType bound = FW_MIN(std::numeric_limits<FwSizeType>::max(), 5000);
    FwSizeType i = 0;
    this->m_cancel = false;
    while (not this->m_cancel and i < bound) {
        i++;
        Os::Task::delay(Fw::TimeInterval(0, 1000)); // Delay 1ms to simulate work
    }
    // Indicate that the work is done
    if (i == bound) {
        this->workDone_out(0, Fw::Completed::COMPLETED);
    } else if (this->m_cancel) {
        this->workDone_out(0, Fw::Completed::CANCELED);
    } else {
        this->workDone_out(0, Fw::Completed::FAILED);
    }
}

}  // namespace ManagerWorker
