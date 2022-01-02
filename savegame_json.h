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
json merge_json_nation_list( const struct savegame *sg, json j );
json merge_json_indian_list( const struct savegame *sg, json j );

/*
json merge_json_colony_list( const struct savegame *sg, json j );
json merge_json_unit_list(   const struct savegame *sg, json j );
json merge_json_tribe_list(  const struct savegame *sg, json j );
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
    j = merge_json_nation_list( sg , j );
    j = merge_json_indian_list( sg , j );

    std::cout << j.dump(4) << std::endl;

/*
    j = merge_json_colony_list( sg , j );
    j = merge_json_unit_list(   sg , j );
    j = merge_json_tribe_list(  sg , j );
    j = merge_json_map(         sg , j );

    std::cout << j.dump(4) << std::endl;
*/

}



json merge_json_head(        const struct savegame *sg, json j )
{
    j["head"]["event"]["the_fountain_of_youth"]["value"] = sg->head.event.the_fountain_of_youth;
    j["head"]["event"]["the_inca_nation"]["value"] = sg->head.event.the_inca_nation;
    j["head"]["event"]["building_a_colony"]["value"] = sg->head.event.building_a_colony;
    j["head"]["event"]["colony_burning"]["value"] = sg->head.event.colony_burning;
    j["head"]["event"]["indian_raid"]["value"] = sg->head.event.indian_raid;
    j["head"]["event"]["discovery_of_the_pacific_ocean"]["value"] = sg->head.event.discovery_of_the_pacific_ocean;
    j["head"]["event"]["colony_destroyed"]["value"] = sg->head.event.colony_destroyed;
    j["head"]["event"]["discovery_of_the_new_world"]["value"] = sg->head.event.discovery_of_the_new_world;
    j["head"]["event"]["woodcut16"]["value"] = sg->head.event.woodcut16;
    j["head"]["event"]["the_aztec_empire"]["value"] = sg->head.event.the_aztec_empire;
    j["head"]["event"]["meeting_fellow_europeans"]["value"] = sg->head.event.meeting_fellow_europeans;
    j["head"]["event"]["entering_indian_village"]["value"] = sg->head.event.entering_indian_village;
    j["head"]["event"]["cargo_from_the_new_world"]["value"] = sg->head.event.cargo_from_the_new_world;
    j["head"]["event"]["meeting_the_natives"]["value"] = sg->head.event.meeting_the_natives;
    j["head"]["event"]["woodcut14"]["value"] = sg->head.event.woodcut14;
    j["head"]["event"]["woodcut15"]["value"] = sg->head.event.woodcut15;
    j["head"]["colony_report_options"]["report_raw_materials_shortages"]["value"] = sg->head.colony_report_options.report_raw_materials_shortages;
    j["head"]["colony_report_options"]["report_inefficient_government"]["value"] = sg->head.colony_report_options.report_inefficient_government;
    j["head"]["colony_report_options"]["report_when_colonists_trained"]["value"] = sg->head.colony_report_options.report_when_colonists_trained;
    j["head"]["colony_report_options"]["report_sons_of_liberty_membership"]["value"] = sg->head.colony_report_options.report_sons_of_liberty_membership;
    j["head"]["colony_report_options"]["report_tools_needed_for_production"]["value"] = sg->head.colony_report_options.report_tools_needed_for_production;
    j["head"]["colony_report_options"]["labels_on_buildings"]["value"] = sg->head.colony_report_options.labels_on_buildings;
    j["head"]["colony_report_options"]["report_food_shortages"]["value"] = sg->head.colony_report_options.report_food_shortages;
    j["head"]["colony_report_options"]["report_rebel_majorities"]["value"] = sg->head.colony_report_options.report_rebel_majorities;
    j["head"]["colony_report_options"]["report_new_cargos_available"]["value"] = sg->head.colony_report_options.report_new_cargos_available;
    j["head"]["colony_report_options"]["unused"]["value"] = sg->head.colony_report_options.unused;
    j["head"]["colony_report_options"]["labels_on_cargo_and_terrain"]["value"] = sg->head.colony_report_options.labels_on_cargo_and_terrain;
    j["head"]["tut3"]["nr8"]["value"] = sg->head.tut3.nr8;
    j["head"]["tut3"]["nr5"]["value"] = sg->head.tut3.nr5;
    j["head"]["tut3"]["nr11"]["value"] = sg->head.tut3.nr11;
    j["head"]["tut3"]["nr12"]["value"] = sg->head.tut3.nr12;
    j["head"]["tut3"]["nr7"]["value"] = sg->head.tut3.nr7;
    j["head"]["tut3"]["nr10"]["value"] = sg->head.tut3.nr10;
    j["head"]["tut3"]["nr6"]["value"] = sg->head.tut3.nr6;
    j["head"]["tut3"]["nr9"]["value"] = sg->head.tut3.nr9;
    j["head"]["map_size_x"]["value"] = sg->head.map_size_x;
    j["head"]["difficulty"]["value"] = sg->head.difficulty;
    j["head"]["unk0"]["value"] = sg->head.unk0;
    j["head"]["year"]["value"] = sg->head.year;
    j["head"]["autumn"]["value"] = sg->head.autumn;
    j["head"]["unk1"]["value"] = sg->head.unk1;
    j["head"]["numbers03"]["value"] = sg->head.numbers03;
    j["head"]["unit_count"]["value"] = sg->head.unit_count;
    j["head"]["unkb"]["value"] = sg->head.unkb;
    j["head"]["map_size_y"]["value"] = sg->head.map_size_y;
    j["head"]["founding_father"]["value"] = sg->head.founding_father;
    j["head"]["numbers05"]["value"] = sg->head.numbers05;
    j["head"]["numbers04"]["value"] = sg->head.numbers04;
    j["head"]["tribe_count"]["value"] = sg->head.tribe_count;
    j["head"]["nation_relation"]["value"] = sg->head.nation_relation;
    j["head"]["game_options"]["show_foreign_moves"]["value"] = sg->head.game_options.show_foreign_moves;
    j["head"]["game_options"]["show_indian_moves"]["value"] = sg->head.game_options.show_indian_moves;
    j["head"]["game_options"]["tutorial_hints"]["value"] = sg->head.game_options.tutorial_hints;
    j["head"]["game_options"]["unknown7"]["value"] = sg->head.game_options.unknown7;
    j["head"]["game_options"]["fast_piece_slide"]["value"] = sg->head.game_options.fast_piece_slide;
    j["head"]["game_options"]["end_of_turn"]["value"] = sg->head.game_options.end_of_turn;
    j["head"]["game_options"]["water_color_cycling"]["value"] = sg->head.game_options.water_color_cycling;
    j["head"]["game_options"]["unknown"]["value"] = sg->head.game_options.unknown;
    j["head"]["game_options"]["autosave"]["value"] = sg->head.game_options.autosave;
    j["head"]["game_options"]["combat_analysis"]["value"] = sg->head.game_options.combat_analysis;
    j["head"]["active_unit"]["value"] = sg->head.active_unit;
    j["head"]["turn"]["value"] = sg->head.turn;
    j["head"]["numbers00"]["value"] = sg->head.numbers00;
    j["head"]["expeditionary_force"]["value"] = sg->head.expeditionary_force;
    j["head"]["colony_count"]["value"] = sg->head.colony_count;
    j["head"]["tut1"]["nr17"]["value"] = sg->head.tut1.nr17;
    j["head"]["tut1"]["nr13"]["value"] = sg->head.tut1.nr13;
    j["head"]["tut1"]["nr15"]["value"] = sg->head.tut1.nr15;
    j["head"]["tut1"]["unk3"]["value"] = sg->head.tut1.unk3;
    j["head"]["tut1"]["unk7"]["value"] = sg->head.tut1.unk7;
    j["head"]["tut1"]["nr14"]["value"] = sg->head.tut1.nr14;
    j["head"]["tut1"]["nr19"]["value"] = sg->head.tut1.nr19;
    j["head"]["tut1"]["nr16"]["value"] = sg->head.tut1.nr16;
    j["head"]["numbers02"]["value"] = sg->head.numbers02;
    j["head"]["tut2"]["nr3"]["value"] = sg->head.tut2.nr3;
    j["head"]["tut2"]["background_music"]["value"] = sg->head.tut2.background_music;
    j["head"]["tut2"]["howtowin"]["value"] = sg->head.tut2.howtowin;
    j["head"]["tut2"]["event_music"]["value"] = sg->head.tut2.event_music;
    j["head"]["tut2"]["nr4"]["value"] = sg->head.tut2.nr4;
    j["head"]["tut2"]["sound_effects"]["value"] = sg->head.tut2.sound_effects;
    j["head"]["tut2"]["nr2"]["value"] = sg->head.tut2.nr2;
    j["head"]["tut2"]["nr1"]["value"] = sg->head.tut2.nr1;
    j["head"]["sig_colonize"]["value"] = sg->head.sig_colonize;
    j["head"]["numbers06"]["value"] = sg->head.numbers06;
    j["head"]["numbers07"]["value"] = sg->head.numbers07;
    j["head"]["count_down"]["value"] = sg->head.count_down;
    j["head"]["numbers01"]["value"] = sg->head.numbers01;
    return j;
}


