// To-Do list using C++ 

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

void show_tasks(const std::vector<std::string> &tasks)
{
  std::cout << "\n\tTo-Do List:" << std::endl;
  for (int i = 0; i < tasks.size(); ++i)
  {
      std::cout << i + 1 << ". " << tasks[i] << std::endl;
  }
}
void delete_task(std::vector<std::string> &tasks, int val){
    char conf;
    std::string task="";
    task = tasks[val];
    std::cout << "\nTask \"" << task << "\" is going to Delete";
    std::cout << "\nDo you want to continue(Y/N): ";
    std::cin >> conf;
    auto itr = std::find(tasks.begin(),tasks.end(),task);
    switch (conf)
    {
    case 'Y':
    case 'y':
        if (itr!=tasks.end()){
            tasks.erase(itr);
            std::cout<<"\nTask Deleted successfully"<<std::endl;
        }
        break;
    case 'N':
    case 'n':
        std::cout <<"\nFunction Terminated\n";
        break;
    default:
        std::cout << "\nInvalid Input: Going back to Main Menu\n";
        break;
    }      
    return ;
}

int main()
{
  std::vector<std::string> tasks;
  std::string task;
  char choice;

  // Load existing tasks from file
  std::ifstream inputFile("tasks.txt");
  while (getline(inputFile, task))
  {
      tasks.push_back(task);
  }
  inputFile.close();

  do
  {
      std::cout << "\n\n\tMain Menu" << std::endl;
      std::cout << "\n\nA - Add a task" << std::endl;
      std::cout << "D - Delete a task" << std::endl;
      std::cout << "V - View tasks" << std::endl;
      std::cout << "Q - Quit" << std::endl;
      std::cout << "\nEnter your choice: ";
      std::cin >> choice;

      switch (choice)
      {
      case 'A':
      case 'a':
          std::cout << "\nEnter a task: ";
          std::cin.ignore(); // Clears the input buffer
          getline(std::cin, task);
          tasks.push_back(task);
          break;
      case 'D':
      case 'd':
          show_tasks(tasks);
          std::cout<<"\nEnter task no. to delete : ";
          int n;
          std::cin>>n;
          delete_task(tasks,n-1); 
          break;         
      case 'V':
      case 'v':
          show_tasks(tasks);
          break;
      case 'Q':
      case 'q':
        std::cout << "\nThanks for using this service\n";
        break;
      default:
        std::cout << "\nInvalid Input: Please enter from give characters\n";
        break;
      }
  } while (choice != 'Q' && choice != 'q');

  // Save tasks to file
  std::ofstream outputFile("tasks.txt");
  for (const auto &t : tasks)
  {
      outputFile << t << std::endl;
  }
  outputFile.close();

  return 0;
}