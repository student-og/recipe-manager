#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "RecipeManager.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addRecipeButton_clicked();
    void on_editRecipeButton_clicked();
    void on_deleteRecipeButton_clicked();
    void on_searchByIngredientButton_clicked();
    void on_searchByNameButton_clicked();
    void on_listByCategoryButton_clicked();
    void on_searchByMultipleIngredientsButton_clicked();
    void on_filterByRatingButton_clicked();
    void on_saveAndExitButton_clicked();

private:
    Ui::MainWindow *ui;
    RecipeManager manager;
};

#endif // MAINWINDOW_H
