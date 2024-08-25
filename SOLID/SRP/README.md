# Single Responsibility Principle (SRP) Explained with Real-World Examples

## Introduction

The Single Responsibility Principle (SRP) is one of the five SOLID principles of object-oriented design. It states that a class should have only one reason to change, meaning that it should only have one responsibility or job. This principle helps in creating more maintainable, scalable, and understandable code by ensuring that each class or module handles a single concern.

In this README, we will explore SRP using three real-world examples: Single Sign-On (SSO), FileManager, and Customer Relationship Management (CRM) systems. These examples will illustrate how SRP can be applied to improve code structure and maintainability.

## 1. Single Sign-On (SSO)

### Scenario

In a Single Sign-On (SSO) system, a user can authenticate once and gain access to multiple applications without needing to log in separately to each one. 

### SRP Application

In an SRP-compliant SSO system, responsibilities are clearly divided:

- **Authentication Handler:** Manages the process of verifying user credentials and issuing authentication tokens.
- **Token Manager:** Handles the creation, validation, and expiration of authentication tokens.
- **User Database Manager:** Interacts with the database to fetch and manage user details.

By separating these responsibilities, each class or module focuses on a single aspect of the SSO system. This separation makes the system easier to maintain and extend. For example, changes to the token management logic don’t affect the authentication or database management code.

## 2. FileManager

### Scenario

A FileManager class is responsible for various file operations, such as reading from and writing to files.

### SRP Application

In an SRP-compliant FileManager system, responsibilities are separated into distinct classes:

- **File Reader:** Handles reading data from files.
- **File Writer:** Manages writing data to files.
- **File Logger:** Responsible for logging file operations, such as access and modification times.

By applying SRP, each class focuses on one specific type of file operation. This makes it easier to update or replace parts of the system without affecting others. For example, if you need to change how files are logged, you only need to modify the `FileLogger` class without touching the file reading or writing functionality.

## 3. Customer Relationship Management (CRM)

### Scenario

A CRM system is used to manage customer interactions and data across various touchpoints.

### SRP Application

In an SRP-compliant CRM system, responsibilities are divided into specialized classes:

- **Customer Data Handler:** Manages customer data, including fetching and updating information.
- **Customer Notifier:** Handles communication with customers, such as sending emails or alerts.
- **Customer Interaction Logger:** Logs interactions with customers for tracking and reporting purposes.

This separation allows each component to focus on a single responsibility. For example, if you need to update the way customer notifications are sent, you can modify the `CustomerNotifier` class without affecting data handling or logging.

## Conclusion

Applying the Single Responsibility Principle (SRP) helps create more organized, maintainable, and flexible code. By ensuring that each class or module has only one reason to change, you reduce the risk of unintended side effects when modifications are made. This approach not only enhances code quality but also makes it easier to manage and evolve complex systems over time.

Understanding and applying SRP can greatly benefit software development practices, leading to cleaner and more efficient codebases. Whether you are working on SSO systems, file management tools, or CRM platforms, keeping SRP in mind will help you build robust and scalable applications.
