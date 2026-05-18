# ApexBank-Core: C++ Object-Oriented Banking Engine Skeleton

A robust, enterprise-grade C++ backend foundation for a Banking Management System. Built completely from the ground up utilizing strict **Object-Oriented Design (OOD)** and **SOLID principles**, this project serves as a secure, scalable skeleton designed for rapid feature expansion, distributed architecture migration, and rigorous security enforcement.

---

## 🚀 Core Architectural Pillars

This project was engineered with a forward-looking backend mindset, prioritizing two non-negotiable qualities of software architecture: **Extensibility** and **Security**.

### 1. Designed for Expansion (Future-Proofing)
* **Decoupled Domain Logic:** Domain models (Accounts, Customers, Transactions) are completely separated from system infrastructure, making it simple to plug in a database persistence layer (e.g., PostgreSQL via `libpqxx` or an ORM) or a network service layer later on.
* **Interface-Driven Design:** Core behaviors such as Transaction Processing, Identity Verification, and Interest Calculation are abstracted behind clean interfaces/abstract classes. Adding a new account type (e.g., High-Yield Savings, Corporate Multi-Currency) requires zero modifications to existing transaction execution logic (adhering to the **Open/Closed Principle**).
* **Granular Composition:** Complex entities are composed of atomic, specialized value objects (e.g., `Address`, `Email`, `CitizenID`) rather than bloated primitive attributes, simplifying field-specific validation updates.

### 2. Security-First Philosophy (Protection by Design)
* **Strict Encapsulation & Type Safety:** Primitives like strings and integers are wrapped inside dedicated validation objects (`CitizenID`, `Email`). This prevents common vulnerabilities like injection or corrupted states right at the object boundary.
* **Immutability of Ledger History:** Once a `Transaction` object is instantiated and executed, its core metrics (Transaction ID, timestamps, source, destination, amount) are strictly immutable (marked `const` or protected via restricted accessors), laying the groundwork for a tamper-resistant financial ledger.
* **Fail-Safe Validation States:** Object constructors employ strict validation guards. An object cannot exist in an invalid or partial state—preventing logic bypass vulnerabilities downstream.

---

## 📐 Domain Design & Class Structure

The skeleton maps out real-world banking mechanics into highly coherent, cleanly partitioned class hierarchies:

### Core Modules
* **Identity & Value Objects:**
  * `CitizenID`: Manages government-issued identification compliance, syntax parsing, and integrity validation.
  * `Address`: Encapsulates standardized geographic data points.
  * `Email`: Handles electronic mail syntax validation and sanitization.
* **User & Customer Layer:**
  * `Customer`: Aggregates personal information, authentication credentials metadata, and a collection of managed financial accounts.
* **Account Ledger Layer:**
  * `Account` (Base Abstract Class): Defines core state behaviors (Balance, Account Number, Routing Keys) and interface routines (`deposit()`, `withdraw()`).
  * `SavingsAccount` & `CheckingAccount`: Concrete implementations extending base account behaviors with distinct rules (e.g., overdraft limits, interest accrual intervals).
* **Transaction Engine:**
  * `Transaction`: Encapsulates an atomic financial movement. Tracks state transitions (e.g., `PENDING`, `SUCCESS`, `FAILED`) and guarantees auditability.

---

## 🛠 Project Layout

```text
apexbank-core/
├── include/
│   ├── core/
│   │   ├── Account.hpp          # Base abstract account interface
│   │   ├── CheckingAccount.hpp  # Checking account specialized mechanics
│   │   ├── SavingsAccount.hpp   # Savings account specialized mechanics
│   │   └── Customer.hpp         # Customer profile aggregate root
│   ├── auth/
│   │   └── UserCredentials.hpp  # Secure access/credential definitions
│   ├── values/
│   │   ├── CitizenID.hpp        # Validated national identification format
│   │   ├── Address.hpp          # Coherent geographic structure
│   │   └── Email.hpp            # Sanitized email structure
│   └── engine/
│       └── Transaction.hpp      # Immutable transaction record
├── src/
│   # Implementation files mapping to headers above
└── README.md
