#include <cstdlib>
#include <vector>
#include <map>
#include <string>
#include <iostream>

using namespace std;

struct Category {
    Category* OwningCategory;
    std::map<std::string, Category*> Categories;
};

void menu(){
    cout << "Manage and view Task Categories with the following text commands... \n";
    cout << "'create': create a category/task\n";
    cout << "'open': open a task to manange and view its subtasks \n";
    cout << "'close': close current task and return to parent tasklist \n";
    cout << "'exit': terminate the program\n\n";
}

int main() {
    Category* TopCategory = new Category();

    cout << "Hello, welcome to the app! This task tree holds definable task categories, which can be opened like folders to define tasks. \n" ;
    cout << "Tasks can also be opened and managed, with no limit to depth.  \n\n"; 

    menu();

    cout << "Open Categories: \n";

    Category* CurrentCategory = TopCategory;

    while(true) {

        int i = 0;

        

        for(auto& Category:  CurrentCategory->Categories) {
            i++;
            cout << i << ": " << Category.first << "\n";
        }

        if(i == 0){
            cout << " {No Categories}\n";
        }

        cout << "\n>>";
    
        string Command;
        cin >> Command;
        
        if(Command == "open") {
            cout << "Open Category by Name: ";
            string CategoryName;

            cin >> CategoryName;

            if(CurrentCategory->Categories.find(CategoryName) != CurrentCategory->Categories.end()) {
                CurrentCategory = CurrentCategory->Categories[CategoryName];

                cout << "\n";
                cout << "Category opened.\n";
            }

            else {
                cout << "\n";
                cout << "Category not found.\n";
            }
        }
    
        if(Command == ("close")) {
            if(CurrentCategory->OwningCategory == nullptr) {
                cout << "\n";
                cout << "Cannot Close Category\n";
            }
            else {
                CurrentCategory = CurrentCategory->OwningCategory;
                cout << "Category Closed.\n";
            }
        }

        if(Command == ("create")) {
            cout << "\n";
            cout << "Name this Category: ";
            
            string CategoryName;
            cin >> CategoryName;
            
            cout << "New Category Created: " << CategoryName << "\n";
            
            Category* NewCategory = new Category;
            NewCategory->OwningCategory = CurrentCategory;

            CurrentCategory->Categories.insert({CategoryName, NewCategory});
        }

        if(Command == ("exit")) return 0;
    }

    return 1;
}