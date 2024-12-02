#include <iostream>
#include <list>
#include <utility>
#include <stdexcept>

/* pair_up(first_list, second_list)
   Given two lists, return a new list of pairs, where the element
   at position i is the pair
    ( element i of list 1, element i of list 2 ).
   If the two lists do not have equal sizes, throw std::runtime_error.
*/
std::list<std::pair<int, int>> pair_up(std::list<int> const &first_list, std::list<int> const &second_list)
{
    std::list<std::pair<int, int>> result{};
    if (first_list.size() != second_list.size())
        throw std::runtime_error("Can't pair up lists of unequal sizes");
    auto iter1{first_list.begin()};
    auto iter2{second_list.begin()};
    while (iter1 != first_list.end())
    {
        auto new_pair{std::make_pair(*iter1, *iter2)};
        result.push_back(new_pair);

        iter1++;
        iter2++;
    }
    return result;
}

/* list_sum_elementwise(first_list, second_list)
   Given two lists, return a new list of ints, where the element at position i
   is the sum of the elements at position i in the two source lists.

   If the two lists do not have equal sizes, throw std::runtime_error.
*/
std::list<int> list_sum_elementwise(std::list<int> const &first_list, std::list<int> const &second_list)
{
    std::list<int> result{};

    if (first_list.size() != second_list.size())
        throw std::runtime_error("Can't pair up lists of unequal sizes");

    auto iter1{first_list.begin()};
    auto iter2{second_list.begin()};

    while (iter1 != first_list.end())
    {
        auto res = (*iter1) + (*iter2);
        result.push_back(res);

        iter1++;
        iter2++;
    }
    return result;
}

/* list_difference_elementwise(first_list, second_list)
   Given two lists, return a new list of ints, where the element at position i
   is the difference of the elements at position i in the two source lists.

   If the two lists do not have equal sizes, throw std::runtime_error.
*/
std::list<int> list_difference_elementwise(std::list<int> const &first_list, std::list<int> const &second_list)
{
    std::list<int> result{};

    if (first_list.size() != second_list.size())
        throw std::runtime_error("Can't pair up lists of unequal sizes");

    auto iter1{first_list.begin()};
    auto iter2{second_list.begin()};

    while (iter1 != first_list.end())
    {
        auto res = (*iter1) - (*iter2);
        result.push_back(res);

        iter1++;
        iter2++;
    }
    return result;
}

/* list_maximum_elementwise(first_list, second_list)
   Given two lists, return a new list of ints, where the element at position i
   is the maximum of the elements at position i in the two source lists.

   If the two lists do not have equal sizes, throw std::runtime_error.
*/
std::list<int> list_maximum_elementwise(std::list<int> const &first_list, std::list<int> const &second_list)
{
    std::list<int> result{};

    if (first_list.size() != second_list.size())
        throw std::runtime_error("Can't pair up lists of unequal sizes");

    auto iter1{first_list.begin()};
    auto iter2{second_list.begin()};

    while (iter1 != first_list.end())
    {
        auto res = std::max((*iter1), (*iter2));
        result.push_back(res);

        iter1++;
        iter2++;
    }
    return result;
}

int main()
{
    std::list<int> L1{6, 116, 187};
    std::list<int> L2{10, 106, 111};

    std::list<std::pair<int, int>> Lp{pair_up(L1, L2)};

    std::cout << "Lp:" << std::endl;
    for (auto p : Lp)
    {
        std::cout << "Pair: (" << p.first << ", " << p.second << ")" << std::endl;
    }

    auto Lsum{list_sum_elementwise(L1, L2)};
    std::cout << "Sum of L1 and L2: " << std::endl;
    for (auto i : Lsum)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    auto Ldiff{list_difference_elementwise(L1, L2)};
    std::cout << "Difference of L1 and L2: " << std::endl;
    for (auto i : Ldiff)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    auto Lmax{list_maximum_elementwise(L1, L2)};
    std::cout << "Max. of L1 and L2: " << std::endl;
    for (auto i : Lmax)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
