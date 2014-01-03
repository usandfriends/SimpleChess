/*
 *  funcs.hpp
 *  ChessPlusPlus
 *
 *  Created by Ronak Gajrawala on 12/8/13.
 *  Copyright (c) 2013 Ronak Gajrawala. All rights reserved.
 */

#ifndef ChessPlusPlus_funcs_hpp
#define ChessPlusPlus_funcs_hpp

/**
 * The Utils class.
 * Holds utilities (functions) for the application.
 * These are functions that are miscellaneous and have no real "home".
 */
class Utils {
public:
    /**
     * Stringifies the piece on a certain square.
     * @see Pieces
     * @param piece_type The piece on the square.
     * @return The name of the piece on the square.
     */
    const char* PStringify(short);
    
    /**
     * Stringifies the background of a certain square.
     * @see Background
     * @param background_type The background of the square.
     * @return The name of the background on the square.
     */
    const char* BStringify(short);
    
    /**
     * Prints the pieces on the board to a file.
     * @see Pieces
     * @see PStringify
     * @param file The file to print to.
     * @param Board The board to print.
     */
    void print_r(FILE*, Board8);
    
    /**
     * Checks to see if the point (hpi, wpi) is in the rectangle (hp, wp, hp + h, wp + w).
     * @param hpi The x of the point.
     * @param wpi The y of the point.
     * @param hp The x of the rectangle.
     * @param wp The y of the rectangle.
     * @param h The height of the rectangle.
     * @param w The width of the rectangle.
     * @return True if the point is in the rectangle, false otherwise.
     */
    bool Contains(float, float, float, float, float, float);
} Utils;

////////// SOURCE //////////

const char* Utils::PStringify(short piece_type) {
    switch(piece_type) {
        case Pieces::White_Pawn: return "White Pawn";
        case Pieces::White_Rook: return "White Rook";
        case Pieces::White_Knight: return "White Knight";
        case Pieces::White_Bishop: return "White Bishop";
        case Pieces::White_King: return "White King";
        case Pieces::White_Queen: return "White Queen";
        case Pieces::Black_Pawn: return "Black Pawn";
        case Pieces::Black_Rook: return "Black Rook";
        case Pieces::Black_Knight: return "Black Knight";
        case Pieces::Black_Bishop: return "Black Bishop";
        case Pieces::Black_King: return "Black King";
        case Pieces::Black_Queen: return "Black Queen";
    }
    
    return "Empty";
}

const char* Utils::BStringify(short background_type) {
    switch(background_type) {
        case Background::Valid_Capture:
        case Background::Enemy_Capture: return "captured";
        case Background::Valid_Move:
        case Background::Enemy_Move: return "moved";
    }
    
    return "did nothing";
}

void Utils::print_r(FILE* file, Board8 Board) {
    for(unsigned short y = 0; y < 8; y++) {
        for(unsigned short x = 0; x < 8; x++) {
            fprintf(file, "%-13s", this->PStringify(Board[y][x]));
        }
        fputc('\n', file);
    }
}

bool Utils::Contains(float hpi, float wpi, float hp, float wp, float h, float w) {
    return hpi >= hp and hpi <= hp + h and wpi >= wp and wpi <= wp + w;
}

#endif