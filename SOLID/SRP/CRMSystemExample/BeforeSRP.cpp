#include <iostream>
#include <fstream>
#include <string>

/*  
    In this design, the CRMSystem class is responsible for data handling, notifications, 
    and logging. This makes the class complex and difficult to maintain. 
*/

class CRMSystem {
public:
    void fetchCustomerData(int customerId) {
        std::cout   << "Fetching data for customer ID: " 
                    << customerId << std::endl;
    }

    void updateCustomerData(int customerId, const std::string& newData) {
        std::cout   << "Updating data for customer ID: " 
                    << customerId << " with new data: " 
                    << newData << std::endl;
    }

    void sendEmailNotification(int customerId, const std::string& message) {
        std::cout   << "Sending email to customer ID: " 
                    << customerId << " with message: " 
                    << message << std::endl;
    }

    void logInteraction(int customerId, const std::string& interaction) {
        std::ofstream logFile("interaction_log.txt", std::ios::app);
        if (logFile.is_open()) {
            logFile << "Customer ID: " 
                    << customerId << " - Interaction: " 
                    << interaction << std::endl;
            logFile.close();
        } else {
            std::cerr << "Unable to open log file" << std::endl;
        }
    }

    void handleCustomer(    
                        int customerId, 
                        const std::string& newData, 
                        const std::string& message, 
                        const std::string& interaction
                        ) 
    {
        fetchCustomerData(customerId);
        updateCustomerData(customerId, newData);
        sendEmailNotification(customerId, message);
        logInteraction(customerId, interaction);
    }
};

int main(void)
{
    CRMSystem crmSystem;

    int customerId = 12345;
    std::string newData = "Updated Address";
    std::string message = "Your data has been updated";
    std::string interaction = "Called customer support";

    crmSystem.handleCustomer(customerId, newData, message, interaction);

    return 0;
}
