#include <iostream>
#include <vector>

using namespace std;

struct Task {
    string description;
    bool completed;
};

//Function to display menu interface
void Menu() {
    cout << "Todo List Menu" << endl;
    cout << "1. Add a task" << endl;
    cout << "2. View tasks" << endl;
    cout << "3. Mark task as completed or pending" << endl;
    cout << "4. Remove a task" << endl;
    cout << "5. Search a task" << endl;
    cout << "6. Exit" << endl;
}

//Function to add task into to-do list with help of struct 
void addTask(vector<Task>& todoList) {
    string description;
    cout << "Enter task description: ";
    getline(cin >> ws, description); //Ensures description is string and not just blank.

    Task task;
    task.description = description;
    task.completed = false;

    todoList.push_back(task);
    cout << "Task added successfully!" << endl;
}

//Function to view all tasks in to-do list 
void viewTasks(vector<Task>& todoList) {
    if (todoList.empty()) {
        return;
    }

    cout << "Todo List:" << endl;
    for (int i = 0; i < todoList.size(); ++i) {
        Task& task = todoList[i];
        cout << i + 1 << ". ";
        cout << (task.completed ? "[V] " : "[ ] "); //ternary operator = if task.completed is true, output is '[V]'. If task.completed is false, then output is '[ ]'.
        cout << task.description << endl;
    }
}

//Function to mark task inside to-do list by taking the to-do list in viewTasks function
void markTask(vector<Task>& todoList) {
    viewTasks(todoList);
    if (todoList.empty()) {
        cout << "To-do list is empty!" << endl;
        return;
    }

    int index;
    cout << "Enter the task number to mark as completed/pending: ";
    cin >> index;

    if (index < 1 || index > todoList.size()) {
        cout << "Invalid task number!" << endl;
        return;
    }

    Task& task = todoList[index - 1];
    task.completed = !task.completed;

    cout << "Task "<< index <<  " marked as " << (task.completed ? "completed" : "pending") << "." << endl;
}

//Function to remove task inside to-do list by taking the to-do list in viewTasks function
void removeTask(vector<Task>& todoList) {
    viewTasks(todoList);
    if (todoList.empty()) {
        cout << "To-do list is empty!" << endl;
        return;
    }

    int index;
    cout << "Enter the task number to remove: ";
    cin >> index;

    if (index < 1 || index > todoList.size()) {
        cout << "Invalid task number!" << endl;
        return;
    }
    todoList.erase(todoList.begin() + index - 1);
    cout << "Task removed successfully!" << endl;
}

// Function to do sequential search in the to-do list (we use sequential search instead of binary because the scale is smaller in to-do lists)
vector<int> sequentialSearch( vector<Task>& todoList, string& key) {
    vector<int> multiple; //Two vectors incase there are more than 1 key found in tasks.
    for (int i = 0; i < todoList.size(); i++) {
        Task& task = todoList[i];
        if (task.description.find(key) != string::npos) { //find function is used to find key inside the string. If key isn't found, then it will exit if function.
            multiple.push_back(i + 1); 
        }
    }
    return multiple;
}

int main() {
    vector<Task> todoList;
    string keyword;
    char choice;
    while (true) {
        Menu();
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;
        switch (choice) {
            case '1': 
                addTask(todoList);
                break;

            case '2': 
                viewTasks(todoList);
                if (todoList.empty()) {
                    cout << "To-do list is empty!" << endl;
                };
                break;

            case '3': 
                markTask(todoList);
                break;

            case '4': 
                removeTask(todoList);
                break;

            case '5': {
                viewTasks(todoList);
                if (todoList.empty()) {
                    cout << "To-do list is empty!" << endl;
                    break;
                }
                cout << "Enter the keyword to search: ";
                cin >> keyword;
                vector<int> multiple = sequentialSearch(todoList, keyword);
                if (!multiple.empty()) {
                    cout << endl << "Keyword found in task(s): ";
                    for (int n : multiple) {
                        cout << n << " ";
                    }
                    cout << endl;
                } else {
                    cout << "No matching tasks found." << endl;
                }
                break;
            }

            case '6': 
                cout << "Goodbye!" << endl;
                return 0;

            default: 
                cout << "Invalid choice. Please try again." << endl;
        }
        cout << endl;
    }
    return 0;
}
