#include <iostream>
#include <string>
#include <list>
#include <set>
#include <unordered_set>
#include <vector>

int main()
{
    /* std::list - A sequence (collection with a defined order) with
       fast insertion and removal, but slow indexing and searching.
    */
    // std::list<std::string> L{"Pear", "Grapefruit"};

    // L.push_front("Raspberry");
    // L.push_back("Pineapple");

    // std::cout << "Contents of L: ";
    // for (const auto &x : L)
    // {
    //     std::cout << x << " ";
    // }
    // std::cout << std::endl;

    // /* std::set - A collection with fast insertion, removal and searching,
    //    with no duplicates permitted and with elements always stored in
    //    ascending order.
    //    (The related std::multiset can be used if the collection must be
    //     allowed to contain duplicates)
    // */

    // std::set<std::string> S{"Pear", "Grapefruit", "Raspberry"};

    // S.insert("Pineapple");
    // S.insert("Apple");
    // S.insert("apple");

    // std::cout << "Contents of S: ";
    // for (const auto &x : S)
    // {
    //     std::cout << x << " ";
    // }
    // std::cout << std::endl;
    // // auto it = S.find("Apple");
    // // std::cout << (it == S.end()) << std::endl;
    // // ++it;
    // // std::cout << *it << std::endl;

    // /* std::unordered_set - A collection with fast insertion,
    //    removal and searching, with no duplicates permitted.
    //    Elements are stored in "no particular order" (that is, you should
    //    not assume the order of elements)
    //    (The related std::unordered_multiset can be used if the
    //     collection must be allowed to contain duplicates)
    // */

    std::unordered_set<std::string> US{"Pear", "Grapefruit", "Raspberry"};

    US.insert("Apple");
    US.insert("Pineapple");

    std::cout << "Contents of US: ";
    for (const auto &x : US)
    {
        std::cout << x << " ";
    }
    std::cout << US.size() << std::endl;

    /* std::vector - A sequence (collection with a defined order) with
       slow insertion, removal and searching, but fast indexing.
       Note that insertion and removal at the end of the vector is
       typically faster than insertion elsewhere.
    */

    std::vector<std::string> V{"Pear", "Grapefruit"};

    //V.push_front("Raspberry"); //Vectors have no push_front function
    V.insert(V.begin(), "Raspberry");
    V.push_back("Pineapple");

    std::cout << "Contents of V: ";
    for (const auto &x : V)
    {
        std::cout << x << " ";
    }
    //     std::cout << std::endl;

    //     return 0;
}
