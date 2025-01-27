#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

struct Task {
    string description;
    bool completed;
};
// Global Variabels
// Task structure to store task details
vector<Task> tasks;

// Function prototypes.

void displayMenu();
void addTask();
void viewTasks();
void markTaskCompleted();

// Main function to run the program
int main() {
    int choice;
    
    while (true) {
        displayMenu(); // Display the menu
        
        // Handle invalid input (non-integer)
        if (!(cin >> choice)) {
            cin.clear(); // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
        
        // Handle user choice
        switch (choice) {
            case 1:
                addTask(); // Add a new task
                break;
            case 2:
                viewTasks(); // View all tasks
                break;
            case 3:
                markTaskCompleted(); // Mark a task as 
                break;
            case 4:
                cout << "Goodbye!\n"; // Exit the program
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}
// Function defination 

// Function to display the main menu options
void displayMenu() {
    std::cout << "========== To-Do List ==========" << std::endl;
    std::cout << "1. Add Task" << std::endl;
    std::cout << "2. Mark Task as Completed" << std::endl;
    std::cout << "3. View Tasks" << std::endl;
    std::cout << "4. Exit" << std::endl;
    std::cout << "================================" << std::endl;
}

// Function to add a new task to the list
void addTask() {
    string description;
    cout << "Enter task description: ";
    getline(cin, description);
    tasks.push_back({description, false});
    cout << "Task added successfully!\n";
}

// Function to display all tasks with their completion status
void viewTasks() {
    if (tasks.empty()) {
        cout << "No tasks available.\n";
        return;
    }
    
    cout << "\nCurrent Tasks:\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". [" << (tasks[i].completed ? "X" : " ") << "] "
             << tasks[i].description << "\n";
    }
}

// Function to mark a task as completed
void markTaskCompleted() {
    int taskNumber;
    if (tasks.empty()) {
        cout << "No tasks to mark.\n";
        return;
    }
    
    viewTasks();
    cout << "Enter task number to mark as completed: ";
    
    cin >> taskNumber;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    if (taskNumber < 1 || taskNumber > static_cast<int>(tasks.size())) {
        cout << "Invalid task number!\n";
        return;
    }
    
    tasks[taskNumber - 1].completed = true;
    cout << "Task marked as completed!\n";
}