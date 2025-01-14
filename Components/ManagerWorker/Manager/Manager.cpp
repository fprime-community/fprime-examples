// ======================================================================
// \title  Manager.cpp
// \author mstarch
// \brief  cpp file for Manager component implementation class
// ======================================================================

#include "Components/ManagerWorker/Manager/Manager.hpp"

namespace ManagerWorker {

// ----------------------------------------------------------------------
// Component construction and destruction
// ----------------------------------------------------------------------

Manager ::Manager(const char* const compName) : ManagerComponentBase(compName) {}

Manager ::~Manager() {}

// ----------------------------------------------------------------------
// Handler implementations for typed input ports
// ----------------------------------------------------------------------

void Manager ::pingIn_handler(FwIndexType portNum, U32 key) {
    this->pingOut_out(portNum, key);
}

void Manager ::doneRecv_handler(FwIndexType portNum, const Fw::Completed& completed) {
    this->m_busy = false;
    switch (completed.e) {
        case Fw::Completed::COMPLETED:
            this->log_ACTIVITY_HI_WorkerDone();
            break;
        case Fw::Completed::CANCELED:
            this->log_ACTIVITY_HI_WorkerCanceled();
            break;
        case Fw::Completed::FAILED:
            this->log_WARNING_HI_WorkerFailed();
            break;
        default:
            FW_ASSERT(0, completed.e);
            break;
    }
}

// ----------------------------------------------------------------------
// Handler implementations for commands
// ----------------------------------------------------------------------

void Manager ::START_cmdHandler(FwOpcodeType opCode, U32 cmdSeq) {
    if (this->m_busy) {
        this->log_WARNING_HI_WorkerBusy();
    } else {
        this->log_ACTIVITY_HI_StartWork();
        this->m_busy = true;
        this->startWorker_out(0);
    }
    this->cmdResponse_out(opCode, cmdSeq, Fw::CmdResponse::OK);
}

void Manager ::STOP_cmdHandler(FwOpcodeType opCode, U32 cmdSeq) {
    this->log_ACTIVITY_HI_StopWork();
    this->cancelWorker_out(0);
    this->cmdResponse_out(opCode, cmdSeq, Fw::CmdResponse::OK);
}

}  // namespace ManagerWorker
