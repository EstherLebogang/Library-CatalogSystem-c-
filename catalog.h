// Catalog.h
#ifndef CATALOG_H
#define CATALOG_H

#include "Resource.h"
#include <unordered_map>
#include <vector>
#include <iostream>

class Catalog {
private:
    std::unordered_map<std::string, Resource*> resources;

public:
    ~Catalog();

    void addResource(Resource* resource);
    void removeResource(const std::string& ISBN);
    std::vector<Resource*> searchByTitle(const std::string& title) const;
    std::vector<Resource*> searchByAuthor(const std::string& author) const;
    std::vector<Resource*> searchByISBN(const std::string& ISBN) const;
    std::vector<Resource*> searchByType(const std::string& type) const;
    void generateReport() const;
};

#endif // CATALOG_H