json merge_json_other(        const struct savegame *sg, json j )
{
    j["other"]["unkXX_xx"]["value"] = sg->other.unkXX_xx;
    return j;
}


json merge_json_stuff(        const struct savegame *sg, json j )
{
    j["stuff"]["counter_decreasing_on_new_colony"]["value"] = sg->stuff.counter_decreasing_on_new_colony;
    j["stuff"]["viewport_x"]["value"] = sg->stuff.viewport_x;
    j["stuff"]["unk15"]["value"] = sg->stuff.unk15;
    j["stuff"]["zoom_level"]["value"] = sg->stuff.zoom_level;
    j["stuff"]["unk_big"]["value"] = sg->stuff.unk_big;
    j["stuff"]["y"]["value"] = sg->stuff.y;
    j["stuff"]["unk7"]["value"] = sg->stuff.unk7;
    j["stuff"]["viewport_y"]["value"] = sg->stuff.viewport_y;
    j["stuff"]["x"]["value"] = sg->stuff.x;
    j["stuff"]["unk_short"]["value"] = sg->stuff.unk_short;
    j["stuff"]["counter_increasing_on_new_colony"]["value"] = sg->stuff.counter_increasing_on_new_colony;
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

    for (int i = 0; i < sg->count.player; ++i) {
        j["player_list"][i] = base;
        j["player_list"][i]["label"] = player_list[i];
        j["player_list"][i]["country"]["value"] = sg->player[i].country;
        j["player_list"][i]["diplomacy"]["value"] = sg->player[i].diplomacy;
        j["player_list"][i]["unk00"]["value"] = sg->player[i].unk00;
        j["player_list"][i]["control"]["value"] = sg->player[i].control;
        j["player_list"][i]["founded_colonies"]["value"] = sg->player[i].founded_colonies;
        j["player_list"][i]["name"]["value"] = sg->player[i].name;
    }
    return j;
}


json merge_json_nation_list(   const struct savegame *sg, json j )
{
    json base = j["nation"];

    for (int i = 0; i < sg->count.nation; ++i) {
        j["nation_list"][i] = base;
        j["nation_list"][i]["label"] = nation_list[i];
        j["nation_list"][i]["relation_by_indian"]["value"] = sg->nation[i].relation_by_indian;
        j["nation_list"][i]["unk5"]["value"] = sg->nation[i].unk5;
        j["nation_list"][i]["unk2"]["value"] = sg->nation[i].unk2;
        j["nation_list"][i]["trade"]["euro_price"]["value"] = sg->nation[i].trade.euro_price;
        j["nation_list"][i]["trade"]["tons2"]["value"] = sg->nation[i].trade.tons2;
        j["nation_list"][i]["trade"]["nr"]["value"] = sg->nation[i].trade.nr;
        j["nation_list"][i]["trade"]["tons"]["value"] = sg->nation[i].trade.tons;
        j["nation_list"][i]["trade"]["gold"]["value"] = sg->nation[i].trade.gold;
        j["nation_list"][i]["villages_burned"]["value"] = sg->nation[i].villages_burned;
        j["nation_list"][i]["gold"]["value"] = sg->nation[i].gold;
        j["nation_list"][i]["unk1"]["value"] = sg->nation[i].unk1;
        j["nation_list"][i]["unk0"]["value"] = sg->nation[i].unk0;
        j["nation_list"][i]["unk7"]["value"] = sg->nation[i].unk7;
        j["nation_list"][i]["next_founding_father"]["value"] = sg->nation[i].next_founding_father;
        j["nation_list"][i]["recruit_count"]["value"] = sg->nation[i].recruit_count;
        j["nation_list"][i]["unk6"]["value"] = sg->nation[i].unk6;
        j["nation_list"][i]["unk4"]["value"] = sg->nation[i].unk4;
        j["nation_list"][i]["ffc_high"]["value"] = sg->nation[i].ffc_high;
        j["nation_list"][i]["unk3"]["value"] = sg->nation[i].unk3;
        j["nation_list"][i]["tax_rate"]["value"] = sg->nation[i].tax_rate;
        j["nation_list"][i]["boycott_bitmap"]["value"] = sg->nation[i].boycott_bitmap;
        j["nation_list"][i]["artillery_count"]["value"] = sg->nation[i].artillery_count;
        j["nation_list"][i]["founding_father_count"]["value"] = sg->nation[i].founding_father_count;
        j["nation_list"][i]["crosses"]["value"] = sg->nation[i].crosses;
        j["nation_list"][i]["liberty_bells_last_turn"]["value"] = sg->nation[i].liberty_bells_last_turn;
        j["nation_list"][i]["recruit"]["value"] = sg->nation[i].recruit;
        j["nation_list"][i]["liberty_bells_total"]["value"] = sg->nation[i].liberty_bells_total;
    }
    return j;
}


json merge_json_indian_list(   const struct savegame *sg, json j )
{
    json base = j["indian"];

    for (int i = 0; i < sg->count.indian; ++i) {
        j["indian_list"][i] = base;
        j["indian_list"][i]["label"] = indian_list[i];
        j["indian_list"][i]["unk1"]["value"] = sg->indian[i].unk1;
        j["indian_list"][i]["met_by_player"]["value"] = sg->indian[i].met_by_player;
        j["indian_list"][i]["unk0"]["value"] = sg->indian[i].unk0;
        j["indian_list"][i]["alarm_by_player"]["value"] = sg->indian[i].alarm_by_player;
    }
    return j;
}


