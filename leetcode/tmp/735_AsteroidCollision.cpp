#include "utils.h"

// std::vector<int>
// asteroidCollision_fail(std::vector<int> &asteroids) { // This code doesn't work
//   std::vector<int> asteroidStack;

//   auto willCollide = [](int a, int b) -> int { return (a ^ b) < 0 ? 1 : 0; };

//   auto getBiggerAsteroid = [](int a, int b) -> std::optional<int> {
//     auto comparator = std::abs(a) <=> std::abs(b);
//     if (comparator < 0)
//       return b;
//     else if (comparator > 0)
//       return a;
//     return std::nullopt;
//   };

//   // A function to compare the asteroid size

//   for (auto &ast : asteroids) {
//     if (!asteroidStack.empty()) {
//       auto asteroid1 = asteroidStack.back();
//       auto asteroid2 = ast;
//       if (willCollide(asteroid1, asteroid2)) {
//         asteroidStack.pop_back();
//         if (getBiggerAsteroid(asteroid1, asteroid2)) {
//           asteroidStack.push_back(
//               getBiggerAsteroid(asteroid1, asteroid2).value());
//         }
//       } else {
//         asteroidStack.push_back(ast);
//       }
//     } else {
//       asteroidStack.push_back(ast);
//     }
//   }

//   return asteroidStack;
// }

// std::vector<int>
// asteroidCollision_fail_2(std::vector<int> &asteroids) { // This code doesn't work
//   auto willCollide = [](int a, int b) -> int { return (a ^ b) < 0 ? 1 : 0; };
//   auto getBiggerAsteroid = [](int a, int b) -> std::optional<int> {
//     auto comparator = std::abs(a) <=> std::abs(b);
//     if (comparator < 0)
//       return b;
//     else if (comparator > 0)
//       return a;
//     return std::nullopt;
//   };

//   auto ast1 = asteroids.begin();
//   auto ast2 = asteroids.begin()+1;

  
// }

// void printVector(std::vector<int> vec) {
//   for(auto& i:vec) 
//     std::cout << i << ", ";
// }

// std::vector<int> asteroidCollision_fail3(const std::vector<int>& asteroids) {

//   if(asteroids.empty() || asteroids.size() == 1)
//     return asteroids;

//   const auto& first = asteroids.at(0);
//   const auto& second = asteroids.at(1);

//   auto willCollide = [](int a, int b) -> int { return (a ^ b) < 0 ? 1 : 0; };

  
// auto getBiggerAsteroid = [](int a, int b) -> std::optional<int> {
//     auto comparator = std::abs(a) <=> std::abs(b);
//     if (comparator < 0)
//       return b;
//     else if (comparator > 0)
//       return a;
//     return std::nullopt;
//   };


//   if(willCollide(first,second)) {
//     if(getBiggerAsteroid(first,second)) {
//       std::vector<int> remains = {getBiggerAsteroid(first,second).value()};
//       remains.insert(remains.end(), asteroids.begin()+2,asteroids.end());
//       return asteroidCollision_fail3(remains);
//     } else {
//       std::vector<int> remains(asteroids.begin()+2,asteroids.end());
//       return asteroidCollision_fail3(remains);
//     }
//   } 

// //This code fails has it not able to know when to stop!!! Recursion depth reached -> segmentation fault causes
//   std::vector<int> res = {first};
//   std::vector<int> remains(asteroids.begin()+1,asteroids.end());  
//   std::vector<int> res2 = asteroidCollision_fail3(remains);
//   res.insert(res.end(),res2.begin(),res2.end());
//   res = asteroidCollision_fail3(res);
//   return res;
// }


std::vector<int> asteroidCollision(std::vector<int> asteroids) {
  if(asteroids.size() == 1 || asteroids.empty())
    return asteroids;

  auto getAsteroids = [](const std::vector<int>& vec) -> std::pair<std::vector<int>::const_iterator,std::vector<int>::const_iterator> {
    return std::make_pair(vec.begin(),vec.begin()+1);
  };
  auto willCollide = [](int a, int b) -> int { return (a ^ b) < 0 ? 1 : 0; };

auto getSmallerAsteroid = [](std::vector<int>::const_iterator first, std::vector<int>::const_iterator second) -> std::optional<std::vector<int>::const_iterator> {
    auto comparator = std::abs(*first) <=> std::abs(*second);
    if (comparator < 0)
      return first;
    else if (comparator > 0)
      return second;

    return std::nullopt;
  };
  auto [first,second] = getAsteroids(asteroids);

  if(willCollide(*first,*second)) {
    if(getSmallerAsteroid(first,second)) {
      asteroids.erase(getSmallerAsteroid(first,second).value());
      asteroids.shrink_to_fit();
      
    } else {
      asteroids.erase(first);
      asteroids.erase(second);
      asteroids.shrink_to_fit();
    }
 } else if(second != asteroids.cend()-1)
  {
    std::vector<int> remains(second,asteroids.cend());
    remains =  asteroidCollision(remains);
    std::vector<int> temp = {*first};
    temp.insert(temp.end(),remains.begin(),remains.end());
    asteroids = asteroidCollision(temp);
  }
 return asteroids;
}




int main() {
  std::vector<int> asteroids = {-2,-1,1,2};
  std::vector<int> res = asteroidCollision(asteroids);

  std::cout << res.size() << std::endl;

  for(auto& i:res) 
    std::cout << i << ", ";

  return 0;
}
