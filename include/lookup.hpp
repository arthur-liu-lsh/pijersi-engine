#ifndef LOOKUP_HPP
#define LOOKUP_HPP

#include <cstdint>
#include <cstdlib>
#include <vector>

using std::vector;

namespace PijersiEngine::Lookup
{
    /* An array associating a cell index to the indices of its 1-range neighbours
    The array is composed of 45 segments of length 7.
    The first element of each segment is the number of neighbours of the corresponding cell.
    The rest of the elements are the indices of the neighbouring cells. Unused values are set to SIZE_MAX. */
    constexpr size_t neighbours[315] = {
        3, 1, 6, 7, SIZE_MAX, SIZE_MAX, SIZE_MAX,
        4, 0, 2, 7, 8, SIZE_MAX, SIZE_MAX,
        4, 1, 3, 8, 9, SIZE_MAX, SIZE_MAX,
        4, 2, 4, 9, 10, SIZE_MAX, SIZE_MAX,
        4, 3, 5, 10, 11, SIZE_MAX, SIZE_MAX,
        3, 4, 11, 12, SIZE_MAX, SIZE_MAX, SIZE_MAX,
        3, 0, 7, 13, SIZE_MAX, SIZE_MAX, SIZE_MAX,
        6, 0, 1, 6, 8, 13, 14,
        6, 1, 2, 7, 9, 14, 15,
        6, 2, 3, 8, 10, 15, 16,
        6, 3, 4, 9, 11, 16, 17,
        6, 4, 5, 10, 12, 17, 18,
        3, 5, 11, 18, SIZE_MAX, SIZE_MAX, SIZE_MAX,
        5, 6, 7, 14, 19, 20, SIZE_MAX,
        6, 7, 8, 13, 15, 20, 21,
        6, 8, 9, 14, 16, 21, 22,
        6, 9, 10, 15, 17, 22, 23,
        6, 10, 11, 16, 18, 23, 24,
        5, 11, 12, 17, 24, 25, SIZE_MAX,
        3, 13, 20, 26, SIZE_MAX, SIZE_MAX, SIZE_MAX,
        6, 13, 14, 19, 21, 26, 27,
        6, 14, 15, 20, 22, 27, 28,
        6, 15, 16, 21, 23, 28, 29,
        6, 16, 17, 22, 24, 29, 30,
        6, 17, 18, 23, 25, 30, 31,
        3, 18, 24, 31, SIZE_MAX, SIZE_MAX, SIZE_MAX,
        5, 19, 20, 27, 32, 33, SIZE_MAX,
        6, 20, 21, 26, 28, 33, 34,
        6, 21, 22, 27, 29, 34, 35,
        6, 22, 23, 28, 30, 35, 36,
        6, 23, 24, 29, 31, 36, 37,
        5, 24, 25, 30, 37, 38, SIZE_MAX,
        3, 26, 33, 39, SIZE_MAX, SIZE_MAX, SIZE_MAX,
        6, 26, 27, 32, 34, 39, 40,
        6, 27, 28, 33, 35, 40, 41,
        6, 28, 29, 34, 36, 41, 42,
        6, 29, 30, 35, 37, 42, 43,
        6, 30, 31, 36, 38, 43, 44,
        3, 31, 37, 44, SIZE_MAX, SIZE_MAX, SIZE_MAX,
        3, 32, 33, 40, SIZE_MAX, SIZE_MAX, SIZE_MAX,
        4, 33, 34, 39, 41, SIZE_MAX, SIZE_MAX,
        4, 34, 35, 40, 42, SIZE_MAX, SIZE_MAX,
        4, 35, 36, 41, 43, SIZE_MAX, SIZE_MAX,
        4, 36, 37, 42, 44, SIZE_MAX, SIZE_MAX,
        3, 37, 38, 43, SIZE_MAX, SIZE_MAX, SIZE_MAX
    };

