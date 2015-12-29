#include "preferences.h"
#include "ui_preferences.h"

preferences::preferences(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::preferences)
{
    ui->setupUi(this);

    switch2gen();

    connect(ui->generalButton,SIGNAL(clicked(bool)),this,SLOT(switch2gen()));
    connect(ui->editButton,SIGNAL(clicked(bool)),this,SLOT(switch2edit()));
    connect(ui->themeButton,SIGNAL(clicked(bool)),this,SLOT(switch2theme()));
    connect(ui->cssButton,SIGNAL(clicked(bool)),this,SLOT(switch2css()));
}

void preferences::switch2gen() {
    set_env('g', true);
    set_env('e', false);
    set_env('t', false);
    set_env('c', false);

    return;
}

void preferences::switch2edit() {
    set_env('g', false);
    set_env('e', true);
    set_env('t', false);
    set_env('c', false);

    return;
}

void preferences::switch2theme() {
    set_env('g', false);
    set_env('e', false);
    set_env('t', true);
    set_env('c', false);

    return;
}

void preferences::switch2css() {
    set_env('g', false);
    set_env('e', false);
    set_env('t', false);
    set_env('c', true);

    return;
}

void preferences::set_env(char env_id, bool env) {

    switch (env_id) {
        case 'g': {
            ui->g_part1->setVisible(env);
            ui->g_part2->setVisible(env);
            ui->g_part3->setVisible(env);
            ui->g_part4->setVisible(env);
            ui->g_part5->setVisible(env);
            ui->g_part6->setVisible(env);
            ui->g_part7->setVisible(env);
            break;
        }
        case 'c': {
            ui->c_part1->setVisible(env);
            ui->c_part2->setVisible(env);
            ui->c_part3->setVisible(env);
            break;
        }
        case 'e': {
            ui->e_part1->setVisible(env);
            ui->e_part2->setVisible(env);
            ui->e_part3->setVisible(env);
            ui->e_part4->setVisible(env);
            ui->e_part5->setVisible(env);
            ui->e_part6->setVisible(env);
            ui->e_part7->setVisible(env);
            ui->e_part8->setVisible(env);
            ui->e_part9->setVisible(env);
            break;
        }
        case 't': {
            ui->t_part1->setVisible(env);
            ui->t_part2->setVisible(env);
            ui->t_part3->setVisible(env);
            break;
        }
    }

    return;
}

preferences::~preferences()
{
    delete ui;
}
