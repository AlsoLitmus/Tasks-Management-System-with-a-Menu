#include <iostream>
#include <string>
#include <vector>

using namespace std;

void displayMenu();
int getChoice(std::vector<string> &t);
void createTask(std::vector<string> &t);
void editTask(std::vector<string> &t);
void deleteTask(std::vector<string> &t);
void viewTasks(std::vector<string> &t);

int main() {
	std::vector<string> tasks;
	int chosenChoice = 0;
	int EXIT_OPTION = 5;

	while (chosenChoice != EXIT_OPTION) {
		displayMenu();
		chosenChoice = getChoice(tasks);
	}
	
	return 0;
}

void displayMenu() {
	cout << "\nTask Manager Menu:" << endl;
	cout << "1. Create Task" << endl;
	cout << "2. Edit Task" << endl;
	cout << "3. Delete Task" << endl;
	cout << "4. View tasks" << endl;
	cout << "5. Exit" << endl;
}

int getChoice(std::vector<string> &tasks) {
	int choice;
	cout << "Enter your choice (1-5): ";
	cin >> choice;

	while (!cin >> choice || choice < 1 || choice > 5) {
		cout << "Invalid input. Please enter a number between 1 and 5: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> choice;
	}

	switch (choice) {
	case 1:
		cout << "Creating a new task..." << endl;
		createTask(tasks);
		break;
	case 2:
		cout << "Editing an existing task..." << endl;
		editTask(tasks);
		break;
	case 3:
		cout << "Deleting a task..." << endl;
		deleteTask(tasks);
		break;
	case 4:
		cout << "Here are all your tasks..." << endl;
		viewTasks(tasks);
		break;
	case 5:
		cout << "Exiting the program." << endl;
		break;
	default:
		cout << "Invalid choice. Please try again." << endl;
		getChoice(tasks);
		break;
	}
	return choice;
}

void createTask(std::vector<string> &tasks) {

	string task;
	cout << "Enter a task: ";
	cin.ignore(); 
	getline(cin, task);
	cout << "Task '" << task << "' created successfully!" << endl;
	tasks.push_back(task);
	
}

void editTask(std::vector<string>& tasks)
{
	if (tasks.empty()) {
		cout << "No tasks available to edit." << endl;
		return;
	}
	cout << "\nHere are your current tasks:" << endl;
	for (size_t i = 0; i < tasks.size(); ++i) {
		cout << i + 1 << ". " << tasks[i] << endl;
	}
	int taskNumber;
	cout << "Enter the number of the task you want to edit: ";
	cin >> taskNumber;

	while (!cin >> taskNumber || taskNumber < 1 || taskNumber > tasks.size()) {
		if (tasks.size() > 1) {
			cout << "Invalid input. Please enter a number between 1 and " << tasks.size() << ": ";
		}
		else {
			cout << "Invalid input. Please enter 1: ";
		}
		cin.clear(); 
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> taskNumber;
	}

	cin.ignore(); 
	string newTask;
	cout << "Enter the new description for the task: ";
	getline(cin, newTask);
	tasks[taskNumber - 1] = newTask;
	cout << "Task updated successfully!" << endl;
}

void deleteTask(std::vector<string> &tasks) {
	if (tasks.empty()) {
		cout << "No tasks available to edit." << endl;
		return;
	}

	cout << "\nHere are your current tasks:" << endl;
	for (size_t i = 0; i < tasks.size(); ++i) {
		cout << i + 1 << ". " << tasks[i] << endl;
	}

	int taskNumber;
	cout << "Enter the number of the task you want to delete: ";
	cin >> taskNumber;

	while (!cin >> taskNumber || taskNumber < 1 || taskNumber > tasks.size()) {
		if (tasks.size() > 1) {
			cout << "Invalid input. Please enter a number between 1 and " << tasks.size() << ": ";
		}
		else {
			cout << "Invalid input. Please enter 1: ";
		}

		cin.clear(); 
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
		cin >> taskNumber;
	}

	cin.ignore(); 
	tasks.erase(tasks.begin() + taskNumber - 1);
	cout << "Task deleted successfully!" << endl;

}

void viewTasks(std::vector<string> &tasks) {
	if (tasks.empty()) {
		cout << "No tasks available." << endl;
		return;
	}
	cout << "\nHere are your current tasks:" << endl;
	for (size_t i = 0; i < tasks.size(); ++i) {
		cout << i + 1 << ". " << tasks[i] << endl;
	}

}
