const uint8_t MorseCode_wlGw12pt7bBitmaps[] PROGMEM = {
  0x00, 0xB8, 0xB8, 0xB8, 0xB8, 0xB8, 0xB8, 0xB8, 0xF7, 0xF7, 0xF7, 0xF7,
  0xB8, 0xB8, 0xFD, 0xB7, 0xB8, 0xB5, 0xAC, 0xF5, 0xA0, 0xFD, 0xBF, 0xBF,
  0x6C, 0xBD, 0xB8, 0xD7, 0xE0, 0xD5, 0x80, 0xD5, 0xF5, 0x80, 0xFD, 0xA0,
  0xFD, 0xA8, 0xFD, 0xBC, 0xFD, 0xB4, 0xF7, 0xB4, 0xB8, 0xF5, 0x60, 0xB8,
  0xBD, 0xA8, 0xB8, 0xB8, 0xF5, 0xF7, 0x80, 0xF4, 0x80, 0xDD, 0xFD, 0xD4,
  0xC0, 0xBF, 0x60, 0xF7, 0xB5, 0xFC, 0xF0, 0xFD, 0x80, 0xB7, 0x80, 0xFD,
  0xE0, 0xB4, 0xD0, 0xE0, 0xDC, 0xD7, 0xBF, 0xF5, 0x80, 0xF7, 0xE0, 0xFD,
  0x80, 0xB8, 0xB8, 0xB8, 0xB8, 0xB8, 0xB8, 0xB8, 0xF5, 0xF7, 0x80, 0xF4,
  0x80, 0xDD, 0xFD, 0xD4, 0xC0, 0xBF, 0x60, 0xF7, 0xB5, 0xFC, 0xF0, 0xFD,
  0x80, 0xB7, 0x80, 0xFD, 0xE0, 0xB4, 0xD0, 0xE0, 0xDC, 0xD7, 0xBF, 0xF5,
  0x80, 0xF7, 0xE0, 0xFD, 0x80, 0xB8, 0x07, 0x00, 0x38, 0x01, 0xC0, 0x0E,
  0x00, 0x70, 0x5F, 0x54, 0x1C, 0x00, 0xE0, 0x07, 0x00, 0x38, 0x01, 0xC0,
  0x0E, 0x00, 0x70, 0x03, 0x80, 0x1C, 0x00, 0xB8, 0xB8 };