json json_base() {
    auto j = R"(
{
   "head" : {
      "event" : {
         "the_fountain_of_youth" : {
            "bytes" : {
               "total" : 2,
               "base" : 2,
               "suffix" : 1
            },
            "hints" : "",
            "order" : 84
         },
         "the_inca_nation" : {
            "order" : 81,
            "bytes" : {
               "total" : 2,
               "base" : 2,
               "suffix" : 1
            },
            "hints" : ""
         },
         "building_a_colony" : {
            "order" : 78,
            "bytes" : {
               "suffix" : 1,
               "base" : 2,
               "total" : 2
            },
            "hints" : ""
         },
         "colony_burning" : {
            "hints" : "",
            "bytes" : {
               "total" : 2,
               "suffix" : 1,
               "base" : 2
            },
            "order" : 87
         },
         "indian_raid" : {
            "order" : 89,
            "hints" : "",
            "bytes" : {
               "total" : 2,
               "base" : 2,
               "suffix" : 1
            }
         },
         "discovery_of_the_pacific_ocean" : {
            "order" : 82,
            "bytes" : {
               "suffix" : 1,
               "base" : 2,
               "total" : 2
            },
            "hints" : ""
         },
         "colony_destroyed" : {
            "order" : 88,
            "bytes" : {
               "total" : 2,
               "suffix" : 1,
               "base" : 2
            },
            "hints" : ""
         },
         "discovery_of_the_new_world" : {
            "bytes" : {
               "total" : 2,
               "suffix" : 1,
               "base" : 2
            },
            "hints" : "",
            "order" : 77
         },
         "woodcut16" : {
            "hints" : "",
            "bytes" : {
               "total" : 2,
               "suffix" : 1,
               "base" : 2
            },
            "order" : 92
         },
         "the_aztec_empire" : {
            "hints" : "",
            "bytes" : {
               "total" : 2,
               "base" : 2,
               "suffix" : 1
            },
            "order" : 80
         },
         "meeting_fellow_europeans" : {
            "hints" : "",
            "bytes" : {
               "total" : 2,
               "base" : 2,
               "suffix" : 1
            },
            "order" : 86
         },
         "entering_indian_village" : {
            "hints" : "",
            "bytes" : {
               "total" : 2,
               "suffix" : 1,
               "base" : 2
            },
            "order" : 83
         },
         "cargo_from_the_new_world" : {
            "bytes" : {
               "total" : 2,
               "suffix" : 1,
               "base" : 2
            },
            "hints" : "",
            "order" : 85
         },
         "meeting_the_natives" : {
            "bytes" : {
               "total" : 2,
               "suffix" : 1,
               "base" : 2
            },
            "hints" : "",
            "order" : 79
         },
         "woodcut14" : {
            "hints" : "",
            "bytes" : {
               "total" : 2,
               "suffix" : 1,
               "base" : 2
            },
            "order" : 90
         },
         "woodcut15" : {
            "bytes" : {
               "total" : 2,
               "suffix" : 1,
               "base" : 2
            },
            "hints" : "",
            "order" : 91
         }
      },
      "colony_report_options" : {
         "report_raw_materials_shortages" : {
            "order" : 35,
            "hints" : "",
            "bytes" : {
               "total" : 2,
               "suffix" : 1,
               "base" : 2
            }
         },
         "report_inefficient_government" : {
            "bytes" : {
               "suffix" : 1,
               "base" : 2,
               "total" : 2
            },
            "hints" : "",
            "order" : 33
         },
         "report_when_colonists_trained" : {
            "order" : 37,
            "hints" : "",
            "bytes" : {
               "suffix" : 1,
               "base" : 2,
               "total" : 2
            }
         },
         "report_sons_of_liberty_membership" : {
            "bytes" : {
               "suffix" : 1,
               "base" : 2,
               "total" : 2
            },
            "hints" : "",
            "order" : 38
         },
         "report_tools_needed_for_production" : {
            "order" : 34,
            "hints" : "",
            "bytes" : {
               "base" : 2,
               "suffix" : 1,
               "total" : 2
            }
         },
         "labels_on_buildings" : {
            "hints" : "",
            "bytes" : {
               "suffix" : 1,
               "base" : 2,
               "total" : 2
            },
            "order" : 31
         },
         "report_food_shortages" : {
            "hints" : "",
            "bytes" : {
               "base" : 2,
               "suffix" : 1,
               "total" : 2
            },
            "order" : 36
         },
         "report_rebel_majorities" : {
            "order" : 39,
            "bytes" : {
               "total" : 2,
               "base" : 2,
               "suffix" : 1
            },
            "hints" : ""
         },
         "report_new_cargos_available" : {
            "bytes" : {
               "suffix" : 1,
               "base" : 2,
               "total" : 2
            },
            "hints" : "",
            "order" : 32
         },
         "unused" : {
            "order" : 40,
            "bytes" : {
               "suffix" : 6,
               "base" : 2,
               "total" : 12
            },
            "hints" : ""
         },
         "labels_on_cargo_and_terrain" : {
            "order" : 30,
            "bytes" : {
               "suffix" : 1,
               "base" : 2,
               "total" : 2
            },
            "hints" : ""
         }
      },
      "tut3" : {
         "nr8" : {
            "bytes" : {
               "total" : 1,
               "suffix" : 1,
               "base" : 1
            },
            "hints" : "",
            "order" : 52
         },
         "nr5" : {
            "hints" : "",
            "bytes" : {
               "total" : 1,
               "base" : 1,
               "suffix" : 1
            },
            "order" : 49
         },
         "nr11" : {
            "hints" : "",
            "bytes" : {
               "suffix" : 1,
               "base" : 1,
               "total" : 1
            },
            "order" : 55
         },
         "nr12" : {
            "order" : 56,
            "hints" : "",
            "bytes" : {
               "total" : 1,
               "suffix" : 1,
               "base" : 1
            }
         },
         "nr7" : {
            "order" : 51,
            "bytes" : {
               "suffix" : 1,
               "base" : 1,
               "total" : 1
            },
            "hints" : ""
         },
         "nr10" : {
            "hints" : "",
            "bytes" : {
               "total" : 1,
               "suffix" : 1,
               "base" : 1
            },
            "order" : 54
         },
         "nr6" : {
            "bytes" : {
               "total" : 1,
               "base" : 1,
               "suffix" : 1
            },
            "hints" : "",
            "order" : 50
         },
         "nr9" : {
            "hints" : "",
            "bytes" : {
               "total" : 1,
               "base" : 1,
               "suffix" : 1
            },
            "order" : 53
         }
      },
      "map_size_x" : {
         "order" : 9,
         "bytes" : {
            "total" : 2,
            "suffix" : 1,
            "base" : 2
         },
         "hints" : ""
      },
      "difficulty" : {
         "hints" : " enum { DISCOVERER = 0, EXPLORER = 1, CONQUISTADOR = 2, GOVERNOR = 3, VICEROY = 4 }; //36",
         "bytes" : {
            "total" : 1,
            "suffix" : 1,
            "base" : 1
         },
         "order" : 68
      },
      "unk0" : {
         "bytes" : {
            "base" : 1,
            "suffix" : 3,
            "total" : 3
         },
         "hints" : "",
         "order" : 8
      },
      "year" : {
         "order" : 58,
         "bytes" : {
            "suffix" : 1,
            "base" : 2,
            "total" : 2
         },
         "hints" : ""
      },
      "autumn" : {
         "bytes" : {
            "base" : 2,
            "suffix" : 1,
            "total" : 2
         },
         "hints" : " //boolean, true if autumn",
         "order" : 59
      },
      "unk1" : {
         "hints" : "",
         "bytes" : {
            "base" : 1,
            "suffix" : 1,
            "total" : 1
         },
         "order" : 19
      },
      "numbers03" : {
         "order" : 67,
         "hints" : "",
         "bytes" : {
            "suffix" : 3,
            "base" : 2,
            "total" : 6
         }
      },
      "unit_count" : {
         "order" : 65,
         "bytes" : {
            "total" : 2,
            "base" : 2,
            "suffix" : 1
         },
         "hints" : ""
      },
      "unkb" : {
         "hints" : "",
         "bytes" : {
            "suffix" : 2,
            "base" : 1,
            "total" : 2
         },
         "order" : 93
      },
      "map_size_y" : {
         "hints" : "",
         "bytes" : {
            "total" : 2,
            "suffix" : 1,
            "base" : 2
         },
         "order" : 10
      },
      "founding_father" : {
         "bytes" : {
            "base" : 1,
            "suffix" : 25,
            "total" : 25
         },
         "hints" : "",
         "order" : 70
      },
      "numbers05" : {
         "hints" : "",
         "bytes" : {
            "suffix" : 3,
            "base" : 2,
            "total" : 6
         },
         "order" : 71
      },
      "numbers04" : {
         "order" : 69,
         "hints" : "",
         "bytes" : {
            "base" : 2,
            "suffix" : 1,
            "total" : 2
         }
      },
      "tribe_count" : {
         "order" : 64,
         "hints" : "",
         "bytes" : {
            "total" : 2,
            "base" : 2,
            "suffix" : 1
         }
      },
      "nation_relation" : {
         "order" : 72,
         "bytes" : {
            "total" : 8,
            "base" : 2,
            "suffix" : 4
         },
         "hints" : ""
      },
      "game_options" : {
         "show_foreign_moves" : {
            "bytes" : {
               "total" : 2,
               "base" : 2,
               "suffix" : 1
            },
            "hints" : "",
            "order" : 28
         },
         "show_indian_moves" : {
            "bytes" : {
               "suffix" : 1,
               "base" : 2,
               "total" : 2
            },
            "hints" : "",
            "order" : 29
         },
         "tutorial_hints" : {
            "order" : 21,
            "hints" : "",
            "bytes" : {
               "total" : 2,
               "suffix" : 1,
               "base" : 2
            }
         },
         "unknown7" : {
            "order" : 20,
            "hints" : "",
            "bytes" : {
               "total" : 14,
               "base" : 2,
               "suffix" : 7
            }
         },
         "fast_piece_slide" : {
            "order" : 26,
            "hints" : "",
            "bytes" : {
               "total" : 2,
               "suffix" : 1,
               "base" : 2
            }
         },
         "end_of_turn" : {
            "bytes" : {
               "total" : 2,
               "base" : 2,
               "suffix" : 1
            },
            "hints" : "",
            "order" : 25
         },
         "water_color_cycling" : {
            "order" : 22,
            "hints" : "",
            "bytes" : {
               "base" : 2,
               "suffix" : 1,
               "total" : 2
            }
         },
         "unknown" : {
            "order" : 27,
            "hints" : "",
            "bytes" : {
               "base" : 2,
               "suffix" : 1,
               "total" : 2
            }
         },
         "autosave" : {
            "hints" : "",
            "bytes" : {
               "total" : 2,
               "suffix" : 1,
               "base" : 2
            },
            "order" : 24
         },
         "combat_analysis" : {
            "order" : 23,
            "bytes" : {
               "total" : 2,
               "base" : 2,
               "suffix" : 1
            },
            "hints" : ""
         }
      },
      "active_unit" : {
         "order" : 62,
         "bytes" : {
            "base" : 2,
            "suffix" : 1,
            "total" : 2
         },
         "hints" : ""
      },
      "turn" : {
         "order" : 60,
         "hints" : "",
         "bytes" : {
            "suffix" : 1,
            "base" : 2,
            "total" : 2
         }
      },
      "numbers00" : {
         "bytes" : {
            "total" : 2,
            "suffix" : 1,
            "base" : 2
         },
         "hints" : "",
         "order" : 57
      },
      "expeditionary_force" : {
         "hints" : "",
         "bytes" : {
            "total" : 8,
            "suffix" : 4,
            "base" : 2
         },
         "order" : 74
      },
      "colony_count" : {
         "order" : 66,
         "hints" : "",
         "bytes" : {
            "total" : 2,
            "suffix" : 1,
            "base" : 2
         }
      },
      "tut1" : {
         "nr17" : {
            "hints" : "",
            "bytes" : {
               "total" : 1,
               "base" : 1,
               "suffix" : 1
            },
            "order" : 16
         },
         "nr13" : {
            "hints" : "",
            "bytes" : {
               "base" : 1,
               "suffix" : 1,
               "total" : 1
            },
            "order" : 11
         },
         "nr15" : {
            "bytes" : {
               "suffix" : 1,
               "base" : 1,
               "total" : 1
            },
            "hints" : "",
            "order" : 14
         },
         "unk3" : {
            "bytes" : {
               "base" : 1,
               "suffix" : 1,
               "total" : 1
            },
            "hints" : "",
            "order" : 13
         },
         "unk7" : {
            "hints" : "",
            "bytes" : {
               "suffix" : 1,
               "base" : 1,
               "total" : 1
            },
            "order" : 17
         },
         "nr14" : {
            "hints" : "",
            "bytes" : {
               "suffix" : 1,
               "base" : 1,
               "total" : 1
            },
            "order" : 12
         },
         "nr19" : {
            "bytes" : {
               "suffix" : 1,
               "base" : 1,
               "total" : 1
            },
            "hints" : "",
            "order" : 18
         },
         "nr16" : {
            "bytes" : {
               "base" : 1,
               "suffix" : 1,
               "total" : 1
            },
            "hints" : "",
            "order" : 15
         }
      },
      "numbers02" : {
         "order" : 63,
         "hints" : "",
         "bytes" : {
            "base" : 2,
            "suffix" : 3,
            "total" : 6
         }
      },
      "tut2" : {
         "nr3" : {
            "order" : 47,
            "hints" : "",
            "bytes" : {
               "total" : 1,
               "suffix" : 1,
               "base" : 1
            }
         },
         "background_music" : {
            "hints" : "",
            "bytes" : {
               "base" : 1,
               "suffix" : 1,
               "total" : 1
            },
            "order" : 42
         },
         "howtowin" : {
            "order" : 41,
            "bytes" : {
               "total" : 1,
               "suffix" : 1,
               "base" : 1
            },
            "hints" : ""
         },
         "event_music" : {
            "bytes" : {
               "total" : 1,
               "base" : 1,
               "suffix" : 1
            },
            "hints" : "",
            "order" : 43
         },
         "nr4" : {
            "hints" : "",
            "bytes" : {
               "base" : 1,
               "suffix" : 1,
               "total" : 1
            },
            "order" : 48
         },
         "sound_effects" : {
            "hints" : "",
            "bytes" : {
               "base" : 1,
               "suffix" : 1,
               "total" : 1
            },
            "order" : 44
         },
         "nr2" : {
            "order" : 46,
            "hints" : " // probably not used, also triggers event_discovery_of_the_new_world",
            "bytes" : {
               "total" : 1,
               "base" : 1,
               "suffix" : 1
            }
         },
         "nr1" : {
            "order" : 45,
            "bytes" : {
               "total" : 1,
               "base" : 1,
               "suffix" : 1
            },
            "hints" : " // shown immediately on game-start"
         }
      },
      "sig_colonize" : {
         "hints" : "",
         "bytes" : {
            "base" : 1,
            "suffix" : 9,
            "total" : 9
         },
         "order" : 7
      },
      "numbers06" : {
         "hints" : "",
         "bytes" : {
            "total" : 10,
            "suffix" : 5,
            "base" : 2
         },
         "order" : 73
      },
      "numbers07" : {
         "order" : 75,
         "bytes" : {
            "suffix" : 4,
            "base" : 2,
            "total" : 8
         },
         "hints" : " //backup force, once you produce enough bells."
      },
      "count_down" : {
         "hints" : "",
         "bytes" : {
            "suffix" : 16,
            "base" : 2,
            "total" : 32
         },
         "order" : 76
      },
      "numbers01" : {
         "order" : 61,
         "hints" : "",
         "bytes" : {
            "total" : 2,
            "suffix" : 1,
            "base" : 2
         }
      }
   },
   "other" : {
      "unkXX_xx" : {
         "hints" : "",
         "bytes" : {
            "total" : 24,
            "base" : 1,
            "suffix" : 24
         },
         "order" : 100
      }
   },
   "nation" : {
      "relation_by_indian" : {
         "order" : 195,
         "bytes" : {
            "total" : 8,
            "base" : 1,
            "suffix" : 8
         },
         "hints" : " enum { NOT_MET = 0x00, WAR = 0x20, PEACE = 0x60};"
      },
      "unk5" : {
         "hints" : "",
         "bytes" : {
            "total" : 8,
            "suffix" : 8,
            "base" : 1
         },
         "order" : 191
      },
      "unk2" : {
         "hints" : "",
         "bytes" : {
            "total" : 5,
            "suffix" : 5,
            "base" : 1
         },
         "order" : 180
      },
      "trade" : {
         "euro_price" : {
            "order" : 197,
            "bytes" : {
               "total" : 16,
               "suffix" : 16,
               "base" : 1
            },
            "hints" : ""
         },
         "tons2" : {
            "bytes" : {
               "base" : 4,
               "suffix" : 16,
               "total" : 64
            },
            "hints" : "",
            "order" : 201
         },
         "nr" : {
            "order" : 198,
            "hints" : "",
            "bytes" : {
               "suffix" : 16,
               "base" : 2,
               "total" : 32
            }
         },
         "tons" : {
            "bytes" : {
               "total" : 64,
               "suffix" : 16,
               "base" : 4
            },
            "hints" : "",
            "order" : 200
         },
         "gold" : {
            "order" : 199,
            "hints" : "",
            "bytes" : {
               "suffix" : 16,
               "base" : 4,
               "total" : 64
            }
         }
      },
      "villages_burned" : {
         "hints" : "",
         "bytes" : {
            "total" : 1,
            "suffix" : 1,
            "base" : 1
         },
         "order" : 187
      },
      "gold" : {
         "hints" : "",
         "bytes" : {
            "total" : 4,
            "base" : 4,
            "suffix" : 1
         },
         "order" : 192
      },
      "unk1" : {
         "hints" : "",
         "bytes" : {
            "suffix" : 1,
            "base" : 1,
            "total" : 1
         },
         "order" : 178
      },
      "unk0" : {
         "bytes" : {
            "suffix" : 1,
            "base" : 1,
            "total" : 1
         },
         "hints" : "",
         "order" : 175
      },
      "unk7" : {
         "order" : 196,
         "hints" : "",
         "bytes" : {
            "total" : 12,
            "suffix" : 12,
            "base" : 1
         }
      },
      "next_founding_father" : {
         "order" : 184,
         "bytes" : {
            "base" : 2,
            "suffix" : 1,
            "total" : 2
         },
         "hints" : ""
      },
      "recruit_count" : {
         "order" : 179,
         "bytes" : {
            "suffix" : 1,
            "base" : 1,
            "total" : 1
         },
         "hints" : " //recruit penalty 120 + (count * 20) (does not go above 180) "
      },
      "unk6" : {
         "order" : 194,
         "hints" : "",
         "bytes" : {
            "base" : 2,
            "suffix" : 4,
            "total" : 8
         }
      },
      "unk4" : {
         "order" : 188,
         "bytes" : {
            "suffix" : 5,
            "base" : 1,
            "total" : 5
         },
         "hints" : ""
      },
      "ffc_high" : {
         "order" : 186,
         "hints" : " //suspect founding_father_count is 32bit.",
         "bytes" : {
            "total" : 2,
            "base" : 2,
            "suffix" : 1
         }
      },
      "unk3" : {
         "bytes" : {
            "base" : 1,
            "suffix" : 2,
            "total" : 2
         },
         "hints" : "",
         "order" : 183
      },
      "tax_rate" : {
         "order" : 176,
         "hints" : "",
         "bytes" : {
            "base" : 1,
            "suffix" : 1,
            "total" : 1
         }
      },
      "boycott_bitmap" : {
         "bytes" : {
            "total" : 2,
            "suffix" : 1,
            "base" : 2
         },
         "hints" : "",
         "order" : 190
      },
      "artillery_count" : {
         "bytes" : {
            "total" : 2,
            "suffix" : 1,
            "base" : 2
         },
         "hints" : " //artillery purchased in europe. 500 + (count * 100) price penalty.",
         "order" : 189
      },
      "founding_father_count" : {
         "hints" : "",
         "bytes" : {
            "base" : 2,
            "suffix" : 1,
            "total" : 2
         },
         "order" : 185
      },
      "crosses" : {
         "bytes" : {
            "suffix" : 1,
            "base" : 2,
            "total" : 2
         },
         "hints" : "",
         "order" : 193
      },
      "liberty_bells_last_turn" : {
         "order" : 182,
         "hints" : "",
         "bytes" : {
            "total" : 2,
            "suffix" : 1,
            "base" : 2
         }
      },
      "recruit" : {
         "order" : 177,
         "hints" : "",
         "bytes" : {
            "base" : 1,
            "suffix" : 3,
            "total" : 3
         }
      },
      "liberty_bells_total" : {
         "order" : 181,
         "hints" : "",
         "bytes" : {
            "total" : 2,
            "base" : 2,
            "suffix" : 1
         }
      }
   },
   "tribe" : {
      "mission" : {
         "order" : 213,
         "hints" : " //ff if none, 0 1 2 3 = eng fra spa dut",
         "bytes" : {
            "suffix" : 1,
            "base" : 1,
            "total" : 1
         }
      },
      "population" : {
         "order" : 212,
         "hints" : "",
         "bytes" : {
            "total" : 1,
            "base" : 1,
            "suffix" : 1
         }
      },
      "unk1" : {
         "bytes" : {
            "suffix" : 4,
            "base" : 1,
            "total" : 4
         },
         "hints" : "",
         "order" : 214
      },
      "unk2" : {
         "bytes" : {
            "base" : 1,
            "suffix" : 6,
            "total" : 6
         },
         "hints" : "",
         "order" : 216
      },
      "state" : {
         "capital" : {
            "bytes" : {
               "base" : 1,
               "suffix" : 1,
               "total" : 1
            },
            "hints" : "",
            "order" : 206
         },
         "unk6" : {
            "bytes" : {
               "suffix" : 1,
               "base" : 1,
               "total" : 1
            },
            "hints" : "",
            "order" : 209
         },
         "unk8" : {
            "order" : 211,
            "hints" : "",
            "bytes" : {
               "total" : 1,
               "base" : 1,
               "suffix" : 1
            }
         },
         "learned" : {
            "order" : 205,
            "bytes" : {
               "total" : 1,
               "base" : 1,
               "suffix" : 1
            },
            "hints" : " //visited and learned skill"
         },
         "artillery" : {
            "order" : 204,
            "bytes" : {
               "total" : 1,
               "base" : 1,
               "suffix" : 1
            },
            "hints" : " //artillery has been nearby?"
         },
         "unk5" : {
            "hints" : "",
            "bytes" : {
               "suffix" : 1,
               "base" : 1,
               "total" : 1
            },
            "order" : 208
         },
         "unk7" : {
            "hints" : "",
            "bytes" : {
               "base" : 1,
               "suffix" : 1,
               "total" : 1
            },
            "order" : 210
         },
         "scouted" : {
            "order" : 207,
            "bytes" : {
               "total" : 1,
               "suffix" : 1,
               "base" : 1
            },
            "hints" : " //visited by scout"
         }
      },
      "panic" : {
         "bytes" : {
            "suffix" : 1,
            "base" : 1,
            "total" : 1
         },
         "hints" : "",
         "order" : 215
      },
      "population_loss_in_current_turn" : {
         "bytes" : {
            "suffix" : 1,
            "base" : 1,
            "total" : 1
         },
         "hints" : " //due to attacks",
         "order" : 217
      },
      "nation" : {
         "bytes" : {
            "total" : 1,
            "suffix" : 1,
            "base" : 1
         },
         "hints" : "",
         "order" : 203
      },
      "x" : {
         "hints" : "",
         "bytes" : {
            "total" : 1,
            "base" : 1,
            "suffix" : 1
         },
         "order" : 202
      }
   },
   "player" : {
      "country" : {
         "bytes" : {
            "total" : 24,
            "suffix" : 24,
            "base" : 1
         },
         "hints" : "",
         "order" : 95
      },
      "diplomacy" : {
         "order" : 99,
         "bytes" : {
            "total" : 1,
            "suffix" : 1,
            "base" : 1
         },
         "hints" : ""
      },
      "unk00" : {
         "hints" : "",
         "bytes" : {
            "total" : 1,
            "suffix" : 1,
            "base" : 1
         },
         "order" : 96
      },
      "control" : {
         "bytes" : {
            "base" : 1,
            "suffix" : 1,
            "total" : 1
         },
         "hints" : " enum { PLAYER = 0, AI = 1 };",
         "order" : 97
      },
      "founded_colonies" : {
         "hints" : " // founded colonies, probably used pick next colony name",
         "bytes" : {
            "suffix" : 1,
            "base" : 1,
            "total" : 1
         },
         "order" : 98
      },
      "name" : {
         "bytes" : {
            "total" : 24,
            "base" : 1,
            "suffix" : 24
         },
         "hints" : "",
         "order" : 94
      }
   },
   "indian" : {
      "unk1" : {
         "order" : 220,
         "bytes" : {
            "total" : 8,
            "suffix" : 8,
            "base" : 1
         },
         "hints" : " "
      },
      "met_by_player" : {
         "order" : 219,
         "bytes" : {
            "total" : 4,
            "base" : 1,
            "suffix" : 4
         },
         "hints" : ""
      },
      "unk0" : {
         "order" : 218,
         "bytes" : {
            "total" : 58,
            "suffix" : 58,
            "base" : 1
         },
         "hints" : ""
      },
      "alarm_by_player" : {
         "order" : 221,
         "bytes" : {
            "total" : 8,
            "base" : 2,
            "suffix" : 4
         },
         "hints" : ""
      }
   },
   "count" : {
      "tribe" : {
         "hints" : "",
         "bytes" : {
            "suffix" : 1,
            "base" : 2,
            "total" : 2
         },
         "order" : 3
      },
      "nation" : {
         "order" : 5,
         "hints" : "",
         "bytes" : {
            "total" : 2,
            "suffix" : 1,
            "base" : 2
         }
      },
      "unit" : {
         "bytes" : {
            "base" : 2,
            "suffix" : 1,
            "total" : 2
         },
         "hints" : "",
         "order" : 2
      },
      "player" : {
         "order" : 4,
         "hints" : "",
         "bytes" : {
            "total" : 2,
            "suffix" : 1,
            "base" : 2
         }
      },
      "colony" : {
         "hints" : "",
         "bytes" : {
            "total" : 2,
            "base" : 2,
            "suffix" : 1
         },
         "order" : 1
      },
      "indian" : {
         "bytes" : {
            "total" : 2,
            "suffix" : 1,
            "base" : 2
         },
         "hints" : "",
         "order" : 6
      }
   },
   "tail" : {
      "unk" : {
         "order" : 234,
         "bytes" : {
            "base" : 1,
            "suffix" : 1502,
            "total" : 1502
         },
         "hints" : ""
      }
   },
   "unit" : {
      "type" : {
         "bytes" : {
            "total" : 1,
            "suffix" : 1,
            "base" : 1
         },
         "hints" : "",
         "order" : 154
      },
      "cargo_item_3" : {
         "order" : 167,
         "bytes" : {
            "total" : 4,
            "suffix" : 4,
            "base" : 1
         },
         "hints" : ""
      },
      "unk06" : {
         "hints" : "",
         "bytes" : {
            "suffix" : 1,
            "base" : 1,
            "total" : 1
         },
         "order" : 159
      },
      "cargo_hold" : {
         "order" : 170,
         "hints" : "",
         "bytes" : {
            "suffix" : 6,
            "base" : 1,
            "total" : 6
         }
      },
      "cargo_item_5" : {
         "hints" : "",
         "bytes" : {
            "total" : 4,
            "base" : 1,
            "suffix" : 4
         },
         "order" : 169
      },
      "moves" : {
         "bytes" : {
            "base" : 1,
            "suffix" : 1,
            "total" : 1
         },
         "hints" : " /* Accumulated moves (3 between land, 1 on roads, etc.) */",
         "order" : 158
      },
      "cargo_item_0" : {
         "bytes" : {
            "suffix" : 4,
            "base" : 1,
            "total" : 4
         },
         "hints" : "",
         "order" : 164
      },
      "order" : {
         "order" : 161,
         "bytes" : {
            "total" : 1,
            "base" : 1,
            "suffix" : 1
         },
         "hints" : " enum { PLOW = 8, ROAD = 9 };"
      },
      "turns_worked" : {
         "hints" : "",
         "bytes" : {
            "suffix" : 1,
            "base" : 1,
            "total" : 1
         },
         "order" : 171
      },
      "unk04" : {
         "order" : 156,
         "hints" : "",
         "bytes" : {
            "base" : 1,
            "suffix" : 4,
            "total" : 4
         }
      },
      "cargo_item_1" : {
         "bytes" : {
            "total" : 4,
            "base" : 1,
            "suffix" : 4
         },
         "hints" : "",
         "order" : 165
      },
      "transport_chain" : {
         "prev_unit_idx" : {
            "order" : 174,
            "bytes" : {
               "total" : 2,
               "suffix" : 1,
               "base" : 2
            },
            "hints" : " // index to unit being transported? (treasure) "
         },
         "next_unit_idx" : {
            "order" : 173,
            "bytes" : {
               "suffix" : 1,
               "base" : 2,
               "total" : 2
            },
            "hints" : ""
         }
      },
      "unk07" : {
         "hints" : "",
         "bytes" : {
            "suffix" : 1,
            "base" : 1,
            "total" : 1
         },
         "order" : 160
      },
      "x" : {
         "order" : 153,
         "bytes" : {
            "total" : 1,
            "suffix" : 1,
            "base" : 1
         },
         "hints" : ""
      },
      "holds_occupied" : {
         "order" : 163,
         "bytes" : {
            "base" : 1,
            "suffix" : 1,
            "total" : 1
         },
         "hints" : ""
      },
      "cargo_item_4" : {
         "order" : 168,
         "bytes" : {
            "base" : 1,
            "suffix" : 4,
            "total" : 4
         },
         "hints" : ""
      },
      "nation" : {
         "order" : 155,
         "bytes" : {
            "base" : 1,
            "suffix" : 4,
            "total" : 4
         },
         "hints" : " /* likely to be owner of unit, eng, fra, spa, dut, indian tribes, etc. */"
      },
      "unk05" : {
         "order" : 157,
         "hints" : "",
         "bytes" : {
            "base" : 1,
            "suffix" : 1,
            "total" : 1
         }
      },
      "cargo_item_2" : {
         "bytes" : {
            "base" : 1,
            "suffix" : 4,
            "total" : 4
         },
         "hints" : "",
         "order" : 166
      },
      "unk08" : {
         "order" : 162,
         "hints" : "",
         "bytes" : {
            "total" : 3,
            "base" : 1,
            "suffix" : 3
         }
      },
      "profession" : {
         "hints" : "",
         "bytes" : {
            "base" : 1,
            "suffix" : 1,
            "total" : 1
         },
         "order" : 172
      }
   },
   "map" : {
      "hints" : "// 56*70 visible + border, = 58*72 = 4176,",
      "bytes" : {
         "base" : 1,
         "suffix" : 4176,
         "total" : 4176
      },
      "order" : 233
   },
   "colony" : {
      "custom_house" : {
         "muskets" : {
            "bytes" : {
               "suffix" : 1,
               "base" : 2,
               "total" : 2
            },
            "hints" : "",
            "order" : 144
         },
         "furs" : {
            "hints" : "",
            "bytes" : {
               "suffix" : 1,
               "base" : 2,
               "total" : 2
            },
            "order" : 133
         },
         "cotton" : {
            "hints" : "",
            "bytes" : {
               "total" : 2,
               "base" : 2,
               "suffix" : 1
            },
            "order" : 132
         },
         "lumber" : {
            "order" : 134,
            "hints" : "",
            "bytes" : {
               "total" : 2,
               "suffix" : 1,
               "base" : 2
            }
         },
         "ore" : {
            "hints" : "",
            "bytes" : {
               "total" : 2,
               "suffix" : 1,
               "base" : 2
            },
            "order" : 135
         },
         "tobacco" : {
            "hints" : "",
            "bytes" : {
               "suffix" : 1,
               "base" : 2,
               "total" : 2
            },
            "order" : 131
         },
         "tools" : {
            "hints" : "",
            "bytes" : {
               "base" : 2,
               "suffix" : 1,
               "total" : 2
            },
            "order" : 143
         },
         "cigars" : {
            "order" : 139,
            "bytes" : {
               "total" : 2,
               "suffix" : 1,
               "base" : 2
            },
            "hints" : ""
         },
         "silver" : {
            "bytes" : {
               "base" : 2,
               "suffix" : 1,
               "total" : 2
            },
            "hints" : "",
            "order" : 136
         },
         "cloth" : {
            "order" : 140,
            "hints" : "",
            "bytes" : {
               "total" : 2,
               "suffix" : 1,
               "base" : 2
            }
         },
         "horses" : {
            "hints" : "",
            "bytes" : {
               "base" : 2,
               "suffix" : 1,
               "total" : 2
            },
            "order" : 137
         },
         "sugar" : {
            "order" : 130,
            "hints" : "",
            "bytes" : {
               "base" : 2,
               "suffix" : 1,
               "total" : 2
            }
         },
         "trade_goods" : {
            "hints" : "",
            "bytes" : {
               "suffix" : 1,
               "base" : 2,
               "total" : 2
            },
            "order" : 142
         },
         "rum" : {
            "bytes" : {
               "total" : 2,
               "base" : 2,
               "suffix" : 1
            },
            "hints" : "",
            "order" : 138
         },
         "food" : {
            "order" : 129,
            "bytes" : {
               "suffix" : 1,
               "base" : 2,
               "total" : 2
            },
            "hints" : ""
         },
         "coats" : {
            "order" : 141,
            "hints" : "",
            "bytes" : {
               "total" : 2,
               "base" : 2,
               "suffix" : 1
            }
         }
      },
      "occupation" : {
         "order" : 106,
         "hints" : "",
         "bytes" : {
            "base" : 1,
            "suffix" : 32,
            "total" : 32
         }
      },
      "rebel_dividend" : {
         "order" : 151,
         "bytes" : {
            "total" : 4,
            "suffix" : 1,
            "base" : 4
         },
         "hints" : ""
      },
      "buildings" : {
         "schoolhouse" : {
            "bytes" : {
               "suffix" : 3,
               "base" : 4,
               "total" : 12
            },
            "hints" : "",
            "order" : 115
         },
         "carpenters_shop" : {
            "hints" : "",
            "bytes" : {
               "suffix" : 2,
               "base" : 2,
               "total" : 4
            },
            "order" : 125
         },
         "stables" : {
            "order" : 117,
            "bytes" : {
               "total" : 4,
               "base" : 4,
               "suffix" : 1
            },
            "hints" : ""
         },
         "warehouse" : {
            "hints" : "",
            "bytes" : {
               "total" : 8,
               "base" : 4,
               "suffix" : 2
            },
            "order" : 116
         },
         "custom_house" : {
            "bytes" : {
               "base" : 4,
               "suffix" : 1,
               "total" : 4
            },
            "hints" : "",
            "order" : 118
         },
         "stockade" : {
            "hints" : "",
            "bytes" : {
               "suffix" : 3,
               "base" : 4,
               "total" : 12
            },
            "order" : 111
         },
         "blacksmiths_house" : {
            "hints" : "",
            "bytes" : {
               "total" : 6,
               "suffix" : 3,
               "base" : 2
            },
            "order" : 127
         },
         "church" : {
            "bytes" : {
               "total" : 4,
               "suffix" : 2,
               "base" : 2
            },
            "hints" : "",
            "order" : 126
         },
         "fur_traders_house" : {
            "order" : 124,
            "hints" : "",
            "bytes" : {
               "suffix" : 3,
               "base" : 2,
               "total" : 6
            }
         },
         "rum_distillers_house" : {
            "bytes" : {
               "base" : 4,
               "suffix" : 3,
               "total" : 12
            },
            "hints" : "",
            "order" : 122
         },
         "printing_press" : {
            "order" : 119,
            "bytes" : {
               "total" : 8,
               "base" : 4,
               "suffix" : 2
            },
            "hints" : ""
         },
         "docks" : {
            "order" : 113,
            "bytes" : {
               "total" : 12,
               "base" : 4,
               "suffix" : 3
            },
            "hints" : ""
         },
         "weavers_house" : {
            "order" : 120,
            "bytes" : {
               "suffix" : 3,
               "base" : 4,
               "total" : 12
            },
            "hints" : ""
         },
         "town_hall" : {
            "bytes" : {
               "suffix" : 3,
               "base" : 4,
               "total" : 12
            },
            "hints" : "",
            "order" : 114
         },
         "unused" : {
            "order" : 128,
            "bytes" : {
               "suffix" : 6,
               "base" : 2,
               "total" : 12
            },
            "hints" : ""
         },
         "tobacconists_house" : {
            "bytes" : {
               "suffix" : 3,
               "base" : 4,
               "total" : 12
            },
            "hints" : "",
            "order" : 121
         },
         "capitol" : {
            "order" : 123,
            "bytes" : {
               "total" : 8,
               "suffix" : 2,
               "base" : 4
            },
            "hints" : " /* not really in use */"
         },
         "armory" : {
            "order" : 112,
            "bytes" : {
               "total" : 12,
               "base" : 4,
               "suffix" : 3
            },
            "hints" : ""
         }
      },
      "population" : {
         "order" : 105,
         "hints" : "",
         "bytes" : {
            "total" : 1,
            "base" : 1,
            "suffix" : 1
         }
      },
      "profession" : {
         "hints" : "",
         "bytes" : {
            "suffix" : 32,
            "base" : 1,
            "total" : 32
         },
         "order" : 107
      },
      "tiles" : {
         "bytes" : {
            "total" : 8,
            "base" : 1,
            "suffix" : 8
         },
         "hints" : " //represents tiles around the colony. idx to citizen.",
         "order" : 109
      },
      "unk6" : {
         "bytes" : {
            "suffix" : 16,
            "base" : 1,
            "total" : 16
         },
         "hints" : "",
         "order" : 108
      },
      "x" : {
         "order" : 101,
         "bytes" : {
            "suffix" : 1,
            "base" : 1,
            "total" : 1
         },
         "hints" : ""
      },
      "building_in_production" : {
         "bytes" : {
            "total" : 1,
            "suffix" : 1,
            "base" : 1
         },
         "hints" : "",
         "order" : 147
      },
      "unk8" : {
         "order" : 110,
         "bytes" : {
            "suffix" : 12,
            "base" : 1,
            "total" : 12
         },
         "hints" : ""
      },
      "rebel_divisor" : {
         "order" : 152,
         "hints" : "",
         "bytes" : {
            "suffix" : 1,
            "base" : 4,
            "total" : 4
         }
      },
      "unk0" : {
         "hints" : "",
         "bytes" : {
            "suffix" : 4,
            "base" : 1,
            "total" : 4
         },
         "order" : 104
      },
      "nation" : {
         "order" : 103,
         "bytes" : {
            "total" : 1,
            "suffix" : 1,
            "base" : 1
         },
         "hints" : ""
      },
      "stock" : {
         "order" : 149,
         "hints" : "",
         "bytes" : {
            "base" : 2,
            "suffix" : 16,
            "total" : 32
         }
      },
      "name" : {
         "hints" : "",
         "bytes" : {
            "suffix" : 24,
            "base" : 1,
            "total" : 24
         },
         "order" : 102
      },
      "hammers" : {
         "hints" : "",
         "bytes" : {
            "total" : 2,
            "base" : 2,
            "suffix" : 1
         },
         "order" : 146
      },
      "unka" : {
         "order" : 145,
         "hints" : "",
         "bytes" : {
            "total" : 6,
            "base" : 1,
            "suffix" : 6
         }
      },
      "unkd" : {
         "order" : 150,
         "bytes" : {
            "suffix" : 8,
            "base" : 1,
            "total" : 8
         },
         "hints" : ""
      },
      "unkb" : {
         "order" : 148,
         "hints" : "",
         "bytes" : {
            "suffix" : 5,
            "base" : 1,
            "total" : 5
         }
      }
   },
   "stuff" : {
      "counter_decreasing_on_new_colony" : {
         "hints" : "",
         "bytes" : {
            "total" : 2,
            "suffix" : 1,
            "base" : 2
         },
         "order" : 223
      },
      "viewport_x" : {
         "order" : 231,
         "hints" : "",
         "bytes" : {
            "suffix" : 1,
            "base" : 2,
            "total" : 2
         }
      },
      "unk15" : {
         "hints" : "",
         "bytes" : {
            "total" : 15,
            "base" : 1,
            "suffix" : 15
         },
         "order" : 222
      },
      "zoom_level" : {
         "bytes" : {
            "total" : 1,
            "base" : 1,
            "suffix" : 1
         },
         "hints" : "",
         "order" : 229
      },
      "unk_big" : {
         "bytes" : {
            "suffix" : 696,
            "base" : 1,
            "total" : 696
         },
         "hints" : "",
         "order" : 226
      },
      "y" : {
         "bytes" : {
            "total" : 2,
            "base" : 2,
            "suffix" : 1
         },
         "hints" : "",
         "order" : 228
      },
      "unk7" : {
         "bytes" : {
            "total" : 1,
            "base" : 1,
            "suffix" : 1
         },
         "hints" : "",
         "order" : 230
      },
      "viewport_y" : {
         "hints" : "",
         "bytes" : {
            "total" : 2,
            "suffix" : 1,
            "base" : 2
         },
         "order" : 232
      },
      "x" : {
         "hints" : "",
         "bytes" : {
            "base" : 2,
            "suffix" : 1,
            "total" : 2
         },
         "order" : 227
      },
      "unk_short" : {
         "order" : 224,
         "bytes" : {
            "total" : 2,
            "suffix" : 1,
            "base" : 2
         },
         "hints" : ""
      },
      "counter_increasing_on_new_colony" : {
         "order" : 225,
         "hints" : "",
         "bytes" : {
            "base" : 2,
            "suffix" : 1,
            "total" : 2
         }
      }
   }
}

    )"_json;
    return j;
}
