#ifndef RECIPE_MANAGER_H
#define RECIPE_MANAGER_H

#include <string>
#include <vector>
#include "Recipe.h"

class RecipeManager {
public:
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);

private:
    std::vector<Recipe> recipes;
};

#endif // RECIPE_MANAGER_H
