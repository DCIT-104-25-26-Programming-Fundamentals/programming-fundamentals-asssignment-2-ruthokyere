#include <iostream>
#include <vector>
#include <string>
using namespace std;


// displayMenu()

void displayMenu() {
    cout << "============================" << endl;
    cout << "     TO-DO LIST MENU" << endl;
    cout << "============================" << endl;
    cout << "1. Add task" << endl;
    cout << "2. View tasks" << endl;
    cout << "3. Delete task" << endl;
    cout << "4. Quit" << endl;
    cout << "Enter your choice (1-4): ";
}


// addTask()

void addTask(vector<string>& tasks) {
    cin.ignore();   
    string task;

    cout << "Enter task: ";
    getline(cin, task);

    tasks.push_back(task);
    cout << "Task added: \"" << task << "\"" << endl;
}


// viewTasks()

void viewTasks(const vector<string>& tasks) {
    if (tasks.empty()) {
        cout << "Your list is empty. Add a task to get started!" << endl;
        return;
    }

    cout << "Your Tasks:" << endl;
    for (int i = 0; i < tasks.size(); i++) {
        cout << (i + 1) << ". " << tasks[i] << endl;  
    }
}


// deleteTask()

void deleteTask(vector<string>& tasks) {
    if (tasks.empty()) {
        cout << "Your list is empty. Nothing to delete." << endl;
        return;
    }

    // Show the list first, same as viewTasks(), so the user knows the numbers
    cout << "Your Tasks:" << endl;
    for (int i = 0; i < tasks.size(); i++) {
        cout << (i + 1) << ". " << tasks[i] << endl;
    }

    int taskNum;
    cout << "Enter task number to delete: ";
    cin >> taskNum;

    // Validate: must be within the range of existing tasks (1 to size)
    if (taskNum < 1 || taskNum > tasks.size()) {
        cout << "Invalid task number." << endl;
        return;
    }

    // Convert from 1-based (what the user sees) to 0-based (vector indexing)
    int index = taskNum - 1;
    string removedTask = tasks[index];   

    tasks.erase(tasks.begin() + index);

    cout << "Task \"" << removedTask << "\" has been removed." << endl;
}


// main()

int main() {
    vector<string> tasks;
    int choice;

    do {
        displayMenu();
        cin >> choice;

        if (choice == 1) {
            addTask(tasks);
        } else if (choice == 2) {
            viewTasks(tasks);
        } else if (choice == 3) {
            deleteTask(tasks);
        } else if (choice == 4) {
            cout << "Goodbye!" << endl;
        } else {
            cout << "Invalid choice. Please enter a number between 1 and 4." << endl;
        }

        cout << endl;  

    } while (choice != 4);

    return 0;
}