    /* An array associating a cell index to the indices of its 2-range neighbours
    The array is composed of 45 segments of length 7.
    The first element of each segment is the number of neighbours of the corresponding cell.
    The rest of the elements are the indices of the neighbouring cells. Unused values are set to SIZE_MAX. */
    constexpr size_t neighbours2[315] = { 
        2, 2, 14, SIZE_MAX, SIZE_MAX, SIZE_MAX, SIZE_MAX,
        3, 3, 13, 15, SIZE_MAX, SIZE_MAX, SIZE_MAX,
        4, 0, 4, 14, 16, SIZE_MAX, SIZE_MAX,
        4, 1, 5, 15, 17, SIZE_MAX, SIZE_MAX,
        3, 2, 16, 18, SIZE_MAX, SIZE_MAX, SIZE_MAX,
        2, 3, 17, SIZE_MAX, SIZE_MAX, SIZE_MAX, SIZE_MAX,
        2, 8, 20, SIZE_MAX, SIZE_MAX, SIZE_MAX, SIZE_MAX,
        3, 9, 19, 21, SIZE_MAX, SIZE_MAX, SIZE_MAX,
        4, 6, 10, 20, 22, SIZE_MAX, SIZE_MAX,
        4, 7, 11, 21, 23, SIZE_MAX, SIZE_MAX,
        4, 8, 12, 22, 24, SIZE_MAX, SIZE_MAX,
        3, 9, 23, 25, SIZE_MAX, SIZE_MAX, SIZE_MAX,
        2, 10, 24, SIZE_MAX, SIZE_MAX, SIZE_MAX, SIZE_MAX,
        3, 1, 15, 27, SIZE_MAX, SIZE_MAX, SIZE_MAX,
        5, 0, 2, 16, 26, 28, SIZE_MAX,
        6, 1, 3, 13, 17, 27, 29,
        6, 2, 4, 14, 18, 28, 30,
        5, 3, 5, 15, 29, 31, SIZE_MAX,
        3, 4, 16, 30, SIZE_MAX, SIZE_MAX, SIZE_MAX,
        3, 7, 21, 33, SIZE_MAX, SIZE_MAX, SIZE_MAX,
        5, 6, 8, 22, 32, 34, SIZE_MAX,
        6, 7, 9, 19, 23, 33, 35,
        6, 8, 10, 20, 24, 34, 36,
        6, 9, 11, 21, 25, 35, 37,
        5, 10, 12, 22, 36, 38, SIZE_MAX,
        3, 11, 23, 37, SIZE_MAX, SIZE_MAX, SIZE_MAX,
        3, 14, 28, 40, SIZE_MAX, SIZE_MAX, SIZE_MAX,
        5, 13, 15, 29, 39, 41, SIZE_MAX,
        6, 14, 16, 26, 30, 40, 42,
        6, 15, 17, 27, 31, 41, 43,
        5, 16, 18, 28, 42, 44, SIZE_MAX,
        3, 17, 29, 43, SIZE_MAX, SIZE_MAX, SIZE_MAX,
        2, 20, 34, SIZE_MAX, SIZE_MAX, SIZE_MAX, SIZE_MAX,
        3, 19, 21, 35, SIZE_MAX, SIZE_MAX, SIZE_MAX,
        4, 20, 22, 32, 36, SIZE_MAX, SIZE_MAX,
        4, 21, 23, 33, 37, SIZE_MAX, SIZE_MAX,
        4, 22, 24, 34, 38, SIZE_MAX, SIZE_MAX,
        3, 23, 25, 35, SIZE_MAX, SIZE_MAX, SIZE_MAX,
        2, 24, 36, SIZE_MAX, SIZE_MAX, SIZE_MAX, SIZE_MAX,
        2, 27, 41, SIZE_MAX, SIZE_MAX, SIZE_MAX, SIZE_MAX,
        3, 26, 28, 42, SIZE_MAX, SIZE_MAX, SIZE_MAX,
        4, 27, 29, 39, 43, SIZE_MAX, SIZE_MAX,
        4, 28, 30, 40, 44, SIZE_MAX, SIZE_MAX,
        3, 29, 31, 41, SIZE_MAX, SIZE_MAX, SIZE_MAX,
        2, 30, 42, SIZE_MAX, SIZE_MAX, SIZE_MAX, SIZE_MAX
    };

