#include <iostream>
#include <vector>
#include <string>

using namespace std;
struct Task {
    string description;
    bool isCompleted;

    Task(string desc) : description(desc), isCompleted(false) {}
};

class ToDoList {
public:
    vector<Task> tasks;

    void addTask(const string& description) {
        tasks.push_back(Task(description));
    }
    void viewTasks() {
        if (tasks.empty()) {
            cout << "No tasks in your to-do list." << endl;
            return;
        }
        cout << "Tasks:" << endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i].description 
                 << " [" << (tasks[i].isCompleted ? "Completed" : "Pending") << "]" << endl;
        }
    }

    void markTaskCompleted(size_t index) {
        if (index >= 0 && index < tasks.size()) {
            tasks[index].isCompleted = true;
        } else {
            cout << "Invalid task number." << endl;
        }
    }

    void removeTask(size_t index) {
        if (index >= 0 && index < tasks.size()) {
            tasks.erase(tasks.begin() + index);
        } else {
            cout << "Invalid task number." << endl;
        }
    }
};

int main() {
    ToDoList myList;
    int choice;
    string taskDescription;
    size_t taskIndex;
cout<<"< CODSOFT TO DO TASK >"<<endl;
    do {
        cout << "\nTo-Do List Manager" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter the description of the task: ";
                getline(cin, taskDescription);
                myList.addTask(taskDescription);
                break;
            case 2:
                myList.viewTasks();
                break;
            case 3:
                myList.viewTasks();
                cout << "Enter the number of the task to mark as completed: ";
                cin >> taskIndex;
                myList.markTaskCompleted(taskIndex - 1);
                break;
            case 4:
                myList.viewTasks();
                cout << "Enter the number of the task to remove: ";
                cin >> taskIndex;
                myList.removeTask(taskIndex - 1);
                break;
            case 5:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (true);

    return 0;
}

