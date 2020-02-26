#ifndef CHARACTER_H
# define CHARACTER_H

# include <vector>
# include <stdint.h>
# include <cstdlib>

# include "dims.h"
# include "utils.h"

typedef enum kill_type {
  kill_direct,
  kill_avenged,
  num_kill_types
} kill_type_t;

class dice;

class character {
 public:
  virtual ~character() {}
  char symbol;
  pair_t position;
  int32_t speed;
  uint32_t alive;
    uint32_t in_water;
  std::vector<uint32_t> color;
  uint32_t hp;
  const dice *damage;
  const char *name;
  uint32_t sequence_number;
  uint32_t kills[num_kill_types];
  uint32_t get_color() { return color[rand_range(0, color.size() - 1)]; }
  char get_symbol() { return symbol; }
};

typedef struct dungeon dungeon_t;

int32_t compare_characters_by_next_turn(const void *character1,
                                        const void *character2);
uint32_t can_see(dungeon_t *d, pair_t voyeur, pair_t exhibitionist,
                 int is_pc, int learn);
void character_delete(character *c);
int16_t *character_get_pos(character *c);
int16_t character_get_y(const character *c);
int16_t character_set_y(character *c, int16_t y);
int16_t character_get_x(const character *c);
int16_t character_set_x(character *c, int16_t x);
uint32_t character_get_next_turn(const character *c);
void character_die(character *c);
int character_is_alive(const character *c);
void character_next_turn(character *c);
void character_reset_turn(character *c);
char character_get_symbol(const character *c);
uint32_t character_get_speed(const character *c);
uint32_t character_get_dkills(const character *c);
uint32_t character_get_ikills(const character *c);
uint32_t character_increment_dkills(character *c);
uint32_t character_increment_ikills(character *c, uint32_t k);
const char *character_get_name(const character *c);

#endif
