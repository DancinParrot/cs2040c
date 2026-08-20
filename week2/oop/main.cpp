#include "Animal.h"
#include "Cat.h"
#include "Dog.h"

int main() {
  Animal *dog1 = new Dog();
  Animal *cat1 = new Cat();

  dog1->talk();
  cat1->talk();

  return 0;
}
