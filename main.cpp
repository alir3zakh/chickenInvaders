#include <QApplication>
#include "game.h"

Game * game ;

int main(int argc, char * argv[]){
    QApplication app(argc, argv);

    game = new Game();
    game->show();
    app.setOverrideCursor(QCursor(QPixmap(":/img/Fork.png")));

    return app.exec();
}
