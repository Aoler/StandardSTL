// Ex2_05.cpp
// Working with a list
#include <iostream>
#include <list>
#include <string>
#include <functional>


using std::list;
using std::string;

// List a range of elements
template<typename Iter>
void list_elements(Iter begin, Iter end)
{
  while (begin != end)
    std::cout << *begin++ << std::endl;
}

void List_Test()
{
    std::list<int> my_values {2,4,6,8,10};
    std::list<int> your_values {-2,1,7,9};
    my_values.merge(your_values);
    bool status = your_values.empty();
    
    std::list<int> hhh_values {4,6,8,9};
    auto compare = [] (int value1, int value2) {return value1 > value2;};
    my_values.merge(hhh_values); //合并元素
    my_values.sort();
    my_values.sort(compare);
    
    std::list<int> lll_values {3,5,7,9};
    my_values.splice(++std::begin(my_values), lll_values, ++std::begin(lll_values));
    my_values.splice(std::begin(my_values), lll_values, std::begin(lll_values), std::end(lll_values));

}

void Ex2_05()
{
    
  std::list<string> proverbs;

  // Read the proverbs
  std::cout << "Enter a few proverbs and enter an empty line to end:" << std::endl;
  string proverb;
  while (getline(std::cin, proverb, '\n'), !proverb.empty())
    proverbs.push_front(proverb);

  std::cout << "Go on, just one more:" << std::endl;
  getline(std::cin, proverb, '\n');
  proverbs.emplace_back(proverb);

  std::cout << "The elements in the list in reverse order are:" << std::endl;
  list_elements(proverbs.rbegin(), proverbs.rend());

  proverbs.sort();                               // Sort the proverbs in ascending sequence
  std::cout << "\nYour proverbs in ascending sequence are:" << std::endl;
  list_elements(std::begin(proverbs), std::end(proverbs));

  proverbs.sort(std::greater<string>());               // Sort the proverbs in descending sequence
  std::cout << "\nYour proverbs in descending sequence:" << std::endl;
  list_elements(std::begin(proverbs), std::end(proverbs));
}
