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

/*
json merge_json_player_list( const struct savegame *sg, json j );
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
    
    std::cout << j.dump(4) << std::endl;

/*
    j = merge_json_player_list( sg , j );
    j = merge_json_colony_list( sg , j );
    j = merge_json_unit_list(   sg , j );
    j = merge_json_nation_list( sg , j );
    j = merge_json_tribe_list(  sg , j );
    j = merge_json_indian_list( sg , j );
    j = merge_json_map(         sg , j );

    json p = j["player"];

    for (int i = 0; i < 4; ++i) {
        j["player_list"][i] = p;
        j["player_list"][i]["nation"]["is"] = nation_list[i];
        j["player_list"][i]["name"]["is"] = sg->player[i].name;
        j["player_list"][i]["country"]["is"] = sg->player[i].country;
    }

    std::cout << j.dump(4) << std::endl;
*/

}


json merge_json_head(        const struct savegame *sg, json j )
{
    j["head"]["tut3"]["nr8"]["is"] = sg->head.tut3.nr8;
    j["head"]["tut3"]["nr7"]["is"] = sg->head.tut3.nr7;
    j["head"]["tut3"]["nr11"]["is"] = sg->head.tut3.nr11;
    j["head"]["tut3"]["nr6"]["is"] = sg->head.tut3.nr6;
    j["head"]["tut3"]["nr9"]["is"] = sg->head.tut3.nr9;
    j["head"]["tut3"]["nr5"]["is"] = sg->head.tut3.nr5;
    j["head"]["tut3"]["nr10"]["is"] = sg->head.tut3.nr10;
    j["head"]["tut3"]["nr12"]["is"] = sg->head.tut3.nr12;
    j["head"]["event"]["woodcut14"]["is"] = sg->head.event.woodcut14;
    j["head"]["event"]["meeting_the_natives"]["is"] = sg->head.event.meeting_the_natives;
    j["head"]["event"]["cargo_from_the_new_world"]["is"] = sg->head.event.cargo_from_the_new_world;
    j["head"]["event"]["discovery_of_the_new_world"]["is"] = sg->head.event.discovery_of_the_new_world;
    j["head"]["event"]["meeting_fellow_europeans"]["is"] = sg->head.event.meeting_fellow_europeans;
    j["head"]["event"]["indian_raid"]["is"] = sg->head.event.indian_raid;
    j["head"]["event"]["building_a_colony"]["is"] = sg->head.event.building_a_colony;
    j["head"]["event"]["woodcut15"]["is"] = sg->head.event.woodcut15;
    j["head"]["event"]["discovery_of_the_pacific_ocean"]["is"] = sg->head.event.discovery_of_the_pacific_ocean;
    j["head"]["event"]["colony_burning"]["is"] = sg->head.event.colony_burning;
    j["head"]["event"]["colony_destroyed"]["is"] = sg->head.event.colony_destroyed;
    j["head"]["event"]["woodcut16"]["is"] = sg->head.event.woodcut16;
    j["head"]["event"]["the_inca_nation"]["is"] = sg->head.event.the_inca_nation;
    j["head"]["event"]["the_aztec_empire"]["is"] = sg->head.event.the_aztec_empire;
    j["head"]["event"]["the_fountain_of_youth"]["is"] = sg->head.event.the_fountain_of_youth;
    j["head"]["event"]["entering_indian_village"]["is"] = sg->head.event.entering_indian_village;
    j["head"]["tribe_count"]["is"] = sg->head.tribe_count;
    j["head"]["numbers07"]["is"] = sg->head.numbers07;
    j["head"]["unk0"]["is"] = sg->head.unk0;
    j["head"]["numbers06"]["is"] = sg->head.numbers06;
    j["head"]["game_options"]["unknown7"]["is"] = sg->head.game_options.unknown7;
    j["head"]["game_options"]["show_foreign_moves"]["is"] = sg->head.game_options.show_foreign_moves;
    j["head"]["game_options"]["tutorial_hints"]["is"] = sg->head.game_options.tutorial_hints;
    j["head"]["game_options"]["combat_analysis"]["is"] = sg->head.game_options.combat_analysis;
    j["head"]["game_options"]["show_indian_moves"]["is"] = sg->head.game_options.show_indian_moves;
    j["head"]["game_options"]["unknown"]["is"] = sg->head.game_options.unknown;
    j["head"]["game_options"]["end_of_turn"]["is"] = sg->head.game_options.end_of_turn;
    j["head"]["game_options"]["fast_piece_slide"]["is"] = sg->head.game_options.fast_piece_slide;
    j["head"]["game_options"]["autosave"]["is"] = sg->head.game_options.autosave;
    j["head"]["game_options"]["water_color_cycling"]["is"] = sg->head.game_options.water_color_cycling;
    j["head"]["numbers02"]["is"] = sg->head.numbers02;
    j["head"]["expeditionary_force"]["is"] = sg->head.expeditionary_force;
    j["head"]["numbers03"]["is"] = sg->head.numbers03;
    j["head"]["founding_father"]["is"] = sg->head.founding_father;
    j["head"]["numbers01"]["is"] = sg->head.numbers01;
    j["head"]["tut1"]["nr14"]["is"] = sg->head.tut1.nr14;
    j["head"]["tut1"]["unk3"]["is"] = sg->head.tut1.unk3;
    j["head"]["tut1"]["nr17"]["is"] = sg->head.tut1.nr17;
    j["head"]["tut1"]["nr15"]["is"] = sg->head.tut1.nr15;
    j["head"]["tut1"]["nr19"]["is"] = sg->head.tut1.nr19;
    j["head"]["tut1"]["unk7"]["is"] = sg->head.tut1.unk7;
    j["head"]["tut1"]["nr13"]["is"] = sg->head.tut1.nr13;
    j["head"]["tut1"]["nr16"]["is"] = sg->head.tut1.nr16;
    j["head"]["year"]["is"] = sg->head.year;
    j["head"]["numbers04"]["is"] = sg->head.numbers04;
    j["head"]["unkb"]["is"] = sg->head.unkb;
    j["head"]["count_down"]["is"] = sg->head.count_down;
    j["head"]["sig_colonize"]["is"] = sg->head.sig_colonize;
    j["head"]["unk1"]["is"] = sg->head.unk1;
    j["head"]["tut2"]["nr1"]["is"] = sg->head.tut2.nr1;
    j["head"]["tut2"]["nr4"]["is"] = sg->head.tut2.nr4;
    j["head"]["tut2"]["background_music"]["is"] = sg->head.tut2.background_music;
    j["head"]["tut2"]["howtowin"]["is"] = sg->head.tut2.howtowin;
    j["head"]["tut2"]["event_music"]["is"] = sg->head.tut2.event_music;
    j["head"]["tut2"]["sound_effects"]["is"] = sg->head.tut2.sound_effects;
    j["head"]["tut2"]["nr3"]["is"] = sg->head.tut2.nr3;
    j["head"]["tut2"]["nr2"]["is"] = sg->head.tut2.nr2;
    j["head"]["map_size_x"]["is"] = sg->head.map_size_x;
    j["head"]["active_unit"]["is"] = sg->head.active_unit;
    j["head"]["colony_report_options"]["report_food_shortages"]["is"] = sg->head.colony_report_options.report_food_shortages;
    j["head"]["colony_report_options"]["report_raw_materials_shortages"]["is"] = sg->head.colony_report_options.report_raw_materials_shortages;
    j["head"]["colony_report_options"]["report_sons_of_liberty_membership"]["is"] = sg->head.colony_report_options.report_sons_of_liberty_membership;
    j["head"]["colony_report_options"]["report_inefficient_government"]["is"] = sg->head.colony_report_options.report_inefficient_government;
    j["head"]["colony_report_options"]["report_new_cargos_available"]["is"] = sg->head.colony_report_options.report_new_cargos_available;
    j["head"]["colony_report_options"]["report_rebel_majorities"]["is"] = sg->head.colony_report_options.report_rebel_majorities;
    j["head"]["colony_report_options"]["report_when_colonists_trained"]["is"] = sg->head.colony_report_options.report_when_colonists_trained;
    j["head"]["colony_report_options"]["report_tools_needed_for_production"]["is"] = sg->head.colony_report_options.report_tools_needed_for_production;
    j["head"]["colony_report_options"]["labels_on_buildings"]["is"] = sg->head.colony_report_options.labels_on_buildings;
    j["head"]["colony_report_options"]["labels_on_cargo_and_terrain"]["is"] = sg->head.colony_report_options.labels_on_cargo_and_terrain;
    j["head"]["colony_report_options"]["unused"]["is"] = sg->head.colony_report_options.unused;
    j["head"]["numbers05"]["is"] = sg->head.numbers05;
    j["head"]["nation_relation"]["is"] = sg->head.nation_relation;
    j["head"]["difficulty"]["is"] = sg->head.difficulty;
    j["head"]["unit_count"]["is"] = sg->head.unit_count;
    j["head"]["map_size_y"]["is"] = sg->head.map_size_y;
    j["head"]["colony_count"]["is"] = sg->head.colony_count;
    j["head"]["autumn"]["is"] = sg->head.autumn;
    j["head"]["turn"]["is"] = sg->head.turn;
    j["head"]["numbers00"]["is"] = sg->head.numbers00;
    return j;
}


