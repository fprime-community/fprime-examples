module ManagerWorker {
    @ A background worker component example
    active component Worker {
        @ Signal to start the work
        async input port startWork: Fw.Signal

        @ Signal to cancel the work
        sync input port cancelWork: Fw.Signal

        @ Signal the work is done
        output port workDone: Fw.CompletionStatus
    }
}