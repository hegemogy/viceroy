// THIS FILE WAS AUTO-GENTERATED FROM savegame.h
// json support, 'using json ...' is for convenience
#include <iostream>
#include <json.hpp>
using json = nlohmann::json;

json json_base();
void print_json(             const struct savegame *sg );
json merge_json_head(        const struct savegame *sg, json j );
json merge_json_other(       const struct savegame *sg, json j );
json merge_json_stuff(       const struct savegame *sg, json j );
json merge_json_tail(        const struct savegame *sg, json j );

json merge_json_player_list( const struct savegame *sg, json j );

/*
json merge_json_colony_list( const struct savegame *sg, json j );
json merge_json_unit_list(   const struct savegame *sg, json j );
json merge_json_nation_list( const struct savegame *sg, json j );
json merge_json_tribe_list(  const struct savegame *sg, json j );
json merge_json_indian_list( const struct savegame *sg, json j );
json merge_json_map(         const struct savegame *sg, json j );
*/

void print_json( const struct savegame *sg )
{
    json j = json_base();

    j = merge_json_head(        sg , j );
    j = merge_json_other(       sg , j );
    j = merge_json_stuff(       sg , j );
    j = merge_json_tail(        sg , j );
    
    j = merge_json_player_list( sg , j );

    std::cout << j.dump(4) << std::endl;

/*
    j = merge_json_colony_list( sg , j );
    j = merge_json_unit_list(   sg , j );
    j = merge_json_nation_list( sg , j );
    j = merge_json_tribe_list(  sg , j );
    j = merge_json_indian_list( sg , j );
    j = merge_json_map(         sg , j );

    std::cout << j.dump(4) << std::endl;
*/

}



