//Task 4
//TO DO LIST
/*
We worship the three-eyed one (Lord Shiva), who is fragrant and who nourishes and increases the vitality of all beings. 
May he liberate us from the bondage of worldly attachments and death, granting us the nectar of immortality.

*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class TaskManager {
private:
    struct Task {
        string description;
        bool completed;
    };

    vector<Task> tasks;

public:
    void addTask() {
        Task newTask;
        cout << "\033[1;36mEnter task description: \033[0m";
        cin.ignore(); // Ignore the newline character left in the input buffer
        getline(cin, newTask.description);
        newTask.completed = false;
        tasks.push_back(newTask);
        cout << "\033[1;32mTask added successfully!\033[0m\n";
    }

    void viewTasks() {
        if (tasks.empty()) {
            cout << "\033[1;31mNo tasks available.\033[0m\n";
            return;
        }
        cout << "\033[1;36mTask List:\n\033[0m";
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i].description << " [" << (tasks[i].completed ? "\033[1;32mCompleted\033[0m" : "\033[1;31mPending\033[0m") << "]\n";
        }
    }

    void markTaskAsCompleted() {
        if (tasks.empty()) {
            cout << "\033[1;31mNo tasks available to mark as completed.\033[0m\n";
            return;
        }
        int index;
        cout << "\033[1;36mEnter the task number to mark as completed: \033[0m";
        cin >> index;
        if (index < 1 || index > tasks.size()) {
            cout << "\033[1;31mInvalid task number.\033[0m\n";
        } else {
            tasks[index - 1].completed = true;
            cout << "\033[1;32mTask marked as completed!\033[0m\n";
        }
    }

    void removeTask() {
        if (tasks.empty()) {
            cout << "\033[1;31mNo tasks available to remove.\033[0m\n";
            return;
        }
        int index;
        cout << "\033[1;36mEnter the task number to remove: \033[0m";
        cin >> index;
        if (index < 1 || index > tasks.size()) {
            cout << "\033[1;31mInvalid task number.\033[0m\n";
        } else {
            tasks.erase(tasks.begin() + index - 1);
            cout << "\033[1;32mTask removed successfully!\033[0m\n";
        }
    }
};

void printBanner() {
    cout << "\033[1;35m"; // Magenta color for the banner
    cout << "***************************************\n";
    cout << "*                                     *\n";
    cout << "*           TO DO LIST                *\n"; // Updated banner text
    cout << "*                                     *\n";
    cout << "***************************************\n";
    cout << "\033[0m"; // Reset color
}

void printBorder() {
    cout << "\033[0;33m"; // Brown color for the border
    cout << "---------------------------------------\n";
    cout << "\033[0m"; // Reset color
}

int main() {
    TaskManager manager;
    int choice;

    while (true) {
        printBanner();
        printBorder();
        cout << "\033[0;33m1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: \033[0m";
        cin >> choice;

        switch (choice) {
            case 1:
                manager.addTask();
                break;
            case 2:
                manager.viewTasks();
                break;
            case 3:
                manager.markTaskAsCompleted();
                break;
            case 4:
                manager.removeTask();
                break;
            case 5:
                cout << "\033[1;35mExiting the To-Do List Manager. Goodbye!\033[0m\n";
                return 0;
            default:
                cout << "\033[1;31mInvalid choice. Please try again.\033[0m\n";
        }
    }

    return 0;
}