json merge_json_other(        const struct savegame *sg, json j )
{
    j["other"]["unkXX_xx"]["is"] = sg->other.unkXX_xx;
    return j;
}


json merge_json_stuff(        const struct savegame *sg, json j )
{
    j["stuff"]["viewport_y"]["is"] = sg->stuff.viewport_y;
    j["stuff"]["x"]["is"] = sg->stuff.x;
    j["stuff"]["unk15"]["is"] = sg->stuff.unk15;
    j["stuff"]["counter_decreasing_on_new_colony"]["is"] = sg->stuff.counter_decreasing_on_new_colony;
    j["stuff"]["unk_big"]["is"] = sg->stuff.unk_big;
    j["stuff"]["y"]["is"] = sg->stuff.y;
    j["stuff"]["unk_short"]["is"] = sg->stuff.unk_short;
    j["stuff"]["zoom_level"]["is"] = sg->stuff.zoom_level;
    j["stuff"]["viewport_x"]["is"] = sg->stuff.viewport_x;
    j["stuff"]["counter_increasing_on_new_colony"]["is"] = sg->stuff.counter_increasing_on_new_colony;
    j["stuff"]["unk7"]["is"] = sg->stuff.unk7;
    return j;
}


json merge_json_tail(        const struct savegame *sg, json j )
{
    j["tail"]["unk"]["is"] = sg->tail.unk;
    return j;
}


