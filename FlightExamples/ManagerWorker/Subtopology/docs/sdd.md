# Subtopology `ManagerWorkerSubtopology`

A subtopology showing the manager/worker pattern.  This subtopology instantiates a manager and worker components to show how these component are hooked-up, and allow integration tests to be written against those components.

## Requirements

| Name                           | Description                                                                          | Validation       |
|--------------------------------|--------------------------------------------------------------------------------------|------------------|
| MANAGER-WORKER-SUBTOPOLOGY-001 | The subtology shall instantiate and wire-together both a manager and worker component| Integration Test |

## Configuration

Ping entries are defined in `ManagerWorkerTopologyDefs.hpp`.  The `GlobalDefs` namespace must be merged into the instantiating topology's `PingEntries` namespace.  `ManagerWorkerConfig.fpp` must be configured with constants specifying the topology offset, priorities, etc.

## Instantiation

To instantiate this topology, use the following:

```
import ManagerWorker.Subtopology
```

## Running Tests

Launch any topology that imports this subtopology and provides a command dispatcher and event logger. Ensure the GDS is connected. Then run the following:

```
cd ManagerWorker/Subtopology
pytest
```

> ![NOTE]
> You might need to supply additional arguments to `pytest` for non-standard GDS setups.
