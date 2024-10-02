// Catalog.cpp
#include "Catalog.h"

Catalog::~Catalog() {
    for (auto& pair : resources) {
        delete pair.second;
    }
}

void Catalog::addResource(Resource* resource) {
    if (resources.find(resource->getISBN()) == resources.end()) {
        resources[resource->getISBN()] = resource;
    } else {
        std::cout << "Resource with ISBN " << resource->getISBN() << " already exists.\n";
    }
}

void Catalog::removeResource(const std::string& ISBN) {
    auto it = resources.find(ISBN);
    if (it != resources.end()) {
        delete it->second;
        resources.erase(it);
    } else {
        std::cout << "Resource with ISBN " << ISBN << " not found.\n";
    }
}

std::vector<Resource*> Catalog::searchByTitle(const std::string& title) const {
    std::vector<Resource*> results;
    for (const auto& pair : resources) {
        if (pair.second->getTitle() == title) {
            results.push_back(pair.second);
        }
    }
    return results;
}

std::vector<Resource*> Catalog::searchByAuthor(const std::string& author) const {
    std::vector<Resource*> results;
    for (const auto& pair : resources) {
        if (pair.second->getAuthor() == author) {
            results.push_back(pair.second);
        }
    }
    return results;
}

std::vector<Resource*> Catalog::searchByISBN(const std::string& ISBN) const {
    std::vector<Resource*> results;
    auto it = resources.find(ISBN);
    if (it != resources.end()) {
        results.push_back(it->second);
    }
    return results;
}

std::vector<Resource*> Catalog::searchByType(const std::string& type) const {
    std::vector<Resource*> results;
    for (const auto& pair : resources) {
        if (pair.second->getType() == type) {
            results.push_back(pair.second);
        }
    }
    return results;
}

void Catalog::generateReport() const {
    std::unordered_map<std::string, std::vector<Resource*>> reportMap;
    for (const auto& pair : resources) {
        reportMap[pair.second->getType()].push_back(pair.second);
    }

    for (const auto& typePair : reportMap) {
        std::cout << "\nType: " << typePair.first << "\n";
        for (const auto& resource : typePair.second) {
            resource->display();
            std::cout << "--------------------\n";
        }
    }
}