    // Associates a piece's uint8_t representation to an index that can be used in other lookup tables
    constexpr size_t pieceToIndex[256] {
        34,
        13,
        34,
        30,
        34,
        14,
        34,
        31,
        34,
        15,
        34,
        32,
        34,
        16,
        34,
        33,
        34,
        0,
        34,
        34,
        34,
        1,
        34,
        34,
        34,
        2,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        17,
        34,
        34,
        34,
        18,
        34,
        34,
        34,
        19,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        3,
        34,
        34,
        34,
        4,
        34,
        34,
        34,
        5,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        20,
        34,
        34,
        34,
        21,
        34,
        34,
        34,
        22,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        6,
        34,
        34,
        34,
        7,
        34,
        34,
        34,
        8,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        23,
        34,
        34,
        34,
        24,
        34,
        34,
        34,
        25,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        9,
        34,
        34,
        34,
        10,
        34,
        34,
        34,
        11,
        34,
        34,
        34,
        12,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        34,
        26,
        34,
        34,
        34,
        27,
        34,
        34,
        34,
        28,
        34,
        34,
        34,
        29
    };

    // Associates a piece's type index and cell index to its score, index = pieceIndex*45 + cellIndex
    constexpr int64_t pieceScores[1575] {
        76790,
        76790,
        76790,
        76790,
        76790,
        76790,
        260,
        260,
        260,
        260,
        260,
        260,
        260,
        250,
        250,
        250,
        250,
        250,
        250,
        220,
        220,
        220,
        220,
        220,
        220,
        220,
        210,
        210,
        210,
        210,
        210,
        210,
        190,
        190,
        190,
        190,
        190,
        190,
        190,
        116,
        116,
        116,
        116,
        116,
        116,
        76790,
        76790,
        76790,
        76790,
        76790,
        76790,
        260,
        260,
        260,
        260,
        260,
        260,
        260,
        250,
        250,
        250,
        250,
        250,
        250,
        220,
        220,
        220,
        220,
        220,
        220,
        220,
        210,
        210,
        210,
        210,
        210,
        210,
        190,
        190,
        190,
        190,
        190,
        190,
        190,
        116,
        116,
        116,
        116,
        116,
        116,
        76790,
        76790,
        76790,
        76790,
        76790,
        76790,
        260,
        260,
        260,
        260,
        260,
        260,
        260,
        250,
        250,
        250,
        250,
        250,
        250,
        220,
        220,
        220,
        220,
        220,
        220,
        220,
        210,
        210,
        210,
        210,
        210,
        210,
        190,
        190,
        190,
        190,
        190,
        190,
        190,
        116,
        116,
        116,
        116,
        116,
        116,
        76790,
        76790,
        76790,
        76790,
        76790,
        76790,
        260,
        260,
        260,
        260,
        260,
        260,
        260,
        250,
        250,
        250,
        250,
        250,
        250,
        220,
        220,
        220,
        220,
        220,
        220,
        220,
        210,
        210,
        210,
        210,
        210,
        210,
        190,
        190,
        190,
        190,
        190,
        190,
        190,
        116,
        116,
        116,
        116,
        116,
        116,
        76790,
        76790,
        76790,
        76790,
        76790,
        76790,
        260,
        260,
        260,
        260,
        260,
        260,
        260,
        250,
        250,
        250,
        250,
        250,
        250,
        220,
        220,
        220,
        220,
        220,
        220,
        220,
        210,
        210,
        210,
        210,
        210,
        210,
        190,
        190,
        190,
        190,
        190,
        190,
        190,
        116,
        116,
        116,
        116,
        116,
        116,
        76790,
        76790,
        76790,
        76790,
        76790,
        76790,
        260,
        260,
        260,
        260,
        260,
        260,
        260,
        250,
        250,
        250,
        250,
        250,
        250,
        220,
        220,
        220,
        220,
        220,
        220,
        220,
        210,
        210,
        210,
        210,
        210,
        210,
        190,
        190,
        190,
        190,
        190,
        190,
        190,
        116,
        116,
        116,
        116,
        116,
        116,
        76790,
        76790,
        76790,
        76790,
        76790,
        76790,
        260,
        260,
        260,
        260,
        260,
        260,
        260,
        250,
        250,
        250,
        250,
        250,
        250,
        220,
        220,
        220,
        220,
        220,
        220,
        220,
        210,
        210,
        210,
        210,
        210,
        210,
        190,
        190,
        190,
        190,
        190,
        190,
        190,
        116,
        116,
        116,
        116,
        116,
        116,
        76790,
        76790,
        76790,
        76790,
        76790,
        76790,
        260,
        260,
        260,
        260,
        260,
        260,
        260,
        250,
        250,
        250,
        250,
        250,
        250,
        220,
        220,
        220,
        220,
        220,
        220,
        220,
        210,
        210,
        210,
        210,
        210,
        210,
        190,
        190,
        190,
        190,
        190,
        190,
        190,
        116,
        116,
        116,
        116,
        116,
        116,
        76790,
        76790,
        76790,
        76790,
        76790,
        76790,
        260,
        260,
        260,
        260,
        260,
        260,
        260,
        250,
        250,
        250,
        250,
        250,
        250,
        220,
        220,
        220,
        220,
        220,
        220,
        220,
        210,
        210,
        210,
        210,
        210,
        210,
        190,
        190,
        190,
        190,
        190,
        190,
        190,
        116,
        116,
        116,
        116,
        116,
        116,
        76790,
        76790,
        76790,
        76790,
        76790,
        76790,
        260,
        260,
        260,
        260,
        260,
        260,
        260,
        250,
        250,
        250,
        250,
        250,
        250,
        220,
        220,
        220,
        220,
        220,
        220,
        220,
        210,
        210,
        210,
        210,
        210,
        210,
        190,
        190,
        190,
        190,
        190,
        190,
        190,
        116,
        116,
        116,
        116,
        116,
        116,
        76790,
        76790,
        76790,
        76790,
        76790,
        76790,
        260,
        260,
        260,
        260,
        260,
        260,
        260,
        250,
        250,
        250,
        250,
        250,
        250,
        220,
        220,
        220,
        220,
        220,
        220,
        220,
        210,
        210,
        210,
        210,
        210,
        210,
        190,
        190,
        190,
        190,
        190,
        190,
        190,
        116,
        116,
        116,
        116,
        116,
        116,
        76790,
        76790,
        76790,
        76790,
        76790,
        76790,
        260,
        260,
        260,
        260,
        260,
        260,
        260,
        250,
        250,
        250,
        250,
        250,
        250,
        220,
        220,
        220,
        220,
        220,
        220,
        220,
        210,
        210,
        210,
        210,
        210,
        210,
        190,
        190,
        190,
        190,
        190,
        190,
        190,
        116,
        116,
        116,
        116,
        116,
        116,
        130,
        130,
        130,
        130,
        130,
        130,
        130,
        130,
        130,
        130,
        130,
        130,
        130,
        130,
        130,
        130,
        130,
        130,
        130,
        130,
        130,
        130,
        130,
        130,
        130,
        130,
        130,
        130,
        130,
        130,
        130,
        130,
        130,
        130,
        130,
        130,
        130,
        130,
        130,
        130,
        130,
        130,
        130,
        130,
        130,
        38400,
        38400,
        38400,
        38400,
        38400,
        38400,
        135,
        135,
        135,
        135,
        135,
        135,
        135,
        130,
        130,
        130,
        130,
        130,
        130,
        115,
        115,
        115,
        115,
        115,
        115,
        115,
        110,
        110,
        110,
        110,
        110,
        110,
        100,
        100,
        100,
        100,
        100,
        100,
        100,
        63,
        63,
        63,
        63,
        63,
        63,
        38400,
        38400,
        38400,
        38400,
        38400,
        38400,
        135,
        135,
        135,
        135,
        135,
        135,
        135,
        130,
        130,
        130,
        130,
        130,
        130,
        115,
        115,
        115,
        115,
        115,
        115,
        115,
        110,
        110,
        110,
        110,
        110,
        110,
        100,
        100,
        100,
        100,
        100,
        100,
        100,
        63,
        63,
        63,
        63,
        63,
        63,
        38400,
        38400,
        38400,
        38400,
        38400,
        38400,
        135,
        135,
        135,
        135,
        135,
        135,
        135,
        130,
        130,
        130,
        130,
        130,
        130,
        115,
        115,
        115,
        115,
        115,
        115,
        115,
        110,
        110,
        110,
        110,
        110,
        110,
        100,
        100,
        100,
        100,
        100,
        100,
        100,
        63,
        63,
        63,
        63,
        63,
        63,
        70,
        70,
        70,
        70,
        70,
        70,
        70,
        70,
        70,
        70,
        70,
        70,
        70,
        70,
        70,
        70,
        70,
        70,
        70,
        70,
        70,
        70,
        70,
        70,
        70,
        70,
        70,
        70,
        70,
        70,
        70,
        70,
        70,
        70,
        70,
        70,
        70,
        70,
        70,
        70,
        70,
        70,
        70,
        70,
        70,
        -116,
        -116,
        -116,
        -116,
        -116,
        -116,
        -190,
        -190,
        -190,
        -190,
        -190,
        -190,
        -190,
        -210,
        -210,
        -210,
        -210,
        -210,
        -210,
        -220,
        -220,
        -220,
        -220,
        -220,
        -220,
        -220,
        -250,
        -250,
        -250,
        -250,
        -250,
        -250,
        -260,
        -260,
        -260,
        -260,
        -260,
        -260,
        -260,
        -76790,
        -76790,
        -76790,
        -76790,
        -76790,
        -76790,
        -116,
        -116,
        -116,
        -116,
        -116,
        -116,
        -190,
        -190,
        -190,
        -190,
        -190,
        -190,
        -190,
        -210,
        -210,
        -210,
        -210,
        -210,
        -210,
        -220,
        -220,
        -220,
        -220,
        -220,
        -220,
        -220,
        -250,
        -250,
        -250,
        -250,
        -250,
        -250,
        -260,
        -260,
        -260,
        -260,
        -260,
        -260,
        -260,
        -76790,
        -76790,
        -76790,
        -76790,
        -76790,
        -76790,
        -116,
        -116,
        -116,
        -116,
        -116,
        -116,
        -190,
        -190,
        -190,
        -190,
        -190,
        -190,
        -190,
        -210,
        -210,
        -210,
        -210,
        -210,
        -210,
        -220,
        -220,
        -220,
        -220,
        -220,
        -220,
        -220,
        -250,
        -250,
        -250,
        -250,
        -250,
        -250,
        -260,
        -260,
        -260,
        -260,
        -260,
        -260,
        -260,
        -76790,
        -76790,
        -76790,
        -76790,
        -76790,
        -76790,
        -116,
        -116,
        -116,
        -116,
        -116,
        -116,
        -190,
        -190,
        -190,
        -190,
        -190,
        -190,
        -190,
        -210,
        -210,
        -210,
        -210,
        -210,
        -210,
        -220,
        -220,
        -220,
        -220,
        -220,
        -220,
        -220,
        -250,
        -250,
        -250,
        -250,
        -250,
        -250,
        -260,
        -260,
        -260,
        -260,
        -260,
        -260,
        -260,
        -76790,
        -76790,
        -76790,
        -76790,
        -76790,
        -76790,
        -116,
        -116,
        -116,
        -116,
        -116,
        -116,
        -190,
        -190,
        -190,
        -190,
        -190,
        -190,
        -190,
        -210,
        -210,
        -210,
        -210,
        -210,
        -210,
        -220,
        -220,
        -220,
        -220,
        -220,
        -220,
        -220,
        -250,
        -250,
        -250,
        -250,
        -250,
        -250,
        -260,
        -260,
        -260,
        -260,
        -260,
        -260,
        -260,
        -76790,
        -76790,
        -76790,
        -76790,
        -76790,
        -76790,
        -116,
        -116,
        -116,
        -116,
        -116,
        -116,
        -190,
        -190,
        -190,
        -190,
        -190,
        -190,
        -190,
        -210,
        -210,
        -210,
        -210,
        -210,
        -210,
        -220,
        -220,
        -220,
        -220,
        -220,
        -220,
        -220,
        -250,
        -250,
        -250,
        -250,
        -250,
        -250,
        -260,
        -260,
        -260,
        -260,
        -260,
        -260,
        -260,
        -76790,
        -76790,
        -76790,
        -76790,
        -76790,
        -76790,
        -116,
        -116,
        -116,
        -116,
        -116,
        -116,
        -190,
        -190,
        -190,
        -190,
        -190,
        -190,
        -190,
        -210,
        -210,
        -210,
        -210,
        -210,
        -210,
        -220,
        -220,
        -220,
        -220,
        -220,
        -220,
        -220,
        -250,
        -250,
        -250,
        -250,
        -250,
        -250,
        -260,
        -260,
        -260,
        -260,
        -260,
        -260,
        -260,
        -76790,
        -76790,
        -76790,
        -76790,
        -76790,
        -76790,
        -116,
        -116,
        -116,
        -116,
        -116,
        -116,
        -190,
        -190,
        -190,
        -190,
        -190,
        -190,
        -190,
        -210,
        -210,
        -210,
        -210,
        -210,
        -210,
        -220,
        -220,
        -220,
        -220,
        -220,
        -220,
        -220,
        -250,
        -250,
        -250,
        -250,
        -250,
        -250,
        -260,
        -260,
        -260,
        -260,
        -260,
        -260,
        -260,
        -76790,
        -76790,
        -76790,
        -76790,
        -76790,
        -76790,
        -116,
        -116,
        -116,
        -116,
        -116,
        -116,
        -190,
        -190,
        -190,
        -190,
        -190,
        -190,
        -190,
        -210,
        -210,
        -210,
        -210,
        -210,
        -210,
        -220,
        -220,
        -220,
        -220,
        -220,
        -220,
        -220,
        -250,
        -250,
        -250,
        -250,
        -250,
        -250,
        -260,
        -260,
        -260,
        -260,
        -260,
        -260,
        -260,
        -76790,
        -76790,
        -76790,
        -76790,
        -76790,
        -76790,
        -116,
        -116,
        -116,
        -116,
        -116,
        -116,
        -190,
        -190,
        -190,
        -190,
        -190,
        -190,
        -190,
        -210,
        -210,
        -210,
        -210,
        -210,
        -210,
        -220,
        -220,
        -220,
        -220,
        -220,
        -220,
        -220,
        -250,
        -250,
        -250,
        -250,
        -250,
        -250,
        -260,
        -260,
        -260,
        -260,
        -260,
        -260,
        -260,
        -76790,
        -76790,
        -76790,
        -76790,
        -76790,
        -76790,
        -116,
        -116,
        -116,
        -116,
        -116,
        -116,
        -190,
        -190,
        -190,
        -190,
        -190,
        -190,
        -190,
        -210,
        -210,
        -210,
        -210,
        -210,
        -210,
        -220,
        -220,
        -220,
        -220,
        -220,
        -220,
        -220,
        -250,
        -250,
        -250,
        -250,
        -250,
        -250,
        -260,
        -260,
        -260,
        -260,
        -260,
        -260,
        -260,
        -76790,
        -76790,
        -76790,
        -76790,
        -76790,
        -76790,
        -116,
        -116,
        -116,
        -116,
        -116,
        -116,
        -190,
        -190,
        -190,
        -190,
        -190,
        -190,
        -190,
        -210,
        -210,
        -210,
        -210,
        -210,
        -210,
        -220,
        -220,
        -220,
        -220,
        -220,
        -220,
        -220,
        -250,
        -250,
        -250,
        -250,
        -250,
        -250,
        -260,
        -260,
        -260,
        -260,
        -260,
        -260,
        -260,
        -76790,
        -76790,
        -76790,
        -76790,
        -76790,
        -76790,
        -130,
        -130,
        -130,
        -130,
        -130,
        -130,
        -130,
        -130,
        -130,
        -130,
        -130,
        -130,
        -130,
        -130,
        -130,
        -130,
        -130,
        -130,
        -130,
        -130,
        -130,
        -130,
        -130,
        -130,
        -130,
        -130,
        -130,
        -130,
        -130,
        -130,
        -130,
        -130,
        -130,
        -130,
        -130,
        -130,
        -130,
        -130,
        -130,
        -130,
        -130,
        -130,
        -130,
        -130,
        -130,
        -63,
        -63,
        -63,
        -63,
        -63,
        -63,
        -100,
        -100,
        -100,
        -100,
        -100,
        -100,
        -100,
        -110,
        -110,
        -110,
        -110,
        -110,
        -110,
        -115,
        -115,
        -115,
        -115,
        -115,
        -115,
        -115,
        -130,
        -130,
        -130,
        -130,
        -130,
        -130,
        -135,
        -135,
        -135,
        -135,
        -135,
        -135,
        -135,
        -38400,
        -38400,
        -38400,
        -38400,
        -38400,
        -38400,
        -63,
        -63,
        -63,
        -63,
        -63,
        -63,
        -100,
        -100,
        -100,
        -100,
        -100,
        -100,
        -100,
        -110,
        -110,
        -110,
        -110,
        -110,
        -110,
        -115,
        -115,
        -115,
        -115,
        -115,
        -115,
        -115,
        -130,
        -130,
        -130,
        -130,
        -130,
        -130,
        -135,
        -135,
        -135,
        -135,
        -135,
        -135,
        -135,
        -38400,
        -38400,
        -38400,
        -38400,
        -38400,
        -38400,
        -63,
        -63,
        -63,
        -63,
        -63,
        -63,
        -100,
        -100,
        -100,
        -100,
        -100,
        -100,
        -100,
        -110,
        -110,
        -110,
        -110,
        -110,
        -110,
        -115,
        -115,
        -115,
        -115,
        -115,
        -115,
        -115,
        -130,
        -130,
        -130,
        -130,
        -130,
        -130,
        -135,
        -135,
        -135,
        -135,
        -135,
        -135,
        -135,
        -38400,
        -38400,
        -38400,
        -38400,
        -38400,
        -38400,
        -70,
        -70,
        -70,
        -70,
        -70,
        -70,
        -70,
        -70,
        -70,
        -70,
        -70,
        -70,
        -70,
        -70,
        -70,
        -70,
        -70,
        -70,
        -70,
        -70,
        -70,
        -70,
        -70,
        -70,
        -70,
        -70,
        -70,
        -70,
        -70,
        -70,
        -70,
        -70,
        -70,
        -70,
        -70,
        -70,
        -70,
        -70,
        -70,
        -70,
        -70,
        -70,
        -70,
        -70,
        -70,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0
    };


}
#endif