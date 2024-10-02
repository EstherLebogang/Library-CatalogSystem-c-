// Resource.cpp
#include "Resource.h"
#include <iostream>

void Resource::display() const {
    std::cout << "Title: " << title << "\n"
              << "Author: " << author << "\n"
              << "ISBN: " << ISBN << "\n"
              << "Type: " << type << "\n";
}

void Book::display() const {
    Resource::display();
    std::cout << "Publication Year: " << publicationYear << "\n";
}

void Journal::display() const {
    Resource::display();
    std::cout << "Volume: " << volume << "\n"
              << "Issue: " << issue << "\n";
}

void DigitalResource::display() const {
    Resource::display();
    std::cout << "URL: " << URL << "\n";
}
