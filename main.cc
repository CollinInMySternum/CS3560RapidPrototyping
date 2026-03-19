#include <cstdlib>
#include <vector>
#include <map>
#include <string>

using namespace std;

struct Category {
    Category* OwningCategory;
    std::map<std::string, Category> Categories;
}

int main() {
    Category TopCategory;

    cout << "Hello, welcome to the app!";

    cout << "Open or Create a Category.";
    cout << "Open Categories: ";

    Category* CurrentCategory = TopCategory;

    while(true) {

        for(int i = 0; i < Categories.size(); i++) {
            cout << i << ": " << Category.key << "\n";
        }
    
        string Command;
        cin >> command;
        
        if(command == "open") {
            cout << "Open Category by Name: ";
            string CategoryName;

            cin >> CategoryName;

            if(CurrentCategory.Categories.Contains(CategoryName)) {
                CurrentCategory = CurrentCategory.Categories[CategoryName];
            }

            else {
                cout << "Category not found.";
            }
        }
    
        if(command == ("close")) {
            if(CurrentCategory.OwningCategory == nullptr) {
                cout << "Cannot Close Category";
            }
            else {
                CurrentCategory = CurrentCategory.OwningCategory;
                cout << "Category Closed.";
            }
        }

        if(command == ("create")) {
            cout << "Name this Category: ";
            
            string CategoryName;
            cin >> CategoryName;
            
            cout << "New Category Created: " << CategoryName;
            
            Category* NewCategory = new Category;
            NewCategory->OwningCategory = CurrentCategory;

            CurrentCategory.Categories.insert({CategoryName, NewCategory});
        }
    }
}