#ifndef LOOKUP_HPP
#define LOOKUP_HPP

#include <cstdint>
#include <cstdlib>
#include <vector>

using std::vector;

namespace PijersiEngine::Lookup
{
    // A vector associating a cell index to the indices of its 1-range neighbours
    const vector<uint32_t> neighbours[45] = {
        vector<uint32_t>({1, 6, 7}),
        vector<uint32_t>({0, 2, 7, 8}),
        vector<uint32_t>({1, 3, 8, 9}),
        vector<uint32_t>({2, 4, 9, 10}),
        vector<uint32_t>({3, 5, 10, 11}),
        vector<uint32_t>({4, 11, 12}),
        vector<uint32_t>({0, 7, 13}),
        vector<uint32_t>({0, 1, 6, 8, 13, 14}),
        vector<uint32_t>({1, 2, 7, 9, 14, 15}),
        vector<uint32_t>({2, 3, 8, 10, 15, 16}),
        vector<uint32_t>({3, 4, 9, 11, 16, 17}),
        vector<uint32_t>({4, 5, 10, 12, 17, 18}),
        vector<uint32_t>({5, 11, 18}),
        vector<uint32_t>({6, 7, 14, 19, 20}),
        vector<uint32_t>({7, 8, 13, 15, 20, 21}),
        vector<uint32_t>({8, 9, 14, 16, 21, 22}),
        vector<uint32_t>({9, 10, 15, 17, 22, 23}),
        vector<uint32_t>({10, 11, 16, 18, 23, 24}),
        vector<uint32_t>({11, 12, 17, 24, 25}),
        vector<uint32_t>({13, 20, 26}),
        vector<uint32_t>({13, 14, 19, 21, 26, 27}),
        vector<uint32_t>({14, 15, 20, 22, 27, 28}),
        vector<uint32_t>({15, 16, 21, 23, 28, 29}),
        vector<uint32_t>({16, 17, 22, 24, 29, 30}),
        vector<uint32_t>({17, 18, 23, 25, 30, 31}),
        vector<uint32_t>({18, 24, 31}),
        vector<uint32_t>({19, 20, 27, 32, 33}),
        vector<uint32_t>({20, 21, 26, 28, 33, 34}),
        vector<uint32_t>({21, 22, 27, 29, 34, 35}),
        vector<uint32_t>({22, 23, 28, 30, 35, 36}),
        vector<uint32_t>({23, 24, 29, 31, 36, 37}),
        vector<uint32_t>({24, 25, 30, 37, 38}),
        vector<uint32_t>({26, 33, 39}),
        vector<uint32_t>({26, 27, 32, 34, 39, 40}),
        vector<uint32_t>({27, 28, 33, 35, 40, 41}),
        vector<uint32_t>({28, 29, 34, 36, 41, 42}),
        vector<uint32_t>({29, 30, 35, 37, 42, 43}),
        vector<uint32_t>({30, 31, 36, 38, 43, 44}),
        vector<uint32_t>({31, 37, 44}),
        vector<uint32_t>({32, 33, 40}),
        vector<uint32_t>({33, 34, 39, 41}),
        vector<uint32_t>({34, 35, 40, 42}),
        vector<uint32_t>({35, 36, 41, 43}),
        vector<uint32_t>({36, 37, 42, 44}),
        vector<uint32_t>({37, 38, 43})};