json merge_json_head(        const struct savegame *sg, json j )
{
    j["head"]["colony_report_options"]["unused"]["value"] = sg->head.colony_report_options.unused;
    j["head"]["colony_report_options"]["report_inefficient_government"]["value"] = sg->head.colony_report_options.report_inefficient_government;
    j["head"]["colony_report_options"]["report_raw_materials_shortages"]["value"] = sg->head.colony_report_options.report_raw_materials_shortages;
    j["head"]["colony_report_options"]["report_tools_needed_for_production"]["value"] = sg->head.colony_report_options.report_tools_needed_for_production;
    j["head"]["colony_report_options"]["report_new_cargos_available"]["value"] = sg->head.colony_report_options.report_new_cargos_available;
    j["head"]["colony_report_options"]["labels_on_cargo_and_terrain"]["value"] = sg->head.colony_report_options.labels_on_cargo_and_terrain;
    j["head"]["colony_report_options"]["labels_on_buildings"]["value"] = sg->head.colony_report_options.labels_on_buildings;
    j["head"]["colony_report_options"]["report_food_shortages"]["value"] = sg->head.colony_report_options.report_food_shortages;
    j["head"]["colony_report_options"]["report_rebel_majorities"]["value"] = sg->head.colony_report_options.report_rebel_majorities;
    j["head"]["colony_report_options"]["report_when_colonists_trained"]["value"] = sg->head.colony_report_options.report_when_colonists_trained;
    j["head"]["colony_report_options"]["report_sons_of_liberty_membership"]["value"] = sg->head.colony_report_options.report_sons_of_liberty_membership;
    j["head"]["difficulty"]["value"] = sg->head.difficulty;
    j["head"]["numbers00"]["value"] = sg->head.numbers00;
    j["head"]["autumn"]["value"] = sg->head.autumn;
    j["head"]["nation_relation"]["value"] = sg->head.nation_relation;
    j["head"]["unk0"]["value"] = sg->head.unk0;
    j["head"]["unkb"]["value"] = sg->head.unkb;
    j["head"]["map_size_x"]["value"] = sg->head.map_size_x;
    j["head"]["turn"]["value"] = sg->head.turn;
    j["head"]["tut3"]["nr10"]["value"] = sg->head.tut3.nr10;
    j["head"]["tut3"]["nr7"]["value"] = sg->head.tut3.nr7;
    j["head"]["tut3"]["nr11"]["value"] = sg->head.tut3.nr11;
    j["head"]["tut3"]["nr6"]["value"] = sg->head.tut3.nr6;
    j["head"]["tut3"]["nr8"]["value"] = sg->head.tut3.nr8;
    j["head"]["tut3"]["nr5"]["value"] = sg->head.tut3.nr5;
    j["head"]["tut3"]["nr9"]["value"] = sg->head.tut3.nr9;
    j["head"]["tut3"]["nr12"]["value"] = sg->head.tut3.nr12;
    j["head"]["map_size_y"]["value"] = sg->head.map_size_y;
    j["head"]["expeditionary_force"]["value"] = sg->head.expeditionary_force;
    j["head"]["numbers01"]["value"] = sg->head.numbers01;
    j["head"]["active_unit"]["value"] = sg->head.active_unit;
    j["head"]["founding_father"]["value"] = sg->head.founding_father;
    j["head"]["colony_count"]["value"] = sg->head.colony_count;
    j["head"]["numbers03"]["value"] = sg->head.numbers03;
    j["head"]["numbers05"]["value"] = sg->head.numbers05;
    j["head"]["tut2"]["nr1"]["value"] = sg->head.tut2.nr1;
    j["head"]["tut2"]["event_music"]["value"] = sg->head.tut2.event_music;
    j["head"]["tut2"]["nr3"]["value"] = sg->head.tut2.nr3;
    j["head"]["tut2"]["nr4"]["value"] = sg->head.tut2.nr4;
    j["head"]["tut2"]["howtowin"]["value"] = sg->head.tut2.howtowin;
    j["head"]["tut2"]["background_music"]["value"] = sg->head.tut2.background_music;
    j["head"]["tut2"]["nr2"]["value"] = sg->head.tut2.nr2;
    j["head"]["tut2"]["sound_effects"]["value"] = sg->head.tut2.sound_effects;
    j["head"]["count_down"]["value"] = sg->head.count_down;
    j["head"]["year"]["value"] = sg->head.year;
    j["head"]["numbers06"]["value"] = sg->head.numbers06;
    j["head"]["numbers02"]["value"] = sg->head.numbers02;
    j["head"]["tut1"]["nr17"]["value"] = sg->head.tut1.nr17;
    j["head"]["tut1"]["unk7"]["value"] = sg->head.tut1.unk7;
    j["head"]["tut1"]["nr16"]["value"] = sg->head.tut1.nr16;
    j["head"]["tut1"]["nr15"]["value"] = sg->head.tut1.nr15;
    j["head"]["tut1"]["nr14"]["value"] = sg->head.tut1.nr14;
    j["head"]["tut1"]["nr19"]["value"] = sg->head.tut1.nr19;
    j["head"]["tut1"]["unk3"]["value"] = sg->head.tut1.unk3;
    j["head"]["tut1"]["nr13"]["value"] = sg->head.tut1.nr13;
    j["head"]["numbers04"]["value"] = sg->head.numbers04;
    j["head"]["game_options"]["fast_piece_slide"]["value"] = sg->head.game_options.fast_piece_slide;
    j["head"]["game_options"]["water_color_cycling"]["value"] = sg->head.game_options.water_color_cycling;
    j["head"]["game_options"]["end_of_turn"]["value"] = sg->head.game_options.end_of_turn;
    j["head"]["game_options"]["unknown"]["value"] = sg->head.game_options.unknown;
    j["head"]["game_options"]["tutorial_hints"]["value"] = sg->head.game_options.tutorial_hints;
    j["head"]["game_options"]["unknown7"]["value"] = sg->head.game_options.unknown7;
    j["head"]["game_options"]["autosave"]["value"] = sg->head.game_options.autosave;
    j["head"]["game_options"]["show_foreign_moves"]["value"] = sg->head.game_options.show_foreign_moves;
    j["head"]["game_options"]["combat_analysis"]["value"] = sg->head.game_options.combat_analysis;
    j["head"]["game_options"]["show_indian_moves"]["value"] = sg->head.game_options.show_indian_moves;
    j["head"]["sig_colonize"]["value"] = sg->head.sig_colonize;
    j["head"]["tribe_count"]["value"] = sg->head.tribe_count;
    j["head"]["unit_count"]["value"] = sg->head.unit_count;
    j["head"]["numbers07"]["value"] = sg->head.numbers07;
    j["head"]["event"]["woodcut15"]["value"] = sg->head.event.woodcut15;
    j["head"]["event"]["indian_raid"]["value"] = sg->head.event.indian_raid;
    j["head"]["event"]["cargo_from_the_new_world"]["value"] = sg->head.event.cargo_from_the_new_world;
    j["head"]["event"]["building_a_colony"]["value"] = sg->head.event.building_a_colony;
    j["head"]["event"]["meeting_fellow_europeans"]["value"] = sg->head.event.meeting_fellow_europeans;
    j["head"]["event"]["colony_destroyed"]["value"] = sg->head.event.colony_destroyed;
    j["head"]["event"]["meeting_the_natives"]["value"] = sg->head.event.meeting_the_natives;
    j["head"]["event"]["discovery_of_the_pacific_ocean"]["value"] = sg->head.event.discovery_of_the_pacific_ocean;
    j["head"]["event"]["the_fountain_of_youth"]["value"] = sg->head.event.the_fountain_of_youth;
    j["head"]["event"]["woodcut14"]["value"] = sg->head.event.woodcut14;
    j["head"]["event"]["woodcut16"]["value"] = sg->head.event.woodcut16;
    j["head"]["event"]["colony_burning"]["value"] = sg->head.event.colony_burning;
    j["head"]["event"]["the_aztec_empire"]["value"] = sg->head.event.the_aztec_empire;
    j["head"]["event"]["entering_indian_village"]["value"] = sg->head.event.entering_indian_village;
    j["head"]["event"]["discovery_of_the_new_world"]["value"] = sg->head.event.discovery_of_the_new_world;
    j["head"]["event"]["the_inca_nation"]["value"] = sg->head.event.the_inca_nation;
    j["head"]["unk1"]["value"] = sg->head.unk1;
    return j;
}


