# Student Management System in C

A comprehensive console-based Student Management System implemented in **C**, demonstrating fundamental data structure concepts using both **Static Arrays** and **Dynamic Singly Linked Lists**.

## 📌 Features

### 1. Array-Based Operations
- **Add Student**: Insert student records (Roll Number, Name, Marks) with duplicate roll number checks and automatic grade calculation.
- **Display Students**: View all student records in a clean tabular format.
- **Search Student**: Search student details by roll number using linear search.
- **Sort Students**: Sort records in descending order of marks using Selection Sort.
- **Update Student**: Modify marks and recalculate grades dynamically.
- **Delete Student**: Delete student records with array element shifting.

### 2. Singly Linked List Operations
- **Add Student**: Dynamically allocate memory for new nodes and append to the linked list.
- **Display List**: Traverse and display all student records.
- **Search in List**: Find student records by traversing the nodes.
- **Delete from List**: Remove specific nodes and properly free memory.
- **Automatic Cleanup**: Complete deallocation of linked list memory upon program termination.

---

## 🗂️ Project Structure

```text
student-management-project-c/
├── main.c          # Full C implementation (Array & Linked List operations)
├── README.md       # Project documentation
└── .gitignore      # Ignored build artifacts and binaries
```

---

## ⚙️ Grading Scale

| Marks Range | Grade |
| ----------- | ----- |
| 90 – 100    | **A** |
| 75 – 89     | **B** |
| 60 – 74     | **C** |
| 40 – 59     | **D** |
| 0 – 39      | **F** |

---

## 🚀 Getting Started

### Prerequisites
You need a C compiler installed:
- **GCC / MinGW** (for Windows/Linux)
- **Clang** (for macOS/Linux)

### Compilation
Using GCC:
```bash
gcc main.c -o student_management
```

### Execution
Run the compiled executable:

**Windows (PowerShell / Command Prompt):**
```powershell
.\student_management.exe
```

**Linux / macOS:**
```bash
./student_management
```

---

## 📜 License
This project is open source and available under the, anyone can use this project [MIT License](LICENSE).