    // A vector associating a cell index to the indices of its 2-range neighbours
    const vector<uint32_t> neighbours2[45] = {
        vector<uint32_t>({2, 14}),
        vector<uint32_t>({3, 13, 15}),
        vector<uint32_t>({0, 4, 14, 16}),
        vector<uint32_t>({1, 5, 15, 17}),
        vector<uint32_t>({2, 16, 18}),
        vector<uint32_t>({3, 17}),
        vector<uint32_t>({8, 20}),
        vector<uint32_t>({9, 19, 21}),
        vector<uint32_t>({6, 10, 20, 22}),
        vector<uint32_t>({7, 11, 21, 23}),
        vector<uint32_t>({8, 12, 22, 24}),
        vector<uint32_t>({9, 23, 25}),
        vector<uint32_t>({10, 24}),
        vector<uint32_t>({1, 15, 27}),
        vector<uint32_t>({0, 2, 16, 26, 28}),
        vector<uint32_t>({1, 3, 13, 17, 27, 29}),
        vector<uint32_t>({2, 4, 14, 18, 28, 30}),
        vector<uint32_t>({3, 5, 15, 29, 31}),
        vector<uint32_t>({4, 16, 30}),
        vector<uint32_t>({7, 21, 33}),
        vector<uint32_t>({6, 8, 22, 32, 34}),
        vector<uint32_t>({7, 9, 19, 23, 33, 35}),
        vector<uint32_t>({8, 10, 20, 24, 34, 36}),
        vector<uint32_t>({9, 11, 21, 25, 35, 37}),
        vector<uint32_t>({10, 12, 22, 36, 38}),
        vector<uint32_t>({11, 23, 37}),
        vector<uint32_t>({14, 28, 40}),
        vector<uint32_t>({13, 15, 29, 39, 41}),
        vector<uint32_t>({14, 16, 26, 30, 40, 42}),
        vector<uint32_t>({15, 17, 27, 31, 41, 43}),
        vector<uint32_t>({16, 18, 28, 42, 44}),
        vector<uint32_t>({17, 29, 43}),
        vector<uint32_t>({20, 34}),
        vector<uint32_t>({19, 21, 35}),
        vector<uint32_t>({20, 22, 32, 36}),
        vector<uint32_t>({21, 23, 33, 37}),
        vector<uint32_t>({22, 24, 34, 38}),
        vector<uint32_t>({23, 25, 35}),
        vector<uint32_t>({24, 36}),
        vector<uint32_t>({27, 41}),
        vector<uint32_t>({26, 28, 42}),
        vector<uint32_t>({27, 29, 39, 43}),
        vector<uint32_t>({28, 30, 40, 44}),
        vector<uint32_t>({29, 31, 41}),
        vector<uint32_t>({30, 42})
    };

