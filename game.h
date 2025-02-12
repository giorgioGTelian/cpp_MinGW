/****************/
// genral class of game
/***************/

#define WAIT_TIME 700

class game {
    public: 
    //argument game class: (board, pieces, pIO, screen)
    game(Board *pBoard, Pieces *pPieces, IO *pIO, Screen *pScreen, int pScreenheight);

    void DrawScene();
    

}