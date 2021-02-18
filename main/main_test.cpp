// unordered_map::insert
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
int main ()
{
  unordered_map<std::string,double> myrecipe ; 
//   unordered_map<std::string,double>  mypantry = {{"milk",2.0},{"flour",1.5}};

  std::pair<std::string,double> myshopping ("baking powder",0.3);
  myrecipe.insert(myshopping);

//   myrecipe.insert (myshopping);                        // copy insertion
//   myrecipe.insert (std::make_pair<std::string,double>("eggs",6.0)); // move insertion
//   myrecipe.insert (mypantry.begin(), mypantry.end());  // range insertion
//   myrecipe.insert ( {{"sugar",0.8},{"salt",0.1}} );    // initializer list insertion

//   std::cout << "myrecipe contains:" << std::endl;
//   for (auto& x: myrecipe)
//     std::cout << x.first << ": " << x.second << std::endl;
    unordered_map<string,double>::iterator iter = myrecipe.find("baking powder");

    cout<<iter->first <<endl;
    cout<<iter->second<<endl;
  std::cout << std::endl;
  return 0;
}