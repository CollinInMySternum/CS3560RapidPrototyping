#include <cstdlib>
#include <string>

#include "task.h"

struct Task {
public:
    std::string Title;
    std::string Body;

    bool bHasDueDate = false;
    
    std::string DueDate;
}