json merge_json_other(        const struct savegame *sg, json j )
{
    j["other"]["unkXX_xx"]["value"] = sg->other.unkXX_xx;
    return j;
}


json merge_json_stuff(        const struct savegame *sg, json j )
{
    j["stuff"]["unk_short"]["value"] = sg->stuff.unk_short;
    j["stuff"]["counter_increasing_on_new_colony"]["value"] = sg->stuff.counter_increasing_on_new_colony;
    j["stuff"]["unk_big"]["value"] = sg->stuff.unk_big;
    j["stuff"]["counter_decreasing_on_new_colony"]["value"] = sg->stuff.counter_decreasing_on_new_colony;
    j["stuff"]["unk7"]["value"] = sg->stuff.unk7;
    j["stuff"]["unk15"]["value"] = sg->stuff.unk15;
    j["stuff"]["viewport_y"]["value"] = sg->stuff.viewport_y;
    j["stuff"]["y"]["value"] = sg->stuff.y;
    j["stuff"]["viewport_x"]["value"] = sg->stuff.viewport_x;
    j["stuff"]["zoom_level"]["value"] = sg->stuff.zoom_level;
    j["stuff"]["x"]["value"] = sg->stuff.x;
    return j;
}


json merge_json_tail(        const struct savegame *sg, json j )
{
    j["tail"]["unk"]["value"] = sg->tail.unk;
    return j;
}


json merge_json_player_list(   const struct savegame *sg, json j )
{
    json base = j["player"];

    for (int i = 0; i < 4; ++i) {
        j["player_list"][i] = base;
        j["player_list"][i]["unk00"]["value"] = sg->player[i].unk00;
        j["player_list"][i]["founded_colonies"]["value"] = sg->player[i].founded_colonies;
        j["player_list"][i]["diplomacy"]["value"] = sg->player[i].diplomacy;
        j["player_list"][i]["name"]["value"] = sg->player[i].name;
        j["player_list"][i]["country"]["value"] = sg->player[i].country;
        j["player_list"][i]["control"]["value"] = sg->player[i].control;
    }
    return j;
}


