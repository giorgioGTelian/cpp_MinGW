/**********/
// Pieces bloc with rotation bloc tipe and position
/**********/
#ifndef _PIECES_
#define _PIECES_

class pieces {
    public:
        int GetBlockType (int pPiece, int pRotation, int pX, int pY);
        int GetXInitialPosition (int pPiece, int pRotation, int pX, int pY);
        int GetYInitialPosition (int pPiece, int pRotation, int pX, int pY);
        int GetXRotationPosition (int pPiece, int pRotation, int pX, int pY);
        int GetYRotationPosition (int pPiece, int pRotation, int pX, int pY);
};

#endif