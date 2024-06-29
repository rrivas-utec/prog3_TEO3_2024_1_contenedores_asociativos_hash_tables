#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <utility> // Se encuentra la estructura std::pair
#include <functional>
#include <algorithm>

void ejemplo_pair() {
  std::pair<std::string, int> p1;
  p1 = {"jose", 10};
  std::cout << p1.first << " " << p1.second << std::endl;
  
  const auto& [k, v] = p1;
  std::cout << k << " " << v << std::endl;
}

void ejemplo_map_1 () {
  std::pair<std::string, int> p1;
  p1 = {"jose", 10};
  std::map<std::string, int, std::less<>> m1 = {p1, {"maria", 20}, {"alfredo", 15}};
  
  for (const auto& item: m1) {
    std::cout << item.first << " " << item.second << std::endl;
  }
  
  for (const auto& [k, v]: m1) {
    std::cout << k << " " << v << std::endl;
  }
}

void ejemplo_map_2 () {
  std::pair<std::string, int> p1;
  p1 = {"jose", 10};
  std::map<std::string, int, std::greater<>> m1 = {p1, {"maria", 20}, {"alfredo", 15}};
  
  for (const auto& item: m1) {
    std::cout << item.first << " " << item.second << std::endl;
  }
  
  for (const auto& [k, v]: m1) {
    std::cout << k << " " << v << std::endl;
  }
}

struct Rectangle {
  int base = 0;
  int altura = 0;
};

struct Coordenada {
  int x = 0;
  int y = 0;
//  bool operator<(const Coordenada& other) const {
//    return x < other.x && y < other.y;
//  }
//  bool operator>(const Coordenada& other) const {
//    return x > other.x && y > other.y;
//  }
};

void ejemplo_map_3 () {
  auto compare_less_coordenadas = [](auto a, auto b) {
    auto d_a = sqrt(a.x * a.x + a.y * a.y);
    auto d_b = sqrt(b.x * b.x + b.y * b.y);
    return d_a < d_b;
  };
  std::map<Coordenada, Rectangle, std::function<bool(Coordenada, Coordenada)>> m1(compare_less_coordenadas);
  m1 = {
      { Coordenada{10, 10}, Rectangle{100, 300} },
      { Coordenada{30, 14}, Rectangle{504, 204} },
      { Coordenada{30, 16}, Rectangle{506, 206} },
      { Coordenada{3, 0}, Rectangle{1500, 250} },
  };
  auto r1 = m1[Coordenada{30, 16}];
  std::cout << r1.base << " " << r1.altura << std::endl;
}

void ejemplo_set_1() {
  std::set<int> s1 = {1, 2, 3, 1, 2, 1, 1, 1, 2};
  std::vector<int> v1 = {10, 15, 12, 14, 12, 10, 14, 15, 15, 20};
  std::set<int, std::greater<>> s2(v1.begin(), v1.end());
  
  for (const auto& item: s1)
    std::cout << item << " ";
  std::cout << std::endl;
  for (const auto& item: s2)
    std::cout << item << " ";
  std::cout << std::endl;
}

void ejemplo_set_2() {
  std::set<int> s1 = {1, 2, 3, 5, 6, 7};
  std::set<int> s2 = {1, 2, 8, 9, 10, 11, 5};
  std::set<int> s_union;
  std::set<int> s_intersection;
  //  Realizar la union
  std::ranges::set_union(
      std::ranges::begin(s1), std::ranges::end(s1),
      std::ranges::begin(s2), std::ranges::end(s2),
      std::inserter(s_union, s_union.begin()));
  std::ranges::set_intersection(
      std::ranges::begin(s1), std::ranges::end(s1),
      std::ranges::begin(s2), std::ranges::end(s2),
      std::inserter(s_intersection, s_intersection.begin()));
  
  for (const auto& item: s_union) {
    std::cout << item << " ";
  }
  std::cout << std::endl;
  for (const auto& item: s_intersection) {
    std::cout << item << " ";
  }
  std::cout << std::endl;
}

void ejemplo_set_3() {
  std::set<int> s1 = {1, 2, 3, 5, 6, 7};
  std::set<int> s2 = {1, 2, 8, 9, 10, 11, 5};
  std::set<int> s_union;
  std::set<int> s_intersection;
  //  Realizar la union
  std::set_union(
      std::begin(s1), s1.find(5),
      std::begin(s2), s2.find(9),
      std::inserter(s_union, s_union.begin()));
  for (const auto& item: s_union) {
    std::cout << item << " ";
  }
  std::cout << std::endl;
}

int main() {
//  ejemplo_pair();
//  ejemplo_map_1();
//  ejemplo_map_2();
//  ejemplo_map_3();
//  ejemplo_set_1();
//  ejemplo_set_2();
  ejemplo_set_3();
  return 0;
}
