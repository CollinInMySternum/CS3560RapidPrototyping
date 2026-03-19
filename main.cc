#include <cstdlib>
#include <vector>
#include <map>
#include <string>

using namespace std;

struct Category {
    Category* OwningCategory;
    std::map<std::string, Category*> Categories;
}

int main() {
    Category* TopCategory = new Category();

    cout << "Hello, welcome to the app! \n";

    cout << "Open or Create a Category. \n";
    cout << "Open Categories: \n";

    Category* CurrentCategory = TopCategory;

    while(true) {

        int i = 0;

        cout << "\n";

        for(auto& Category:  CurrentCategory->Categories) {
            i++;
            cout << i << ": " << Category.first << "\n";
        }

        cout << "\n";
    
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