json json_base() {
    auto j = R"(
{
   "stuff" : {
      "unk_short" : {
         "hints" : "",
         "bytes" : 2,
         "order" : 218
      },
      "counter_increasing_on_new_colony" : {
         "hints" : "",
         "bytes" : 2,
         "order" : 219
      },
      "unk_big" : {
         "hints" : "",
         "bytes" : 696,
         "order" : 220
      },
      "counter_decreasing_on_new_colony" : {
         "bytes" : 2,
         "hints" : "",
         "order" : 217
      },
      "unk7" : {
         "order" : 224,
         "hints" : "",
         "bytes" : 1
      },
      "unk15" : {
         "order" : 216,
         "bytes" : 15,
         "hints" : ""
      },
      "viewport_y" : {
         "hints" : "",
         "bytes" : 2,
         "order" : 226
      },
      "y" : {
         "bytes" : 2,
         "hints" : "",
         "order" : 222
      },
      "viewport_x" : {
         "bytes" : 2,
         "hints" : "",
         "order" : 225
      },
      "zoom_level" : {
         "order" : 223,
         "hints" : "",
         "bytes" : 1
      },
      "x" : {
         "hints" : "",
         "bytes" : 2,
         "order" : 221
      }
   },
   "unit" : {
      "unk05" : {
         "bytes" : 1,
         "hints" : "",
         "order" : 151
      },
      "unk06" : {
         "bytes" : 1,
         "hints" : "",
         "order" : 153
      },
      "moves" : {
         "order" : 152,
         "hints" : " /* Accumulated moves (3 between land, 1 on roads, etc.) */",
         "bytes" : 1
      },
      "type" : {
         "hints" : "",
         "bytes" : 1,
         "order" : 148
      },
      "holds_occupied" : {
         "order" : 157,
         "bytes" : 1,
         "hints" : ""
      },
      "unk08" : {
         "order" : 156,
         "hints" : "",
         "bytes" : 3
      },
      "owner" : {
         "hints" : " /* likely to be owner of unit, eng, fra, spa, dut, indian tribes, etc. */",
         "bytes" : 4,
         "order" : 149
      },
      "cargo_item_1" : {
         "hints" : "",
         "bytes" : 4,
         "order" : 159
      },
      "transport_chain" : {
         "prev_unit_idx" : {
            "hints" : " // index to unit being transported? (treasure) ",
            "bytes" : 2,
            "order" : 168
         },
         "next_unit_idx" : {
            "order" : 167,
            "bytes" : 2,
            "hints" : ""
         }
      },
      "cargo_item_0" : {
         "order" : 158,
         "hints" : "",
         "bytes" : 4
      },
      "cargo_item_4" : {
         "order" : 162,
         "bytes" : 4,
         "hints" : ""
      },
      "cargo_item_5" : {
         "order" : 163,
         "hints" : "",
         "bytes" : 4
      },
      "order" : {
         "bytes" : 1,
         "hints" : " enum { PLOW = 8, ROAD = 9 };",
         "order" : 155
      },
      "cargo_item_3" : {
         "bytes" : 4,
         "hints" : "",
         "order" : 161
      },
      "unk07" : {
         "hints" : "",
         "bytes" : 1,
         "order" : 154
      },
      "unk04" : {
         "hints" : "",
         "bytes" : 4,
         "order" : 150
      },
      "cargo_hold" : {
         "hints" : "",
         "bytes" : 6,
         "order" : 164
      },
      "x" : {
         "order" : 147,
         "hints" : "",
         "bytes" : 1
      },
      "profession" : {
         "hints" : "",
         "bytes" : 1,
         "order" : 166
      },
      "cargo_item_2" : {
         "bytes" : 4,
         "hints" : "",
         "order" : 160
      },
      "turns_worked" : {
         "order" : 165,
         "hints" : "",
         "bytes" : 1
      }
   },
   "other" : {
      "unkXX_xx" : {
         "order" : 94,
         "bytes" : 24,
         "hints" : ""
      }
   },
   "indian_relations" : {
      "unk1" : {
         "bytes" : 8,
         "hints" : "",
         "order" : 214
      },
      "unk0" : {
         "order" : 212,
         "bytes" : 58,
         "hints" : ""
      },
      "meeting" : {
         "order" : 213,
         "hints" : "",
         "bytes" : 4
      },
      "aggr" : {
         "hints" : "",
         "bytes" : 8,
         "order" : 215
      }
   },
   "tribe" : {
      "panic" : {
         "hints" : "",
         "bytes" : 1,
         "order" : 209
      },
      "nation" : {
         "hints" : "",
         "bytes" : 1,
         "order" : 197
      },
      "unk2" : {
         "hints" : "",
         "bytes" : 6,
         "order" : 210
      },
      "population_loss_in_current_turn" : {
         "bytes" : 1,
         "hints" : " //due to attacks",
         "order" : 211
      },
      "mission" : {
         "order" : 207,
         "hints" : " //ff if none, 0 1 2 3 = eng fra spa dut",
         "bytes" : 1
      },
      "state" : {
         "artillery" : {
            "bytes" : 1,
            "hints" : " //artillery has been nearby?",
            "order" : 198
         },
         "unk8" : {
            "bytes" : 1,
            "hints" : "",
            "order" : 205
         },
         "unk5" : {
            "hints" : "",
            "bytes" : 1,
            "order" : 202
         },
         "learned" : {
            "order" : 199,
            "hints" : " //visited and learned skill",
            "bytes" : 1
         },
         "capital" : {
            "hints" : "",
            "bytes" : 1,
            "order" : 200
         },
         "unk7" : {
            "order" : 204,
            "bytes" : 1,
            "hints" : ""
         },
         "scouted" : {
            "bytes" : 1,
            "hints" : " //visited by scout",
            "order" : 201
         },
         "unk6" : {
            "hints" : "",
            "bytes" : 1,
            "order" : 203
         }
      },
      "unk1" : {
         "hints" : "",
         "bytes" : 4,
         "order" : 208
      },
      "population" : {
         "order" : 206,
         "bytes" : 1,
         "hints" : ""
      },
      "x" : {
         "order" : 196,
         "bytes" : 1,
         "hints" : ""
      }
   },
   "player" : {
      "unk00" : {
         "bytes" : 1,
         "hints" : "",
         "order" : 90
      },
      "founded_colonies" : {
         "bytes" : 1,
         "hints" : " // founded colonies, probably used pick next colony name",
         "order" : 92
      },
      "diplomacy" : {
         "hints" : "",
         "bytes" : 1,
         "order" : 93
      },
      "name" : {
         "order" : 88,
         "bytes" : 24,
         "hints" : ""
      },
      "country" : {
         "bytes" : 24,
         "hints" : "",
         "order" : 89
      },
      "control" : {
         "order" : 91,
         "hints" : " enum { PLAYER = 0, AI = 1 };",
         "bytes" : 1
      }
   },
   "nation" : {
      "unk3" : {
         "order" : 177,
         "bytes" : 2,
         "hints" : ""
      },
      "artillery_count" : {
         "order" : 183,
         "hints" : " //artillery purchased in europe. 500 + (count * 100) price penalty.",
         "bytes" : 2
      },
      "liberty_bells_last_turn" : {
         "order" : 176,
         "bytes" : 2,
         "hints" : ""
      },
      "liberty_bells_total" : {
         "hints" : "",
         "bytes" : 2,
         "order" : 175
      },
      "crosses" : {
         "order" : 187,
         "hints" : "",
         "bytes" : 2
      },
      "boycott_bitmap" : {
         "order" : 184,
         "hints" : "",
         "bytes" : 2
      },
      "indian_relation" : {
         "hints" : " enum { NOT_MET = 0x00, WAR = 0x20, PEACE = 0x60};",
         "bytes" : 8,
         "order" : 189
      },
      "villages_burned" : {
         "order" : 181,
         "hints" : "",
         "bytes" : 1
      },
      "unk2" : {
         "order" : 174,
         "hints" : "",
         "bytes" : 5
      },
      "trade" : {
         "gold" : {
            "order" : 193,
            "bytes" : 64,
            "hints" : ""
         },
         "euro_price" : {
            "bytes" : 16,
            "hints" : "",
            "order" : 191
         },
         "tons" : {
            "bytes" : 64,
            "hints" : "",
            "order" : 194
         },
         "nr" : {
            "order" : 192,
            "bytes" : 32,
            "hints" : ""
         },
         "tons2" : {
            "order" : 195,
            "hints" : "",
            "bytes" : 64
         }
      },
      "recruit" : {
         "hints" : "",
         "bytes" : 3,
         "order" : 171
      },
      "unk0" : {
         "bytes" : 1,
         "hints" : "",
         "order" : 169
      },
      "unk4" : {
         "order" : 182,
         "hints" : "",
         "bytes" : 5
      },
      "tax_rate" : {
         "order" : 170,
         "hints" : "",
         "bytes" : 1
      },
      "gold" : {
         "bytes" : 4,
         "hints" : "",
         "order" : 186
      },
      "unk5" : {
         "hints" : "",
         "bytes" : 8,
         "order" : 185
      },
      "next_founding_father" : {
         "order" : 178,
         "bytes" : 2,
         "hints" : ""
      },
      "unk1" : {
         "order" : 172,
         "bytes" : 1,
         "hints" : ""
      },
      "unk7" : {
         "order" : 190,
         "bytes" : 12,
         "hints" : ""
      },
      "unk6" : {
         "order" : 188,
         "bytes" : 8,
         "hints" : ""
      },
      "recruit_count" : {
         "bytes" : 1,
         "hints" : " //recruit penalty 120 + (count * 20) (does not go above 180) ",
         "order" : 173
      },
      "founding_father_count" : {
         "order" : 179,
         "bytes" : 2,
         "hints" : ""
      },
      "ffc_high" : {
         "bytes" : 2,
         "hints" : " //suspect founding_father_count is 32bit.",
         "order" : 180
      }
   },
   "tail" : {
      "unk" : {
         "order" : 228,
         "hints" : "",
         "bytes" : 1502
      }
   },
   "head" : {
      "colony_report_options" : {
         "unused" : {
            "hints" : "",
            "bytes" : 12,
            "order" : 34
         },
         "report_inefficient_government" : {
            "hints" : "",
            "bytes" : 2,
            "order" : 27
         },
         "report_raw_materials_shortages" : {
            "order" : 29,
            "hints" : "",
            "bytes" : 2
         },
         "report_tools_needed_for_production" : {
            "hints" : "",
            "bytes" : 2,
            "order" : 28
         },
         "report_new_cargos_available" : {
            "hints" : "",
            "bytes" : 2,
            "order" : 26
         },
         "labels_on_cargo_and_terrain" : {
            "bytes" : 2,
            "hints" : "",
            "order" : 24
         },
         "labels_on_buildings" : {
            "bytes" : 2,
            "hints" : "",
            "order" : 25
         },
         "report_food_shortages" : {
            "bytes" : 2,
            "hints" : "",
            "order" : 30
         },
         "report_rebel_majorities" : {
            "order" : 33,
            "hints" : "",
            "bytes" : 2
         },
         "report_when_colonists_trained" : {
            "hints" : "",
            "bytes" : 2,
            "order" : 31
         },
         "report_sons_of_liberty_membership" : {
            "hints" : "",
            "bytes" : 2,
            "order" : 32
         }
      },
      "difficulty" : {
         "hints" : " enum { DISCOVERER = 0, EXPLORER = 1, CONQUISTADOR = 2, GOVERNOR = 3, VICEROY = 4 }; //36",
         "bytes" : 1,
         "order" : 62
      },
      "numbers00" : {
         "order" : 51,
         "hints" : "",
         "bytes" : 2
      },
      "autumn" : {
         "order" : 53,
         "hints" : " //boolean, true if autumn",
         "bytes" : 2
      },
      "nation_relation" : {
         "order" : 66,
         "hints" : "",
         "bytes" : 8
      },
      "unk0" : {
         "hints" : "",
         "bytes" : 3,
         "order" : 2
      },
      "unkb" : {
         "order" : 87,
         "hints" : "",
         "bytes" : 2
      },
      "map_size_x" : {
         "order" : 3,
         "hints" : "",
         "bytes" : 2
      },
      "turn" : {
         "order" : 54,
         "bytes" : 2,
         "hints" : ""
      },
      "tut3" : {
         "nr10" : {
            "order" : 48,
            "bytes" : 1,
            "hints" : ""
         },
         "nr7" : {
            "hints" : "",
            "bytes" : 1,
            "order" : 45
         },
         "nr11" : {
            "order" : 49,
            "bytes" : 1,
            "hints" : ""
         },
         "nr6" : {
            "hints" : "",
            "bytes" : 1,
            "order" : 44
         },
         "nr8" : {
            "bytes" : 1,
            "hints" : "",
            "order" : 46
         },
         "nr5" : {
            "order" : 43,
            "bytes" : 1,
            "hints" : ""
         },
         "nr9" : {
            "order" : 47,
            "hints" : "",
            "bytes" : 1
         },
         "nr12" : {
            "order" : 50,
            "hints" : "",
            "bytes" : 1
         }
      },
      "map_size_y" : {
         "hints" : "",
         "bytes" : 2,
         "order" : 4
      },
      "expeditionary_force" : {
         "order" : 68,
         "bytes" : 8,
         "hints" : ""
      },
      "numbers01" : {
         "order" : 55,
         "hints" : "",
         "bytes" : 2
      },
      "active_unit" : {
         "order" : 56,
         "bytes" : 2,
         "hints" : ""
      },
      "founding_father" : {
         "bytes" : 25,
         "hints" : "",
         "order" : 64
      },
      "colony_count" : {
         "hints" : "",
         "bytes" : 2,
         "order" : 60
      },
      "numbers03" : {
         "hints" : "",
         "bytes" : 6,
         "order" : 61
      },
      "numbers05" : {
         "order" : 65,
         "bytes" : 6,
         "hints" : ""
      },
      "tut2" : {
         "nr1" : {
            "order" : 39,
            "bytes" : 1,
            "hints" : " // shown immediately on game-start"
         },
         "event_music" : {
            "order" : 37,
            "hints" : "",
            "bytes" : 1
         },
         "nr3" : {
            "order" : 41,
            "bytes" : 1,
            "hints" : ""
         },
         "nr4" : {
            "hints" : "",
            "bytes" : 1,
            "order" : 42
         },
         "howtowin" : {
            "order" : 35,
            "bytes" : 1,
            "hints" : ""
         },
         "background_music" : {
            "order" : 36,
            "hints" : "",
            "bytes" : 1
         },
         "nr2" : {
            "order" : 40,
            "hints" : " // probably not used, also triggers event_discovery_of_the_new_world",
            "bytes" : 1
         },
         "sound_effects" : {
            "bytes" : 1,
            "hints" : "",
            "order" : 38
         }
      },
      "count_down" : {
         "bytes" : 32,
         "hints" : "",
         "order" : 70
      },
      "year" : {
         "bytes" : 2,
         "hints" : "",
         "order" : 52
      },
      "numbers06" : {
         "order" : 67,
         "hints" : "",
         "bytes" : 10
      },
      "numbers02" : {
         "hints" : "",
         "bytes" : 6,
         "order" : 57
      },
      "tut1" : {
         "nr17" : {
            "order" : 10,
            "bytes" : 1,
            "hints" : ""
         },
         "unk7" : {
            "order" : 11,
            "bytes" : 1,
            "hints" : ""
         },
         "nr16" : {
            "order" : 9,
            "hints" : "",
            "bytes" : 1
         },
         "nr15" : {
            "order" : 8,
            "hints" : "",
            "bytes" : 1
         },
         "nr14" : {
            "hints" : "",
            "bytes" : 1,
            "order" : 6
         },
         "nr19" : {
            "bytes" : 1,
            "hints" : "",
            "order" : 12
         },
         "unk3" : {
            "order" : 7,
            "hints" : "",
            "bytes" : 1
         },
         "nr13" : {
            "hints" : "",
            "bytes" : 1,
            "order" : 5
         }
      },
      "numbers04" : {
         "order" : 63,
         "bytes" : 2,
         "hints" : ""
      },
      "game_options" : {
         "fast_piece_slide" : {
            "order" : 20,
            "hints" : "",
            "bytes" : 2
         },
         "water_color_cycling" : {
            "order" : 16,
            "hints" : "",
            "bytes" : 2
         },
         "end_of_turn" : {
            "order" : 19,
            "bytes" : 2,
            "hints" : ""
         },
         "unknown" : {
            "bytes" : 2,
            "hints" : "",
            "order" : 21
         },
         "tutorial_hints" : {
            "hints" : "",
            "bytes" : 2,
            "order" : 15
         },
         "unknown7" : {
            "bytes" : 14,
            "hints" : "",
            "order" : 14
         },
         "autosave" : {
            "order" : 18,
            "hints" : "",
            "bytes" : 2
         },
         "show_foreign_moves" : {
            "bytes" : 2,
            "hints" : "",
            "order" : 22
         },
         "combat_analysis" : {
            "bytes" : 2,
            "hints" : "",
            "order" : 17
         },
         "show_indian_moves" : {
            "hints" : "",
            "bytes" : 2,
            "order" : 23
         }
      },
      "sig_colonize" : {
         "order" : 1,
         "bytes" : 9,
         "hints" : ""
      },
      "tribe_count" : {
         "hints" : "",
         "bytes" : 2,
         "order" : 58
      },
      "unit_count" : {
         "order" : 59,
         "bytes" : 2,
         "hints" : ""
      },
      "numbers07" : {
         "order" : 69,
         "bytes" : 8,
         "hints" : " //backup force, once you produce enough bells."
      },
      "event" : {
         "woodcut15" : {
            "hints" : "",
            "bytes" : 2,
            "order" : 85
         },
         "indian_raid" : {
            "hints" : "",
            "bytes" : 2,
            "order" : 83
         },
         "cargo_from_the_new_world" : {
            "bytes" : 2,
            "hints" : "",
            "order" : 79
         },
         "building_a_colony" : {
            "hints" : "",
            "bytes" : 2,
            "order" : 72
         },
         "meeting_fellow_europeans" : {
            "order" : 80,
            "bytes" : 2,
            "hints" : ""
         },
         "colony_destroyed" : {
            "bytes" : 2,
            "hints" : "",
            "order" : 82
         },
         "meeting_the_natives" : {
            "order" : 73,
            "bytes" : 2,
            "hints" : ""
         },
         "discovery_of_the_pacific_ocean" : {
            "bytes" : 2,
            "hints" : "",
            "order" : 76
         },
         "the_fountain_of_youth" : {
            "bytes" : 2,
            "hints" : "",
            "order" : 78
         },
         "woodcut14" : {
            "order" : 84,
            "bytes" : 2,
            "hints" : ""
         },
         "woodcut16" : {
            "bytes" : 2,
            "hints" : "",
            "order" : 86
         },
         "colony_burning" : {
            "bytes" : 2,
            "hints" : "",
            "order" : 81
         },
         "the_aztec_empire" : {
            "bytes" : 2,
            "hints" : "",
            "order" : 74
         },
         "entering_indian_village" : {
            "hints" : "",
            "bytes" : 2,
            "order" : 77
         },
         "discovery_of_the_new_world" : {
            "hints" : "",
            "bytes" : 2,
            "order" : 71
         },
         "the_inca_nation" : {
            "bytes" : 2,
            "hints" : "",
            "order" : 75
         }
      },
      "unk1" : {
         "order" : 13,
         "bytes" : 1,
         "hints" : ""
      }
   },
   "map" : {
      "order" : 227,
      "bytes" : 4176,
      "hints" : "// 56*70 visible + border, = 58*72 = 4176,"
   },
   "colony" : {
      "buildings" : {
         "stables" : {
            "order" : 111,
            "bytes" : 4,
            "hints" : ""
         },
         "fur_traders_house" : {
            "bytes" : 6,
            "hints" : "",
            "order" : 118
         },
         "unused" : {
            "order" : 122,
            "bytes" : 12,
            "hints" : ""
         },
         "weavers_house" : {
            "order" : 114,
            "hints" : "",
            "bytes" : 12
         },
         "printing_press" : {
            "order" : 113,
            "hints" : "",
            "bytes" : 8
         },
         "town_hall" : {
            "hints" : "",
            "bytes" : 12,
            "order" : 108
         },
         "armory" : {
            "hints" : "",
            "bytes" : 12,
            "order" : 106
         },
         "capitol" : {
            "hints" : " /* not really in use */",
            "bytes" : 8,
            "order" : 117
         },
         "church" : {
            "bytes" : 4,
            "hints" : "",
            "order" : 120
         },
         "rum_distillers_house" : {
            "bytes" : 12,
            "hints" : "",
            "order" : 116
         },
         "warehouse" : {
            "order" : 110,
            "bytes" : 8,
            "hints" : ""
         },
         "custom_house" : {
            "order" : 112,
            "bytes" : 4,
            "hints" : ""
         },
         "schoolhouse" : {
            "order" : 109,
            "bytes" : 12,
            "hints" : ""
         },
         "docks" : {
            "order" : 107,
            "hints" : "",
            "bytes" : 12
         },
         "tobacconists_house" : {
            "hints" : "",
            "bytes" : 12,
            "order" : 115
         },
         "carpenters_shop" : {
            "order" : 119,
            "bytes" : 4,
            "hints" : ""
         },
         "blacksmiths_house" : {
            "hints" : "",
            "bytes" : 6,
            "order" : 121
         },
         "stockade" : {
            "order" : 105,
            "bytes" : 12,
            "hints" : ""
         }
      },
      "profession" : {
         "order" : 101,
         "bytes" : 32,
         "hints" : ""
      },
      "x" : {
         "bytes" : 1,
         "hints" : "",
         "order" : 95
      },
      "tiles" : {
         "order" : 103,
         "hints" : " //represents tiles around the colony. idx to citizen.",
         "bytes" : 8
      },
      "population" : {
         "order" : 99,
         "bytes" : 1,
         "hints" : ""
      },
      "unk0" : {
         "order" : 98,
         "bytes" : 4,
         "hints" : ""
      },
      "rebel_divisor" : {
         "hints" : "",
         "bytes" : 4,
         "order" : 146
      },
      "building_in_production" : {
         "hints" : "",
         "bytes" : 1,
         "order" : 141
      },
      "name" : {
         "order" : 96,
         "hints" : "",
         "bytes" : 24
      },
      "unkb" : {
         "hints" : "",
         "bytes" : 5,
         "order" : 142
      },
      "occupation" : {
         "order" : 100,
         "hints" : "",
         "bytes" : 32
      },
      "stock" : {
         "order" : 143,
         "hints" : "",
         "bytes" : 32
      },
      "nation" : {
         "order" : 97,
         "bytes" : 1,
         "hints" : ""
      },
      "unk8" : {
         "order" : 104,
         "hints" : "",
         "bytes" : 12
      },
      "unkd" : {
         "bytes" : 8,
         "hints" : "",
         "order" : 144
      },
      "custom_house" : {
         "tools" : {
            "order" : 137,
            "bytes" : 2,
            "hints" : ""
         },
         "trade_goods" : {
            "order" : 136,
            "hints" : "",
            "bytes" : 2
         },
         "sugar" : {
            "hints" : "",
            "bytes" : 2,
            "order" : 124
         },
         "silver" : {
            "order" : 130,
            "bytes" : 2,
            "hints" : ""
         },
         "ore" : {
            "bytes" : 2,
            "hints" : "",
            "order" : 129
         },
         "muskets" : {
            "order" : 138,
            "hints" : "",
            "bytes" : 2
         },
         "cotton" : {
            "order" : 126,
            "bytes" : 2,
            "hints" : ""
         },
         "food" : {
            "bytes" : 2,
            "hints" : "",
            "order" : 123
         },
         "cloth" : {
            "order" : 134,
            "hints" : "",
            "bytes" : 2
         },
         "tobacco" : {
            "order" : 125,
            "bytes" : 2,
            "hints" : ""
         },
         "horses" : {
            "order" : 131,
            "bytes" : 2,
            "hints" : ""
         },
         "lumber" : {
            "order" : 128,
            "hints" : "",
            "bytes" : 2
         },
         "rum" : {
            "hints" : "",
            "bytes" : 2,
            "order" : 132
         },
         "cigars" : {
            "hints" : "",
            "bytes" : 2,
            "order" : 133
         },
         "furs" : {
            "hints" : "",
            "bytes" : 2,
            "order" : 127
         },
         "coats" : {
            "order" : 135,
            "hints" : "",
            "bytes" : 2
         }
      },
      "unk6" : {
         "order" : 102,
         "bytes" : 16,
         "hints" : ""
      },
      "unka" : {
         "hints" : "",
         "bytes" : 6,
         "order" : 139
      },
      "hammers" : {
         "bytes" : 2,
         "hints" : "",
         "order" : 140
      },
      "rebel_dividend" : {
         "bytes" : 4,
         "hints" : "",
         "order" : 145
      }
   }
}

    )"_json;
    return j;
}
