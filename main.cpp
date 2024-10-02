// main.cpp
#include "Catalog.h"
#include "Resource.h"
#include <iostream>
#include <limits>

void menu() {
    std::cout << "Library Catalog System\n";
    std::cout << "1. Add Resource\n";
    std::cout << "2. Remove Resource\n";
    std::cout << "3. Search Resource\n";
    std::cout << "4. Generate Report\n";
    std::cout << "5. Exit\n";
    std::cout << "Choose an option: ";
}

int main() {
    Catalog catalog;
    int choice;

    while (true) {
        menu();
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (choice == 5) break;

        std::string title, author, ISBN, type;
        int publicationYear, volume, issue;
        std::string URL;

        switch (choice) {
            case 1: // Add Resource
                std::cout << "Enter type (Book/Journal/Digital): ";
                std::getline(std::cin, type);
                std::cout << "Enter Title: ";
                std::getline(std::cin, title);
                std::cout << "Enter Author: ";
                std::getline(std::cin, author);
                std::cout << "Enter ISBN: ";
                std::getline(std::cin, ISBN);

                if (type == "Book") {
                    std::cout << "Enter Publication Year: ";
                    std::cin >> publicationYear;
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    catalog.addResource(new Book(title, author, ISBN, publicationYear));
                } else if (type == "Journal") {
                    std::cout << "Enter Volume: ";
                    std::cin >> volume;
                    std::cout << "Enter Issue: ";
                    std::cin >> issue;
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    catalog.addResource(new Journal(title, author, ISBN, volume, issue));
                } else if (type == "Digital") {
                    std::cout << "Enter URL: ";
                    std::getline(std::cin, URL);
                    catalog.addResource(new DigitalResource(title, author, ISBN, URL));
                } else {
                    std::cout << "Invalid type.\n";
                }
                break;

            case 2: // Remove Resource
                std::cout << "Enter ISBN to remove: ";
                std::getline(std::cin, ISBN);
                catalog.removeResource(ISBN);
                break;

            case 3: { // Search Resource
                std::cout << "Search by (Title/Author/ISBN/Type): ";
                std::getline(std::cin, type);
                if (type == "Title") {
                    std::cout << "Enter Title: ";
                    std::getline(std::cin, title);
                    auto results = catalog.searchByTitle(title);
                    for (const auto& resource : results) {
                        resource->display();
                        std::cout << "--------------------\n";
                    }
                } else if (type == "Author") {
                    std::cout << "Enter Author: ";
                    std::getline(std::cin, author);
                    auto results = catalog.searchByAuthor(author);
                    for (const auto& resource : results) {
                        resource->display();
                        std::cout << "--------------------\n";
                    }
                } else if (type == "ISBN") {
                    std::cout << "Enter ISBN: ";
                    std::getline(std::cin, ISBN);
                    auto results = catalog.searchByISBN(ISBN);
                    if (results.empty()) {
                        std::cout << "Resource not found.\n";
                    } else {
                        results[0]->display();
                    }
                } else if (type == "Type") {
                    std::cout << "Enter Type: ";
                    std::getline(std::cin, type);
                    auto results = catalog.searchByType(type);
                    for (const auto& resource : results) {
                        resource->display();
                        std::cout << "--------------------\n";
                    }
                } else {
                    std::cout << "Invalid search type.\n";
                }
                break;
            }

            case 4: // Generate Report
                catalog.generateReport();
                break;

            default:
                std::cout << "Invalid option.\n";
                break;
        }
    }

    return 0;
}
