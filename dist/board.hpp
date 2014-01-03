/*
 *  board.hpp
 *  ChessPlusPlus
 *
 *  Created by Ronak Gajrawala on 12/21/13.
 *  Copyright (c) 2013 Ronak Gajrawala. All rights reserved.
 */

#ifndef ChessPlusPlus_board_hpp
#define ChessPlusPlus_board_hpp

/**
 * Piece IDs for the board.
 */
class Pieces {
public:
    static const short Empty = 0, /**< Nothing will be printed. */
                       White_Pawn = 1, /**< A White Pawn will be printed. */
                       White_Rook = 2, /**< A White Rook (Castle) will be printed. */
                       White_Knight = 3, /**< A White Knight (Horse) will be printed. */
                       White_Bishop = 4, /**< A White Bishop will be printed. */
                       White_Queen = 5, /**< A White Queen will be printed. */
                       White_King = 6, /**< A White King will be printed. */
                       Black_Pawn = 7, /**< A Black Pawn will be printed. */
                       Black_Rook = 8, /**< A Black Rook (Castle) will be printed. */
                       Black_Knight = 9, /**< A Black Knight (Horse) will be printed. */
                       Black_Bishop = 10, /**< A Black Bishop will be printed. */
                       Black_Queen = 11, /**< A Black Queen will be printed. */
                       Black_King = 12; /**< A Black King will be printed. */
    
    /**
     * Checks if the piece is empty.
     * @see Empty
     * @param piece The piece to check.
     * @return True if the piece is empty, otherwise false.
     */
    bool isEmpty(const short);
    
    /**
     * Checks if the piece is black.
     * @see Black_Pawn
     * @see Black_Rook
     * @see Black_Knight
     * @see Black_Bishop
     * @see Black_Queen
     * @see Black_King
     * @param piece The piece to check.
     * @return True if the piece is black, otherwise false.
     */
    bool isBlack(const short);
    
    /**
     * Checks if the piece if white.
     * @see White_Pawn
     * @see White_Rook
     * @see White_Knight
     * @see White_Bishop
     * @see White_Queen
     * @see White_King
     * @param piece The piece to check.
     * @return True if the piece is white, otherwise false.
     */
    bool isWhite(const short);
} Pieces;

/**
 * The Background class.
 * Background IDs for the board.
 */
class Background {
public:
    static const short Empty = 0, /**< Nothing will be printed. */
                       Valid_Move = 1, /**< A filled green square will be printed. */
                       Valid_Capture = 2, /**< A green-bordered square will be printed. */
                       Enemy_Capture = 3, /**< A filled red square will be printed. */
                       Enemy_Move = 4; /**< A red-bordered square will be printed. */
} Background;

typedef std::array<std::array<short, 8>, 8> Board8; /**< Typedef for board. */

/**
 * The Texture class.
 * The images will be loaded into these textures for continuous use.
 * Textures::Initialize must first be called.
 */
class Textures {
public:
    sf::Texture ChessBoard, /**< The board image (chessboard.png) will be loaded into here. */
                Enemy_Capture, /**< The enemy capture (red-bordered square) image (enemy_capture.png) will be loaded into here. */
                Enemy_Move, /**< The enemy move (filled red square) image (enemy_move.png) will be loaded into here. */
                Valid_Capture, /**< The valid capture (green-bordered square) image (valid_capture.png) will be loaded into here. */
                Valid_Move; /**< The valid move (filled green square) image (valid_move.png) will be loaded into here. */
    
    /**
     * The Textures::Black class.
     * The black pieces' images will be stored here for use.
     */
    class Black {
    public:
        sf::Texture Pawn, /**< The piece image for a Black Pawn (black_pawn.png). */
                    Rook, /**< The piece image for a Black Rook (Castle) (black_rook.png). */
                    Knight, /**< The piece image for a Black Knight (Horse) (black_knight.png). */
                    Bishop, /**< The piece image for a Black Bishop (black_bishop.png). */
                    King, /**< The piece image for a Black King (black_king.png). */
                    Queen; /**< The piece image for a Black Queen (black_queen.png). */
    } Black;
    
    /**
     * The Textures::White class.
     * The white pieces' images will be stored here for use.
     */
    class White {
    public:
        sf::Texture Pawn, /**< The piece image for a White Pawn (white_pawn.png). */
                    Rook, /**< The piece image for a White Rook (Castle) (white_rook.png). */
                    Knight, /**< The piece image for a White Knight (Horse) (white_knight.png). */
                    Bishop, /**< The piece image for a White Bishop (white_bishop.png). */
                    King, /**< The piece image for a White King (white_king.png). */
                    Queen; /**< The piece image for a White Queen (white_queen.png). */
    } White;
    
    /**
     * Loads all the textures with their images.
     */
    void Initialize(void);
} Textures;

////////// SOURCE //////////

void Textures::Initialize(void) {
    if(!this->ChessBoard.loadFromFile(GetResource("chessboard.png"))) {
        exit(EXIT_FAILURE);
    }
    
    if(!this->Black.Pawn.loadFromFile(GetResource("black_pawn.png"))) {
        exit(EXIT_FAILURE);
    }
    
    if(!this->Black.Rook.loadFromFile(GetResource("black_rook.png"))) {
        exit(EXIT_FAILURE);
    }
    
    if(!this->Black.Knight.loadFromFile(GetResource("black_knight.png"))) {
        exit(EXIT_FAILURE);
    }
    
    if(!this->Black.Bishop.loadFromFile(GetResource("black_bishop.png"))) {
        exit(EXIT_FAILURE);
    }
    
    if(!this->Black.Queen.loadFromFile(GetResource("black_queen.png"))) {
        exit(EXIT_FAILURE);
    }
    
    if(!this->Black.King.loadFromFile(GetResource("black_king.png"))) {
        exit(EXIT_FAILURE);
    }
    
    if(!this->White.Pawn.loadFromFile(GetResource("white_pawn.png"))) {
        exit(EXIT_FAILURE);
    }
    
    if(!this->White.Rook.loadFromFile(GetResource("white_rook.png"))) {
        exit(EXIT_FAILURE);
    }
    
    if(!this->White.Knight.loadFromFile(GetResource("white_knight.png"))) {
        exit(EXIT_FAILURE);
    }
    
    if(!this->White.Bishop.loadFromFile(GetResource("white_bishop.png"))) {
        exit(EXIT_FAILURE);
    }
    
    if(!this->White.Queen.loadFromFile(GetResource("white_queen.png"))) {
        exit(EXIT_FAILURE);
    }
    
    if(!this->White.King.loadFromFile(GetResource("white_king.png"))) {
        exit(EXIT_FAILURE);
    }
    
    if(!this->Valid_Move.loadFromFile(GetResource("valid_move.png"))) {
        exit(EXIT_FAILURE);
    }
    
    if(!this->Valid_Capture.loadFromFile(GetResource("valid_capture.png"))) {
        exit(EXIT_FAILURE);
    }
    
    if(!this->Enemy_Move.loadFromFile(GetResource("enemy_move.png"))) {
        exit(EXIT_FAILURE);
    }
    
    if(!this->Enemy_Capture.loadFromFile(GetResource("enemy_capture.png"))) {
        exit(EXIT_FAILURE);
    }
}

bool Pieces::isEmpty(const short piece) {
    return piece == 0;
}

bool Pieces::isBlack(const short piece) {
    return piece > 6;
}

bool Pieces::isWhite(const short piece) {
    return piece > 0 and piece < 7;
}

#endif