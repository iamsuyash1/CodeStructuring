#include <iostream>
#include <string>
#include <fstream>

/*
    In this example, we have focused on a part of the CRM system that handles customer data and interactions. 
    We have applied SRP by separating concerns into distinct classes:

    CustomerDataHandler: Manages customer data (e.g., fetching, updating).
    CustomerNotifier: Handles notifications to customers (e.g., sending emails, alerts).
    CustomerInteractionLogger: Logs interactions with customers.
    CRMManager: Orchestrates the use of the above classes.
*/

class CustomerDataHandler {
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
};

class CustomerNotifier {
public:
    void sendEmailNotification(int customerId, const std::string& message) {
        std::cout   << "Sending email to customer ID: " 
                    << customerId << " with message: " 
                    << message << std::endl;
    }
};

class CustomerInteractionLogger {
public:
    void logInteraction(int customerId, const std::string& interaction) {
        std::ofstream logFile("interaction_log.txt", std::ios::app);
        if (logFile.is_open()) {
            logFile << "Customer ID: " 
                    << customerId 
                    << " - Interaction: " 
                    << interaction << std::endl;

            logFile.close();
        } 
        else {
            std::cerr << "Unable to open log file" << std::endl;
        }
    }
};

class CRMManager {
private:
    CustomerDataHandler dataHandler;
    CustomerNotifier notifier;
    CustomerInteractionLogger interactionLogger;

public:
    void handleCustomer(
                        int customerId, 
                        const std::string& newData, 
                        const std::string& message, 
                        const std::string& interaction
                        ) 
    {
        dataHandler.fetchCustomerData(customerId);
        dataHandler.updateCustomerData(customerId, newData);
        notifier.sendEmailNotification(customerId, message);
        interactionLogger.logInteraction(customerId, interaction);
    }
};

int main(void) {
    CRMManager crmManager;
    int customerId = 12345;
    std::string newData = "Updated Address";
    std::string message = "Your data has been updated";
    std::string interaction = "Called customer support";

    crmManager.handleCustomer(customerId, newData, message, interaction);

    return 0;
}