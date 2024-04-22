#include"utils.h"


 // std::set<char> ss;
 //  ss.insert('c');
 //  ss.insert('b');
 //  ss.insert('a');
 //  int a = 5;
 //  int b = 4;
 //  auto ax = a <=>  b ;

 //  auto testingFunc = [](int a) -> std::optional<bool> {return 1; };

 //   std::cout << (ax > 0) << std::endl;
 //  int result = (1 ^ 1) < 0 ? 1 : 0;

 //  if(testingFunc(5)) {
 //    LOG("EXECUTED");
 //  }

 //  //About vector functionality

 //  std::vector<int> v2 = {1,2,3,45};
 //  printVec(v2);
 //  LOG("vector test");
 //  auto itr = v2.cbegin();
 //  LOG(v2.capacity());
 //  LOG(v2.size());
 //  v2.erase(itr);
 //  LOG(v2.capacity());
 //  LOG(v2.size());
 //  v2.shrink_to_fit();
 //  LOG(v2.capacity());
 //  LOG(v2.size());
 //  LOG("vector test over");
  
 //  std::vector<int> vv = {1,2};

 //  LOG(*(vv.end()-1));

 //  std::cout << result  << std::endl;


// void findLongestPalindrome(std::string& s) {
//   auto start = s.begin();
//   auto end = s.end();

//   auto expandPalindrome = [&](auto left, auto right) {
//     while(left >= start && right < end && *left == *right ) {
//       --left;
//       ++right;
//     }
//     return std::make_tuple(left+1,right);
//   }
// }

void utilTest() {
  std::vector<int> v = {1,2,3,4};
  printVec(v);
  ListNode* head = intVecToList(v);
  printList(head);
  
}

int main() {
  utilTest();
   return 0;
}
