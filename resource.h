// Resource.h
#ifndef RESOURCE_H
#define RESOURCE_H

#include <string>

class Resource {
protected:
    std::string title;
    std::string author;
    std::string ISBN;
    std::string type; // "Book", "Journal", "Digital"

public:
    Resource(const std::string& t, const std::string& a, const std::string& i, const std::string& ty)
        : title(t), author(a), ISBN(i), type(ty) {}

    virtual ~Resource() = default;

    virtual void display() const;

    const std::string& getTitle() const { return title; }
    const std::string& getAuthor() const { return author; }
    const std::string& getISBN() const { return ISBN; }
    const std::string& getType() const { return type; }
};

class Book : public Resource {
private:
    int publicationYear;

public:
    Book(const std::string& t, const std::string& a, const std::string& i, int pubYear)
        : Resource(t, a, i, "Book"), publicationYear(pubYear) {}

    void display() const override;
};

class Journal : public Resource {
private:
    int volume;
    int issue;

public:
    Journal(const std::string& t, const std::string& a, const std::string& i, int vol, int iss)
        : Resource(t, a, i, "Journal"), volume(vol), issue(iss) {}

    void display() const override;
};

class DigitalResource : public Resource {
private:
    std::string URL;

public:
    DigitalResource(const std::string& t, const std::string& a, const std::string& i, const std::string& url)
        : Resource(t, a, i, "Digital"), URL(url) {}

    void display() const override;
};

#endif // RESOURCE_H