const GFXglyph MorseCode_wlGw12pt7bGlyphs[] PROGMEM = {
  {     0,   1,   1,  24,    0,    0 },   // 0x20 ' '
  {     1,   5,   1,  24,    0,  -13 },   // 0x21 '!'
  {     2,   5,   1,  24,    0,  -13 },   // 0x22 '"'
  {     3,   5,   1,  24,    0,  -13 },   // 0x23 '#'
  {     4,   5,   1,  24,    0,  -13 },   // 0x24 '$'
  {     5,   5,   1,  24,    0,  -13 },   // 0x25 '%'
  {     6,   5,   1,  24,    0,  -13 },   // 0x26 '&'
  {     7,   5,   1,  24,    0,  -13 },   // 0x27 '''
  {     8,  16,   1,  19,    2,  -13 },   // 0x28 '('
  {    10,  16,   1,  19,    2,  -13 },   // 0x29 ')'
  {    12,   5,   1,  24,    0,  -13 },   // 0x2A '*'
  {    13,   5,   1,  24,    0,  -13 },   // 0x2B '+'
  {    14,  16,   1,  19,    2,  -13 },   // 0x2C ','
  {    16,   5,   1,  24,    0,  -13 },   // 0x2D '-'
  {    17,  14,   1,  17,    2,  -13 },   // 0x2E '.'
  {    19,  11,   1,  14,    2,  -13 },   // 0x2F '/'
  {    21,  16,   1,  19,    2,  -13 },   // 0x30 '0'
  {    23,  14,   1,  16,    1,  -13 },   // 0x31 '1'
  {    25,  13,   1,  15,    2,  -13 },   // 0x32 '2'
  {    27,  11,   1,  14,    2,  -13 },   // 0x33 '3'
  {    29,   9,   1,  12,    2,  -13 },   // 0x34 '4'
  {    31,   8,   1,  10,    2,  -13 },   // 0x35 '5'
  {    32,   9,   1,  12,    2,  -13 },   // 0x36 '6'
  {    34,  11,   1,  14,    2,  -13 },   // 0x37 '7'
  {    36,  13,   1,  15,    2,  -13 },   // 0x38 '8'
  {    38,  14,   1,  17,    2,  -13 },   // 0x39 '9'
  {    40,  14,   1,  17,    2,  -13 },   // 0x3A ':'
  {    42,  14,   1,  17,    2,  -13 },   // 0x3B ';'
  {    44,   5,   1,  24,    0,  -13 },   // 0x3C '<'
  {    45,  11,   1,  14,    2,  -13 },   // 0x3D '='
  {    47,   5,   1,  24,    0,  -13 },   // 0x3E '>'
  {    48,  13,   1,  15,    2,  -13 },   // 0x3F '?'
  {    50,   5,   1,  24,    0,  -13 },   // 0x40 '@'
  {    51,   5,   1,   6,    1,  -13 },   // 0x41 'A'
  {    52,   8,   1,  10,    2,  -13 },   // 0x42 'B'
  {    53,   9,   1,  12,    2,  -13 },   // 0x43 'C'
  {    55,   6,   1,   8,    2,  -13 },   // 0x44 'D'
  {    56,   1,   1,   3,    2,  -13 },   // 0x45 'E'
  {    57,   8,   1,  10,    2,  -13 },   // 0x46 'F'
  {    58,   8,   1,  10,    2,  -13 },   // 0x47 'G'
  {    59,   6,   1,   8,    2,  -13 },   // 0x48 'H'
  {    60,   2,   1,   5,    2,  -13 },   // 0x49 'I'
  {    61,  11,   1,  13,    1,  -13 },   // 0x4A 'J'
  {    63,   8,   1,  10,    2,  -13 },   // 0x4B 'K'
  {    64,   8,   1,  10,    2,  -13 },   // 0x4C 'L'
  {    65,   6,   1,   8,    2,  -13 },   // 0x4D 'M'
  {    66,   4,   1,   7,    2,  -13 },   // 0x4E 'N'
  {    67,   9,   1,  12,    2,  -13 },   // 0x4F 'O'
  {    69,   9,   1,  12,    2,  -13 },   // 0x50 'P'
  {    71,  11,   1,  14,    2,  -13 },   // 0x51 'Q'
  {    73,   6,   1,   8,    2,  -13 },   // 0x52 'R'
  {    74,   4,   1,   7,    2,  -13 },   // 0x53 'S'
  {    75,   3,   1,   5,    2,  -13 },   // 0x54 'T'
  {    76,   6,   1,   8,    2,  -13 },   // 0x55 'U'
  {    77,   8,   1,  10,    2,  -13 },   // 0x56 'V'
  {    78,   8,   1,   9,    1,  -13 },   // 0x57 'W'
  {    79,   9,   1,  12,    2,  -13 },   // 0x58 'X'
  {    81,  11,   1,  14,    2,  -13 },   // 0x59 'Y'
  {    83,   9,   1,  12,    2,  -13 },   // 0x5A 'Z'
  {    85,   5,   1,  24,    0,  -13 },   // 0x5B '['
  {    86,   5,   1,  24,    0,  -13 },   // 0x5C '\'
  {    87,   5,   1,  24,    0,  -13 },   // 0x5D ']'
  {    88,   5,   1,  24,    0,  -13 },   // 0x5E '^'
  {    89,   5,   1,  24,    0,  -13 },   // 0x5F '_'
  {    90,   5,   1,  24,    0,  -13 },   // 0x60 '`'
  {    91,   5,   1,   6,    1,  -13 },   // 0x61 'a'
  {    92,   8,   1,  10,    2,  -13 },   // 0x62 'b'
  {    93,   9,   1,  12,    2,  -13 },   // 0x63 'c'
  {    95,   6,   1,   8,    2,  -13 },   // 0x64 'd'
  {    96,   1,   1,   3,    2,  -13 },   // 0x65 'e'
  {    97,   8,   1,  10,    2,  -13 },   // 0x66 'f'
  {    98,   8,   1,  10,    2,  -13 },   // 0x67 'g'
  {    99,   6,   1,   8,    2,  -13 },   // 0x68 'h'
  {   100,   2,   1,   5,    2,  -13 },   // 0x69 'i'
  {   101,  11,   1,  13,    1,  -13 },   // 0x6A 'j'
  {   103,   8,   1,  10,    2,  -13 },   // 0x6B 'k'
  {   104,   8,   1,  10,    2,  -13 },   // 0x6C 'l'
  {   105,   6,   1,   8,    2,  -13 },   // 0x6D 'm'
  {   106,   4,   1,   7,    2,  -13 },   // 0x6E 'n'
  {   107,   9,   1,  12,    2,  -13 },   // 0x6F 'o'
  {   109,   9,   1,  12,    2,  -13 },   // 0x70 'p'
  {   111,  11,   1,  14,    2,  -13 },   // 0x71 'q'
  {   113,   6,   1,   8,    2,  -13 },   // 0x72 'r'
  {   114,   4,   1,   7,    2,  -13 },   // 0x73 's'
  {   115,   3,   1,   5,    2,  -13 },   // 0x74 't'
  {   116,   6,   1,   8,    2,  -13 },   // 0x75 'u'
  {   117,   8,   1,  10,    2,  -13 },   // 0x76 'v'
  {   118,   8,   1,   9,    1,  -13 },   // 0x77 'w'
  {   119,   9,   1,  12,    2,  -13 },   // 0x78 'x'
  {   121,  11,   1,  14,    2,  -13 },   // 0x79 'y'
  {   123,   9,   1,  12,    2,  -13 },   // 0x7A 'z'
  {   125,   5,   1,  24,    0,  -13 },   // 0x7B '{'
  {   126,  13,  15,  15,    2,  -18 },   // 0x7C '|'
  {   151,   5,   1,  24,    0,  -13 },   // 0x7D '}'
  {   152,   5,   1,  24,    0,  -13 } }; // 0x7E '~'

const GFXfont MorseCode_wlGw12pt7b PROGMEM = {
  (uint8_t  *)MorseCode_wlGw12pt7bBitmaps,
  (GFXglyph *)MorseCode_wlGw12pt7bGlyphs,
  0x20, 0x7E, 24 };

// Approx. 825 bytes
