#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QInputDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
    manager.loadFromFile("recipes.txt");
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_addRecipeButton_clicked() {
    bool ok;
    QString name = QInputDialog::getText(this, tr("Add Recipe"), tr("Recipe Name:"), QLineEdit::Normal, "", &ok);
    if (ok && !name.isEmpty()) {
        QString category = QInputDialog::getText(this, tr("Add Recipe"), tr("Category:"), QLineEdit::Normal, "", &ok);
        if (ok && !category.isEmpty()) {
            QString ingredients = QInputDialog::getText(this, tr("Add Recipe"), tr("Ingredients (comma separated):"), QLineEdit::Normal, "", &ok);
            if (ok && !ingredients.isEmpty()) {
                QString rating = QInputDialog::getText(this, tr("Add Recipe"), tr("Rating:"), QLineEdit::Normal, "", &ok);
                if (ok && !rating.isEmpty()) {
                    QString comments = QInputDialog::getText(this, tr("Add Recipe"), tr("Comments (newline separated):"), QLineEdit::Normal, "", &ok);
                    if (ok) {
                        std::vector<std::string> ingredientsVec;
                        for (const auto& ingredient : ingredients.split(",")) {
                            ingredientsVec.push_back(ingredient.toStdString());
                        }
                        Recipe recipe(name.toStdString(), category.toStdString(), ingredientsVec);
                        recipe.setRating(rating.toInt());
                        for (const auto& comment : comments.split("\n")) {
                            recipe.addComment(comment.toStdString());
                        }
                        manager.addRecipe(recipe);
                    }
                }
            }
        }
    }
}

void MainWindow::on_editRecipeButton_clicked() {
    // Implement edit recipe functionality
}

void MainWindow::on_deleteRecipeButton_clicked() {
    bool ok;
    QString name = QInputDialog::getText(this, tr("Delete Recipe"), tr("Recipe Name:"), QLineEdit::Normal, "", &ok);
    if (ok && !name.isEmpty()) {
        manager.deleteRecipe(name.toStdString());
    }
}

void MainWindow::on_searchByIngredientButton_clicked() {
    bool ok;
    QString ingredient = QInputDialog::getText(this, tr("Search by Ingredient"), tr("Ingredient:"), QLineEdit::Normal, "", &ok);
    if (ok && !ingredient.isEmpty()) {
        manager.searchByIngredient(ingredient.toStdString());
    }
}

void MainWindow::on_searchByNameButton_clicked() {
    bool ok;
    QString name = QInputDialog::getText(this, tr("Search by Name"), tr("Recipe Name:"), QLineEdit::Normal, "", &ok);
    if (ok && !name.isEmpty()) {
        manager.searchByName(name.toStdString());
    }
}

void MainWindow::on_listByCategoryButton_clicked() {
    bool ok;
    QString category = QInputDialog::getText(this, tr("List by Category"), tr("Category:"), QLineEdit::Normal, "", &ok);
    if (ok && !category.isEmpty()) {
        manager.listRecipesByCategory(category.toStdString());
    }
}

void MainWindow::on_searchByMultipleIngredientsButton_clicked() {
    bool ok;
    QString ingredients = QInputDialog::getText(this, tr("Search by Multiple Ingredients"), tr("Ingredients (comma separated):"), QLineEdit::Normal, "", &ok);
    if (ok && !ingredients.isEmpty()) {
        std::vector<std::string> ingredientsVec;
        for (const auto& ingredient : ingredients.split(",")) {
            ingredientsVec.push_back(ingredient.toStdString());
        }
        manager.searchByMultipleIngredients(ingredientsVec);
    }
}

void MainWindow::on_filterByRatingButton_clicked() {
    bool ok;
    int rating = QInputDialog::getInt(this, tr("Filter by Rating"), tr("Minimum Rating:"), 0, 0, 5, 1, &ok);
    if (ok) {
        manager.filterByRating(rating);
    }
}

void MainWindow::on_saveAndExitButton_clicked() {
    manager.saveToFile("recipes.txt");
    QApplication::quit();
}