json json_base() {
    auto j = R"(
{
   "head" : {
      "tut3" : {
         "nr8" : {
            "comment" : "",
            "bytes" : 1,
            "order" : 46
         },
         "nr7" : {
            "order" : 45,
            "bytes" : 1,
            "comment" : ""
         },
         "nr11" : {
            "comment" : "",
            "bytes" : 1,
            "order" : 49
         },
         "nr6" : {
            "order" : 44,
            "bytes" : 1,
            "comment" : ""
         },
         "nr9" : {
            "comment" : "",
            "bytes" : 1,
            "order" : 47
         },
         "nr5" : {
            "comment" : "",
            "bytes" : 1,
            "order" : 43
         },
         "nr10" : {
            "bytes" : 1,
            "comment" : "",
            "order" : 48
         },
         "nr12" : {
            "order" : 50,
            "bytes" : 1,
            "comment" : ""
         }
      },
      "event" : {
         "woodcut14" : {
            "order" : 84,
            "comment" : "",
            "bytes" : 2
         },
         "meeting_the_natives" : {
            "order" : 73,
            "comment" : "",
            "bytes" : 2
         },
         "cargo_from_the_new_world" : {
            "comment" : "",
            "bytes" : 2,
            "order" : 79
         },
         "discovery_of_the_new_world" : {
            "order" : 71,
            "bytes" : 2,
            "comment" : ""
         },
         "meeting_fellow_europeans" : {
            "order" : 80,
            "bytes" : 2,
            "comment" : ""
         },
         "indian_raid" : {
            "order" : 83,
            "comment" : "",
            "bytes" : 2
         },
         "building_a_colony" : {
            "order" : 72,
            "bytes" : 2,
            "comment" : ""
         },
         "woodcut15" : {
            "comment" : "",
            "bytes" : 2,
            "order" : 85
         },
         "discovery_of_the_pacific_ocean" : {
            "order" : 76,
            "comment" : "",
            "bytes" : 2
         },
         "colony_burning" : {
            "order" : 81,
            "comment" : "",
            "bytes" : 2
         },
         "colony_destroyed" : {
            "order" : 82,
            "bytes" : 2,
            "comment" : ""
         },
         "woodcut16" : {
            "order" : 86,
            "bytes" : 2,
            "comment" : ""
         },
         "the_inca_nation" : {
            "comment" : "",
            "bytes" : 2,
            "order" : 75
         },
         "the_aztec_empire" : {
            "bytes" : 2,
            "comment" : "",
            "order" : 74
         },
         "the_fountain_of_youth" : {
            "comment" : "",
            "bytes" : 2,
            "order" : 78
         },
         "entering_indian_village" : {
            "order" : 77,
            "comment" : "",
            "bytes" : 2
         }
      },
      "tribe_count" : {
         "order" : 58,
         "comment" : "",
         "bytes" : 2
      },
      "numbers07" : {
         "order" : 69,
         "bytes" : 8,
         "comment" : " //backup force, once you produce enough bells."
      },
      "unk0" : {
         "comment" : "",
         "bytes" : 3,
         "order" : 2
      },
      "numbers06" : {
         "order" : 67,
         "comment" : "",
         "bytes" : 10
      },
      "game_options" : {
         "unknown7" : {
            "bytes" : 14,
            "comment" : "",
            "order" : 14
         },
         "show_foreign_moves" : {
            "order" : 22,
            "comment" : "",
            "bytes" : 2
         },
         "tutorial_hints" : {
            "comment" : "",
            "bytes" : 2,
            "order" : 15
         },
         "combat_analysis" : {
            "bytes" : 2,
            "comment" : "",
            "order" : 17
         },
         "show_indian_moves" : {
            "comment" : "",
            "bytes" : 2,
            "order" : 23
         },
         "unknown" : {
            "comment" : "",
            "bytes" : 2,
            "order" : 21
         },
         "end_of_turn" : {
            "order" : 19,
            "comment" : "",
            "bytes" : 2
         },
         "fast_piece_slide" : {
            "order" : 20,
            "bytes" : 2,
            "comment" : ""
         },
         "autosave" : {
            "order" : 18,
            "bytes" : 2,
            "comment" : ""
         },
         "water_color_cycling" : {
            "order" : 16,
            "comment" : "",
            "bytes" : 2
         }
      },
      "numbers02" : {
         "order" : 57,
         "comment" : "",
         "bytes" : 6
      },
      "expeditionary_force" : {
         "comment" : "",
         "bytes" : 8,
         "order" : 68
      },
      "numbers03" : {
         "bytes" : 6,
         "comment" : "",
         "order" : 61
      },
      "founding_father" : {
         "order" : 64,
         "bytes" : 25,
         "comment" : ""
      },
      "numbers01" : {
         "order" : 55,
         "bytes" : 2,
         "comment" : ""
      },
      "tut1" : {
         "nr14" : {
            "bytes" : 1,
            "comment" : "",
            "order" : 6
         },
         "unk3" : {
            "order" : 7,
            "bytes" : 1,
            "comment" : ""
         },
         "nr17" : {
            "order" : 10,
            "bytes" : 1,
            "comment" : ""
         },
         "nr15" : {
            "bytes" : 1,
            "comment" : "",
            "order" : 8
         },
         "nr19" : {
            "order" : 12,
            "comment" : "",
            "bytes" : 1
         },
         "unk7" : {
            "order" : 11,
            "comment" : "",
            "bytes" : 1
         },
         "nr13" : {
            "comment" : "",
            "bytes" : 1,
            "order" : 5
         },
         "nr16" : {
            "bytes" : 1,
            "comment" : "",
            "order" : 9
         }
      },
      "year" : {
         "comment" : "",
         "bytes" : 2,
         "order" : 52
      },
      "numbers04" : {
         "bytes" : 2,
         "comment" : "",
         "order" : 63
      },
      "unkb" : {
         "comment" : "",
         "bytes" : 2,
         "order" : 87
      },
      "count_down" : {
         "order" : 70,
         "comment" : "",
         "bytes" : 32
      },
      "sig_colonize" : {
         "comment" : "",
         "bytes" : 9,
         "order" : 1
      },
      "unk1" : {
         "order" : 13,
         "comment" : "",
         "bytes" : 1
      },
      "tut2" : {
         "nr1" : {
            "order" : 39,
            "comment" : " // shown immediately on game-start",
            "bytes" : 1
         },
         "nr4" : {
            "bytes" : 1,
            "comment" : "",
            "order" : 42
         },
         "background_music" : {
            "order" : 36,
            "bytes" : 1,
            "comment" : ""
         },
         "howtowin" : {
            "order" : 35,
            "bytes" : 1,
            "comment" : ""
         },
         "event_music" : {
            "comment" : "",
            "bytes" : 1,
            "order" : 37
         },
         "sound_effects" : {
            "comment" : "",
            "bytes" : 1,
            "order" : 38
         },
         "nr3" : {
            "bytes" : 1,
            "comment" : "",
            "order" : 41
         },
         "nr2" : {
            "bytes" : 1,
            "comment" : " // probably not used, also triggers event_discovery_of_the_new_world",
            "order" : 40
         }
      },
      "map_size_x" : {
         "order" : 3,
         "comment" : "",
         "bytes" : 2
      },
      "active_unit" : {
         "order" : 56,
         "bytes" : 2,
         "comment" : ""
      },
      "colony_report_options" : {
         "report_food_shortages" : {
            "order" : 30,
            "comment" : "",
            "bytes" : 2
         },
         "report_raw_materials_shortages" : {
            "comment" : "",
            "bytes" : 2,
            "order" : 29
         },
         "report_sons_of_liberty_membership" : {
            "comment" : "",
            "bytes" : 2,
            "order" : 32
         },
         "report_inefficient_government" : {
            "comment" : "",
            "bytes" : 2,
            "order" : 27
         },
         "report_new_cargos_available" : {
            "comment" : "",
            "bytes" : 2,
            "order" : 26
         },
         "report_rebel_majorities" : {
            "bytes" : 2,
            "comment" : "",
            "order" : 33
         },
         "report_when_colonists_trained" : {
            "comment" : "",
            "bytes" : 2,
            "order" : 31
         },
         "report_tools_needed_for_production" : {
            "order" : 28,
            "comment" : "",
            "bytes" : 2
         },
         "labels_on_buildings" : {
            "order" : 25,
            "comment" : "",
            "bytes" : 2
         },
         "labels_on_cargo_and_terrain" : {
            "bytes" : 2,
            "comment" : "",
            "order" : 24
         },
         "unused" : {
            "order" : 34,
            "comment" : "",
            "bytes" : 12
         }
      },
      "numbers05" : {
         "order" : 65,
         "bytes" : 6,
         "comment" : ""
      },
      "nation_relation" : {
         "bytes" : 8,
         "comment" : "",
         "order" : 66
      },
      "difficulty" : {
         "order" : 62,
         "comment" : " enum { DISCOVERER = 0, EXPLORER = 1, CONQUISTADOR = 2, GOVERNOR = 3, VICEROY = 4 }; //36",
         "bytes" : 1
      },
      "unit_count" : {
         "bytes" : 2,
         "comment" : "",
         "order" : 59
      },
      "map_size_y" : {
         "comment" : "",
         "bytes" : 2,
         "order" : 4
      },
      "colony_count" : {
         "order" : 60,
         "bytes" : 2,
         "comment" : ""
      },
      "autumn" : {
         "bytes" : 2,
         "comment" : " //boolean, true if autumn",
         "order" : 53
      },
      "turn" : {
         "order" : 54,
         "bytes" : 2,
         "comment" : ""
      },
      "numbers00" : {
         "order" : 51,
         "comment" : "",
         "bytes" : 2
      }
   },
   "map" : {
      "order" : 227,
      "bytes" : 4176,
      "comment" : "// 56*70 visible + border, = 58*72 = 4176,"
   },
   "tail" : {
      "unk" : {
         "order" : 228,
         "comment" : "",
         "bytes" : 1502
      }
   },
   "indian_relations" : {
      "unk1" : {
         "order" : 214,
         "comment" : "",
         "bytes" : 8
      },
      "unk0" : {
         "order" : 212,
         "bytes" : 58,
         "comment" : ""
      },
      "aggr" : {
         "order" : 215,
         "bytes" : 8,
         "comment" : ""
      },
      "meeting" : {
         "order" : 213,
         "bytes" : 4,
         "comment" : ""
      }
   },
   "tribe" : {
      "mission" : {
         "comment" : " //ff if none, 0 1 2 3 = eng fra spa dut",
         "bytes" : 1,
         "order" : 207
      },
      "panic" : {
         "comment" : "",
         "bytes" : 1,
         "order" : 209
      },
      "nation" : {
         "comment" : "",
         "bytes" : 1,
         "order" : 197
      },
      "population" : {
         "order" : 206,
         "comment" : "",
         "bytes" : 1
      },
      "x" : {
         "order" : 196,
         "bytes" : 1,
         "comment" : ""
      },
      "unk1" : {
         "order" : 208,
         "comment" : "",
         "bytes" : 4
      },
      "population_loss_in_current_turn" : {
         "order" : 211,
         "comment" : " //due to attacks",
         "bytes" : 1
      },
      "unk2" : {
         "comment" : "",
         "bytes" : 6,
         "order" : 210
      },
      "state" : {
         "unk8" : {
            "order" : 205,
            "bytes" : 1,
            "comment" : ""
         },
         "learned" : {
            "bytes" : 1,
            "comment" : " //visited and learned skill",
            "order" : 199
         },
         "artillery" : {
            "bytes" : 1,
            "comment" : " //artillery has been nearby?",
            "order" : 198
         },
         "scouted" : {
            "bytes" : 1,
            "comment" : " //visited by scout",
            "order" : 201
         },
         "unk7" : {
            "order" : 204,
            "bytes" : 1,
            "comment" : ""
         },
         "unk5" : {
            "order" : 202,
            "bytes" : 1,
            "comment" : ""
         },
         "unk6" : {
            "bytes" : 1,
            "comment" : "",
            "order" : 203
         },
         "capital" : {
            "comment" : "",
            "bytes" : 1,
            "order" : 200
         }
      }
   },
   "unit" : {
      "unk05" : {
         "comment" : "",
         "bytes" : 1,
         "order" : 151
      },
      "turns_worked" : {
         "comment" : "",
         "bytes" : 1,
         "order" : 165
      },
      "order" : {
         "order" : 155,
         "comment" : " enum { PLOW = 8, ROAD = 9 };",
         "bytes" : 1
      },
      "profession" : {
         "order" : 166,
         "bytes" : 1,
         "comment" : ""
      },
      "holds_occupied" : {
         "order" : 157,
         "bytes" : 1,
         "comment" : ""
      },
      "x" : {
         "bytes" : 1,
         "comment" : "",
         "order" : 147
      },
      "unk06" : {
         "order" : 153,
         "comment" : "",
         "bytes" : 1
      },
      "cargo_item_0" : {
         "comment" : "",
         "bytes" : 4,
         "order" : 158
      },
      "cargo_item_4" : {
         "order" : 162,
         "comment" : "",
         "bytes" : 4
      },
      "moves" : {
         "comment" : " /* Accumulated moves (3 between land, 1 on roads, etc.) */",
         "bytes" : 1,
         "order" : 152
      },
      "type" : {
         "comment" : "",
         "bytes" : 1,
         "order" : 148
      },
      "owner" : {
         "comment" : " /* likely to be owner of unit, eng, fra, spa, dut, indian tribes, etc. */",
         "bytes" : 4,
         "order" : 149
      },
      "unk08" : {
         "order" : 156,
         "comment" : "",
         "bytes" : 3
      },
      "transport_chain" : {
         "prev_unit_idx" : {
            "bytes" : 2,
            "comment" : " // index to unit being transported? (treasure) ",
            "order" : 168
         },
         "next_unit_idx" : {
            "bytes" : 2,
            "comment" : "",
            "order" : 167
         }
      },
      "unk04" : {
         "order" : 150,
         "comment" : "",
         "bytes" : 4
      },
      "cargo_item_5" : {
         "comment" : "",
         "bytes" : 4,
         "order" : 163
      },
      "unk07" : {
         "order" : 154,
         "comment" : "",
         "bytes" : 1
      },
      "cargo_item_3" : {
         "order" : 161,
         "bytes" : 4,
         "comment" : ""
      },
      "cargo_item_1" : {
         "bytes" : 4,
         "comment" : "",
         "order" : 159
      },
      "cargo_item_2" : {
         "order" : 160,
         "bytes" : 4,
         "comment" : ""
      },
      "cargo_hold" : {
         "bytes" : 6,
         "comment" : "",
         "order" : 164
      }
   },
   "other" : {
      "unkXX_xx" : {
         "order" : 94,
         "bytes" : 24,
         "comment" : ""
      }
   },
   "colony" : {
      "stock" : {
         "bytes" : 32,
         "comment" : "",
         "order" : 143
      },
      "buildings" : {
         "custom_house" : {
            "bytes" : 4,
            "comment" : "",
            "order" : 112
         },
         "blacksmiths_house" : {
            "order" : 121,
            "comment" : "",
            "bytes" : 6
         },
         "stockade" : {
            "bytes" : 12,
            "comment" : "",
            "order" : 105
         },
         "printing_press" : {
            "order" : 113,
            "comment" : "",
            "bytes" : 8
         },
         "carpenters_shop" : {
            "bytes" : 4,
            "comment" : "",
            "order" : 119
         },
         "weavers_house" : {
            "order" : 114,
            "bytes" : 12,
            "comment" : ""
         },
         "stables" : {
            "order" : 111,
            "comment" : "",
            "bytes" : 4
         },
         "town_hall" : {
            "order" : 108,
            "bytes" : 12,
            "comment" : ""
         },
         "capitol" : {
            "comment" : " /* not really in use */",
            "bytes" : 8,
            "order" : 117
         },
         "church" : {
            "order" : 120,
            "comment" : "",
            "bytes" : 4
         },
         "warehouse" : {
            "order" : 110,
            "comment" : "",
            "bytes" : 8
         },
         "fur_traders_house" : {
            "order" : 118,
            "comment" : "",
            "bytes" : 6
         },
         "unused" : {
            "order" : 122,
            "bytes" : 12,
            "comment" : ""
         },
         "tobacconists_house" : {
            "bytes" : 12,
            "comment" : "",
            "order" : 115
         },
         "docks" : {
            "order" : 107,
            "bytes" : 12,
            "comment" : ""
         },
         "armory" : {
            "bytes" : 12,
            "comment" : "",
            "order" : 106
         },
         "schoolhouse" : {
            "order" : 109,
            "bytes" : 12,
            "comment" : ""
         },
         "rum_distillers_house" : {
            "order" : 116,
            "bytes" : 12,
            "comment" : ""
         }
      },
      "population" : {
         "order" : 99,
         "bytes" : 1,
         "comment" : ""
      },
      "tiles" : {
         "comment" : " //represents tiles around the colony. idx to citizen.",
         "bytes" : 8,
         "order" : 103
      },
      "nation" : {
         "comment" : "",
         "bytes" : 1,
         "order" : 97
      },
      "name" : {
         "order" : 96,
         "bytes" : 24,
         "comment" : ""
      },
      "hammers" : {
         "order" : 140,
         "comment" : "",
         "bytes" : 2
      },
      "rebel_divisor" : {
         "order" : 146,
         "comment" : "",
         "bytes" : 4
      },
      "occupation" : {
         "order" : 100,
         "comment" : "",
         "bytes" : 32
      },
      "rebel_dividend" : {
         "order" : 145,
         "comment" : "",
         "bytes" : 4
      },
      "unkb" : {
         "bytes" : 5,
         "comment" : "",
         "order" : 142
      },
      "unka" : {
         "comment" : "",
         "bytes" : 6,
         "order" : 139
      },
      "unkd" : {
         "order" : 144,
         "comment" : "",
         "bytes" : 8
      },
      "custom_house" : {
         "rum" : {
            "bytes" : 2,
            "comment" : "",
            "order" : 132
         },
         "horses" : {
            "order" : 131,
            "bytes" : 2,
            "comment" : ""
         },
         "silver" : {
            "order" : 130,
            "comment" : "",
            "bytes" : 2
         },
         "tobacco" : {
            "order" : 125,
            "comment" : "",
            "bytes" : 2
         },
         "food" : {
            "comment" : "",
            "bytes" : 2,
            "order" : 123
         },
         "trade_goods" : {
            "comment" : "",
            "bytes" : 2,
            "order" : 136
         },
         "cloth" : {
            "order" : 134,
            "comment" : "",
            "bytes" : 2
         },
         "sugar" : {
            "order" : 124,
            "comment" : "",
            "bytes" : 2
         },
         "cotton" : {
            "order" : 126,
            "comment" : "",
            "bytes" : 2
         },
         "lumber" : {
            "order" : 128,
            "bytes" : 2,
            "comment" : ""
         },
         "tools" : {
            "comment" : "",
            "bytes" : 2,
            "order" : 137
         },
         "muskets" : {
            "bytes" : 2,
            "comment" : "",
            "order" : 138
         },
         "cigars" : {
            "comment" : "",
            "bytes" : 2,
            "order" : 133
         },
         "furs" : {
            "order" : 127,
            "comment" : "",
            "bytes" : 2
         },
         "ore" : {
            "bytes" : 2,
            "comment" : "",
            "order" : 129
         },
         "coats" : {
            "order" : 135,
            "comment" : "",
            "bytes" : 2
         }
      },
      "unk8" : {
         "bytes" : 12,
         "comment" : "",
         "order" : 104
      },
      "unk0" : {
         "bytes" : 4,
         "comment" : "",
         "order" : 98
      },
      "profession" : {
         "comment" : "",
         "bytes" : 32,
         "order" : 101
      },
      "unk6" : {
         "comment" : "",
         "bytes" : 16,
         "order" : 102
      },
      "building_in_production" : {
         "comment" : "",
         "bytes" : 1,
         "order" : 141
      },
      "x" : {
         "order" : 95,
         "bytes" : 1,
         "comment" : ""
      }
   },
   "nation" : {
      "unk5" : {
         "comment" : "",
         "bytes" : 8,
         "order" : 185
      },
      "recruit_count" : {
         "comment" : " //recruit penalty 120 + (count * 20) (does not go above 180) ",
         "bytes" : 1,
         "order" : 173
      },
      "artillery_count" : {
         "order" : 183,
         "comment" : " //artillery purchased in europe. 500 + (count * 100) price penalty.",
         "bytes" : 2
      },
      "unk6" : {
         "comment" : "",
         "bytes" : 8,
         "order" : 188
      },
      "unk2" : {
         "bytes" : 5,
         "comment" : "",
         "order" : 174
      },
      "ffc_high" : {
         "comment" : " //suspect founding_father_count is 32bit.",
         "bytes" : 2,
         "order" : 180
      },
      "crosses" : {
         "bytes" : 2,
         "comment" : "",
         "order" : 187
      },
      "founding_father_count" : {
         "bytes" : 2,
         "comment" : "",
         "order" : 179
      },
      "liberty_bells_last_turn" : {
         "order" : 176,
         "bytes" : 2,
         "comment" : ""
      },
      "indian_relation" : {
         "comment" : " enum { NOT_MET = 0x00, WAR = 0x20, PEACE = 0x60};",
         "bytes" : 8,
         "order" : 189
      },
      "unk7" : {
         "bytes" : 12,
         "comment" : "",
         "order" : 190
      },
      "unk4" : {
         "order" : 182,
         "comment" : "",
         "bytes" : 5
      },
      "boycott_bitmap" : {
         "comment" : "",
         "bytes" : 2,
         "order" : 184
      },
      "liberty_bells_total" : {
         "order" : 175,
         "comment" : "",
         "bytes" : 2
      },
      "unk0" : {
         "order" : 169,
         "bytes" : 1,
         "comment" : ""
      },
      "trade" : {
         "nr" : {
            "bytes" : 32,
            "comment" : "",
            "order" : 192
         },
         "gold" : {
            "bytes" : 64,
            "comment" : "",
            "order" : 193
         },
         "tons2" : {
            "comment" : "",
            "bytes" : 64,
            "order" : 195
         },
         "tons" : {
            "order" : 194,
            "bytes" : 64,
            "comment" : ""
         },
         "euro_price" : {
            "comment" : "",
            "bytes" : 16,
            "order" : 191
         }
      },
      "recruit" : {
         "bytes" : 3,
         "comment" : "",
         "order" : 171
      },
      "unk3" : {
         "comment" : "",
         "bytes" : 2,
         "order" : 177
      },
      "villages_burned" : {
         "order" : 181,
         "bytes" : 1,
         "comment" : ""
      },
      "next_founding_father" : {
         "order" : 178,
         "comment" : "",
         "bytes" : 2
      },
      "tax_rate" : {
         "comment" : "",
         "bytes" : 1,
         "order" : 170
      },
      "unk1" : {
         "order" : 172,
         "bytes" : 1,
         "comment" : ""
      },
      "gold" : {
         "comment" : "",
         "bytes" : 4,
         "order" : 186
      }
   },
   "stuff" : {
      "viewport_y" : {
         "order" : 226,
         "comment" : "",
         "bytes" : 2
      },
      "x" : {
         "order" : 221,
         "comment" : "",
         "bytes" : 2
      },
      "unk15" : {
         "order" : 216,
         "comment" : "",
         "bytes" : 15
      },
      "counter_decreasing_on_new_colony" : {
         "bytes" : 2,
         "comment" : "",
         "order" : 217
      },
      "unk_big" : {
         "bytes" : 696,
         "comment" : "",
         "order" : 220
      },
      "y" : {
         "order" : 222,
         "comment" : "",
         "bytes" : 2
      },
      "unk_short" : {
         "order" : 218,
         "bytes" : 2,
         "comment" : ""
      },
      "zoom_level" : {
         "order" : 223,
         "comment" : "",
         "bytes" : 1
      },
      "viewport_x" : {
         "order" : 225,
         "comment" : "",
         "bytes" : 2
      },
      "counter_increasing_on_new_colony" : {
         "comment" : "",
         "bytes" : 2,
         "order" : 219
      },
      "unk7" : {
         "comment" : "",
         "bytes" : 1,
         "order" : 224
      }
   },
   "player" : {
      "control" : {
         "comment" : " enum { PLAYER = 0, AI = 1 };",
         "bytes" : 1,
         "order" : 91
      },
      "unk00" : {
         "bytes" : 1,
         "comment" : "",
         "order" : 90
      },
      "founded_colonies" : {
         "bytes" : 1,
         "comment" : " // founded colonies, probably used pick next colony name",
         "order" : 92
      },
      "diplomacy" : {
         "comment" : "",
         "bytes" : 1,
         "order" : 93
      },
      "country" : {
         "bytes" : 24,
         "comment" : "",
         "order" : 89
      },
      "name" : {
         "order" : 88,
         "comment" : "",
         "bytes" : 24
      }
   }
}

    )"_json;
    return j;
}
