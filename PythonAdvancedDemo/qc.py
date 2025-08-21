from qiskit import QuantumCircuit, Aer, execute

# Create a quantum circuit with 2 qubits
qc = QuantumCircuit(2)

# Apply a Hadamard gate to the first qubit
qc.h(0)

# Apply a CNOT gate with the first qubit as control and the second qubit as target
qc.cx(0, 1)

# Measure the qubits
qc.measure_all()

# Simulate the circuit using the local Aer simulator
simulator = Aer.get_backend('qasm_simulator')
job = execute(qc, simulator, shots=1000)
result = job.result()

# Get the counts of the measurement outcomes
counts = result.get_counts(qc)
print(counts)

