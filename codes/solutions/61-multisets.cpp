#include <iostream>
#include <set>
#include <string>

int main()
{
    //Notice that elements are not added in alphabetical order
    std::multiset<std::string> S{"Pineapple"};

    //Try adding "Raspberry" multiple times
    S.insert("Raspberry");
    S.insert("Raspberry");
    S.insert("Raspberry");
    S.insert("Raspberry");

    S.insert("Apple");
    S.insert("Apple");
    S.insert("Apple");
    S.insert("Apple");
    S.insert("Pear");
    S.insert("Banana");
    S.insert("Peach");
    S.insert("Strawberry");

    std::cout << "Initial Contents: ";
    for (auto s : S)
    {
        std::cout << s << " ";
    }
    std::cout << std::endl;

    std::cout << "Occurrences of \"Raspberry\": " << S.count("Raspberry") << std::endl;

    //Erase all occurrences of the element "Apple"
    auto num_removed = S.erase("Apple");
    std::cout << "Return value of erase(\"Apple\"): " << num_removed << std::endl;
    std::cout << "after erasing apple: ";
    for (auto s : S)
    {
        std::cout << s << " ";
    }
    std::cout << std::endl;

    //Search for the key "Raspberry"
    //The .find() function returns an iterator, which will equal S.end() if the
    //element was not found (and otherwise will point to the found element).
    //The real type of the iterator is std::multiset<std::string>::iterator in this case
    auto search_iter = S.find("Raspberry");
    if (search_iter != S.end())
    {
        std::cout << "Deleting one occurrence of \"Raspberry\"." << std::endl;
        S.erase(search_iter);
    }
    else
    {
        std::cout << "The element \"Raspberry\" was not found." << std::endl;
    }

    std::cout << "Final Contents: ";
    for (auto s : S)
    {
        std::cout << s << " ";
    }
    std::cout << std::endl;

    return 0;
}
