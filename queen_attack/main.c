#include <stdio.h>
#include "queen_attack.h"

#define LOG(format, ...) printf(format "\n", ##__VA_ARGS__)

void test_attack(position_t queen_1, position_t queen_2, attack_status_t expected) {
    attack_status_t result = can_attack(queen_1, queen_2);
    const char *result_str = (result == CAN_ATTACK) ? "CAN_ATTACK" :
                             (result == CAN_NOT_ATTACK) ? "CAN_NOT_ATTACK" : "INVALID_POSITION";
    const char *expected_str = (expected == CAN_ATTACK) ? "CAN_ATTACK" :
                               (expected == CAN_NOT_ATTACK) ? "CAN_NOT_ATTACK" : "INVALID_POSITION";

    LOG("Test: Queen 1 at (%d, %d), Queen 2 at (%d, %d). Expected: %s, Got: %s",
        queen_1.row, queen_1.column, queen_2.row, queen_2.column, expected_str, result_str);
}

int main() {
    position_t queen_1, queen_2;

    LOG("Starting test cases...\n");

    // Test 1: Same position (invalid)
    queen_1 = (position_t){3, 3};
    queen_2 = (position_t){3, 3};
    test_attack(queen_1, queen_2, INVALID_POSITION);

    // Test 2: One queen off the board (invalid)
    queen_1 = (position_t){7, 7};
    queen_2 = (position_t){8, 8};
    test_attack(queen_1, queen_2, INVALID_POSITION);

    // Test 3: Same row (can attack)
    queen_1 = (position_t){3, 4};
    queen_2 = (position_t){3, 7};
    test_attack(queen_1, queen_2, CAN_ATTACK);

    // Test 4: Same column (can attack)
    queen_1 = (position_t){2, 3};
    queen_2 = (position_t){5, 3};
    test_attack(queen_1, queen_2, CAN_ATTACK);

    // Test 5: Same diagonal (can attack)
    queen_1 = (position_t){1, 1};
    queen_2 = (position_t){4, 4};
    test_attack(queen_1, queen_2, CAN_ATTACK);

    // Test 6: Different diagonal (cannot attack)
    queen_1 = (position_t){0, 0};
    queen_2 = (position_t){2, 3};
    test_attack(queen_1, queen_2, CAN_NOT_ATTACK);

    // Test 7: Invalid position (off the board)
    queen_1 = (position_t){8, 8};
    queen_2 = (position_t){5, 5};
    test_attack(queen_1, queen_2, INVALID_POSITION);

    // Test 8: Valid attack diagonally
    queen_1 = (position_t){2, 2};
    queen_2 = (position_t){5, 5};
    test_attack(queen_1, queen_2, CAN_ATTACK);

    // Test 9: Valid attack horizontally
    queen_1 = (position_t){1, 2};
    queen_2 = (position_t){1, 5};
    test_attack(queen_1, queen_2, CAN_ATTACK);

    // Test 10: Valid attack vertically
    queen_1 = (position_t){3, 4};
    queen_2 = (position_t){6, 4};
    test_attack(queen_1, queen_2, CAN_ATTACK);

    LOG("Test cases complete.\n");
    return 0;
}

