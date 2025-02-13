module ManagerWorker {

    instance manager: ManagerWorker.Manager base id ManagerWorkerSubtopologyConfig.ManagerWorkerSubtopology_BASE_ID + 0x0000 \
        queue size ManagerWorkerSubtopologyConfig.Defaults.QUEUE_SIZE \
        stack size ManagerWorkerSubtopologyConfig.Defaults.STACK_SIZE \
        priority ManagerWorkerSubtopologyConfig.Priorities.manager

    instance worker: ManagerWorker.Worker base id ManagerWorkerSubtopologyConfig.ManagerWorkerSubtopology_BASE_ID + 0x1000 \
        queue size ManagerWorkerSubtopologyConfig.Defaults.QUEUE_SIZE \
        stack size ManagerWorkerSubtopologyConfig.Defaults.STACK_SIZE \
        priority ManagerWorkerSubtopologyConfig.Priorities.worker

    @ Subtopology for connecting manager/worker
    topology Subtopology {
        instance manager
        instance worker

        connections ManagerWorker {
            manager.startWorker -> worker.startWork
            manager.cancelWorker -> worker.cancelWork
            worker.workDone -> manager.doneRecv
        }
    } # end topology
} # end ManagerWorkerSubtopology