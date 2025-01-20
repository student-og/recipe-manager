#include "RecipeManager.h"
#include <fstream>
#include <iostream>

void RecipeManager::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const auto& recipe : recipes) {
            file << recipe.serialize() << "\n";
        }
    } else {
        std::cerr << "Unable to open file for writing.\n";
    }
}

void RecipeManager::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        recipes.clear();
        std::string name, category, ingredient, comment;
        std::vector<std::string> ingredients, comments;
        int rating;  // Initialize rating as needed

        while (std::getline(file, name)) {
            std::getline(file, category);
            ingredients.clear();
            while (std::getline(file, ingredient) && ingredient != "---") {
                ingredients.push_back(ingredient);
            }
            comments.clear();
            while (std::getline(file, comment) && comment != "---") {
                comments.push_back(comment);
            }
            recipes.push_back(Recipe(name, category, ingredients, rating, comments));
        }
    } else {
        std::cerr << "Unable to open file for reading.\n";
    }
}
