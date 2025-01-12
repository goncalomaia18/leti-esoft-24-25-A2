#include <iostream>
#include "Core/Headers/Controllers/restapi/AgentController.h"
using namespace std;

     int main() {
        std::string testInput = R"({
        "name": "John Doe",
        "email": "johndoe@example.com",
        "citizenCard": "AB123456",
        "phoneNumber": "+1234567890"
    })";

        AgentController controller;
        std::string email = controller.extractValue(testInput, "email");
        std::cout << "Extracted email: " << email << std::endl;

        return 0;
    }

