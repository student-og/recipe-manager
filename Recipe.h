#ifndef RECIPE_H
#define RECIPE_H

#include <string>

class Recipe {
public:
    // Add your members and methods here
    std::string name;
    std::string ingredient;
    int rating;

    // Constructor, methods, etc.
    Recipe(const std::string& name, const std::string& ingredient, int rating)
        : name(name), ingredient(ingredient), rating(rating) {}
};

#endif // RECIPE_H
