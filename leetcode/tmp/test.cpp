#include"utils.h"
#include <iterator>

bool foo() {
    LOG("bar");
  return true;
}
void boolFooBar() {
  if(false && foo()) {
    LOG("foo");    
  }
  if(true && foo()) {
    LOG("bar");
  }
}

void strTest() {
  std::string s = "arpiku";
  LOG(s.substr(1,6));
}

void dist() {
  vecInt vv = {1,2,3}  ;
  std::cout << std::distance(vv.end(),vv.begin());
}


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

void transform() {
}

void reverseInsert() {
  std::vector<int> vv = {1,2,3,4,5,6,7,8,9};
  printVec(vv);
  std::vector<int>vv2 = {0};
  std::copy_backward(vv.rbegin(),vv.rbegin()+5,std::back_inserter(vv2));
  printVec(vv2);
}

void generate_n() {
  std::vector<int> vv = {1,2,3};
  std::vector<int> v2 = {0,0,0};
  std::vector<int> v3 = {};
  static int i;
  auto foobar = [](int n){return n*n;};
  std::generate_n(v2.begin(), 7,[&](){return foobar(vv[i++]);}); //v2 must have the memory already available
  printVec(v2);
}

void fills() {
  std::vector<int> vv = {1,1,1,1,1};
  std::fill(vv.begin(),vv.end(),-1);
  printVec(vv);
  std::ranges::fill(vv,-2); //This is different as the ranges based paradigm shift in C++20.
  printVec(vv);
}

int main() {
  dist();
   return 0;
}
