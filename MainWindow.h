#include "MainWindow.h"
#include "RecipeManager.h"
#include <string>
#include <vector>

// Example function where the error was occurring
void MainWindow::on_addRecipeButton_clicked() {
    std::string name = ui->nameLineEdit->text().toStdString();
    std::string category = ui->categoryLineEdit->text().toStdString();
    std::vector<std::string> ingredientsVec;

    // Assuming you have a way to gather ingredients from the UI
    for (const auto& ingredient : ui->ingredientsListWidget->items()) {
        ingredientsVec.push_back(ingredient->text().toStdString());
    }

    int rating = ui->ratingSpinBox->value(); // Assuming you have a spinBox for rating
    std::vector<std::string> commentsVec;

    // Assuming you have a way to gather comments from the UI
    for (const auto& comment : ui->commentsListWidget->items()) {
        commentsVec.push_back(comment->text().toStdString());
    }

    Recipe recipe(name, category, ingredientsVec, rating, commentsVec);

    // Further processing
    manager.addRecipe(recipe);
}

// Other member functions can be updated similarly
