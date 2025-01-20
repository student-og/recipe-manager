#include "RecipeManager.h"
#include <algorithm>
#include <iostream>
#include <fstream>

void RecipeManager::addRecipe(const Recipe& recipe) {
    recipes.push_back(recipe);
}

void RecipeManager::editRecipe(const std::string& name, const Recipe& newRecipe) {
    auto it = std::find_if(recipes.begin(), recipes.end(), [&name](const Recipe& r) { return r.getName() == name; });
    if (it != recipes.end()) {
        *it = newRecipe;
    } else {
        std::cout << "Recipe not found.\n";
    }
}

void RecipeManager::deleteRecipe(const std::string& name) {
    recipes.erase(std::remove_if(recipes.begin(), recipes.end(), [&name](const Recipe& r) { return r.getName() == name; }), recipes.end());
}

void RecipeManager::searchByIngredient(const std::string& ingredient) const {
    for (const auto& recipe : recipes) {
        if (std::find(recipe.getIngredients().begin(), recipe.getIngredients().end(), ingredient) != recipe.getIngredients().end()) {
            recipe.print();
        }
    }
}

void RecipeManager::searchByName(const std::string& name) const {
    for (const auto& recipe : recipes) {
        if (recipe.getName() == name) {
            recipe.print();
        }
    }
}

void RecipeManager::listRecipesByCategory(const std::string& category) const {
    for (const auto& recipe : recipes) {
        if (recipe.getCategory() == category) {
            recipe.print();
        }
    }
}

void RecipeManager::searchByMultipleIngredients(const std::vector<std::string>& ingredients) const {
    for (const auto& recipe : recipes) {
        bool allIngredientsFound = true;
        for (const auto& ingredient : ingredients) {
            if (std::find(recipe.getIngredients().begin(), recipe.getIngredients().end(), ingredient) == recipe.getIngredients().end()) {
                allIngredientsFound = false;
                break;
            }
        }
        if (allIngredientsFound) {
            recipe.print();
        }
    }
}

void RecipeManager::filterByRating(int rating) const {
    for (const auto& recipe : recipes) {
        if (recipe.getRating() >= rating) {
            recipe.print();
        }
    }
}

void RecipeManager::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const auto& recipe : recipes) {
            file << recipe.getName() << "\n";
            file << recipe.getCategory() << "\n";
            for (const auto& ingredient : recipe.getIngredients()) {
                file << ingredient << "\n";
            }
            file << recipe.getRating() << "\n";
            for (const auto& comment : recipe.getComments()) {
                file << comment << "\n";
            }
            file << "---\n";
        }
        file.close();
    } else {
        std::cout << "Unable to open file for writing.\n";
    }
}

void RecipeManager::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        recipes.clear();
        std::string name, category, ingredient, comment;
        std::vector<std::string> ingredients, comments;
        int rating;
        while (std::getline(file, name)) {
            std::getline(file, category);
            ingredients.clear();
            while (std::getline(file, ingredient) && ingredient != "---") {
                ingredients.push_back(ingredient);
            }
            file >> rating;
            file.ignore();
            comments.clear();
            while (std::getline(file, comment) && comment != "---") {
                comments.push_back(comment);
            }
            Recipe recipe(name, category, ingredients);
            recipe.setRating(rating);
            for (const auto& c : comments) {
                recipe.addComment(c);
            }
            recipes.push_back(recipe);
        }
        file.close();
    } else {
        std::cout << "Unable to open file for reading.\n";
    }
}