    // Associates a piece's uint8_t representation to an index that can be used in other lookup tables
    const size_t pieceToIndex[256] {
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
    const int64_t pieceScores[1575] {
        1048577,
        1048577,
        1048577,
        1048577,
        1048577,
        1048577,
        290,
        309,
        287,
        277,
        340,
        271,
        305,
        238,
        266,
        263,
        277,
        258,
        262,
        249,
        237,
        238,
        253,
        238,
        268,
        219,
        253,
        225,
        212,
        248,
        234,
        213,
        190,
        193,
        199,
        190,
        213,
        228,
        216,
        162,
        141,
        142,
        160,
        186,
        191,
        1048577,
        1048577,
        1048577,
        1048577,
        1048577,
        1048577,
        290,
        309,
        287,
        277,
        340,
        271,
        305,
        238,
        266,
        263,
        277,
        258,
        262,
        249,
        237,
        238,
        253,
        238,
        268,
        219,
        253,
        225,
        212,
        248,
        234,
        213,
        190,
        193,
        199,
        190,
        213,
        228,
        216,
        162,
        141,
        142,
        160,
        186,
        191,
        1048577,
        1048577,
        1048577,
        1048577,
        1048577,
        1048577,
        290,
        309,
        287,
        277,
        340,
        271,
        305,
        238,
        266,
        263,
        277,
        258,
        262,
        249,
        237,
        238,
        253,
        238,
        268,
        219,
        253,
        225,
        212,
        248,
        234,
        213,
        190,
        193,
        199,
        190,
        213,
        228,
        216,
        162,
        141,
        142,
        160,
        186,
        191,
        1048577,
        1048577,
        1048577,
        1048577,
        1048577,
        1048577,
        290,
        309,
        287,
        277,
        340,
        271,
        305,
        238,
        266,
        263,
        277,
        258,
        262,
        249,
        237,
        238,
        253,
        238,
        268,
        219,
        253,
        225,
        212,
        248,
        234,
        213,
        190,
        193,
        199,
        190,
        213,
        228,
        216,
        162,
        141,
        142,
        160,
        186,
        191,
        1048577,
        1048577,
        1048577,
        1048577,
        1048577,
        1048577,
        290,
        309,
        287,
        277,
        340,
        271,
        305,
        238,
        266,
        263,
        277,
        258,
        262,
        249,
        237,
        238,
        253,
        238,
        268,
        219,
        253,
        225,
        212,
        248,
        234,
        213,
        190,
        193,
        199,
        190,
        213,
        228,
        216,
        162,
        141,
        142,
        160,
        186,
        191,
        1048577,
        1048577,
        1048577,
        1048577,
        1048577,
        1048577,
        290,
        309,
        287,
        277,
        340,
        271,
        305,
        238,
        266,
        263,
        277,
        258,
        262,
        249,
        237,
        238,
        253,
        238,
        268,
        219,
        253,
        225,
        212,
        248,
        234,
        213,
        190,
        193,
        199,
        190,
        213,
        228,
        216,
        162,
        141,
        142,
        160,
        186,
        191,
        1048577,
        1048577,
        1048577,
        1048577,
        1048577,
        1048577,
        290,
        309,
        287,
        277,
        340,
        271,
        305,
        238,
        266,
        263,
        277,
        258,
        262,
        249,
        237,
        238,
        253,
        238,
        268,
        219,
        253,
        225,
        212,
        248,
        234,
        213,
        190,
        193,
        199,
        190,
        213,
        228,
        216,
        162,
        141,
        142,
        160,
        186,
        191,
        1048577,
        1048577,
        1048577,
        1048577,
        1048577,
        1048577,
        290,
        309,
        287,
        277,
        340,
        271,
        305,
        238,
        266,
        263,
        277,
        258,
        262,
        249,
        237,
        238,
        253,
        238,
        268,
        219,
        253,
        225,
        212,
        248,
        234,
        213,
        190,
        193,
        199,
        190,
        213,
        228,
        216,
        162,
        141,
        142,
        160,
        186,
        191,
        1048577,
        1048577,
        1048577,
        1048577,
        1048577,
        1048577,
        290,
        309,
        287,
        277,
        340,
        271,
        305,
        238,
        266,
        263,
        277,
        258,
        262,
        249,
        237,
        238,
        253,
        238,
        268,
        219,
        253,
        225,
        212,
        248,
        234,
        213,
        190,
        193,
        199,
        190,
        213,
        228,
        216,
        162,
        141,
        142,
        160,
        186,
        191,
        1048577,
        1048577,
        1048577,
        1048577,
        1048577,
        1048577,
        290,
        309,
        287,
        277,
        340,
        271,
        305,
        238,
        266,
        263,
        277,
        258,
        262,
        249,
        237,
        238,
        253,
        238,
        268,
        219,
        253,
        225,
        212,
        248,
        234,
        213,
        190,
        193,
        199,
        190,
        213,
        228,
        216,
        162,
        141,
        142,
        160,
        186,
        191,
        1048577,
        1048577,
        1048577,
        1048577,
        1048577,
        1048577,
        290,
        309,
        287,
        277,
        340,
        271,
        305,
        238,
        266,
        263,
        277,
        258,
        262,
        249,
        237,
        238,
        253,
        238,
        268,
        219,
        253,
        225,
        212,
        248,
        234,
        213,
        190,
        193,
        199,
        190,
        213,
        228,
        216,
        162,
        141,
        142,
        160,
        186,
        191,
        1048577,
        1048577,
        1048577,
        1048577,
        1048577,
        1048577,
        290,
        309,
        287,
        277,
        340,
        271,
        305,
        238,
        266,
        263,
        277,
        258,
        262,
        249,
        237,
        238,
        253,
        238,
        268,
        219,
        253,
        225,
        212,
        248,
        234,
        213,
        190,
        193,
        199,
        190,
        213,
        228,
        216,
        162,
        141,
        142,
        160,
        186,
        191,
        173,
        173,
        173,
        173,
        173,
        173,
        173,
        173,
        173,
        173,
        173,
        173,
        173,
        173,
        173,
        173,
        173,
        173,
        173,
        173,
        173,
        173,
        173,
        173,
        173,
        173,
        173,
        173,
        173,
        173,
        173,
        173,
        173,
        173,
        173,
        173,
        173,
        173,
        173,
        173,
        173,
        173,
        173,
        173,
        173,
        524288,
        524288,
        524288,
        524288,
        524288,
        524288,
        144,
        154,
        143,
        138,
        170,
        135,
        152,
        118,
        132,
        131,
        138,
        128,
        130,
        124,
        118,
        119,
        126,
        119,
        133,
        109,
        126,
        112,
        106,
        123,
        117,
        106,
        94,
        96,
        99,
        94,
        106,
        114,
        107,
        80,
        70,
        70,
        79,
        92,
        95,
        524288,
        524288,
        524288,
        524288,
        524288,
        524288,
        144,
        154,
        143,
        138,
        170,
        135,
        152,
        118,
        132,
        131,
        138,
        128,
        130,
        124,
        118,
        119,
        126,
        119,
        133,
        109,
        126,
        112,
        106,
        123,
        117,
        106,
        94,
        96,
        99,
        94,
        106,
        114,
        107,
        80,
        70,
        70,
        79,
        92,
        95,
        524288,
        524288,
        524288,
        524288,
        524288,
        524288,
        144,
        154,
        143,
        138,
        170,
        135,
        152,
        118,
        132,
        131,
        138,
        128,
        130,
        124,
        118,
        119,
        126,
        119,
        133,
        109,
        126,
        112,
        106,
        123,
        117,
        106,
        94,
        96,
        99,
        94,
        106,
        114,
        107,
        80,
        70,
        70,
        79,
        92,
        95,
        86,
        86,
        86,
        86,
        86,
        86,
        86,
        86,
        86,
        86,
        86,
        86,
        86,
        86,
        86,
        86,
        86,
        86,
        86,
        86,
        86,
        86,
        86,
        86,
        86,
        86,
        86,
        86,
        86,
        86,
        86,
        86,
        86,
        86,
        86,
        86,
        86,
        86,
        86,
        86,
        86,
        86,
        86,
        86,
        86,
        -197,
        -158,
        -169,
        -191,
        -165,
        -162,
        -181,
        -231,
        -226,
        -211,
        -205,
        -200,
        -188,
        -201,
        -208,
        -200,
        -198,
        -216,
        -214,
        -225,
        -249,
        -263,
        -289,
        -235,
        -220,
        -204,
        -256,
        -273,
        -250,
        -280,
        -256,
        -261,
        -332,
        -297,
        -278,
        -277,
        -273,
        -262,
        -292,
        -1048577,
        -1048577,
        -1048577,
        -1048577,
        -1048577,
        -1048577,
        -197,
        -158,
        -169,
        -191,
        -165,
        -162,
        -181,
        -231,
        -226,
        -211,
        -205,
        -200,
        -188,
        -201,
        -208,
        -200,
        -198,
        -216,
        -214,
        -225,
        -249,
        -263,
        -289,
        -235,
        -220,
        -204,
        -256,
        -273,
        -250,
        -280,
        -256,
        -261,
        -332,
        -297,
        -278,
        -277,
        -273,
        -262,
        -292,
        -1048577,
        -1048577,
        -1048577,
        -1048577,
        -1048577,
        -1048577,
        -197,
        -158,
        -169,
        -191,
        -165,
        -162,
        -181,
        -231,
        -226,
        -211,
        -205,
        -200,
        -188,
        -201,
        -208,
        -200,
        -198,
        -216,
        -214,
        -225,
        -249,
        -263,
        -289,
        -235,
        -220,
        -204,
        -256,
        -273,
        -250,
        -280,
        -256,
        -261,
        -332,
        -297,
        -278,
        -277,
        -273,
        -262,
        -292,
        -1048577,
        -1048577,
        -1048577,
        -1048577,
        -1048577,
        -1048577,
        -197,
        -158,
        -169,
        -191,
        -165,
        -162,
        -181,
        -231,
        -226,
        -211,
        -205,
        -200,
        -188,
        -201,
        -208,
        -200,
        -198,
        -216,
        -214,
        -225,
        -249,
        -263,
        -289,
        -235,
        -220,
        -204,
        -256,
        -273,
        -250,
        -280,
        -256,
        -261,
        -332,
        -297,
        -278,
        -277,
        -273,
        -262,
        -292,
        -1048577,
        -1048577,
        -1048577,
        -1048577,
        -1048577,
        -1048577,
        -197,
        -158,
        -169,
        -191,
        -165,
        -162,
        -181,
        -231,
        -226,
        -211,
        -205,
        -200,
        -188,
        -201,
        -208,
        -200,
        -198,
        -216,
        -214,
        -225,
        -249,
        -263,
        -289,
        -235,
        -220,
        -204,
        -256,
        -273,
        -250,
        -280,
        -256,
        -261,
        -332,
        -297,
        -278,
        -277,
        -273,
        -262,
        -292,
        -1048577,
        -1048577,
        -1048577,
        -1048577,
        -1048577,
        -1048577,
        -197,
        -158,
        -169,
        -191,
        -165,
        -162,
        -181,
        -231,
        -226,
        -211,
        -205,
        -200,
        -188,
        -201,
        -208,
        -200,
        -198,
        -216,
        -214,
        -225,
        -249,
        -263,
        -289,
        -235,
        -220,
        -204,
        -256,
        -273,
        -250,
        -280,
        -256,
        -261,
        -332,
        -297,
        -278,
        -277,
        -273,
        -262,
        -292,
        -1048577,
        -1048577,
        -1048577,
        -1048577,
        -1048577,
        -1048577,
        -197,
        -158,
        -169,
        -191,
        -165,
        -162,
        -181,
        -231,
        -226,
        -211,
        -205,
        -200,
        -188,
        -201,
        -208,
        -200,
        -198,
        -216,
        -214,
        -225,
        -249,
        -263,
        -289,
        -235,
        -220,
        -204,
        -256,
        -273,
        -250,
        -280,
        -256,
        -261,
        -332,
        -297,
        -278,
        -277,
        -273,
        -262,
        -292,
        -1048577,
        -1048577,
        -1048577,
        -1048577,
        -1048577,
        -1048577,
        -197,
        -158,
        -169,
        -191,
        -165,
        -162,
        -181,
        -231,
        -226,
        -211,
        -205,
        -200,
        -188,
        -201,
        -208,
        -200,
        -198,
        -216,
        -214,
        -225,
        -249,
        -263,
        -289,
        -235,
        -220,
        -204,
        -256,
        -273,
        -250,
        -280,
        -256,
        -261,
        -332,
        -297,
        -278,
        -277,
        -273,
        -262,
        -292,
        -1048577,
        -1048577,
        -1048577,
        -1048577,
        -1048577,
        -1048577,
        -197,
        -158,
        -169,
        -191,
        -165,
        -162,
        -181,
        -231,
        -226,
        -211,
        -205,
        -200,
        -188,
        -201,
        -208,
        -200,
        -198,
        -216,
        -214,
        -225,
        -249,
        -263,
        -289,
        -235,
        -220,
        -204,
        -256,
        -273,
        -250,
        -280,
        -256,
        -261,
        -332,
        -297,
        -278,
        -277,
        -273,
        -262,
        -292,
        -1048577,
        -1048577,
        -1048577,
        -1048577,
        -1048577,
        -1048577,
        -197,
        -158,
        -169,
        -191,
        -165,
        -162,
        -181,
        -231,
        -226,
        -211,
        -205,
        -200,
        -188,
        -201,
        -208,
        -200,
        -198,
        -216,
        -214,
        -225,
        -249,
        -263,
        -289,
        -235,
        -220,
        -204,
        -256,
        -273,
        -250,
        -280,
        -256,
        -261,
        -332,
        -297,
        -278,
        -277,
        -273,
        -262,
        -292,
        -1048577,
        -1048577,
        -1048577,
        -1048577,
        -1048577,
        -1048577,
        -197,
        -158,
        -169,
        -191,
        -165,
        -162,
        -181,
        -231,
        -226,
        -211,
        -205,
        -200,
        -188,
        -201,
        -208,
        -200,
        -198,
        -216,
        -214,
        -225,
        -249,
        -263,
        -289,
        -235,
        -220,
        -204,
        -256,
        -273,
        -250,
        -280,
        -256,
        -261,
        -332,
        -297,
        -278,
        -277,
        -273,
        -262,
        -292,
        -1048577,
        -1048577,
        -1048577,
        -1048577,
        -1048577,
        -1048577,
        -197,
        -158,
        -169,
        -191,
        -165,
        -162,
        -181,
        -231,
        -226,
        -211,
        -205,
        -200,
        -188,
        -201,
        -208,
        -200,
        -198,
        -216,
        -214,
        -225,
        -249,
        -263,
        -289,
        -235,
        -220,
        -204,
        -256,
        -273,
        -250,
        -280,
        -256,
        -261,
        -332,
        -297,
        -278,
        -277,
        -273,
        -262,
        -292,
        -1048577,
        -1048577,
        -1048577,
        -1048577,
        -1048577,
        -1048577,
        -173,
        -173,
        -173,
        -173,
        -173,
        -173,
        -173,
        -173,
        -173,
        -173,
        -173,
        -173,
        -173,
        -173,
        -173,
        -173,
        -173,
        -173,
        -173,
        -173,
        -173,
        -173,
        -173,
        -173,
        -173,
        -173,
        -173,
        -173,
        -173,
        -173,
        -173,
        -173,
        -173,
        -173,
        -173,
        -173,
        -173,
        -173,
        -173,
        -173,
        -173,
        -173,
        -173,
        -173,
        -173,
        -98,
        -78,
        -84,
        -95,
        -82,
        -80,
        -90,
        -115,
        -113,
        -105,
        -102,
        -99,
        -94,
        -100,
        -103,
        -99,
        -99,
        -107,
        -106,
        -112,
        -124,
        -131,
        -144,
        -117,
        -110,
        -102,
        -127,
        -136,
        -124,
        -139,
        -127,
        -130,
        -165,
        -148,
        -138,
        -138,
        -136,
        -130,
        -146,
        -524288,
        -524288,
        -524288,
        -524288,
        -524288,
        -524288,
        -98,
        -78,
        -84,
        -95,
        -82,
        -80,
        -90,
        -115,
        -113,
        -105,
        -102,
        -99,
        -94,
        -100,
        -103,
        -99,
        -99,
        -107,
        -106,
        -112,
        -124,
        -131,
        -144,
        -117,
        -110,
        -102,
        -127,
        -136,
        -124,
        -139,
        -127,
        -130,
        -165,
        -148,
        -138,
        -138,
        -136,
        -130,
        -146,
        -524288,
        -524288,
        -524288,
        -524288,
        -524288,
        -524288,
        -98,
        -78,
        -84,
        -95,
        -82,
        -80,
        -90,
        -115,
        -113,
        -105,
        -102,
        -99,
        -94,
        -100,
        -103,
        -99,
        -99,
        -107,
        -106,
        -112,
        -124,
        -131,
        -144,
        -117,
        -110,
        -102,
        -127,
        -136,
        -124,
        -139,
        -127,
        -130,
        -165,
        -148,
        -138,
        -138,
        -136,
        -130,
        -146,
        -524288,
        -524288,
        -524288,
        -524288,
        -524288,
        -524288,
        -86,
        -86,
        -86,
        -86,
        -86,
        -86,
        -86,
        -86,
        -86,
        -86,
        -86,
        -86,
        -86,
        -86,
        -86,
        -86,
        -86,
        -86,
        -86,
        -86,
        -86,
        -86,
        -86,
        -86,
        -86,
        -86,
        -86,
        -86,
        -86,
        -86,
        -86,
        -86,
        -86,
        -86,
        -86,
        -86,
        -86,
        -86,
        -86,
        -86,
        -86,
        -86,
        -86,
        -86,
        -86,
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