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
        std::cerr << "Unable to open file for writing.\n";
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
            recipes.push_back(Recipe(name, category, ingredients, rating, comments));
        }
        file.close();
    } else {
        std::cerr << "Unable to open file for reading.\n";
    }
}
